/*
 *  I2C_DRIVER.C
 *  $Rev:: 39                        $:
 *  $Date:: 2011-04-13 10:36:58 -040#$:
 *  $Author:: jcdonelson             $:
 * 
 */

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "I2C_DRIVER.h"
extern void CLI(void);
extern void STI(void);

#define ERROR_NONE              0
#define ERROR_BUSBUSY           1
#define ERROR_NOTREADY          2
#define ERROR_NAK               4
#define ERROR_ARB_LOSS          8

          
          
#define CHAN_BUSY        0x01          
         
#ifndef IIC1C1_MST
#define IIC1C1_MST IICC_MST
#define IIC1C1_TX  IICC_TX
#define IIC1C1_TXAK IICC_TXAK 
#define IIC1S_RXAK_MASK IICS_RXAK_MASK
#define IIC1D  IICD
#define IIC1S  IICS
#define IIC1S_ARBL IICS_ARBL
#define IIC1S_ARBL_MASK  IICS_ARBL_MASK
#define IIC1S_IICIF    IICS_IICIF
#define IIC1C1_TX      IICC_TX
#define IIC1C1_RSTA    IICC_RSTA
#define IIC1S_BUSY     IICS_BUSY
#define IIC1F  IICF
#define IIC1C1_IICEN  IICC_IICEN
#define IIC1C1        IICC



#endif

static volatile byte I2C_Status;            
static byte DeviceAddress;            

static byte LastErrorStatus = 0;
static word ReadBufferSize=0;             
static byte *pReadPointer=0;
static word WriteBufferSize=0;                 
static byte *pWritePointer=0;

byte I2CGetLastError(void)
{
    byte rc  = LastErrorStatus;
    LastErrorStatus = 0;
    return rc;
}

void ServiceSendInterrupt(byte StatusRegister );
void ServiceSendInterrupt(byte StatusRegister )
{
  if(StatusRegister & IIC1S_RXAK_MASK ) 
  { 
    // Didn't get an ack, so it is a NACK
    // Stop everything.
    ReadBufferSize = 0;   
    WriteBufferSize = 0;   
    IIC1C1_TX = 0;              // Cancel TX mode.
    IIC1C1_MST = 0;             // Send stop signal
    I2C_Status &= ~(CHAN_BUSY); 
    LastErrorStatus |= ERROR_NAK;
    return;
  }
    if(WriteBufferSize) 
    {  // More TX Data ?               
      WriteBufferSize--;                 
      IIC1D = *(pWritePointer)++;   // Send it.   
    }
    else 
    {
      if(ReadBufferSize) 
      {               
        if(ReadBufferSize == 1) 
        {        
          IIC1C1_TXAK = 1;         
        }
        else 
        {
          IIC1C1_TXAK = 0; 
        }
        IIC1C1_TX = 0;
        // Read the character to cause another interrupt.
        (void)IIC1D;      
      }
      else 
      {
        I2C_Status &= ~CHAN_BUSY; 
        IIC1C1_MST = 0;            
        IIC1C1_TX = 0;             
//           I2C_OnTransmitData();     
      }
    }

}
#ifndef VectorNumber_Viic1x
#define VectorNumber_Viic1x VectorNumber_Viic 
#endif
interrupt  VectorNumber_Viic1x void I2CInterruptHandler(void)
{
  byte StatusRegister;

  StatusRegister = IIC1S;
  // Clear the interrupt.
  IIC1S_IICIF = 1;       
  if( IIC1S_ARBL_MASK & StatusRegister )
  {  // Loss of arbitration.... should not happen.
    IIC1S_ARBL = 1;                     // Clear bit
    // Cancel all transactions.
    ReadBufferSize = 0;   
    WriteBufferSize = 0;   
    IIC1C1_TX = 0; 
    I2C_Status &= ~CHAN_BUSY; 
    // Set error status.
    LastErrorStatus |= ERROR_ARB_LOSS;
    return;
  }
  if(IIC1C1_TX) 
  {   
    ServiceSendInterrupt( StatusRegister );
  }
  else  
  {
    ReadBufferSize--; 
    if(ReadBufferSize) 
    {
      if(ReadBufferSize == 1) 
      { 
        // Don't send an ack as last read.
        IIC1C1_TXAK = 1;
      }
    }
    else 
    {
      IIC1C1_MST = 0;           // Send stop, so we don't get more data
      IIC1C1_TXAK = 0;          // Reset from last one above.
    }
    *(pReadPointer)++ = IIC1D;  
  }
  
}

word I2CGetRemainingSendBytes(void)
{
  return WriteBufferSize; // Bytes left to send.
}

word I2CGetRemainingRecieveBytes(void)
{
  return ReadBufferSize; // Number of bytes received.
}


