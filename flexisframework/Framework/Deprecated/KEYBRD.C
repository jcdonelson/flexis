/*
 * KEYBRD.C
 *   
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
#include "../Headers/KEYBRD.H"
static byte char_ready = 0;
static byte character= 0;

#define DEBOUNCED    3
static byte last_char= 0;
static byte debounce_counter=0;

void InitKeyboard(void)
{
	PTDDD = 0xF0;  // Upper bits output
	PTDPE = 0xF;   // Pull up the inputs.
}
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
// should be called periodically. 1MS is good (Like from the RTC).
byte ScanKeyboard()
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

byte KbrdReadChar()
{
	volatile char c;
	CLI();
	c = character;
	
	if( char_ready)
	{
		char_ready = 0;
		(void)STI();
		return c;
	}
	STI();
	return 0xff;

}
