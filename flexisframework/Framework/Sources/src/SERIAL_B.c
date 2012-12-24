/*
 *  SERIAL_B.C
 *  Interrupt driven support for both serial ports.
 *
 *  $Rev:: 184                       $:
 *  $Date:: 2012-09-09 16:24:03 -040#$:
 *  $Author:: jcdonelson             $:
*/

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#include "SERIAL_B.H"
extern void CLI(void);
extern void STI(void);
#include "CONFIG.H"

//
// Baud rate constants 
//
// 0 = 1200
// 1 = 2400
// 2 = 4800
// 3 = 9600
// 4 = 19200
// 5 = 38400
// 6 = 57600
// 7 = 115200
#if CLK12MHZ_XTAL   == 1
// 48MHz
static const  byte  BaudRateH[0x08] = {0x04,0x02,0x01,0x00,0x00,0x00,0x00,0x00};
static const  byte  BaudRateL[0x08] = {0xE2,0x71,0x38,0x9C,0x4E,0x27,0x1A,0x0D};
#else 
// Internal clock at 50.331648 at 115200 there is a 2.5% error.
static const  byte BaudRateH[0x08] = {0x05,0x02,0x01,0x00,0x00,0x00,0x00,0x00};
static const  byte BaudRateL[0x08] = {0x1F,0x8F,0x48,0xA4,0x52,0x29,0x1B,0x0E};
#endif



#define OVERRUN_ERR      1          
#define COMMON_ERR       2         
#define FULL_RX          16  // Indicates rx buffer is full.   


typedef struct _serial_state {
	byte StatusFlag;          
	byte RXBufferCount;                // How many byte are in the RX buffer     
	byte ReadRXIndex;                  // Next byte to read from buffer
	byte WriteRXIndex;                 // Next byte to write into buffer.
	byte InputBuffer[RX_BUFFER_SIZE]; 
	byte TXBufferCount;                // Remaing TX Data bytes
	byte ReadTXIndex;                  // Next byte to read from TX buffer
	byte WriteTXIndex;                 // Next byte to write to in TX buffer.
	byte OutputBuffer[TX_BUFFER_SIZE]; 
	void (*OnSCInRxChar)(void);
	void (*OnSCInRxOverrun)(void);
	void (*OnSCInError)(void);
	void (*OnSCInTxChar)(int);
} SERIAL_STATE;

static SERIAL_STATE states[2];

typedef struct _sci_regs {
	volatile byte* SCInC1;
	volatile byte* SCInC2;
	volatile byte* SCInC3;
	volatile byte* SCInS1;
	volatile byte* SCInS2;
	volatile byte* SCInBDH;
	volatile byte* SCInBDL;
	volatile byte* SCInD;
} SCI_REGS;
static SCI_REGS sci_regs[2]={
{&SCI1C1,&SCI1C2,&SCI1C3,&SCI1S1,&SCI1S2,&SCI1BDH,&SCI1BDL,&SCI1D},		
{&SCI2C1,&SCI2C2,&SCI2C3,&SCI2S1,&SCI2S2,&SCI2BDH,&SCI2BDL,&SCI2D},		
};
void SendString(int port,char *s) 
{
   while(*s) 
   {
       while(TX_FULL == Serial_txbyte(port,(byte)*s))
       ;
       ++s;
   }
}


byte Serial_rxbyte(int port, byte *data)
{
  byte rc = 0;                

  if (states[port].RXBufferCount > 0) 
  {
    CLI();                  
    states[port].RXBufferCount--;                      
    *data = states[port].InputBuffer[states[port].ReadRXIndex];        
    states[port].ReadRXIndex++; 
    // Wrap the buffer around    
    if(states[port].ReadRXIndex == RX_BUFFER_SIZE)
    	states[port].ReadRXIndex = 0;     
    STI();                   
  } 
  else 
  {
    return RX_EMPTY;                
  }
  return rc;                       
}


byte Serial_txbyte(int port,byte data)
{
  
  if (states[port].TXBufferCount == TX_BUFFER_SIZE) 
  { 
    return TX_FULL;                 
  }
  // Disable interrupts if enabled.
  CLI();
                       
  states[port].TXBufferCount++;                       
  // Place the character in the buffer
  // for the interrupt to send
  states[port].OutputBuffer[states[port].WriteTXIndex] = data;           
  
  states[port].WriteTXIndex++;
  
  if(states[port].WriteTXIndex == TX_BUFFER_SIZE)
	  states[port].WriteTXIndex = 0;
  
  // Raising TIE will cause an interrupt.
  // TDRE is set out of reset, and we leave it that
  // way in the handler unless we have another character to send.
  if (0 == (*sci_regs[port].SCInC2 & SCI1C2_TIE_MASK)  ) 
  {                 
	  *sci_regs[port].SCInC2 |= SCI1C2_TIE_MASK;               
  }
  // Re-enable interrupts if disabled.
  STI();                     
  return 0;                       
}


byte Serial_txbuf(int port,byte* data, word len, word *sent)
{
  word count = 0;                   

  while((count < len) && (states[port].TXBufferCount < TX_BUFFER_SIZE)) 
  {
    CLI();                   
    states[port].TXBufferCount++;                      
    states[port].OutputBuffer[states[port].WriteTXIndex] = *data++; 
         
    states[port].WriteTXIndex++;
    if(  states[port].WriteTXIndex == TX_BUFFER_SIZE)
    	states[port].WriteTXIndex = 0;

    count++;                          
    
    if (0 == (*sci_regs[port].SCInC2 & SCI1C2_TIE_MASK)  ) 
    {                 
  	  *sci_regs[port].SCInC2 |= SCI1C2_TIE_MASK;               
    }
    STI();                   
  }
  
  *sent = count;
                         
  if (count != len) 
  {                
    return TX_FULL;                
  }
  return 0;                       
}

