/*
 * loop_mfgdemo.c
 *
 *  $Rev:: 71                        $:
 *  $Date:: 2011-05-21 21:12:31 -040#$:
 *  $Author:: jcdonelson             $:
 *
 *  Created on: Mar 17, 2011
 *      Author: jdonelson
 */

#include <hidef.h>       // 
#include "derivative.h"  // Defines for the MCU we are using

#include <stdio.h>
//#define _EWL_FLOATING_POINT_IO 1
#include <ansi_parms.h>
#include <string.h>
#include <ctype.h>
#include "math.h"
#include "ALL.H"
#include "COMND_LINE.H"
#include "CONFIG.H"
#define RGB_ENABLE    	22
#define RGB_GREEN		3
#define RGB_RED			5
#define RGB_BLUE		9
#define RGB_GREEN_PWM	0
#define RGB_RED_PWM		1
#define RGB_BLUE_PWM	3
#define RGB_ON			0
#define RGB_OFF			1
#define LED				13
void SetRGB(dword rgb);
void SetRGB(dword rgb)
{ 
	analogWrite(RGB_BLUE_PWM,(int)(PWM_MAX - (rgb & 0xff)*4) );
	rgb >>= 8;
	analogWrite(RGB_GREEN_PWM,(int)(PWM_MAX -(rgb & 0xff)*4) );
	rgb >>= 8;
	analogWrite(RGB_RED_PWM,(int)(PWM_MAX -(rgb & 0xff)*4));
	
}
BEGIN_PIO_TABLE(mytable)
PIO_ENTRY(D_PORTE,BIT2) // 0
PIO_ENTRY(D_PORTE,BIT2) // PTE1 TX
PIO_ENTRY(D_PORTE,BIT0) // PTE0 RX
PIO_ENTRY(D_PORTG,BIT3) // PTG3
PIO_ENTRY(D_PORTE,BIT2) // PTE2 TPM1CH0
END_PIO_TABLE(mytable)
// Set up for servo.
SRV_DECALARE_DATA(); 
SONG yankee[];
void SongIsDoneCallback(void);
void TEST1_callback(void);
int TEST1_digitalIO(void);
void Serial_Reader(int serial_port);
void RTCTickCallback(void);
int counter = 0;		// Determine when 1/2 a second is up.
int  blink_state=0;		// Toggles with XOR
void (*test_callback)(int counter) = 0;
void (*loop_callback)(void) = 0;
byte endcallback = 1;
volatile byte btn;
byte pflag = 0;
void RTCTickCallback(void)
{
	++counter;			// Increment the 1 ms counter.
	if(test_callback)
		test_callback(counter);
	if( (counter % 100) == 0 )
	{
		if( pflag )
			pulseOut(8,1000,0);
		else
			pulseStop();
	    pflag ^= 1;
	}
	
	SongRTCCallback();


}
extern far IOREGS ioregisters[];
void OnButtonChanged(int state);
void OnButtonChanged(int state)
{
	state = ++state;
}
void setup(void)
{
	setPIOTable(FB32_PIO);
	
	pinMode(0,OUTPUT);
	digitalWrite(0,0);
	Serial_Init(SCI1);
	LCDInit(8,2);
	LCDWriteLine(" Ready",0);
	SetActiveConsole(SCI1_CONSOLE );
	SetOnSongDoneCallback(SongIsDoneCallback);
	analogWrite(0,0);
	printf("\r\n\n*** RESET ***\r\n\ncmd>");
	BUTTONInit();
	BUTTONSetCallback(OnButtonChanged);
	TEST1_digitalIO();
	//printf("TripTemp, Temp: %f, %f\n", thermocoupleTripValue, thermocoupleValue);


	
	
	
}


void loop(void)
{
	CMDLINE_Reader(SCI1);
	//*((char*) 0) = 0;
	if(loop_callback)
	{
		loop_callback();
	}
	
}
/*
 *  Command handlers and table
 */
byte mnt1_pins[]={15,14,2,4,5,25,7,8,9};

byte mnt1_pinsG0[]={22,23,2,4};
byte mnt1_pinsG1[]={5,6,7,8};
byte mnt1_pinsG2[]={9,11,12,17};
byte mnt1_pinsG3[]={14,10,15,16};
byte mnt1_pinsG4[]={13,18,19,20};
byte* mnt1_ports[]={
&mnt1_pinsG0[0],&mnt1_pinsG1[0],&mnt1_pinsG2[0],&mnt1_pinsG3[0],&mnt1_pinsG4[0],
0};
void mini_test1_Testcallback(int counter);
int mini_test1(char* s);

