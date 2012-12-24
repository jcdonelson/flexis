/*
 * MCURESETCF.H
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

#ifndef MCURESETCF_H_
#define MCURESETCF_H_

byte MCUResetSource();
char *MCUGetResetString();
#define RESET_POR		8
#define RESET_PIN		7
#define RESET_COP		6
#define RESET_ILOP		5
#define RESET_ILAD      4
#define RESET_LOC		3
#define RESET_LDV		2
#define UNKNOWN         1
#define RESET_BDM		0
#define MCURESET   asm {dc.w 0xF300}
#endif /* MCURESETCF_H_ */
