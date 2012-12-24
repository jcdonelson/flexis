/*
 * SHELL.H
 * SHELL Uses a CONSOLE for device i/o.
 *  Created on: May 18, 2012
 *      Author: jdonelson
 *      
 *      
 * 	$Revision: 145 $
 *	$Date: 2012-05-29 18:02:35 -0400 (Tue, 29 May 2012) $
 *	$Author: jcdonelson $
 *
 *	$Header: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Headers/SHELL.H 145 2012-05-29 22:02:35Z jcdonelson $
 * 	$HeadURL: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Headers/SHELL.H $
 * 
 *
 */

#ifndef SHELL_H_
#define SHELL_H_
#include "CONSOLE.H"

typedef struct _shell_cmd_decoder 
{
	char*   name;					// What the user types to invoke the command.
	byte  (*func)(char* cmdline);	// function to call. Pass commond line.
	char*   help;					// Help text.
} SHELL_CMD_DECODER;

#ifdef COMMENT_OUT
// SAMPLE LEAVE COMMENTED OUT!
SHELL_CMD_DECODER _cmds[]={
		{"help",help,"Display help"},
		{"uecho",uecho,"Run Echo Test. Must Run PC Program."},
		{"adc",ADC,"'adc n' Read ADC Channel n = channel to read ^Z to exit"},
		0
};
#endif
typedef struct _HSHELL_ {
	SHELL_CMD_DECODER* cmds;
	byte *prompt;
	HCONSOLE* console;
	// Private
	byte state;
} HSHELL;
#ifdef COMMENT_OUT
/*
 * BELOW IS SAMPLE CODE LEAVE COMMENTED OUT!
 */
HSHELL hShell = 
{
	_cmds,
	"SH>",
	&_console_data
		
};
#endif
/*
 * byte SHELLProcessInput(HSHELL* shell);
 * Call to check for next key and execute command.
 */
byte SHELLProcessInput(HSHELL* shell);

byte SHELLFindCommand(HSHELL* shell);
byte SHELLShowHelp(HSHELL* shell);
byte __strfind(byte* s1,byte* s2);

#define SHELL_STATE_BEGIN		0
#define SHELL_STATE_READ_LINE	1
#define _T(x) (byte*) x


#endif /* SHELL_H_ */
