/*
 * MCURESETCF.H
 *
 *  Created on: Jul 22, 2012
 *      Author: jdonelson
 * 	$Revision: 205 $
 *	$Date: 2012-09-23 21:43:24 -0400 (Sun, 23 Sep 2012) $
 *	$Author: jcdonelson $
 *
 *	$Header: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Headers/MCURESETCF.H 205 2012-09-24 01:43:24Z jcdonelson $
 *	$HeadURL: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Headers/MCURESETCF.H $
 
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
#define MCURESET   asm {\
		move.l  #0,d0\
		movec   d0,CPUCR\
		dc.w 0xF300\
}

#endif /* MCURESETCF_H_ */