byte Serial_rxlen(int port, word *count) 
{
   *count = (word)states[port].RXBufferCount;
   return 0;
}


byte Serial_txlen(int port, word *count)
{
  *count = (word) states[port].TXBufferCount;            
  return 0;                     
}
void RXInterruptHandler(int port);
interrupt VectorNumber_Vsci1rx  void SCI1_RXInterruptandler(void);
interrupt VectorNumber_Vsci1rx  void SCI1_RXInterruptandler(void)
{
	RXInterruptHandler(0);
}
interrupt VectorNumber_Vsci2rx  void SCI2_RXInterruptandler(void);
interrupt VectorNumber_Vsci2rx  void SCI2_RXInterruptandler(void)
{
	RXInterruptHandler(1);
}

void RXInterruptHandler(int port)
{
	  byte Status = *sci_regs[port].SCInS1;               
	  byte RxData = *sci_regs[port].SCInD;         

	  if (states[port].RXBufferCount < RX_BUFFER_SIZE) 
	  { 
		  states[port].RXBufferCount++;                      
		  states[port].InputBuffer[states[port].WriteRXIndex] = RxData;        
		  states[port].WriteRXIndex++;
	    if(states[port].WriteRXIndex == RX_BUFFER_SIZE)
	    	states[port].WriteRXIndex = 0;
	 
	  } 
	  else                                                                      
	  {
		  states[port].StatusFlag |= FULL_RX;                
	  }
	  
	  if( states[port].OnSCInRxChar )
		  states[port].OnSCInRxChar();	
}

void TXInterruptHandler(int port);
interrupt VectorNumber_Vsci1tx  void SCI1_TXInterruptandler(void);
interrupt VectorNumber_Vsci1tx  void SCI1_TXInterruptandler(void)
{
	TXInterruptHandler(0);      

}
interrupt VectorNumber_Vsci2tx  void SCI2_TXInterruptandler(void);
interrupt VectorNumber_Vsci2tx  void SCI2_TXInterruptandler(void)
{
	TXInterruptHandler(1);      

}

void TXInterruptHandler(int port)
{
	  if (states[port].TXBufferCount) 
	  {                    
		states[port].TXBufferCount--;
		// Set up to clear TDRE
		(void)*sci_regs[port].SCInS1;
		// Send the next character and clear TDRE                      
		*sci_regs[port].SCInD = 
			states[port].OutputBuffer[states[port].ReadTXIndex];       
		states[port].ReadTXIndex++;
		// Roll over the buffer if at end.
		if( states[port].ReadTXIndex == TX_BUFFER_SIZE )
			states[port].ReadTXIndex = 0;
	  } 
	  else 
	  {
	    // If this is the last character to be sent,
		// Then disable TX interrupts, as we leave it armed.
		// When TIE is set again, it will interrupt. 
	    *sci_regs[port].SCInC2 &= ~(SCI1C2_TIE_MASK); 
	  }
	   if( states[port].OnSCInTxChar )
		   states[port].OnSCInTxChar(states[port].TXBufferCount);   	
}

static void ErrorInterruptHandler(int port);
interrupt VectorNumber_Vsci1err void SCI1_InterruptErrorHandler();
interrupt VectorNumber_Vsci1err void SCI1_InterruptErrorHandler()
{
	ErrorInterruptHandler(0);        
                       
}
interrupt VectorNumber_Vsci2err void SCI2_InterruptErrorHandler();
interrupt VectorNumber_Vsci2err void SCI2_InterruptErrorHandler()
{
	ErrorInterruptHandler(1);        
                       
}
void ErrorInterruptHandler(int port)
{
	volatile byte Status =  *sci_regs[port].SCInS1;
	  // Read to clear error
	  (void) *sci_regs[port].SCInD ;                         
	  
	  states[port].StatusFlag |= COMMON_ERR; 
	  
	  if( states[port].OnSCInError )
		  states[port].OnSCInError();        
}
//------------------------------------------------
//
//  Initialize and set baud rate to 9600.
//
//------------------------------------------------

void Serial_Init(int port)
{
	states[port].StatusFlag = 0;                      
	states[port].TXBufferCount = states[port].RXBufferCount = 0;                   
	states[port].ReadRXIndex = states[port].WriteRXIndex = 0;          
	states[port].ReadTXIndex = states[port].WriteTXIndex = 0;         
  /* SCI1C1: LOOPS=0,SCISWAI=0,RSRC=0,M=0,WAKE=0,ILT=0,PE=0,PT=0 */
	*sci_regs[port].SCInC1 = 0;               
	*sci_regs[port].SCInC3 = 0;               
	*sci_regs[port].SCInS2 = 0;                
	*sci_regs[port].SCInC2 = 0; 

  // Set default baud rate to 9600 
	Serial_setbaudrate( port,3); 
  // Enable error interrupts.
	*sci_regs[port].SCInC3 |= 0x0F;    
  
  // Enable TX, RX, and RX Interrupts
  // Only turn on TX (TIE) interrupts when there is data to send                   
	*sci_regs[port].SCInC2 |= ( SCI1C2_TE_MASK | SCI1C2_RE_MASK | SCI1C2_RIE_MASK); 
}
//------------------------------------------------
// See baud rate table.
//
//------------------------------------------------
byte Serial_setbaudrate(int port,byte Baud)
{

  if (Baud >= 0x08) 
  {                   
    return (byte) BAD_BAUD_RATE;                  
  }
  *sci_regs[port].SCInBDH  = BaudRateH[Baud];                  
  *sci_regs[port].SCInBDL = BaudRateL[Baud];                  
  return 0;                      
}


