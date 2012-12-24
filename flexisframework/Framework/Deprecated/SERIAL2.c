

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#include "../Headers/SCI2.H"
extern void CLI(void);
extern void STI(void);
typedef void(*PFNCALLBACK)(void);

//
// Baud rate constants for 48 MHz
//
// 0 = 1200
// 1 = 2400
// 2 = 4800
// 3 = 9600
// 4 = 19200
// 5 = 38400
// 6 = 57600
// 7 = 115200
static const  byte  BaudRateH[0x08] = {0x04,0x02,0x01,0x00,0x00,0x00,0x00,0x00};
static const  byte  BaudRateL[0x08] = {0xE2,0x71,0x38,0x9C,0x4E,0x27,0x1A,0x0D};



#define OVERRUN_ERR      1          
#define COMMON_ERR       2         
#define FULL_RX          16  // Indicates rx buffer is full.   


static volatile byte StatusFlag;          
static byte RXBufferCount;                      
static byte ReadRXIndex;                  // Next byte to read from buffer
static byte WriteRXIndex;                 // Next byte to write into buffer.
static byte InputBuffer[RX_BUFFER_SIZE]; 
static byte TXBufferCount;                // Remaing TX Data bytes
static byte ReadTXIndex;                  // Next byte to read from TX buffer
static byte WriteTXIndex;                 // Next byte to write to in TX buffer.
static byte OutputBuffer[TX_BUFFER_SIZE]; 
static byte OnFreeTxBuf_semaphore;     /* Disable the false calling of the OnFreeTxBuf event */


byte SCI2_RXByte(byte *data)
{
  byte rc = 0;                

  if (RXBufferCount > 0) 
  {
    CLI();                  
    RXBufferCount--;                      
    *data = InputBuffer[ReadRXIndex];        
    ReadRXIndex++; 
    // Wrap the buffer around    
    if(ReadRXIndex == RX_BUFFER_SIZE)
        ReadRXIndex = 0;     
    STI();                   
  } 
  else 
  {
    return RX_EMPTY;                
  }
  return rc;                       
}


byte SCI2_TXByte(byte data)
{
  
  if (TXBufferCount == TX_BUFFER_SIZE) 
  { 
    return TX_FULL;                 
  }
  // Disable interrupts if enabled.
  CLI();
                       
  TXBufferCount++;                       
  // Place the character in the buffer
  // for the interrupt to send
  OutputBuffer[WriteTXIndex] = data;           
  
  ++WriteTXIndex;
  
  if(WriteTXIndex == TX_BUFFER_SIZE)
      WriteTXIndex = 0;
  
  // Raising TIE will cause an interrupt.
  // TDRE is set out of reset, and we leave it that
  // way in the handler unless we have another character to send.
  if (!SCI2C2_TIE) 
  {                 
      SCI2C2_TIE = 0x01;               
  }
  // Re-enable interrupts if disabled.
  STI();                     
  return 0;                       
}



byte SCI2_TxBuffer(byte* data, word len, word *sent)
{
  word count = 0;                   

  while((count < len) && (TXBufferCount < TX_BUFFER_SIZE)) 
  {
    CLI();                   
    TXBufferCount++;                      
    OutputBuffer[WriteTXIndex] = *data++; 
         
    ++WriteTXIndex;
    if(  WriteTXIndex == TX_BUFFER_SIZE)
      WriteTXIndex = 0;

    count++;                          
    
    if (!SCI2C2_TIE) 
    {                 
      SCI2C2_TIE = 1;              
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

byte SCI2_RxCount(word *count) 
{
   *count = (word)RXBufferCount;
   return 0;
}


byte SCI2_TxCount(word *count)
{
  *count = (word) TXBufferCount;            
  return 0;                     
}

void (*OnSCI2RxChar)(void) =(PFNCALLBACK) 0;
void (*OnSCI2RxOverrun)(void) = (PFNCALLBACK)0;
interrupt VectorNumber_Vsci2rx  void SCI2_RXInterruptandler();
interrupt VectorNumber_Vsci2rx  void SCI2_RXInterruptandler()
{
  volatile byte Status = SCI2S1;               
  byte RxData = SCI2D;         

  if (RXBufferCount < RX_BUFFER_SIZE) 
  { 
    RXBufferCount++;                      
    InputBuffer[WriteRXIndex] = RxData;        
     ++WriteRXIndex;
    if(WriteRXIndex == RX_BUFFER_SIZE)
          WriteRXIndex = 0;
 
  } 
  else                                                                      
  {
    StatusFlag |= FULL_RX;                
  }
  
  if( OnSCI2RxChar )
     OnSCI2RxChar();           
}

typedef void(*PFNINTCALLBACK)(int);
void (*OnSCI2TxChar)(int) = (PFNINTCALLBACK) 0;
interrupt VectorNumber_Vsci2tx  void SCI2_TXInterruptandler();
interrupt VectorNumber_Vsci2tx  void SCI2_TXInterruptandler()
{
	
  // Reset the interrupt...
  volatile byte Status = SCI2S1;	

  if (TXBufferCount) 
  {                    
    TXBufferCount--;                     
    // Send the next character                      
    SCI2D = OutputBuffer[ReadTXIndex];       
    
    ++ReadTXIndex;
    if( ReadTXIndex == TX_BUFFER_SIZE )
            ReadTXIndex = 0;
  } 
  else 
  {
    // If this is the last character to be sent,
    // do NOT clear TDRE so that raising TIE cause an interrupt.
    SCI2C2_TIE = 0; 
  }
   if( OnSCI2TxChar )
     OnSCI2TxChar(TXBufferCount);           

}

void (*OnSCI2Error)(void) =(PFNCALLBACK) 0;
interrupt VectorNumber_Vsci2err void SCI2_InterruptErrorHandler();
interrupt VectorNumber_Vsci2err void SCI2_InterruptErrorHandler()
{
  volatile byte Status = SCI2S1;
  // Read to clear error
  (void)SCI2D;                         
  
  StatusFlag |= COMMON_ERR; 
  
  if( OnSCI2Error )
     OnSCI2Error();           
                       
}

//------------------------------------------------
//
//  Initialize and set baud rate to 9600.
//
//------------------------------------------------

void SCI2_Init(void)
{
  StatusFlag = 0;                      
  TXBufferCount = RXBufferCount = 0;                   
  ReadRXIndex = WriteRXIndex = 0;          
  ReadTXIndex = WriteTXIndex = 0;         
  /* SCI1C1: LOOPS=0,SCISWAI=0,RSRC=0,M=0,WAKE=0,ILT=0,PE=0,PT=0 */
  SCI2C1 = 0;               
  SCI2C3 = 0;               
  SCI2S2 = 0;                
  SCI2C2 = 0; 
  
  // Set default baud rate to 9600 with 48Mhz clock. 
  SCI2BDH = 0; 
  SCI2BDL = 0x9C;
  
  // Enable error interrupts.
  SCI2C3 |= 0x0F;    
  
  // Enable TX, RX, and RX Interrupts
  // Only turn on TX (TIE) interrupts when there is data to send                   
  SCI2C2 |= ( SCI2C2_TE_MASK | SCI2C2_RE_MASK | SCI2C2_RIE_MASK); 
}
//------------------------------------------------
// See baud rate table.
//
//------------------------------------------------
byte SCI2_SetBaudRate(byte Baud)
{

  if (Baud >= 0x08) 
  {                   
    return (byte) 1;                  
  }
  SCI2BDH = BaudRateH[Baud];                  
  SCI2BDL = BaudRateL[Baud];                  
  return 0;                      
}


