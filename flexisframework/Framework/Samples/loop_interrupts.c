/*
 * loop_interrupts.c
 * 
 * Apply a pulse to pin 3
 * The code should measure the period in uS.
 * 
 *  Created on: Mar 19, 2011
 *      Author: jdonelson
 */

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#include <stdio.h>
#include <ansi_parms.h>
#include "ALL.H"
void RTCTickCallback(void);
void interruptCallback(void);
void setup(void);
void loop(void);
int counter = 0;		// Determine when 1/2 a second is up.
int  blink_state=0;		// Toggles with XOR
void RTCTickCallback(void)
{
	++counter;			// Increment the 1 ms counter.
	if(500 == counter )	// 1/2 second yet ?
	{
		counter = 0;  		// reset the counter so we start over
		blink_state ^= 1;	// Use the "C" xor operator to toggle the state
		// write to the LED.
		digitalWrite(13,blink_state);
	}
}
long lastcount=0;
long period;
void interruptCallback(void)
{
	long m = micros();
	period = m - lastcount;
	lastcount = m;
}
void setup(void)
{
	pinMode(13,OUTPUT);
	
	// Apply a pulse to pin 3.
	attachInterrupt(0,interruptCallback,RISING);
	
}
void loop(void)
{
}

