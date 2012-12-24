/*
 * loop_low_power.c
 */

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "ALL.H"

// Prototypes for our functions.
void RTCTickCallback(void);
void setup(void);
void loop(void);
// New line again
int counter = 0;	// Determine when 1/2 a second is up.
int blink_state=0;	// Toggles with XOR

void RTCTickCallback(void)
{
   ++counter;		// Increment the 1 ms counter.
//    if( counter >= 100 )	// 1/2 second yet ?
    {
        counter = 0;            // reset the counter so we start over
        blink_state ^= 1;       // Use the "C" xor operator to toggle the state
        // write to the LED.
        digitalWrite(13,blink_state);
  }
}
void setup(void)
{
    // Initialize the LED pin to output.
    pinMode(13,OUTPUT);
    
    // 0 turns the LED on.
    digitalWrite(13,0);
    InitRTCInternalClock();
    RTCSetPeriodLPO(RTC_LPO_100MS);
    SetSTOPMode(STOP3);
    // This does not seem to make much difference.
    // Look in the header file and shut of modules not used at all.
    // This just leaves the RTC up, but when stopped, the other power down any way.
   // powerModulesDown(0xFFFF & (~P_RTC));
}
void loop(void)
{
	EnterStopMode();
}

