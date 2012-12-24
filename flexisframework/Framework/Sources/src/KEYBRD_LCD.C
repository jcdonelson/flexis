/*
 *  KEYBRD_LCD.C
 *  Support for FB32 and Nano32 LCD and KEYBOARD,
 *
 *  $Rev:: 194                       $:
 *  $Date:: 2012-09-23 15:48:10 -040#$:
 *  $Author:: jcdonelson             $:
 *  Assumed  connection of keyboard as is on FB32
 *   C1   C2   C3  C4
 *   |1   |2   |3  |A
 *  ----------------- R1
 *   |4   |5   |6  |B
 *  ----------------- R2
 *   |7   |8   |9  |C
 *  ----------------- R3
 *   |*   |0   |#  |D
 *  ----------------- R4
 *  C1 = PTD0
 *  C2 = PTD1
 *  C3 = PTD2
 *  C4 = PTD3
 *  
 *  R1 = PTD4
 *  R2 = PTD5
 *  R3 = PTD6
 *  R4 = PTD7
 *  
 */
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "KEYBRD_LCD.H"
#include "RTC.H"
#include  "DIGITAL_IO.H"
#include "CONFIG.H"
#ifndef PWM_MAX
#define PWM_MAX 1024
#endif
byte KPADScan(void);
byte BTNScan(void);
static byte char_ready = 0;
static byte character= 0;

#define DEBOUNCED    3
static byte last_char= 0;
static byte debounce_counter=0;

typedef struct _scantable {
  byte output; // what to output.
  byte input;  // expected input
  byte c; 
}SCANTABLE;
SCANTABLE _st[]={
{0x70,0x7,'D'}, // 0
{0x70,0xB,'#'}, // 1
{0x70,0xD,'0'}, // 2
{0x70,0xE,'*'}, // 3

{0xB0,0x7,'C'}, // 4
{0xB0,0xB,'9'}, // 5
{0xB0,0xD,'8'}, // 6
{0xB0,0xE,'7'}, // 7

{0xD0,0x7,'B'}, // 8
{0xD0,0xB,'6'}, // 9
{0xD0,0xD,'5'}, // 10 
{0xD0,0xE,'4'}, // 11

{0xE0,0x7,'A'}, // 12
{0xE0,0xB,'3'}, // 13
{0xE0,0xD,'2'}, // 14
{0xE0,0xE,'1'}, //1 5

};
static PFNRTCCB_I _KBRDChainCallback = 0; 
static PFNRTCCB_I _KBRDUserCallback = 0; 

static void _KBRDCallback(int ticks);
static void _KBRDCallback(int ticks)
{
	if(_KBRDChainCallback)
		_KBRDChainCallback(ticks);
	KPADScan();
}
void KPADInit(void)
{
	PTDDD = 0xF0;  // Upper bits output
	PTDPE = 0xF;   // Pull up the inputs.
	_KBRDChainCallback = SetRTChainCallback(_KBRDCallback );
	
}
// should be called periodically. 1MS is good (Like from the RTC).
byte KPADScan()
{
	 int i;
	 byte read;
	 byte c = 0;
	 
	 
	 for( i = 0 ; i < 16 ; ++i)
	 {
		 PTDD = _st[i].output;
		 // Need this delay to allow the signal
		 // to propagate. Tested with 6" cable.
		 asm {
			 nop
			 nop
			 nop
			 nop
		 }
		 read = PTDD & 0xf;
		 
		 if(read == _st[i].input )
			 break;
	 }
	 // No key pressed
	if( i == 16)
	{
		debounce_counter = 0;
		last_char = 0;
		return 0;
	}
	
    c =  _st[i].c;
	 
	if( c == last_char )
	{
		// waiting for the key to be released...
		if(DEBOUNCED < debounce_counter)
			return 255;
		 ++debounce_counter;
		 
	}
	else // start over counting for debounce.
		debounce_counter = 0;
	
	last_char = c;
	
	if( DEBOUNCED == debounce_counter )
	{
		char_ready =  1;
		character = c;
	}
	
	return c;
	 

}
void CLI(void);
void STI(void);

