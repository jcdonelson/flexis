/*
 * CONSOLE.C
 * 	$Revision: 196 $
 *	$Date: 2012-09-23 15:49:45 -0400 (Sun, 23 Sep 2012) $
 *	$Author: jcdonelson $

	$Header: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Sources/src/CONSOLE.C 196 2012-09-23 19:49:45Z jcdonelson $
	$HeadURL: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Sources/src/CONSOLE.C $
 * 

 *
 * Reads a line from a VT100+ terminal and allows editing.
 * - Arrow keys to go into the line and edit
 * - Always in insert mode "insert" key ignored.
 * See code for more details.
 * Note: This should not include any MCU specific headers to stay
 * generic.
 * 
 *		
 *		
 
 *  Created on: May 5, 2012
 *  Author: jdonelson
 * 	$Revision: 196 $
 *	$Date: 2012-09-23 15:49:45 -0400 (Sun, 23 Sep 2012) $
 *	$Author: jcdonelson $
 *
 *	$Header: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Sources/src/CONSOLE.C 196 2012-09-23 19:49:45Z jcdonelson $
 *	$HeadURL: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Sources/src/CONSOLE.C $
 
 *      
 */

#include "CONSOLE.H"
#define BUFFER_ADDRESS(x) &console->bufferbase[x*console->inputbuffer_size]
#define CLEAR_STATUS(x) console->status &= ~x
byte CONSOLEEditLine(HCONSOLE *console, char editcmd);
byte CONSOLEDeleteCharacter(HCONSOLE *console);
byte CONSOLEInsertCharacter(HCONSOLE *console, byte c);
byte CONSOLEHomeCursor(HCONSOLE *console);
byte CONSOLEGetPrevLine(HCONSOLE *console);
byte CONSOLEGetNextLine(HCONSOLE *console);
byte CONSOLERestoreLine(HCONSOLE *console, byte line );

static byte __isPrintable(HCONSOLE *console, byte c);
static word __strlen(byte *s);

/*
 * byte CONSOLEReadkey(CONSOLE *console)
 * 
 * Monitor a serial port for input lines.
 * returns:
 * ERROR_CONSOLE_NO_ERROR - if nothing special happened. 
 * ERROR_CONSOLE_LINE_READY  - if completed line in buffer (User hit EOL (return/enter)).
 * It is assumed that the line has been processed and a new line is started.
 * 
 * ERROR_EOF_KEY - If the End of File attention character was set and was hit.
 * 
 * Must be called at regular intervals to poll.
 */

