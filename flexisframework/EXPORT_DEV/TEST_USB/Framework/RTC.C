/*
 *   RTC.C 
 *  Support for real time clock.
 *  $Rev:: 63                        $:
 *  $Date:: 2011-05-10 22:07:33 -040#$:
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
void InitRTC()
{
	RTCSC_RTIE   = 1;    // Enable interrupt.
	RTCSC_RTCLKS = 1;    // Use internal 12Mhz clock
	RTCSC_RTCPS  = 1000; // /1000 =12Khz
	// Use 3 for 4Mhz rock.
	//RTCMOD = 5;     	 // /6 = 500us
	RTCMOD = 11;     	 // /12 = 1MS
}
void InitRTCInternalClock(void)
{
	// Set RTIE to enable interrupts, select the 1KHz internal oscillator
	// set the divider to 1 for a 1ms interrupt.
	RTCSC = 0x18;
	RTCMOD = 0;

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
void RTC_msDelay(unsigned int ms)
{
	++ms;
	CLI();
	UserDelay = ms*4;
	STI();
	while( UserDelay)
		;
}
