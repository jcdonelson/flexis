/*
 * loop_mfgdemo.c
 *
 *  Created on: Mar 17, 2011
 *      Author: jdonelson
 */
/*
 * 1.  Chirp once.
2.  LCD displays "Hello World!" 
3.  Flash Red, Green and Blue 0.25 second for each color, then all off
4.  Flash LED D13 twice and then stays on.
5   Sing the "Yankee Doodle" twice or keep singing.
 
 */
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#include <stdio.h>
//#include <ansi_parms.h>
#include "ALL.H"
#include "CONFIG.H"
#define RGB_ENABLE    	22
#define RGB_GREEN	3
#define RGB_RED		5
#define RGB_BLUE	9
#define RGB_GREEN_PWM	0
#define RGB_RED_PWM	1
#define RGB_BLUE_PWM	3
#define RGB_ON		0
#define RGB_OFF		1
#define LED		13

SONG yankee[];
void RTCTickCallback(void);
void setup(void);
void loop(void);
void chirp(int f, int ms);
void SetRGB(dword rgb);
void Serial_Echo(int serial_port);
void chirploop(void);

void chirp(int f, int ms)
{
	volatile long starttime = millis();
	SetFrequencySpeaker((dword)f * 10);
	SpeakerON();
	while( (millis() - starttime ) < ms)
		;
	starttime = millis();
	SpeakerOFF();
	
}
void chirploop(void)
{
	int i; 
	for( i = 0 ; i < 15 ; ++i )
		chirp(2000 + (i * 500),12);
}
void SetRGB(dword rgb)
{ 
	analogWrite(RGB_BLUE_PWM,(int)(PWM_MAX - (rgb & 0xff)*4) );
	rgb >>= 8;
	analogWrite(RGB_GREEN_PWM,(int)(PWM_MAX -(rgb & 0xff)*4) );
	rgb >>= 8;
	analogWrite(RGB_RED_PWM,(int)(PWM_MAX -(rgb & 0xff)*4));
	
}
int seconds = 0;
int counter =0;
int blink_state=0;
int speed = 0;
int rgb_counter = 2000;
dword colors[]={
		0xFF0000,
		0x00FF00,
		0x0000FF,
		0x8000FF,  // purple
		0x0080FF,  // cyan
		0xFFAA00,  // Yellow
		0x8080FF,  // White

		0
};
int color_index = 1;
int song_doneflag = 0;
int end_time = 0;
int reps = 0;
int button_dn=0;
void SongIsDoneCallback(void);

void SongIsDoneCallback(void)
{
	song_doneflag = 1;
	end_time =  counter;
	++reps;
}
#if MCU_HCS08 == 1
#define BLINKRATE 150
#define ID_TEXT "  9S08  "
#else
#define BLINKRATE 500
#define ID_TEXT "  CFV1  "
#endif
byte EEPROM_fail = 0;
void RTCTickCallback(void)
{
	++counter;
	if(EEPROM_fail)
		return;
	if( counter % BLINKRATE == 0)
	{
		if( button_dn )
		{			
		blink_state ^= 1;
		digitalWrite(LED,blink_state);
		}
	}
	if( (counter % 1000) == 0)
	{
		++seconds; 
	}
	if( (counter % rgb_counter) == 0)
	{
		if( speed == 2)
			rgb_counter = 500;
		RGBSetColor(colors[color_index]);
		//SetRGB(colors[color_index]);
		++color_index;
		if(0 == colors[color_index])
		{
			color_index = 0;
			++speed;
		}
	}
	
	if( seconds == 2 && end_time == 0 )
	{
		song_doneflag = 1;
		end_time = 1;
	}
	if( song_doneflag && end_time < (counter+ 2000) && reps < 3 )
	{
		song_doneflag = 0;
		SetSong(&yankee[0]);

	}
	SongRTCCallback();
	
}
void OnButtonChanged(int state);
void OnButtonChanged(int state)
{
	button_dn = state;
	if(!state)
		digitalWrite(LED,1);

}
EEPROM_WRITE_BLOCK eeprom_write_data;
byte I2C_ReadBuffer[34];
void EEPROMFailed(char* reason);
int ReadWriteEEPROM(word address, int data);
int ReadWriteEEPROM(word address, int data)
{
  int i;
  eeprom_write_data.address = address;

  for( i = 0 ; i < 32 ; ++i)
  {
    if( data >= 0)
          eeprom_write_data.data[i] =(char) data;
    else
      eeprom_write_data.data[i] =(char) i;
    I2C_ReadBuffer[i] = 0xff; // Smudge the read buffer
  }
  EEPROMWriteBlock((byte *)&eeprom_write_data,0);
  
  EEPROMReadBlock(address, &I2C_ReadBuffer[0],32);
  while(I2CGetStatus())
   ;
  for( i = 0 ; i < 32 ; ++i)
  {
      if( eeprom_write_data.data[i] != I2C_ReadBuffer[i] )
      {
        EEPROMFailed((char*)"BAD DATA");
      }
  }
 return 0;
}
void EEPROMFailed(char* reason)
{
    SendString(SCI1,"EEPROM FAILED\r\n");
    SendString(SCI1,reason);
    SendString(SCI1,"\r\n");
    
    LCDWriteLine(" EEPROM ", 0);
    LCDWriteLine(reason, 1);
    pinMode(LED,OUTPUT);
    digitalWrite(LED,1);
    EEPROM_fail = 1;
    while(1)
    {
            delay(250);
            chirploop();
    
    }
}
void I2CTest(void);

