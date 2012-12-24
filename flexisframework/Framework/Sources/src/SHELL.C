/*
 * SHELL.C
 *
 *  Created on: May 18, 2012
 *      Author: jdonelson
 *      
 * 	$Revision: 142 $
 *	$Date: 2012-05-29 17:59:35 -0400 (Tue, 29 May 2012) $
 *	$Author: jcdonelson $
 *
 *	$Header: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Sources/src/SHELL.C 142 2012-05-29 21:59:35Z jcdonelson $
 *	$HeadURL: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Sources/src/SHELL.C $
 * 
 */
#include "CONSOLE.H"
#include "SHELL.H"
extern byte temp[80];
byte __strfind(byte* s1,byte* s2);
/*
 * byte SHELLProcessInput(HSHELL* shell)
 * Read the next key and if it is a line, processes
 * it. Call this to poll the keyboard.
 */
byte SHELLProcessInput(HSHELL* shell)
{
	byte rc;
	if(SHELL_STATE_BEGIN == shell->state )
	{
		CONSOLEWritestring(shell->console,shell->prompt);
		shell->state = SHELL_STATE_READ_LINE;
	}
	rc = CONSOLEReadkey(shell->console);
	
	if(ERROR_CONSOLE_LINE_READY == rc )
	{
		SHELLFindCommand(shell);
		CONSOLEWritestring(shell->console,shell->prompt);
	}
}
/*
 * byte SHELLFindCommand(HSHELL* shell)
 * Look thru the table of commands and match to first token.
 * If found, run the command.
 */
byte SHELLFindCommand(HSHELL* shell)
{
	byte i;
	for(i = 0 ; shell->cmds[i].name ; ++i)
	{
	   if(0 == __strfind((byte*)shell->cmds[i].name,shell->console->inputbuffer))
	   {
		   shell->cmds[i].func((char*)shell->console->inputbuffer);
		   return i;
	   }
	}
	CONSOLEWritestring(shell->console,_T("Command not found\r\n"));
	CONSOLEWritestring(shell->console,(byte*)"\r\n");
	SHELLShowHelp(shell);
	return 0xff;
}
byte SHELLShowHelp(HSHELL* shell)
{
	byte i;
	for(i = 0 ; shell->cmds[i].name ; ++i)
	{
		CONSOLEWritestring(shell->console,_T(shell->cmds[i].name));
		CONSOLEWritestring(shell->console,_T(" - ") );
		CONSOLEWritestring(shell->console,_T(shell->cmds[i].help));
		CONSOLEWritestring(shell->console,_T("\r\n"));
	}
	
}

/*
 * word __strfind(byte* s1,byte* s2)
 * - Does s2 start with s1?
 * - s2 can be terminated by space, tab or EOL.
 * - s1 must be null terminated.
 */
byte __strfind(byte* s1,byte* s2)
{
	while(*s1 == *s2)
	{
		if (*s1=='\0')
			break;
		s2++,s1++;
	}
	if(!*s1 && (0 == *s2 ||
		' ' == *s2 || 0x9 == *s2 || EOL == *s2 ) )
		return 0;
	return 1;
}