byte KPADReadChar()
{
	volatile byte c;
	CLI();
	c = (byte) character;
	
	if( char_ready)
	{
		char_ready = 0;
		(void)STI();
		return (byte) c;
	}
	STI();
	return 0xff;

}
byte BTNScan(void)
{
	static byte status = 99;
	static byte dbounce = 0;
	if( status == 99)
	{
		PTGDD |= 1;
		PTGPE |= 1;
		status = 0;
		return 0;
	}
	if(status != (PTGD & 1))
	{
		if(dbounce == 10)
		{
			status = (PTGD & 1);
		}
		else if(dbounce < 10)
			++dbounce;
		
	}
	else
		dbounce = 0;
	
	
	return status;
}
/*******************************************************
 * 
 * LCD SUPPORT
 * 
******************************************************* */
/*
 *  LCD - Writes to LCD for FB JR, FB SR and NANO
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

// Delay constants for 48MHz clock.
// Set to work with CF, too long for 08.
#define ENBIT (0x02)
#define DELAY40US (104)
#define DELAY4_1MS (10761)
#define DELAY100US (262)
#define LCDWIDTH (16)
#define EN_DELAY    (90)
static int lcd_width = 0;
static int lcd_lines = 0;

static void lcd_delay(word count); 
void InitLCD(int width); 
static void LCDWrite8BitMode(byte data);
void LCDWriteByte(byte data, byte rs);
void LCDWriteLine(char *string, byte line);
void LCDClear(void);
void SetCursorLCD( byte pos);

/*
 * 
 */
static void lcd_delay(word count) 
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
int LCDGetWidth(void)
{
	return lcd_width;
}
/*
 * 
 */
void LCDInit(int width,int lines) 
{ 
  int i;	
  lcd_width = width;
  lcd_lines = lines;
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
    lcd_delay(DELAY100US);
  // See HD44780 spec. It tells you to do this...
  LCDWrite8BitMode(0x30);  // tell it once
  lcd_delay(DELAY4_1MS);
  LCDWrite8BitMode(0x30);  // tell it twice
  lcd_delay(DELAY4_1MS);
  LCDWrite8BitMode(0x30);  // tell it thrice
  lcd_delay(DELAY4_1MS);

  // This sets 4 bit mode, but you can't write the low nibble yet.
  LCDWrite8BitMode(0x20);
  lcd_delay(DELAY4_1MS);
 
  // Now it's set to 4 bit mode.
  // 0 0 1 DL | N F X X
  // N = 2/1 line, DL = 8/4 bit F=5x10/5x8
  LCDWriteByte(0x28, 0); // last function set: 4-bit mode, 2 lines, 5x8 matrix
  lcd_delay(DELAY4_1MS);
  // 0 0 0 0 | 1 D C B
  // D= Display on off, C = Cursor, B-Blink
  LCDWriteByte(0x0c, 0); // display on, cursor off, blink off
  lcd_delay(DELAY4_1MS);
  LCDWriteByte(0x01, 0); // display clear
  lcd_delay(DELAY4_1MS);
  // 0 0 0 0 | 0 1 I/D  S
  // I/D = Increment/Decrement S = Shift
  LCDWriteByte(0x06, 0); // cursor auto-increment, disable display shift
  lcd_delay(DELAY4_1MS);
  for( i = 0 ; i < lines ; ++i)
  {
	  LCDWriteLine("",(byte) i);
  }
  
}

//
// Used to write while LCD is still in 8 bit mode.
//
static void LCDWrite8BitMode(byte data) 
{
  byte shifted;

  // Shift the high nibble into proper place
  shifted =(byte) (data >> 2); 
  // Pulse EN line
  PTAD = shifted; 
  // raise the strobe
  PTAD |= ENBIT;
  // We need thighs because we are too fast.
  lcd_delay(EN_DELAY);
  // Lower the strobe
  PTAD &= ~ENBIT; 
  // Delay for command to complete.
  lcd_delay(DELAY40US);
} 