void I2CTest(void)
{
  int i;
  volatile byte rc;
  dword address=0;
  PTGDD |= 4;
  PTGD &=  ~4;

  EnableInterrupts;
  if( I2CInit() )
	  EEPROMFailed((char*)" SHORT");
  
  I2CSetDeviceAddress(I2C_EEPROM_ModuleAddress);
  
  // We do this to make sure that the device is responding.
  I2CSend((byte*) &address,2);
  while(I2CGetStatus())
   ;
  if(ERROR_NAK == I2CGetLastError())
      EEPROMFailed((char*)" NO ACK");
    
  
  ReadWriteEEPROM(0, 0);
  ReadWriteEEPROM(0, 0xff);
  ReadWriteEEPROM(0, -1 );
  ReadWriteEEPROM(32, 0);
  ReadWriteEEPROM(32, 0xff);
  ReadWriteEEPROM(32, -1 );
}
byte toggle=0;
int Testpca9535()
{
  byte config[] = {0x06,0};
  byte data[]={0x02,0xaa};
  byte rxcmd[]={0x0};
  byte rxdata[4];
   
  I2CSetDeviceAddress(0x40);
  I2CSend((byte*) &config,2);
  while(I2CGetStatus())
   ;
  if( toggle)
    data[1] = 0xaa;
  else
    data[1] = 0x55;
  toggle ^= 1;
  I2CSend((byte*) &data,2);
  while(I2CGetStatus())
   ;

  if(ERROR_NAK == I2CGetLastError())
       return -1;
  I2CSend((byte*) &rxcmd,1);
  while(I2CGetStatus())
   ;

  I2CRecieve(&rxdata[0],1);
  while(I2CGetStatus())
    ;

  return 0;

}
void setup(void)
{
	int i=0;
	
	volatile byte rc;
	
	
	SpeakerInit();  
	EnableInterrupts;
	rc = I2CInit(); 
	return;
	          

	LCDInit(8,2);
	if( OSCILLATOR_Fail)
	{
		LCDWriteLine(" XTAL  ", 0);
		LCDWriteLine(" FAILED ", 1);
		while(1)
			;

	}
	Serial_Init(SCI1);
	SendString(SCI1,"********************\r\n"); 
	SendString(SCI1,"***  DEMO V2.0A  ***\r\n"); 
	SendString(SCI1,"********************\r\n\n"); 
	SendString(SCI1,"Echo Test - Type 'X' for txtest\r\n"); 
	I2CTest();
	pinMode(LED,OUTPUT);
	/*
	pinMode(RGB_ENABLE,OUTPUT);
	digitalWrite(RGB_ENABLE,1);
	
	pinMode(RGB_BLUE,OUTPUT);
	pinMode(RGB_RED,OUTPUT);
	pinMode(RGB_GREEN,OUTPUT);
	digitalWrite(RGB_BLUE,1);
	digitalWrite(RGB_RED,1);
	digitalWrite(RGB_GREEN,1);
	*/
//	SetRGB(colors[0]);
	RGBSetColor(colors[0]);
	SetOnSongDoneCallback(SongIsDoneCallback);
	KPADInit();
	
	chirploop();
#if MCU_HCS08 == 1
	delay(250);
	chirploop();
	delay(250);
	chirploop();
#endif	
	
	LCDWriteLine("Firebird", 0);
	LCDWriteLine(ID_TEXT, 1);
	BUTTONInit();
	BUTTONSetCallback(OnButtonChanged);
	




	

}
void loop(void)
{
  char c;
  static char lcd_msg[8];
  static byte lcd_index = 0;
  int rc =0 ;
  while(1)
  rc = Testpca9535();
  Serial_Echo(SCI1);
  // Echo the keypad to the LCD
  if(KPAD_NOCHAR != (c = KPADReadChar()))
   {
      LCDClear();
      if( lcd_index < sizeof(lcd_msg) - 1)
        lcd_msg[lcd_index++] = c;
      else
        {
          lcd_index = 0;
          lcd_msg[lcd_index++] = c;
          
        }
      lcd_msg[lcd_index] = 0;
      LCDWriteLine(lcd_msg, 0);
            
    }

}



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

void Serial_Echo(int serial_port)
{
	byte rc;
	byte rxdata;
	static txtest = 0;
	rc  = Serial_rxbyte(serial_port, &rxdata);
	if( 0 == rc ) 
	{
		(void) Serial_txbyte(serial_port,rxdata);
		if( rxdata == '\r' )
		  (void) Serial_txbyte(serial_port,'\n');
		if( 'X' == rxdata ) 
		{
		   SendString(serial_port,"\r\nGot it!\r\n"); 
		   txtest ^= 1;
		}
		rxdata = 0;
	}
	if( txtest ) 
	{
		SendString(serial_port,"ABCDEFGHIJKLMNOPQRSTUZWXYZ 123456780!@#$%^&*(){}[]\r\n"); 
	}

}
