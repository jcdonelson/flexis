/*
 * ENCODER.H
 *
 *  Created on: Jul 22, 2012
 *      Author: jdonelson
 * 	$Revision: 142 $
 *	$Date: 2012-05-29 17:59:35 -0400 (Tue, 29 May 2012) $
 *	$Author: jcdonelson $
 *
 *	$Header: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Sources/src/SHELL.C 142 2012-05-29 21:59:35Z jcdonelson $
 *	$HeadURL: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Sources/src/SHELL.C $
 */

#ifndef ENCODER_H_
#define ENCODER_H_
#define ENCODER_UNUSED		0xFF
typedef struct _ENCODER {
	byte PhaseAInterrupt;
	byte PhaseAInput;
	byte PhaseBInterrupt;
	byte PhaseBInput;
	byte IndexInterrupt;
	long CPR;

	long position;
	long IndexCounter;
	long target;
	byte direction;
} ENCODER;
void ENCODERInit(ENCODER* encoder);
inline long ENCODERGetPosition(ENCODER* encoder)
{
	return encoder->position;
}
inline void ENCODERSetPosition(ENCODER* encoder, long p)
{
	encoder->position  = p;
}
inline long ENCODERGetCPR(ENCODER* encoder)
{
	return encoder->CPR;
}
#endif /* ENCODER_H_ */