byte CONSOLEReadkey(HCONSOLE *console)
{
	byte c=0;
	volatile byte count = 0;
	
	// should only happen on first call...
	if( 0 == console->inputbuffer)
	{
		console->inputbuffer = console->bufferbase;
	}
	
	// Means a new edit line is starting....
	if(console->flag & CONSOLE_FLAG_EOL_RETURNED)
	{
		byte i=0;
		// If not all buffers are used, always use the first unused one.
		for( i = 1 ; i < console->number_inputbuffers ; ++i)
		{
			if(0 == *BUFFER_ADDRESS(i) ) 
			{
				console->last_line = i-1;
				break;
			}
		}
		++console->last_line;
		if( console->last_line >= console->number_inputbuffers)
			console->last_line = 0;
		console->inputbuffer = &console->bufferbase[console->last_line*console->inputbuffer_size];
		*console->inputbuffer = 0;
		
		console->flag &= ~CONSOLE_FLAG_EOL_RETURNED;
	}
	// While there are still more key hits waiting....
	while( 0 != (count=console->pfKbhit(console->port)) )
	{
		// Read the key.
		c = console->pfReadchar(console->port);
		if( EOL == c)
		{
			console->pfWritechar(console->port,'\r');
			if(console->flag & CONSOLE_FLAG_SEND_NEWLINE)
				console->pfWritechar(console->port,'\n');
			
			CLEAR_STATUS(CONSOLE_STATUS_IGNORE_NEXT | CONSOLE_STATUS_ESC | CONSOLE_STATUS_L_BRACKET | CONSOLE_STATUS_MODE_EDIT);
			console->index = 0;
			console->edit_index = 0;
			
			// Remember that we just ended a line.
			console->flag |= CONSOLE_FLAG_EOL_RETURNED;
			return  ERROR_CONSOLE_LINE_READY;
		}

		if( console->EOFChar)
		{
			if( c == console->EOFChar)
				return ERROR_EOF_KEY;
		}
		
		if(BACKSPACE == c || DELETE == c)
		{
			CONSOLEEditLine(console, c);
			continue;
		}
		// ANSI Escape sequence are ESC[character
		if(ESC == c && (console->flag & CONSOLE_FLAG_FILTER_ANSI_ESC))
		{
			console->status |= CONSOLE_STATUS_ESC;
			continue;
		}
		if( '[' == c && (console->status & CONSOLE_STATUS_ESC))
		{
			CLEAR_STATUS(CONSOLE_STATUS_ESC);
			console->status |= CONSOLE_STATUS_L_BRACKET;
			continue;
			
		}
		if( (console->status & CONSOLE_STATUS_L_BRACKET))
		{
			CLEAR_STATUS(CONSOLE_STATUS_L_BRACKET);
			// 
			CONSOLEEditLine(console, c);
			// If it was a digit then a '~' is sent after. Just ignore it.
			if( c >= '0' && c <= '9')
				console->status |= CONSOLE_STATUS_IGNORE_NEXT;
	
			continue;
			
		}
		if( (console->status & CONSOLE_STATUS_IGNORE_NEXT))
		{
			CLEAR_STATUS(CONSOLE_STATUS_IGNORE_NEXT);
			continue;
		}
		CLEAR_STATUS(CONSOLE_STATUS_IGNORE_NEXT | CONSOLE_STATUS_ESC | CONSOLE_STATUS_L_BRACKET );

		// Beep if buffer hit end.		
		if( !(console->flag & CONSOLE_FLAG_NO_BELL) && console->index >= (console->inputbuffer_size-1) )
				 CONSOLEWritechar(console,BELL);
		
		if( 0x9 == c) 
			c = 0x20;
		
		if( !__isPrintable(console, c) || (console->index >= (console->inputbuffer_size-1)))
			continue;
		
		if(console->flag & CONSOLE_FLAG_ECHO)
			console->pfWritechar(console->port,c);
		
		if( console->status & CONSOLE_STATUS_MODE_EDIT )
		{
			// Edit mode is controlled by the arrow keys.
			// Currently we are always in insert mode...
			CONSOLEInsertCharacter(console,  c);
#ifdef OVER_WRITE
			// Overwrite the character.
			console->inputbuffer[console->edit_index] = c;
			++console->edit_index;
			if(console->edit_index ==  console->index)
			{
				console->con_mode &= ~CON_MODE_EDIT;
			}
#endif
		}
		else 
		{
			// Append the character. 
			console->inputbuffer[console->index] = c;
			++console->index;
			console->inputbuffer[console->index] = 0;
		}

	}
	return ERROR_CONSOLE_NO_ERROR;
	
}
/*
 * byte CONSOLEWritechar(const CONSOLE *console,byte c)
 * 
 */
byte CONSOLEWritechar(const HCONSOLE *console,byte c)
{
   	return console->pfWritechar(console->port,c);
}
/*
 * byte CONSOLEWritestring(const CONSOLE *console, const byte* s)
 * 
 */
byte CONSOLEWritestring(const HCONSOLE *console, const byte* s)
{
	while(*s)
	{
		 CONSOLEWritechar(console,*s);
		++s;
	}
	
}
/*
 * byte CONSOLEEditLine(CONSOLE *console, char editcmd)
 * 
 * Perform the operation on the data structure and update the display.
 * 
 */
