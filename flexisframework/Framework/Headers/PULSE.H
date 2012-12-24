/*
 * PULSE.H
 *  $Rev:: 46                        $:
 *  $Date:: 2011-04-18 09:41:32 -040#$:
 *  $Author:: jcdonelson             $:
 */


void pulseOut(int pin,long frequency,long nPulses);
void pulseStop(void);
int pulseRunning(void);
void InitPulse(void);