void mini_test1_Testcallback(int counter)
{
	static word index = 0;
	int i = 0;
	counter;
	if( 0 == index )
	{
		singleshotPulse(0,(dword) 2000);
		
	}
	while(mnt1_ports[i])
	{
		portWriteEx(mnt1_ports[i],index,4);
		i++;
	}

	if( index % 2 == 0)
	{
		digitalWrite(21,1);
	}
	else digitalWrite(21,0);
	++index;
	if(16 == index)
		index = 0;
}
int mini_test1(char* s)
{
	int i = 0;
	s;
	setPIOTable(MINI_PIO);
	printf("Hit ESC to end\r\n");
	while(mnt1_ports[i])
	{
		portModeEx(mnt1_ports[i],OUTPUT,4);
		i++;
	}
	pinMode(21,OUTPUT);
	test_callback = mini_test1_Testcallback;
	
	return 0;
}
void nano_test1_Testcallback(int counter);
int nano_test1(char* s);
byte nat1_pinsG0[]={0,1,2,3};
byte nat1_pinsG1[]={4,5,6,7};
byte nat1_pinsG2[]={8,9,10,11};
byte nat1_pinsG3[]={12,13,14,15};
byte nat1_pinsG4[]={16,17,18,19};
byte nat1_pinsG5[]={20,21,22,23};
byte nat1_pinsG6[]={24,28,29,30};
byte nat1_pinsG7[]={31,32,33,33};
byte* nat1_ports[]={
		&nat1_pinsG0[0],
		&nat1_pinsG1[0],
		&nat1_pinsG2[0],
		&nat1_pinsG3[0],
		&nat1_pinsG4[0],
		&nat1_pinsG5[0],
		&nat1_pinsG6[0],
		&nat1_pinsG7[0],
0};
void nano_test1_Testcallback(int counter)
{
	static word index = 0;
	int i = 0;
	counter;
	if( 0 == index )
	{
		singleshotPulse(0,(dword) 2000);
		
	}
	while(nat1_ports[i])
	{
		portWriteEx(nat1_ports[i],index,4);
		i++;
	}

	++index;
	if(16 == index)
		index = 0;
}
int nano_test1(char* s)
{
	int i = 0;
	s;
	setPIOTable(NANO_PIO);
	printf("Hit ESC to end\r\n");
	while(nat1_ports[i])
	{
		portModeEx(nat1_ports[i],OUTPUT,4);
		i++;
	}
	
	pinModeEx(31,OUTPUT | HI_DRIVE );
	test_callback = nano_test1_Testcallback;
	
	return 0;
}
void SendTestcallback(void);
void SendTestcallback(void)
{
	printf("The quick brown fox jumps over the lazy dog. 0123456789!@#$%^&*(){}[] Hit ESC\r\n");
}

void TEST1_callback(void)
{
	static int i=0;
	digitalWrite(i,i & 1);
	++i;
	if( i == 42)
	{
		i = 0;
	}
}
int TEST1_digitalIO(void)
{
	int i;
	for(i = 0 ; i < 21 ; ++i)
	{
		pinMode(i,OUTPUT);
	}
	//test_callback = TEST1_callback;
	return 0;
}
int cmd_led_on(char* s);
int cmd_digitalWrite(char* s);
int cmd_pinMode(char* s);
int cmd_escape(char* s);
int cmd_lcd_test(char *s);
int cmd_led_off(char* s);

int cmd_txtest(char *c);
int cmd_txtest(char *c)
{
	 c;
	printf("\r\n\nHIT ESC TO STOP\r\r"); 
	loop_callback =SendTestcallback;
	return 0;
}
int cmd_pinMode(char* s)
{
	int pin;
	char mode;
	if( 2 != sscanf(s,"%d %c",&pin,&mode)  ) 
	{
		printf("pm pin mode i=INPUT o=OUTPUT 'pm 13 o' \r\n");
		return 0;
	}
	if( mode == 'o')
		pinMode(pin, OUTPUT);
	else if(mode == 'i')
		pinMode(pin, INPUT);
	else
	{
		printf("mode must be 'i' or 'o' \r\n");
	}
	
	return 0;
			
}