byte CONSOLEEditLine(HCONSOLE *console, char editcmd)
{
	switch(editcmd)
	{
	case BACKSPACE:
		if(console->index > 0 && !(CONSOLE_STATUS_MODE_EDIT & console->status) )
		{   // Not in edit mode
			--console->index;
			console->inputbuffer[console->index] = 0;
			console->pfWritechar(console->port,BACKSPACE);
			console->pfWritechar(console->port,' ');
			console->pfWritechar(console->port,BACKSPACE);

			return ERROR_CONSOLE_NO_ERROR;
		}
		else
		{  // In edit mode - cheat move the edit position back one and do a delete.
			if( console->edit_index > 0)
			{
				console->edit_index--;
				console->pfWritechar(console->port,BACKSPACE);
				CONSOLEDeleteCharacter(console);
			}
		}
		break;
	case UP_ARROW:
		// Get the previous line
		CONSOLEGetPrevLine(console);
		break;
	case DN_ARROW:
		// get next line
		CONSOLEGetNextLine(console);
		break;
	case DELETE:
	case ALT_DELETE:
		// If you are at the end of the line, it does nothing.
		if(!(CONSOLE_STATUS_MODE_EDIT & console->status))
			return ERROR_CONSOLE_NO_ERROR;
		// Close hole.
		 CONSOLEDeleteCharacter(console);
		break;
	case RT_ARROW:
//		if(CON_MODE_APPEND == console->con_mode)
//			return ERROR_CONSOLE_NO_ERROR;
		
		if(console->edit_index < console->index)
		{
			++console->edit_index;	
			CONSOLEWritestring(console,(byte*)"\033[C");
			if(console->edit_index == console->index)
				console->status &= ~CONSOLE_STATUS_MODE_EDIT;
		}
		
		break;
	case LFT_ARROW:
		if(!(CONSOLE_STATUS_MODE_EDIT & console->status))
		{
			console->status |= CONSOLE_STATUS_MODE_EDIT;
			if(console->index )
			  console->edit_index = console->index - 1;
			CONSOLEWritechar(console,BACKSPACE);
		}
		else
		{
			
			if( console->edit_index > 0)
			{
			  --console->edit_index;
			  CONSOLEWritechar(console,BACKSPACE);
			}
		}
		break;
	case INSERT:
		// Currently this is ignored, we are always in insert.
#ifdef COMMENT_OUT		
		console->con_mode ^= CON_MODE_OVERWRITE;
		if(console->con_mode & CON_MODE_OVERWRITE)
			CONSOLEWritestring(console,(byte*)"\033[0 q");
		else
			CONSOLEWritestring(console,(byte*)"\033[3 q");
#endif		
		break;
	case END_KEY:
		if(CONSOLE_STATUS_MODE_EDIT & console->status)
		{
			// Move cursor to the right.
			while(console->edit_index < console->index )
			{
				CONSOLEWritestring(console,(byte*)"\033[C");
				console->edit_index++;
			}
			console->status &= ~CONSOLE_STATUS_MODE_EDIT;
		}
		break;
	case HOME_KEY:
		CONSOLEHomeCursor(console);
		console->edit_index = 0;
		console->status |= CONSOLE_STATUS_MODE_EDIT;
		break;
	default:
			return 0;
	}
	return 0;
}
 
/*
 * byte CONSOLEInsertCharacter(CONSOLE *console, byte c)
 * - Open a hole in the string and insert a character.
 * - Re-write the line on the screen.
 * 
 */
byte CONSOLEInsertCharacter(HCONSOLE *console, byte c)
{
	int i;
	
	// Can't insert, end of the buffer.
	if(console->index >= console->inputbuffer_size-1)
		return 0;
	// Open a hole in the string.
	for(i = console->index ; i >= console->edit_index ; --i)
	{
		console->inputbuffer[i+1] =  console->inputbuffer[i];
	}
	
	// Put the new character into the string.
	console->inputbuffer[console->edit_index] = c;
	
	// Re-write the console line shifted right one.
	for(i = console->edit_index+1 ; i < console->index+1 ;++i)
		  CONSOLEWritechar(console,console->inputbuffer[i]);
	
	// Back up the cursor to where it should be.
	i =  (console->index) -  console->edit_index;
	while(i--)
		  CONSOLEWritechar(console,BACKSPACE);
	
	// Move the edit position to the new position of the original character
	console->edit_index++;
	
	// Adjust the index for the new character and null terminate.	
	console->index++;
	console->inputbuffer[console->index] = 0;
}
/*
 * byte CONSOLEDeleteCharacter(CONSOLE *console)
 * 
 * Delete the character at the current edit position.
 * Make the string one shorter.
 * Adjust the display.
 * 
 */
