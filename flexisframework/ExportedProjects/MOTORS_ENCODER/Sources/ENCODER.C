/*
 * ENCODER.C
 *
 *  Created on: Jul 22, 2012
 *      Author: jdonelson
 *      
 * 	$Revision: 142 $
 *	$Date: 2012-05-29 17:59:35 -0400 (Tue, 29 May 2012) $
 *	$Author: jcdonelson $
 *
 *	$Header: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Sources/src/SHELL.C 142 2012-05-29 21:59:35Z jcdonelson $
 *	$HeadURL: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Sources/src/SHELL.C $
 
 */
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "ALL.H"
#include "CONFIG.H"
#include "ENCODER.H"
long ENCODERedges = 0;

void ENCODERPhaseACallback(void*);
void ENCODERPhaseBCallback(void*);
void ENCODERIndexCallback(void* context);
void ENCODERInit(ENCODER* encoder)
{
	
	pinMode(encoder->PhaseAInput,INPUT);
	attachInterruptEx(encoder->PhaseAInterrupt,ENCODERPhaseACallback,RISING,(void*) encoder);
	pinMode(encoder->PhaseBInput,INPUT);
	attachInterruptEx(encoder->PhaseBInterrupt,ENCODERPhaseBCallback,RISING,(void*) encoder);
	
	if(ENCODER_UNUSED != encoder->IndexInterrupt)
	{
		attachInterruptEx(encoder->IndexInterrupt,ENCODERIndexCallback,RISING,(void*) encoder);
		
	}
}
void ENCODERIndexCallback(void* context)
{
	ENCODER* pThis = (ENCODER*) context;
	++pThis->IndexCounter;
}

void ENCODERPhaseACallback(void* context)
{
	ENCODER* pThis = (ENCODER*) context;
	++ENCODERedges;
	
	if( digitalRead(pThis->PhaseBInput))
	{
		 ++pThis->position;
	}
	else
	{
		 --pThis->position;
	}
	
}
void ENCODERPhaseBCallback(void* context)
{
	ENCODER* pThis = (ENCODER*) context;
	++ENCODERedges;
	
	if( digitalRead(pThis->PhaseAInput))
	{
		 ++pThis->position;
	}
	else
	{
		 --pThis->position;
	}
	
}