int cmd_digitalWrite(char* s)
{
	int pin,data;
	if( 2 != sscanf(s,"%d %d",&pin,&data) ) 
	{
		printf("dw pin data (need to set mode with pm)\r\n");
		return 0;
	}
	
	digitalWrite(pin, data);
	return 0;
			
}
int cmd_digitalRead(char* s);
int cmd_digitalRead(char* s)
{
	int pin;
	if( 1 != sscanf(s," %d ",&pin) ) 
	{
		printf("dr pin (need to set mode with pm)\r\n");
		return 0;
	}
	
	printf("\r\tPin %d is %d\r\n",pin,digitalRead(pin));
	return 0;
			
}
int cmd_escape(char* s)
{
	s;
	loop_callback = 0;
	test_callback = 0;
	endcallback = 1;

	return 0;
}
void  test_singleshot_pulse_callback(int counter);
int cmd_test_singleshot_pulse(char *s);
int pwmchannel;
int interval;
int duration;
void  test_singleshot_pulse_callback(int counter)
{
	if((counter % interval) == 0)
		singleshotPulse(pwmchannel,(dword) duration);
}
int cmd_test_singleshot_pulse(char *s)
{
	if( 3 != sscanf(s," %d %d %d ",&pwmchannel,&duration,&interval) || pwmchannel > 7 ) 
	{
		printf("\rsst ch(0-7) duration(us) interval(ms) 'sst 0 1000 10'\r\n");
		return 0;
	}
	test_callback = test_singleshot_pulse_callback;
	
	
}
static lcd_init = 0;
int cmd_lcd_test(char *s)
{
	
	int line;
	if(!lcd_init)
		LCDInit(8,2);
	lcd_init = 1;
	if( 1 != sscanf(s, " %d ", &line))
	{
		printf("linenumber text\r\n");
		return 0;
	}
	while(!isdigit(*s++))
		;
	*s++; // Skip the first space.
	LCDWriteLine(s,(byte)line);
}
int cmd_led_on(char* s)
{
	s;
	pinMode(13, OUTPUT);
	digitalWrite(13,1);
	return 0;
}
int cmd_led_off(char* s)
{
	s;
	digitalWrite(13,0);
	return 0;

}
int use_table(char* s);
int use_table(char* s)
{
	int table_no;
	if( 1 != sscanf(s," %d ",&table_no) || table_no > 3 ) 
	{
		printf("\rTable number 0=FB32 1=NANO 2=MINI\r\n");
		return 0;
	}
	switch(table_no)
	{
	case 0:
		setPIOTable(FB32_PIO);
		break;
	case 1:
		setPIOTable(NANO_PIO);
		break;
	case 2:
		setPIOTable(MINI_PIO);
		break;
	default:
		;
		
	}
	return 0;
}
int cmd_servo_pos(char *s);
int cmd_svrch(char *s);
int cmd_svrch(char *s)
{
	if( 1 != sscanf(s," %d ",&pwmchannel) || pwmchannel > 7 ) 
	{
		printf("\rsst ch(0-7) \r\n");
		return 0;
	}
	return 0;
	
}
int cmd_servo_pos(char *s)
{
	if( 1 != sscanf(s," %d ",&duration)  ) 
	{
		printf("\rsp ms \r\n");
		return 0;
	}
	interval = 10;
	test_callback = test_singleshot_pulse_callback;
	return 0;
	
}
void SongIsDoneCallback(void)
{
	
}
int cmd_play(char *s);
int cmd_play(char *s)
{
	s=s;
	setPIOTable(FB32_PIO);
	SpeakerInit(); 
	SetSong(&yankee[0]);
}
int cmd_rgb(char *s);
int cmd_rgb(char *s)
{
	dword rgb;
	if( 1 != sscanf(s," %lx ",&rgb)  ) 
	{
		printf("\rrgb rrbbgg in hex \r\n");
		return 0;
	}
	setPIOTable(FB32_PIO);
	pinMode(RGB_ENABLE,OUTPUT);
	digitalWrite(RGB_ENABLE,1);
	SetRGB( rgb);
	return 0;
	
}

START_CMD_TABLE()
	CMD("esc",cmd_escape,"\t The ESC key cancels any running command")
	CMD("pm",cmd_pinMode,"\t pinMode 'pm 13 o' ")
	CMD("dw",cmd_digitalWrite,"\t digitalWrite 'dw 13 1'")
    CMD("dr",cmd_digitalRead,"\t digitalRead 'dw 13'")
	CMD("sst",cmd_test_singleshot_pulse,"\t Send single shot test 'sst ch 1000 10'")
	CMD("txt1",cmd_txtest,"\t Send text lines to serial port ESC to stop")
	CMD("lcd",cmd_lcd_test,"\t Write to the 'lcd 0 Hello!'")
    CMD("mt1",mini_test1,"\t Run mini test 1 Count patterns")
    CMD("nt1",nano_test1,"\t Run nano test 1 Count patterns")
    CMD("upt",use_table,"\t Use pio table 0=FB32 1=NANO 2=MINI")
    CMD("srvch",cmd_svrch,"\t Set Servo Channel 0-7")
    CMD("sp",cmd_servo_pos,"\t Position servo ms ESC to stop")
    CMD("play",cmd_play,"\t Play a song ESC to stop")
    CMD("rgb",cmd_rgb,"\t rgb rr bb gg in hex")
END_CMD_TABLE()

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