/*
 *   I2C_Send(byte *data,word size)
 */
byte I2CSend(byte *data,word size)
{
  if (0 == size) 
  {                          
    return ERROR_NONE;                  
  }
  // If the chip says busy, or we think we are busy or we are reading
  if((IIC1S_BUSY)||(I2C_Status & CHAN_BUSY)||(ReadBufferSize)) 
  { 
    return ERROR_BUSBUSY;                 
  }

  CLI(); 
  IIC1C1_TX = 1; 
  pWritePointer = data;           
  WriteBufferSize = size;            
             
  I2C_Status |= CHAN_BUSY;  
  if(IIC1C1_MST) 
  {  
    // If we are already in master mode, the do a repeat start
    IIC1C1_RSTA = 1;        
  }
  else 
  {
    // This also generates a start signal.
    IIC1C1_MST = 1;
  }
  IIC1D = DeviceAddress;
  STI();           
  return ERROR_NONE;
}


byte I2CRecieve(byte* data,word size)
{
  if (!size) 
  {                         
    return ERROR_NONE;                     
  }
  if((IIC1S_BUSY)||(ReadBufferSize)||(I2C_Status&(CHAN_BUSY))) 
  { 
    return ERROR_BUSBUSY;
  }
  CLI();
  IIC1C1_TX = 1;                // Set TX Mode.
  ReadBufferSize = size; 
  pReadPointer = data;               
                     
  if(IIC1C1_MST) 
  {  
    // If we are already in master mode, the do a repeat start
    IIC1C1_RSTA = 1;         
  }
  else 
  {
    // This will send a start.
    IIC1C1_MST = 1;
  }
  IIC1D = (byte)(DeviceAddress+1);      // Set LSB to indicate write.
  STI();
  return ERROR_NONE;
}



void I2CSetDeviceAddress(byte address)
{
  DeviceAddress = (byte)(address) & ~1;  // Force LSB to zero.
  return;
}

void i2c_delay(int n);
void UnhangI2C(void);
static void i2c_delay(int n)
{
  int i;
  for( i = 0 ; i < n ; ++i)
    asm {
      nop ; nop ; nop ;nop
    };
}
void UnhangI2C(void)
{
  int i = 0;
  // This will clear out a "hung" I2C device
  // but clocking away the low it may be asserting
  // on SDA

  PTCDD |= 3;
  PTCPE |= 3;
  PTCD  |= 1;
  for( i = 0 ; i < 30 ; ++i )
    {
      i2c_delay(5000);
      PTCD ^= 1;
      // if the clock is hi, raise SDA
      // to send a stop.
      i2c_delay(2500);
      if(PTCD & 1)
        PTCD |= 2;
      else
        PTCD &= ~2;
    
    }
  PTCDD &= ~3;
  
}
 typedef struct _I2C_BAUDS {
   int rate; byte value;
 }I2C_BAUDS;
 const  I2C_BAUDS _i2c_bauds[]= {
     {1,0xBF}, // 1.5
     {3,0xBB},
     {5,0xB6},
     {10,0xAC},
     {14,0xAA},
     {25,0x9f},
     {57,0x96},
     {100,0x8E},
     {172,0x89},
     {330,0x49},
     {400,0x47},
     {500,0x40},
     {1000,0},
 };

 byte I2CSetBaudrate(int rate_khz)
 {
	 int i;
	 if( I2C_Status&(CHAN_BUSY) )
		 return ERROR_BUSBUSY;
	 
	 for( i = 0 ; i < (sizeof(_i2c_bauds)/sizeof(I2C_BAUDS ))-2 ; ++i )
	 {
		 if( rate_khz >= _i2c_bauds[i].rate
				 && rate_khz <= _i2c_bauds[i+1].rate )
		 {
			 IIC1F = _i2c_bauds[i].value;
			 break;
		 }
			 
	 }
	 if( i == sizeof(_i2c_bauds)/sizeof(I2C_BAUDS) - 1)
	 {
		 IIC1F = _i2c_bauds[sizeof(_i2c_bauds)/sizeof(I2C_BAUDS) - 1].value;
	 }
 }
void I2CInit(void)
{
  UnhangI2C();
  I2C_Status = 0; 
  DeviceAddress = 0x10; 
  IIC1F = 0x8e;   // mul = 2   0x89 = 172KHz 0x8A=160K  0x80=285K 0x8E = 100K
                  // mul=1 0x49=330KHz 0x47=400K 0x40=500K 
                  // 0x00 = 1Mhz 0x7 = 500Khz

  IIC1C1_IICEN = 1;  // Enable I2C Module 
  
  IIC1C1 = 0xC0; 
}


