/*
 * MCURESETCF.C
 *
 *  Created on: Jul 22, 2012
 *      Author: jdonelson
 *      Reset Functions.
 *      
 * 	$Revision: 142 $
 *	$Date: 2012-05-29 17:59:35 -0400 (Tue, 29 May 2012) $
 *	$Author: jcdonelson $
 *
 *	$Header: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Sources/src/SHELL.C 142 2012-05-29 21:59:35Z jcdonelson $
 *	$HeadURL: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Sources/src/SHELL.C $
 *      
 */
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#include "CONFIG.H"
#include "MCURESETCF.H"

char* RESET_STRINGS[]={
"BDM Reset",
"Unknown",
"Low Voltage Detect",
"Loss-of-Clock Reset",
"Illegal Address",
"Illegal Opcode",
"COP Timer",
"Reset pin",
"Power on reset",
};
/*
 * byte ResetSource()
 * Return the source of the most recent reset.
 */

byte MCUResetSource()
{
	byte resetsrs = SRS;
	
	byte source = 8;

	if(!resetsrs )
		return 0;
	
	do {
		if(resetsrs & 0x80)
		{
			return source;
		}
		resetsrs <<= 1;
		source -= 1;
	} while(resetsrs && source > 0);

	return source;
}
char *MCUGetResetString()
{
	return RESET_STRINGS[MCUResetSource()];
}
  
