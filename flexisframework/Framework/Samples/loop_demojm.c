/*
 * loop_mfgdemo.c
 *
 *  Created on: Mar 17, 2011
 *      Author: jdonelson
 */

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#include <stdio.h>
#include <ansi_parms.h>
#include "ALL.H"
void RTCTickCallback(void);
void setup(void);
void loop(void);

// Defines for JMDEMO Board.
#define LED0 	3
#define LED1    5
#define POT     2


word tick_counter;
byte led_state;
int pot_setting;
void RTCTickCallback(void)
{
	++tick_counter;
	// Toggle the LED to show alive and well.
	if( tick_counter == 500)
	{
		tick_counter = 0;
		led_state ^= 1;
		// Toggle the LED.
		digitalWrite( LED0, led_state);
		
	}
	// Control the brightness of the LED with the pot.
	pot_setting = analogRead(POT);
	analogWrite(LED1,pot_setting);
}

void setup(void)
{
	pinMode(LED0 , OUTPUT);
}
void loop(void)
{
}

