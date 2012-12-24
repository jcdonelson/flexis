/*
 *  LCD.C - Writes to LCD for FB JR, FB SR and NANO
 *  
 *  This assumes an HD44780 or compatible LCD. 4 bit interface
 *  It's been tested on several, and some LCDs seem to need more delay time
 *  If you get garbage characters, try increasing the delay.
 *  PTA0 = RS (data/command) (Pin 4 on LCD module)
 *  PTA1 = EN  (Write pulse) (Pin 6, also called E)
 *  PTA2 = Data 4  (Pin 11)    
 *  PTA3 = Data 5  (Pin 12)
 *  PTA4 = Data 6  (Pin 13) 
 *  PTA5 = Data 7  (Pin 14)
 *  Pins 1 & 5 should be 0V on the LCD module
 *  Pin 5 is R/W and we only use W so ground it
 *  Pin 3 should go to ground thru a 1K resistor
 *  Pin 15 is the positive side of the back light LED and can be connected to +5
 *  Pin 16 is the ground side of the back light LED, and should go to ground thru a 
 *  100OHM or higher resistor. You could also hook up a PWM signal here.
 *  (note: The resistor can be on either side of the LED. You MUST have a resistor)
 *  thru a transistor for variable back light.
 *  
 *  jdonelson 12/10 
 */


#include <hidef.h> 		/* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "../Headers/LCD.H"

// Delay constants for 48MHz clock.
// Set to work with CF, too long for 08.
#define ENBIT (0x02)
#define DELAY40US (104)
#define DELAY4_1MS (10761)
#define DELAY100US (262)
#define LCDWIDTH (16)
#define EN_DELAY    (90)
static int lcd_width = 0;

static void delay(word count); 
void InitLCD(int width); 
static void WriteLCD8BitMode(byte data);
void WriteByteLCD(byte data, byte rs);
void WriteLineLCD(char *string, byte line);
void ClearLCD(void);
void SetCursorLCD( byte pos);

/*
 * 
 */
static void delay(word count) 
{
   word i  = 0;
   for( i = 0; i < count ; ++i) {
      asm {
         nop
         nop
         nop
         nop
         nop
         nop
         nop
         nop
         nop
      }
   }
}
int GetLCDWidth(void)
{
	return lcd_width;
}
/*
 * 
 */
void InitLCD(int width) 
{ 
  int i;	
  lcd_width = width;
  // Set bits to output
  // PTA0 = RS (0=cmd,1=data) PTA1=EN lo-high-lo to write
  // PTA2-5 =Data bits 4-7
  PTADD |= 0x3F;
  // Enable pull ups.   
  PTAPE |= 0x3F;
  // Write all low;
  PTAD &= ~0x3f;  
  // Need to do this in case still powering up.
  // Should be 20MS
  for( i = 0 ; i < 250 ; ++i)
    delay(DELAY100US);
  // See HD44780 spec. It tells you to do this...
  WriteLCD8BitMode(0x30);  // tell it once
  delay(DELAY4_1MS);
  WriteLCD8BitMode(0x30);  // tell it twice
  delay(DELAY4_1MS);
  WriteLCD8BitMode(0x30);  // tell it thrice
  delay(DELAY4_1MS);

  // This sets 4 bit mode, but you can't write the low nibble yet.
  WriteLCD8BitMode(0x20);
  delay(DELAY4_1MS);
 
  // Now it's set to 4 bit mode.
  // 0 0 1 DL | N F X X
  // N = 2/1 line, DL = 8/4 bit F=5x10/5x8
  WriteByteLCD(0x28, 0); // last function set: 4-bit mode, 2 lines, 5x8 matrix
  delay(DELAY4_1MS);
  // 0 0 0 0 | 1 D C B
  // D= Display on off, C = Cursor, B-Blink
  WriteByteLCD(0x0c, 0); // display on, cursor off, blink off
  delay(DELAY4_1MS);
  WriteByteLCD(0x01, 0); // display clear
  delay(DELAY4_1MS);
  // 0 0 0 0 | 0 1 I/D  S
  // I/D = Increment/Decrement S = Shift
  WriteByteLCD(0x06, 0); // cursor auto-increment, disable display shift
  delay(DELAY4_1MS);
  
}

