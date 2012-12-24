/*
 * PWRMAN.C
 *
 *  V1 Powermanagement fucntions.
 *  $Rev:: 158                       $:
 *  $Date:: 2012-09-08 16:22:56 -040#$:
 *  $Author:: jcdonelson             $:
 *  Created on: Sep 6, 2012
 *      Author: jdonelson
 */




#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "PWRMAN.H"



void powerModulesDown(unsigned long modules)
{
	SCGC1 &= ~(modules & 0xff);
	SCGC2 &= ~((modules >> 8) & 0xff);
	SCGC3 &= ~((modules >> 16) & 0xff);
}

void powerModulesUp(unsigned long modules)
{
	SCGC1 |= (modules & 0xff);
	SCGC2 |= ((modules >> 8) & 0xff);
	SCGC3 |= ((modules >> 16) & 0xff);
}





byte SetSTOPMode(byte which)
{
	switch(which)
	{
		case STOP2:
			//SOPT1_STOPE = 1; This is a write once bit, so don't bother.
			SOPT1_WAITE = 0;
			SPMSC2_PPDC = 1;
			SPMSC1_LVDSE = 0;
			SPMSC1_LVDE = 0;
			break;
		case STOP3:
			//SOPT1_STOPE = 1;
			SOPT1_WAITE = 0;
			SPMSC2_PPDC = 0;
			SPMSC1_LVDSE = 0;
			SPMSC1_LVDE = 0;
			break;
		case STOP4:
			//SOPT1_STOPE = 1;
			SOPT1_WAITE = 0;
			SPMSC1_LVDSE = 1;
			SPMSC1_LVDE = 1;
			break;
		case WAIT:
			SOPT1_WAITE = 1;
			break;
		
		default:
			return 1;
	}
	return 0;
}
byte ReadResetSource()
{
	return SRS;
}
