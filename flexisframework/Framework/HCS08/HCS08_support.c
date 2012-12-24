#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
volatile byte CCR_register;
void CLI(void) 
{
 { asm PSHA; asm TPA; asm SEI; asm STA CCR_register; asm PULA; } 
}

void STI(void) 
{
   // If this is the last call, then restore SR.
  { asm PSHA; asm LDA CCR_register; asm TAP; asm PULA; }
}