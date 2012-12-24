/*
 * CONSOLE.H
 *
 *  Created on: May 5, 2012
 *      Author: jdonelson
 *      
 *      
 * 	$Revision: 144 $
 *	$Date: 2012-05-29 18:01:27 -0400 (Tue, 29 May 2012) $
 *	$Author: jcdonelson $
 *
 *	$Header: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Headers/CONSOLE.H 144 2012-05-29 22:01:27Z jcdonelson $
 *	$HeadURL: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Headers/CONSOLE.H $
 *    
 *    VT100, Backspace sends ^H, Enter sends CR (0xd)
 */

#ifndef CONSOLE_H_
#define CONSOLE_H_
#ifndef byte
#define byte unsigned char
#define word unsigned short
#endif
/*
 * User  flags.
 */
#define CONSOLE_FLAG_FILTER_ANSI_ESC		1
#define CONSOLE_FLAG_ECHO					2
#define CONSOLE_FLAG_SEND_NEWLINE			4
#define CONSOLE_FLAG_EOL_RETURNED			8
#define CONSOLE_FLAG_NO_BELL				16
#define CONSOLE_FLAG_BLANK_LINE				32

/*
 * Return codes
 */
#define ERROR_CONSOLE_NO_ERROR				0
#define ERROR_CONSOLE_LINE_READY			1
#define ERROR_CONSOLE_OVERFLOW				2
#define ERROR_CONSOLE_ESC					3
#define ERROR_CONSOLE_LEFT_B				4
#define ERROR_CONSOLE_ANSI_CTRL				5
#define ERROR_IGNORED						6
#define ERROR_EOF_KEY						7

#define EOL  		0xD
#define BACKSPACE 	'\b'
#define ESC			0x1b
#define DELETE		0x7f
#define ALT_DELETE  '3'
#define UP_ARROW	'A'
#define DN_ARROW	'B'
#define RT_ARROW	'C'
#define LFT_ARROW	'D'
#define INSERT		'2'
#define END_KEY		'4'
#define HOME_KEY	'1'
#define CTRL_C		0x3
#define CTRL_Z		0x1a
#define CTRL_X		0x3
#define BELL		0x7


// return true if rx byte waiting.
typedef  byte (*PFKBHIT)(byte port);
typedef  byte (*PFWRITECHAR)(byte port, byte c);
typedef  byte (*PFREADCHAR)(byte port);
typedef struct _HCONSOLE_
{
	byte port;
	byte* bufferbase;
	byte inputbuffer_size;
	byte number_inputbuffers;
	byte flag;

	PFKBHIT pfKbhit;			// Pointer to key ready function.
	PFREADCHAR pfReadchar;		// Pointer to read char function.
	PFWRITECHAR pfWritechar;	// pointer to write char function.
	byte EOFChar;  				// If this is hit return right away with
	
	// Private vars...
	byte index;  				// This is the current end of the line.
	byte edit_index;			// if in edit mode, edit index.
	byte* inputbuffer;			// The current read buffer
	byte status;				// internal state.
	byte last_line;				// Can have multiple buffers. this is number of the current one.
} HCONSOLE;
#ifdef COMMENT_OUT
// REFERNCE CODE ONLY
#define SPORT  SCI1				// Define the serial port.
byte conbuffer[41*4];
HCONSOLE _console_data={SPORT,&conbuffer[0],40,4,
		CONSOLE_FLAG_ECHO|CONSOLE_FLAG_SEND_NEWLINE|CONSOLE_FLAG_FILTER_ANSI_ESC,
		// You must provide these functions. They can be called anything you like.
		_console_kbhit,  		// Key hit 
		_console_ReadChar,		// Read a waiting character.
		_console_WriteChar      // Write a character.
		};  
#endif


byte CONSOLEReadkey(HCONSOLE *console);
#ifdef COMMENT_OUT
/*
* REFERENCE ONLY DO NOT UNCOMMENT. 
* Call byte CONSOLEReadkey(HCONSOLE *console) to poll.
* Returns: ERROR_CONSOLE_LINE_READY when a line is ready.
* Example to read the line and echo it with a prompt:
* 
*/
if(ERROR_CONSOLE_LINE_READY == CONSOLEReadkey(&_console_data) )
 {
	  CONSOLEWritestring(&_console_data,_console_data.inputbuffer);
	  CONSOLEWritestring(&_console_data,"\r\n");
	  
	  CONSOLEWritestring(&_console_data,CONSOLE_PROMPT);
 }
#endif
byte CONSOLEWritechar(const HCONSOLE *console,byte c);
byte CONSOLEWritestring(const HCONSOLE *console, const byte* s);



byte CONSOLEResetLine(const HCONSOLE *console);

#define CONSOLE_STATUS_ESC				1
#define CONSOLE_STATUS_L_BRACKET		2
#define CONSOLE_STATUS_IGNORE_NEXT		4
#define CONSOLE_STATUS_MODE_EDIT		8
#define CONSOLE_STATUS_MODE_OVERWRITE	16

#endif /* CONSOLE_H_ */