//
// Write 8 bits, 4 bits at a time.
//
void LCDWriteByte(byte data, byte rs) 
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
  lcd_delay(EN_DELAY);
  // Clear EN bit
  PTAD &= ~ENBIT; 
  // Now do lo nibble.
  low = (byte) (((data & 0x0f) << 2) | (rs & 0x01)) ;
  PTAD = low; 
  PTAD |= ENBIT; 
  lcd_delay(EN_DELAY);
  PTAD &= ~ENBIT; 
  // Delay for command to complete.
  lcd_delay(DELAY40US);
} 


void LCDWriteLine(char *string, byte line) 
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
	
	LCDWriteByte( cmd, 0);  // write as command
	// Clear the line first
	for( i = 0 ; i < lcd_width ; ++i)
		LCDWriteByte( ' ', 1);
	LCDWriteByte( cmd, 0);  // write as command
	
	// Send out the whole line...
	for( i = 0; string[i]  &&  i < lcd_width; i++) 
	{
		if( string[i] == '\r' || string[i] == '\n')
			continue;
		LCDWriteByte((byte) string[i], 1); 
	}
}
void LCDWriteBuffer(char *string, int count, byte line) 
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
	
	LCDWriteByte( cmd, 0);  // write as command
	// Clear the line first
	for( i = 0 ; i < lcd_width ; ++i)
		LCDWriteByte( ' ', 1);
	LCDWriteByte( cmd, 0);  // write as command
	// Send out the whole line...
	for( i = 0; i < count  &&  i < lcd_width; i++) 
	{
		if( string[i] == '\r' || string[i] == '\n')
			continue;
		LCDWriteByte((byte) string[i], 1); 
	}
} 

void LCDClear(void)
{
	 LCDWriteByte(0x01, 0); // display clear
	 lcd_delay(DELAY4_1MS);
//	 LCDWriteByte(0x06, 0); // re-set as clear clears this to.
//	 delay(DELAY100US);
	 
}
void SetCursorLCD( byte pos)
{
	LCDWriteByte( pos | 0x80, 0);
}
void _BUTTONCallback(int ticks);
static PFNRTCCB_I _BUTTONChainCallback = 0; 
static PFNRTCCB_I _BUTTONUserCallback = 0; 
#define BUTTON_DEBOUNCE 		20
static void _BUTTONCallback(int ticks)
{
	static byte state = 1;
	static byte debounce = 0;
	if(_BUTTONChainCallback)
		_BUTTONChainCallback(ticks);
	PTGDD &= ~1; // set the bit to input.
	PTGPE |= 1;

	if((PTGD & 1) == state  )
	{
		if(debounce == BUTTON_DEBOUNCE + 1)
			return;
		++debounce;
		if(debounce == BUTTON_DEBOUNCE)
		{
			_BUTTONUserCallback((int)state);
			return;
		}
	}
	else
	{
		state = PTGD & 1; 
		debounce = 0;
		
	}
	
}
void BUTTONInit(void)
{
	PTGDD &= ~1; // set the bit to input.
	PTGPE |= 1;
	_BUTTONChainCallback = SetRTChainCallback(_BUTTONCallback );

}
void BUTTONSetCallback(void(*fb)(int state))
{
	_BUTTONUserCallback = fb;
}

void RGBSetColor(dword rgb)
{
    pinMode(RGB_ENABLE,OUTPUT);
    digitalWrite(RGB_ENABLE,1);
    analogWrite(RGB_BLUE_PWM,(int)(PWM_MAX - (rgb & 0xff)*4) );
    rgb >>= 8;
    analogWrite(RGB_GREEN_PWM,(int)(PWM_MAX -(rgb & 0xff)*4) );
    rgb >>= 8;
    analogWrite(RGB_RED_PWM,(int)(PWM_MAX -(rgb & 0xff)*4));


}
