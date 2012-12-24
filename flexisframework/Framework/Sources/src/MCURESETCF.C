/*
 * MCURESETCF.C
 *
 *  Created on: Jul 22, 2012
 *      Author: jdonelson
 *      Reset Functions.
 *      
 * 	$Revision: 204 $
 *	$Date: 2012-09-23 21:42:33 -0400 (Sun, 23 Sep 2012) $
 *	$Author: jcdonelson $
 *
 *	$Header: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Sources/src/MCURESETCF.C 204 2012-09-24 01:42:33Z jcdonelson $
 *	$HeadURL: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Sources/src/MCURESETCF.C $
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
  
