
/**
**   ADC.C
**   ADC Support for Firebird SR.
**   Interrupt Driven
**   Jim Donelson  9/2010
**/

#include <hidef.h>      /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

// Defines channel constants - these values enable interrupts and 
// select a channel to be converted.
static const  byte ChannelCodes[16] = {0x47,0x44,0x42,0x43}; 
// Next channel to be sampled
static byte ChannelIndex = 0;
// Total number of samples.
static byte NumberOfChannels = 2;
// Stores samples during a measurement cycle
static byte Samples[16];
// User defined call back
static void (*OnMeasureDone)(void);
#define RUN 	0
#define STOP	1
static void ZeroSamples()
{
	int i = 0;
	for( i = 0 ; i < NumberOfChannels ; ++i)
	{
		Samples[i] = 0;
	}
}

// Internal states
static byte DoneFlag = 0;
static byte State=STOP;

void InitADC(void)
{
	// Disable module until later.	
	ADCSC1 =  0x1F;
	// Pin select the channels we are using.
	APCTL1 = 0xf;  
	// disable triggers and compare.
	ADCSC2 =  0x00;               
	//  ADLPC=0 not low power, ADIV01=01 clk/2, ADLSMP=1 Long sample time
	// ,MODE=0 8-bit bus ADICLK= bus clk/2
	//  71 = cpu clk
	//  73 = ADC clk
	ADCCFG =  0x73;              
	State = STOP;
	ChannelIndex = 0;
}
/*
**
**
**/
interrupt  VectorNumber_Vadc void ADCInterruptHandler(void)
{
	Samples[ChannelIndex] = ADCRL;           
	ChannelIndex++;                          
	  if (ChannelIndex == NumberOfChannels) {                  
		  ChannelIndex = 0;                      
		  DoneFlag = 1;                     
		  OnMeasureDone();                       
		  State = STOP;                    
	    return;                            
	  }
	  // Fire off next cahnnel.
	  ADCSC1 = ChannelCodes[ChannelIndex];          

}
/*
**
**
**/
void SetADCDoneCallback(void (*f)(void))
{
	OnMeasureDone = f;
}

/*
**
**
**/
byte ADCMeasureAll(byte Wait)
{
  if (State != STOP) {               
    return 1;                  
  }
  State = RUN;;                  
  ChannelIndex = 0;                       
  ZeroSamples();                         
  ADCSC1 = ChannelCodes[ChannelIndex];        

  if (Wait) 
  {                 
    while (State == RUN) 
    	;     
  }
  
  return 0;                       
}
/*
**
**
**/
byte ADCGetChannnelValue8(byte channel,byte *v)
{
	if(channel >= NumberOfChannels )
		return 1;
	*v = Samples[channel];
	return 0;
}

