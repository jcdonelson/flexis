/*
 * loop_blink_fb32.c
 */

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "ALL.H"

// Prototypes for our functions.
void RTCTickCallback(void);
void setup(void);
void loop(void);

int counter = 0;	// Determine when 1/2 a second is up.
int blink_state=0;	// Toggles with XOR

void RTCTickCallback(void)
{
    ++counter;		// Increment the 1 ms counter.
    if(500 == counter )	// 1/2 second yet ?
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
}
void loop(void)
{
}