byte CONSOLEDeleteCharacter(HCONSOLE *console)
{
	int i;
	
	if(console->index <= 0)
		return 0;
	
	// Re-write the text shifted left on display, overwriting the deleted character
	for( i = console->edit_index + 1; i < console->index; ++i)
		CONSOLEWritechar(console,console->inputbuffer[i]);
	// The cursor is left at the end of the line..

	// Delete the last character on the screen.
	// as the line is one shorted now.
	CONSOLEWritechar(console,' ');
	
	// Move the cursor back to where it should be.
	for( i = console->index - console->edit_index ; i > 0 ; --i)
		CONSOLEWritechar(console,BACKSPACE);
	
	// Shift the characters in the buffer.
	for( i = console->edit_index ; i < console->index; ++i)
		console->inputbuffer[i] = console->inputbuffer[i+1];
	
	// Adjust the index for one less character.
	if(console->index > 0)
	  console->index--;
	
	console->inputbuffer[console->index] = 0;
	
	return 0;
}
/*
 * byte CONSOLEHomeCursor(HCONSOLE *console)
 * Move the cursor to the first column.
 */
byte CONSOLEHomeCursor(HCONSOLE *console)
{
	int i;
	// Write backspace until the cursor is at position 0.
	if(CONSOLE_STATUS_MODE_EDIT & console->status)
	{
		i = console->edit_index;
	}
	else
	{
		i = console->index;
	}
	while(i--)
	{
		CONSOLEWritechar(console,BACKSPACE);
	}
	return 0;
}

/*
 * byte CONSOLERestoreLine(HCONSOLE *console, byte line )
 * Bring back a previous line if there is one.
 */
byte CONSOLERestoreLine(HCONSOLE *console, byte line )
{
	int i;
	byte* p;
	// If the line is blank, then do not restore it.
	p = &console->bufferbase[line *console->inputbuffer_size];
	if(!*p)
		return  0;
	// Update the new current line number.
	console->last_line = line ;
	// Move cursor to the beginning of the line
	CONSOLEHomeCursor(console);
	// Clear the old line by writing spaces.
	for(i = 0 ; i <  console->index ; ++i)
	{
		CONSOLEWritechar(console,' ');
	}
	// Move  back to the beginning of the line.
	CONSOLEHomeCursor(console);
	// Clear edit mode, as the cursor will be at the end of the line.
	console->status &= ~CONSOLE_STATUS_MODE_EDIT;
	// Set the new buffer.
	console->inputbuffer = p;
	// Set index to the length of the new line.
	console->index = (byte) __strlen(p);
	// Display the new line.
	for(i = 0; i <  console->index &&  EOL != console->inputbuffer[i]; ++i)
		CONSOLEWritechar(console,console->inputbuffer[i]);
	// Null terminate, as there may have been an EOL at end.
	console->inputbuffer[i] = 0;
	// Update index in case of an EOL at the end.
	console->index = (byte)i;
	return 0;
}
byte CONSOLEGetNextLine(HCONSOLE *console)
{

	byte  i = console->last_line;
	
	if(console->number_inputbuffers <= 1)
		return 0;
	++i;
	
	if( i >= console->number_inputbuffers)
		i = 0;
	
	return CONSOLERestoreLine(console, i ); 
}
byte CONSOLEGetPrevLine(HCONSOLE *console)
{

	byte  i = console->last_line;

	if(console->number_inputbuffers <= 1 )
		return 0;

	if( 0 == i)
		i = console->number_inputbuffers-1;
	else --i;
	
	return CONSOLERestoreLine(console, i );	
}
/*
 * _isPrintable(HCONSOLE *console, byte c)
 * Determine if the character is a visible one.
 */
static byte __isPrintable(HCONSOLE *console, byte c)
{
	console;
	if( c >= 20 && c < 0x7f)
		return 1;
	return 0;
}
/*
 * static word __strlen(byte *s)
 * Calculate the length of a string.
 */
static word __strlen(byte *s)
{
	word i = 0;
	while(*s++)
		i++;
	return i;
}