//
// Used to write while LCD is still in 8 bit mode.
//
static void WriteLCD8BitMode(byte data) 
{
  byte shifted;

  // Shift the high nibble into proper place
  shifted =(byte) (data >> 2); 
  // Pulse EN line
  PTAD = shifted; 
  // raise the strobe
  PTAD |= ENBIT;
  // We need thighs because we are too fast.
  delay(EN_DELAY);
  // Lower the strobe
  PTAD &= ~ENBIT; 
  // Delay for command to complete.
  delay(DELAY40US);
} 

//
// Write 8 bits, 4 bits at a time.
//
void WriteByteLCD(byte data, byte rs) 
{
  byte high, low;
  
  // Need to do 2x 4 bit writes
  // Extract the high nibble and the lo nibble and
  // shift them into proper bit positions.
  // 'or' in the command/data flag.
  high =(byte) (((data & 0xf0) >> 2) | (rs & 0x01)) ;

  // Write, sets EN=0
  PTAD = high; 
  // Raise EN bit to strobe data.
  PTAD |= ENBIT; 
  delay(EN_DELAY);
  // Clear EN bit
  PTAD &= ~ENBIT; 
  // Now do lo nibble.
  low = (byte) (((data & 0x0f) << 2) | (rs & 0x01)) ;
  PTAD = low; 
  PTAD |= ENBIT; 
  delay(EN_DELAY);
  PTAD &= ~ENBIT; 
  // Delay for command to complete.
  delay(DELAY40US);
} 


void WriteLineLCD(char *string, byte line) 
{
	byte i=0;
	byte cmd=0;

	// Set up which line to write on.
	// Set "Cursor Address" command.
	// 1 A A A | A A A A
	// AAAAAAA can be 00H to 27H 
	// for the first line, and 40H to 67H for the second line.
	switch(line) 
	{
		case 0:
			cmd = 0x80;
			break;
		case 1:
			cmd = 0xc0;
			break;
		case 2:
			cmd = 0x94;
			break;
		case 3:
			cmd = 0xD4;
		default:
			;
	}
	
	WriteByteLCD( cmd, 0);  // write as command
	// Clear the line first
	for( i = 0 ; i < lcd_width ; ++i)
		WriteByteLCD( ' ', 1);
	WriteByteLCD( cmd, 0);  // write as command
	
	// Send out the whole line...
	for( i = 0; string[i]  &&  i < lcd_width; i++) 
	{
		if( string[i] == '\r' || string[i] == '\n')
			continue;
		WriteByteLCD( string[i], 1); 
	}
}
void WriteBufferLCD(char *string, int count, byte line) 
{
	byte i=0;
	byte cmd=0;

	// Set up which line to write on.
	// Set "Cursor Address" command.
	// 1 A A A | A A A A
	// AAAAAAA can be 00H to 27H 
	// for the first line, and 40H to 67H for the second line.
	switch(line) 
	{
		case 0:
			cmd = 0x80;
			break;
		case 1:
			cmd = 0xc0;
			break;
		case 2:
			cmd = 0x94;
			break;
		case 3:
			cmd = 0xD4;
		default:
			;
	}
	
	WriteByteLCD( cmd, 0);  // write as command
	// Clear the line first
	for( i = 0 ; i < lcd_width ; ++i)
		WriteByteLCD( ' ', 1);
	WriteByteLCD( cmd, 0);  // write as command
	// Send out the whole line...
	for( i = 0; i < count  &&  i < lcd_width; i++) 
	{
		if( string[i] == '\r' || string[i] == '\n')
			continue;
		WriteByteLCD( string[i], 1); 
	}
} 

void ClearLCD(void)
{
	 WriteByteLCD(0x01, 0); // display clear
	 delay(DELAY4_1MS);
//	 WriteByteLCD(0x06, 0); // re-set as clear clears this to.
//	 delay(DELAY100US);
	 
}
void SetCursorLCD( byte pos)
{
	WriteByteLCD( pos | 0x80, 0);
}
