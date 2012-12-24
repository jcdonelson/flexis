/*
 * MAIN_LOOP.C
 * This provides base initialatiion fo the framework
 * - Calls setup then loop.
 *
 *  $Rev:: 71                        $:
 *  $Date:: 2011-05-21 21:12:31 -040#$:
 *  $Author:: jcdonelson             $:
*/



#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "CONFIG.H"
#include <stdio.h>
#if MCU_HCS08 == 0
#include <ansi_parms.h>
#endif
#include "ALL.H"
extern void RTCTickCallback(void);
extern void setup(void);
extern void loop(void);




void main(void) {
//	SOPT1 = 0x10; // Disable watch dog.
    SOPT1 = SOPT1_STOPE_MASK;
    SOPT2 &= ~SOPT2_USB_BIGEND_MASK;

	InitRTCInternalClock();
	
	SetRTCUserCallback( RTCTickCallback );
	InitCLOCK();
	InitTPM1Counter();
	//InitPulse();
	
	setup();
	EnableInterrupts;
	
	
 
  /* include your code here */

  

  for(;;) 
  {
	  loop();
  } /* loop forever */
  /* please make sure that you never leave main */
}
