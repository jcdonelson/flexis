/*
 * CLOCK.H
 *
 *  $Rev:: 63                        $:
 *  $Date:: 2011-05-10 22:07:33 -040#$:
 *  $Author:: jcdonelson             $:
 */

#ifndef CLOCK_H_
#define CLOCK_H_
extern void InitCLOCK(void);				// Init 12MHZ oscillator to 48 MHz TODO: Support other xtals.
extern void InitInternalClock(void);    // Set the internal clock to 50.331648
extern int OSCILLATOR_Fail;
#endif /* CLOCK_H_ */

