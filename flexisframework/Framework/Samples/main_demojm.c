#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include <stdio.h>
#include <ansi_parms.h>
#include "ALL.H"
// Defines for JMDEMO Board.
#define LED0 	3
#define LED1    5
#define POT     2
void RTCTickCallback(void);
word tick_counter;
byte led_state;
int pot_setting;
void RTCTickCallback(void)
{
	++tick_counter;
	if( tick_counter == 500)
	{
		tick_counter = 0;
		led_state ^= 1;
		digitalWrite( LED0, led_state);
		
	}
	pot_setting = analogRead(POT);
	analogWrite(LED1,pot_setting/4);
}



void main(void) 
{
	SOPT1 = 0x10; // Disable watch dog.
	InitRTCInternalClock();
	SetRTCUserCallback( RTCTickCallback );
	InitCLOCK();
	InitTPM1Counter();
	pinMode(LED0 , OUTPUT);
	EnableInterrupts;
  for(;;) {
    
  } /* loop forever */
}
