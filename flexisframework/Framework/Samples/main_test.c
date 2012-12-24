///////////////////////////////////////////////////////////////////////
//
// Manufacturing Test Program
// Firebird32
// Jim Donelson 10/10
//
///////////////////////////////////////////////////////////////////////

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include <stdio.h>
#include "ALL.H"

void SetLeds(byte data);
void  RTC_handler(void);
void SendString(char *s);
int out_test_pin = 19;
int in_test_pin = 13;


SONG yankee[]=
{
		{10,1,4},
		{10,1,4},
		{12,1,4},
		{2,2,4},
		
		{10,1,4},
		{2,2,4},
		{12,1,4},
		{5,1,4},
		
		{10,1,4},
		{10,1,4},
		{12,1,4},
		{2,2,4},
		
		{10,1,2},
		{9,1,2},
		
		{10,1,4},
		{10,1,4},
		{12,1,4},
		{2,2,4},
		
		{3,2,4},
		{2,2,4},
		{12,1,4},
		{10,1,4},

		{9,1,4},
		{5,1,4},
		{7,1,4},
		{9,1,4},

		{10,1,2},
		{10,1,2},

		{255,1,1}, // 255 is a rest.
		{255,1,1}, // 255 is a rest.
		{255,1,1}, // 255 is a rest.
		{0}
};
void InitSpeaker();
byte UserDelay;
word time_counter = 0;
word pattern_counter = 0;
int duty =0;
int dir=1;


byte digit = 0;
byte pot;
byte light;
 char message[80];
 int pwm_value = 0;
 int pwm_counter = 0;
 // 1MS tick. 
void  RTC_handler(void)
{

	volatile int read_data;
	volatile byte c;
	SongRTCCallback();
    read_data = analogRead(7);
    c =  ScanKeyboard();
    //digitalWrite(out_test_pin, read_data);
    return;
    

	
  --UserDelay;
 
  


 
  ++time_counter;
  if( 250 == time_counter ) 
  {
      time_counter = 0;
    
  }
}



void SendString(char *s) 
{
   while(*s) 
   {
       while(TX_FULL == SCI1_TXByte(*s) )
            ;
       ++s;
   }
}
#define RISING_EDGE  0x4
#define FALLING_EDGE 0x8
#define BOTH_EDGES   0xc
void InitEdgeInterrupt(byte edge)
{
	if( 0 == (TPM1SC & 0x18))  // See if CLK is 00
	  TPM1SC = 8; 			 // CLKS can't be at 0 for this to work.
	  TPM1C3SC = 0x40 | edge;       // Enable channel 3 PTF1 for edge interrupt.
	  PTFDD &= ~2;
	  PTFPE |= 2;

}
volatile byte rc;
void main(void) 
{
 
 volatile int i = 0;
	byte rxdata;
	byte txtest = 0;
	
	SOPT1 = 0x10; // Disable watch dog.
	InitKeyboard();
	InitCLOCK();
	SetRTCUserCallback(RTC_handler);
	InitRTC();
  
  
	InitLCD(8);
	EnableInterrupts; /* enable interrupts */
	InitSpeaker();
	SetSong((SONG*)&yankee);
	
  
 
	//WriteLineLCD("                ", 1);
	WriteLineLCD(" Hello", 0);
	WriteLineLCD(" World!", 1);
	//WriteLineLCD(" Line 3    ", 2);
	//WriteLineLCD(" Line 4    ", 3);
	SCI1_Init();
	(void)SCI1_SetBaudRate(BAUD_115200);
	/*
	while(1){
	SendString("AT\n\r");
	for( i = 0 ; i < 1000; ++i)
		 asm{
		   nop
		   nop
		   nop
		   nop
	     }
	
	}
	*/
	/* include your code here */
	
	//(void)SCI2_TXByte('q');
	pinMode(in_test_pin,INPUT | HI_DRIVE);
	pinMode(out_test_pin,OUTPUT);
	digitalWrite(out_test_pin,1);
 
  for(;;) {
	  char c;
	  char lcd_msg[16];
	  byte lcd_index = 0;
	  
	  if(KBRD_NOCHAR != (c = KbrdReadChar()))
	  {
		  ClearLCD();
		  if( lcd_index < sizeof(lcd_msg) - 1)
		    lcd_msg[lcd_index++] = c;
		  
		  lcd_msg[lcd_index] = 0;
		  WriteLineLCD(lcd_msg, 0);
		  
	  }
	  rc = 2;
      rc = SCI1_RXByte(&rxdata);
      if( 0 == rc ) 
      {
          (void)SCI1_TXByte(rxdata);
          if( rxdata == '\r' )
             SCI1_TXByte('\n');
          if( 'X' == rxdata ) 
          {
             
             
             SendString("\r\nGot it!\r\n"); 
             txtest ^= 1;
          }
          rxdata = 0;
      }
      if( txtest ) 
      {
          SendString("The quick brown fox jumps over the lazy dog\r\n"); 
      }
    
  } /* loop forever */
  /* please make sure that you never leave main */
}
