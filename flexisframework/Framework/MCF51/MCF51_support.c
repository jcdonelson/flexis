/*
 *  MCF51_SUPPORT.C
 *
 *  Provides MCU specific support for V1
 *
 *  $Rev:: 39                        $:
 *  $Date:: 2011-04-13 10:36:58 -040#$:
 *  $Author:: jcdonelson             $:
 *
 *
 */
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
void CLI(void);
void STI(void);
volatile byte SR_level = 0x00;
volatile word saved_SR = 0x00;
void CLI(void) 
{
   // If this is the first call, the save SR and disable int.
   if (++SR_level == 1) 
   {
      asm
      {
       move.w SR,D0; 
       move.w D0,saved_SR; 
       ori.l #0x700,D0;
       move.w D0,SR;
       }
   
   }
}

void STI(void) 
{
   // If this is the last call, then restore SR.
   if (--SR_level == 0) 
   {
      asm
      { 
        move.w saved_SR,D0; 
        move.w D0,SR; 
      }     
   
   }
}
