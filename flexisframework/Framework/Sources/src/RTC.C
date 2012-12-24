/*
 *   RTC.C 
 *  Support for real time clock.
 *  $Rev:: 169                       $:
 *  $Date:: 2012-09-08 22:39:57 -040#$:
 *  $Author:: jcdonelson             $:

 */
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "RTC.H"
extern void CLI(void);
extern void STI(void);

void  RTC_InterruptHandler(void);
static PFNRTCCB UserCallback = (PFNRTCCB)0;
static PFNRTCCB_I ChainCallback = (PFNRTCCB_I)0;

PFNRTCCB_I SetRTChainCallback( void(*uc)(int) )
{
   PFNRTCCB_I temp; 
   CLI();	
   temp = ChainCallback;
   ChainCallback = uc;
   STI();
   return temp;
   
}

PFNRTCCB GetRTCUserCallback()
{
	return UserCallback;
}
void SetRTCUserCallback( void(*uc)(void) )
{
   UserCallback = uc;
}
void RTCSetPeriod(int us)
{
  RTCSC_RTIE   = 1;    // Enable interrupt.
  RTCSC_RTCLKS = 1;    // Use internal 12Mhz clock
  RTCSC_RTCPS  = 8;// (byte) 1000; // /1000 =12Khz
  // 5 = 500 us
  // 2 = 250 us
  RTCMOD = (byte) us;        // /6 = 500us

}

void RTCSetPeriodLPO(int ms)
{
	RTCSC_RTCPS = ms;


}
int RTCGetPeriod()
{
	switch(RTCMOD)
	{
	case RTC_250US:
		return 250;
	case RTC_500US:
		return 500;
	case RTC_1MS:
		return 1000;
	
	
	}
	return (int) 0;
}
void InitRTC()
{
	RTCSC = 0;
	RTCSC_RTIE   = 1;    // Enable interrupt.
	RTCSC_RTCLKS = 1;    // Use internal 12Mhz clock
	
	
	RTCSC_RTCPS  = 8; // /1000 =12Khz
	// Use 3 for 4Mhz rock. = /4
	RTCMOD = 11;     	 // /12 = 1MS
}
void InitRTCInternalClock(void)
{
	// Set RTIE to enable interrupts, select the 1KHz internal oscillator
	// set the divider to 1 for a 1ms interrupt.
	RTCSC = 0;
	RTCSC_RTIE   = 1;    // Enable interrupt.
	RTCSC_RTCLKS = 0;    // Use 1 KHz LPO
	RTCSC_RTCPS  = 8;    // /1 in LPO

	RTCMOD = 0;          // 1 ms.

}
static int ms_counter=0;
static unsigned int usec_counter=0;
static unsigned int UserDelay=0;
static unsigned int tick_counter=0;
#define ONE_MS_TICKS   1
interrupt  VectorNumber_Vrtc void  RTC_InterruptHandler(void);
interrupt  VectorNumber_Vrtc void  RTC_InterruptHandler(void)
{
	++ms_counter;
	if( ms_counter == ONE_MS_TICKS )
	{
		ms_counter = 0;
		if(UserCallback)
			UserCallback();
		if(ChainCallback)
			ChainCallback(ms_counter);
	}
	if( UserDelay)
		--UserDelay;
	++tick_counter;
	RTCSC |= 0x80;   // Ack the interrupt
}
// TODO: Fix this so it follows the clock rate.
void RTC_msDelay(unsigned int ms)
{
	++ms;
	CLI();
	UserDelay = ms*4;
	STI();
	while( UserDelay)
		;
}
