/*
 * loop_dual_servo_fb32.c
 *  $Rev:: 107                       $:
 *  $Date:: 2011-06-11 16:40:15 -040#$:
 *  $Author:: jcdonelson             $:
 *  This code is licensed under GPL, any version.
 */

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include <ansi_parms.h>
#include <stdio.h>
#include <string.h> 
#include <ctype.h>
#include <stdlib.h>
#include "math.h"

#include "ALL.H"
#include "CONFIG.H"
#include "STEPPER.H"
#include "CONSOLE.H"
#include "SHELL.H"
#include "MCURESETCF.H"
#include "ENCODER.H"
#include "SERVOMOTOR.H"
#include "PWRMAN.H"

#define RUGGED_LED1			16			// A2
#define RUGGED_LED2			17			// A3
#define RUGGED_LED3			9			// A2
#define RUGGED_LED4			10			// A3
#define RUGGED_LED3_PWM		4
#define RUGGED_LED4_PWM		5

#define RUGGED_MOTOR1_PWM		0   // Analog 0 (D3)
#define RUGGED_MOTOR1_DIR       12 // D13
#define RUGGED_MOTOR2_PWM		5   // Analog 5 (D10)
#define RUGGED_MOTOR2_DIR		13  // D13


#define USE_PWM  	1
#define BOARD_A    	0

#define STEPPER		0
#define SERVO 		1
#define RCSERVO     0

// Stepper motor states.
#define MODE_STEP   0
#define MODE_SLEEP  1
#define MODE_STOP   2
#define MODE_INDEX  3
#define MODE_SEEK	4
int mode = MODE_STOP;
#define ENCODER_PORT1   1
#if ENCODER_PORT1  == 0
#define PIN_ENCODER_A     	5
#define PIN_ENCODER_B     	6
#else
#define PIN_ENCODER_A     	9
#define PIN_ENCODER_B     	10
#endif
#define PIN_INDEX			10
void CheckAtTarget();
byte direction = STEPPER_CCLOCKWISE;
//byte const* table = &fullstep_table[0];
//byte state = 1;
ENCODER encoder1 ={3,9,4,10,ENCODER_UNUSED,500,5000};
ENCODER encoder2 ={1,5,2,6,ENCODER_UNUSED,500,5000};
SERVOMOTOR servo1={RUGGED_MOTOR1_PWM,RUGGED_MOTOR1_DIR,0,&encoder1};		
SERVOMOTOR servo2={RUGGED_MOTOR2_PWM,RUGGED_MOTOR2_DIR,0,&encoder2};		
SERVOMOTOR* _motors[]={
		&servo1,
		&servo2,
		0
};
byte  nMotors = (sizeof(_motors)/sizeof(SERVOMOTOR*));
void InitServos();
void AllServosOff();
void InitServos()
{
	int i;
	for( i = 0 ; _motors[i] ; ++i)
	{
		SERVOMOTORInit(_motors[i]);
	}
}
void AllServosOff()
{
	int i;
	for( i = 0 ; _motors[i] ; ++i)
	{
		SERVOMOTORSetSpeed(_motors[i],0);
	}
	
}
int steps = 1000;
int sleep_time = 100;
int run_speed = 12;
int step_counter=0;
int sleep_counter = 0;
int speed = 80;
int encoder_position = 5000;
int target_position=0;

dword indexCounter=0;



extern byte _console_kbhit(byte port);
extern byte _console_ReadChar(byte port );
extern byte _console_WriteChar(byte port, byte c);
void STEPPERSeekPosition(int target);
#define SPORT  SCI1
byte conbuffer[81*4];
HCONSOLE _console_data={SPORT,&conbuffer[0],30,4,
		CONSOLE_FLAG_ECHO|CONSOLE_FLAG_SEND_NEWLINE|CONSOLE_FLAG_FILTER_ANSI_ESC,
		// Provided functions...
		_console_kbhit,  
		_console_ReadChar,
		_console_WriteChar,
		CTRL_Z  // Must be 0 if not using...
};

#define CONSOLE_PROMPT "FB>"
extern HSHELL hShell;
byte Index(char* cmd);
byte Speed(char* cmd);
byte StepperDirection(char* cmd);
byte Step(char* cmd);
byte help(char* cmd);
byte uecho(char* cmd);
byte Seek(char* cmd);
byte Setp(char* cmd);
byte Position(char* cmd);
byte DisplayEncoder(char* cmd);
byte SetPwmDutyCycle(char* cmd);
byte ResetMCU(char* cmd);
byte ServoDirection(char* cmd);
byte ServoMotorsOff(char*);

SHELL_CMD_DECODER _cmds[]={
		{"help",help,"Display help"},
		{"reset",ResetMCU,"Reset MCU"},
		{"index",Index,"Seek index"},
		{"speed",Speed,"Set speed"},
		{"dir",StepperDirection,"Set direction 0/1"},
		{"step",Step,"Take n steps if n<0 reverse direction"},
		{"seek",Seek,"Seek to position n"},
		{"setp",Setp,"Set current position to n"},
		{"pos",Position,"Show Current position"},
		{"lpos",DisplayEncoder,"Loop on showing Current position"},
		{"pwm",SetPwmDutyCycle,"Channel 0 or 1 0-100"},
		{"off",ServoMotorsOff,"Set duty cycle to 0"},
		{"pdir",ServoDirection,"Motor 0/1 dir 0/1"},
		
		0
};
HSHELL hShell = {
		(SHELL_CMD_DECODER*) &_cmds[0],
		"SH>",
		&_console_data
		
};
// Prototypes for our functions.
void RTCTickCallback(void);
void setup(void);
void loop(void);

// New line again
int counter = 0;	// Determine when 1/2 a second is up.
int blink_state=0;	// Toggles with XOR
// This is for the red board.
#if BOARD_A == 1
int motor_a_pwm = 10;
int motor_a_dir = 13;
int motor_b_pwm = 9;
int motor_b_dir = 12;
#else
#if USE_PWM == 1
byte motor_a_pwm = 0;		// ENABLE 1 Analog 0
byte motor_a_dir = 12;		// DIRECTION 1 
byte motor_b_pwm = 5;		// ENABLE 2  Analog 5
byte motor_b_dir = 13;		// DIRECTION 2
#else
// This is for the Rugged AD-030
byte motor_a_pwm = 3;		// ENABLE 1 Analog 0
byte motor_a_dir = 12;		// DIRECTION 1 
byte motor_b_pwm = 11;		// ENABLE 2  Analog 5
byte motor_b_dir = 13;		// DIRECTION 2
#endif
#endif
#if USE_PWM == 1
STEPPER_CONTROL step_contol={
		STEPPER_CCLOCKWISE
		,&halfstep_table2[0] //&fullstep_table[0]
	    ,motor_a_pwm,
	    motor_a_dir,
	    motor_b_pwm,
	    motor_b_dir
	    ,STEPPER_MODE_EN_DIR | STEPPER_MODE_USE_PWM
	    
};
#else
STEPPER_CONTROL step_contol={
		STEPPER_CCLOCKWISE
		,&halfstep_table2[0] //&fullstep_table[0]
	    ,motor_a_pwm,
	    motor_a_dir,
	    motor_b_pwm,
	    motor_b_dir
	    ,STEPPER_MODE_EN_DIR ,
	    1000
};
#endif

void STEPPERSeekPosition(int target)
{
	CLI();
	target_position = target;
	if(target_position > encoder_position)
		STEPPERSetDirection(STEPPER_CCLOCKWISE,&step_contol);
	else
		STEPPERSetDirection(STEPPER_CLOCKWISE,&step_contol);
	mode = MODE_SEEK;
	STI();
	
}

int pulse = 1000;
void RTCTickCallback(void)
{
	++counter;
#if RCSERVO == 1	
	if(counter == 200)
	{
		counter = 0;
		singleshotPulse(0, pulse);
	}
#endif	
#ifdef TEST_TIME
	digitalWrite(10, digitalRead(10) ^ 1);
	return;
#endif
#if STEPPER == 1	
	if(mode ==  MODE_SLEEP )
	{
		// If we are in sleep mode, decrement the sleep counter.
	    if(sleep_counter > 0)
	      --sleep_counter;
		STEPPERStop(&step_contol);
	    return;
		
	}
    ++counter;		// Increment the 1 ms counter.
	if( mode == MODE_STOP )
	{
		if( counter > 24)
		{
			//STEPPERStep(&step_contol);
			STEPPERStop(&step_contol);
			counter = 0;
		}
		return;
	}
    if( mode == MODE_INDEX && indexCounter >= 1 )
    {
		STEPPERStop(&step_contol);
		encoder_position = 5000;
		mode = MODE_STOP;
    	return;
    	
    }
    CheckAtTarget();
    if( speed == 0) 
    {
    	counter = 0;
    	STEPPERStop(&step_contol);
    	return;
    
    }
    else if(counter >= speed )
    { 	
    	counter = 0;  
    	if( mode != MODE_STOP)
    	 STEPPERStep(&step_contol);
    	if( mode == MODE_STEP)
    	{
			--step_counter;
			if(step_counter <= 0 )
			{
				mode = MODE_SLEEP;
				//STEPPERStop(&step_contol);
			}
    	}
    }
#endif
}

byte Index(char* cmd)
{
	cmd;
	 CLI();
	STEPPERStop(&step_contol);
	indexCounter = 0;

	mode = MODE_INDEX;
	STI();
	printf("Moving to index speed =  %d direction = %d \r\n",speed,direction);
	printf("position=%d speed =  %d direction = %d index=%d \r\n",
			encoder_position,speed,direction,digitalRead(PIN_INDEX));
	return 0;
}
char* dummy[80];
byte Speed(char* cmd)
{
	sscanf(cmd,"%s %d",dummy,&speed);
	printf("Speed set to: %d\r\n",speed);
	return 0;
}
byte Position(char* cmd)
{
	cmd;
	printf("Position: %d\r\n",encoder_position);
	return 0;
}
byte StepperDirection(char* cmd)
{
	int direction;
	sscanf(cmd,"%s %d",dummy,&direction);
	printf("Direction set to: %s\r\n",(direction == 1) ? "CLW" : "CCLW");
	CLI();
	switch(direction)
	{
	case 0:
		STEPPERSetDirection(STEPPER_CCLOCKWISE,&step_contol);
		break;
	case 1:
		STEPPERSetDirection(STEPPER_CLOCKWISE,&step_contol);
		break;
	default:
		;
	}
	STI();
	return 0;
}

byte Step(char* cmd)
{
	int steps;
	sscanf(cmd,"%s %d",dummy,&steps);
	if( steps < 0)
	{
		step_contol.direction ^= 1;
		steps *= -1;
	}
	printf("Taking %d steps\r\n", steps);
	CLI();
	step_counter = steps;
	mode = MODE_STEP;
	STI();
	return 0;
}
byte Seek(char* cmd)
{
	int p;
	sscanf(cmd,"%s %d",dummy,&p);
	STEPPERSeekPosition(p);
	printf("Seeking to target = %d  position=%d speed =  %d direction = %d index=%d \r\n",
			p,encoder_position,speed,direction,digitalRead(PIN_INDEX));

}

byte Setp(char* cmd)
{
	int p;
	sscanf(cmd,"%s %d",dummy,&p);
	encoder_position = p;
	

}
#define SECONDS_PER_MIN   60
byte DisplayEncoder(char* cmd)
{
	int p;
	int p2;
	long t1 = -1000;
	cmd;
	printf("Any key to quit\r\n");
	do {
	if((millis() - t1) >= 1000 )
	{
		// These are 1000 CPR
		int diff = abs(ENCODERGetPosition(&encoder1) - p);
		int rpm = (diff*SECONDS_PER_MIN)/(ENCODERGetCPR(&encoder1)*2);
		p = ENCODERGetPosition(&encoder1);
		printf("\r                                                                         ");
		printf("\r\t 1=%05d RPM=%d d=%03d",p,rpm,diff);
		
		
		rpm = (abs(ENCODERGetPosition(&encoder2) - p2)*60)/1000;
		p2 = ENCODERGetPosition(&encoder2);
		printf(" 2=%05d RPM=%d",p2 ,rpm);
		
	   t1 = millis();
	}
	
	
	} while(!_console_kbhit(SPORT));
	printf("\r\n");
	_console_ReadChar(SPORT);
	

}
void SeekIndex(void);
void SeekIndex(void)
{
	++indexCounter;
    if( MODE_INDEX == mode)
    {
    	mode = MODE_STOP;
    	//STEPPERStop(&step_contol);
    	encoder_position = 5000;
    }
}
#ifdef NO_USED
int edges=0;
int edges2=0;
void edgePhaseBCallback(void);
void edgePhaseACallback(void);
//
// STEPPER_CCLOCKWISE motion increases counts.
//
// Pin 5 is edge callback2
// Encoder phase A.
// interrupt 2 is pin 6, PTF1
void CheckAtTarget()
{
    if( MODE_SEEK == mode)
    {
    	if(step_contol.direction == STEPPER_CCLOCKWISE )
    	{
    		if(encoder_position < target_position)
    		{
    			return;
    		} 
    	}
    	else if(encoder_position > target_position)
    	{
    		  return;
    		
    	}
    }	
    else
    	return;
	 mode = MODE_STOP;
	 step_contol.direction ^= 1;
     STEPPERStep(&step_contol);
     
     
	   counter = 0;
	
}
void edgePhaseBCallback(void)
{
	++edges;
	
	if( digitalRead(PIN_ENCODER_A))
	{
		 ++encoder_position;
	}
	else
	{
		--encoder_position;
	}
	
	CheckAtTarget();
}
// Encoder Phase B. interrupt callback
/*
 * 
 */
void edgePhaseACallback(void)
{
	++edges2;
	
	if( digitalRead(PIN_ENCODER_B))
	{
		 --encoder_position;
	}
	else
	{
		++encoder_position;
	}
	CheckAtTarget();
}


#endif
int avalue = 255;

void setup(void)
{
	word count;
	char msg[80];
	step_counter=0;
	sleep_counter = 0;
	speed = 8;
	encoder_position = 5000;
	target_position=0; 
	indexCounter=0;
	SetSTOPMode(STOP3);
//	 RTCSetPeriod(RTC_1MS);
	 RTCSetPeriodLPO(0);
	 EnableInterrupts;


//    pinMode(RUGGED_LED2,OUTPUT);
//   pinMode(RUGGED_LED1,OUTPUT);    
//   pinMode(RUGGED_LED3,OUTPUT);
//   pinMode(RUGGED_LED4,OUTPUT);
//    digitalWrite(RUGGED_LED2,0);
//    digitalWrite(RUGGED_LED1,0);
 //   digitalWrite(RUGGED_LED3,1);
  //  digitalWrite(RUGGED_LED4,1);
 //   analogWrite(RUGGED_LED3_PWM,PWM_MAX/8);
    
#if STEPPER == 1 
    STEPPERInit(&step_contol);
    STEPPERStop(&step_contol); 
    speed = run_speed;
    step_counter = steps;
    ENCODERInit(&encoder1);
    // 4 is pin 10, index pulse
 	attachInterrupt(4,SeekIndex,RISING);

    
#endif
#if SERVO == 1
   
/*    pinMode( motor_a_dir,OUTPUT);
    pinMode( motor_b_dir,OUTPUT);
    analogWrite(motor_a_pwm,PWM_MAX/2);
    analogWrite(motor_b_pwm,PWM_MAX/2);
*/
    ENCODERInit(&encoder1);
    ENCODERInit(&encoder2);
    InitServos();
    SERVOMOTORSetSpeed(&servo1,0);
    SERVOMOTORSetSpeed(&servo2,0);

#endif
#if RCSERVO == 1
    singleshotPulse(0, 1000);
#endif    
   
    LCDInit(20,4);
    KPADInit();
    LCDClear();
    LCDWriteLine("'*' = Do Command.", 0);
    LCDWriteLine("", 1);
    LCDWriteLine("A=st B=sp C=sl D=md", 2);
   
    //pinMode(9,INPUT);
#ifdef NOT_USED    
    // Init for encoder.
    pinMode(PIN_ENCODER_A,INPUT);
    pinMode(PIN_ENCODER_B,INPUT);
    //pinMode(PIN_INDEX,INPUT);
    
    // Set up encoder interrupts.
#if ENCODER_PORT1 == 0    
	// 1 is pin 5
	attachInterrupt(1,edgePhaseACallback,RISING);
	// interrupt 2 is pin 6, PTF1
	attachInterrupt(2,edgePhaseBCallback,RISING);
#else	
    // 3 is 9
    attachInterrupt(3,edgePhaseACallback,RISING);
    // 4 is 10
    attachInterrupt(4,edgePhaseBCallback,RISING);
#endif    
#endif
    
    
 	
   //EnableInterrupts;
   Serial_Init(SPORT);
   Serial_setbaudrate(SPORT,BAUD_115200);
   SetActiveConsole(SCI1_CONSOLE);


   
   
   printf("\r\nReset source = %s %x \r\n",MCUGetResetString(),SRS);
   CONSOLEWritestring(&_console_data,msg);
   
   CONSOLEWritestring(&_console_data,"\r\n\n*** Ready ***\n\r");
   // Enable printf to Serial port 1.
   
   do
   {
	   Serial_txlen(0, &count); 
   } while(count);
   //DisableInterrupts;
   
 
   
   //CONSOLEWritestring(&_console_data,CONSOLE_PROMPT);
     
}
void  keybrdCmd(char *lcd_msg);

void loop(void)
{
  char c;
  static char lcd_msg[20];
  static byte lcd_index = 0;
  //return;
  //powerModulesDown(0xFFFF & (~P_RTC));
 // asm { stop #0 }
  /*
  byte rc = CONSOLEReadkey(&_console_data);
  
  if(ERROR_CONSOLE_LINE_READY == rc )
  {
	  CONSOLEWritestring(&_console_data,_console_data.inputbuffer);
	  CONSOLEWritestring(&_console_data,"\r\n");
	  
	  CONSOLEWritestring(&_console_data,CONSOLE_PROMPT);
  }
  */
  SHELLProcessInput(&hShell); 
  
 
  if(KPAD_NOCHAR != (c = KPADReadChar()) )
  {
    //LCDClear();
	 
		  
     if( lcd_index < sizeof(lcd_msg) - 1)
       lcd_msg[lcd_index++] = c;
     else
     {
         lcd_index = 0;
         lcd_msg[lcd_index++] = c;
         
     }
     lcd_msg[lcd_index] = 0;
     LCDWriteLine(lcd_msg, 1);
     if( c == '*')
     {
          keybrdCmd(lcd_msg);
          lcd_index=0;
          lcd_msg[0]=0;
          LCDWriteLine(lcd_msg, 1);
          
     }
           
    
  }
  /*
  if( MODE_STEP == mode && 0 == step_counter )
    {
      mode = MODE_SLEEP;
      CLI();
      sleep_counter = sleep_time;
      direction ^= 1;
      STEPPERSetDirection(STEPPERGetDirection(&step_contol)^1,&step_contol);
      STI();
      
    }
  if( MODE_SLEEP == mode && 0 == sleep_counter )
    {
      mode = MODE_STEP;
      CLI();
      step_counter = steps;
      speed = run_speed;
      STI();
    }
 */
  
  
}
void LoadStepPattern();
void LoadStepPattern()
{
	if( 0 == steps || 0 == run_speed)
	{
        mode = MODE_STOP;
        speed = 0;
		
	}
	else
	{
		mode = MODE_STEP;
		step_counter = steps;
		speed = run_speed;
	}
}
void  keybrdCmd(char *lcd_msg)
{
	int v;
	int c;
	char dbuffer[128];
	
	sscanf(lcd_msg,"%c%d",&c,&v);
	switch(lcd_msg[0])
	{
	case 'A':
		steps = v;
        LoadStepPattern();
		break;
	case 'B':
		run_speed = v;
		LoadStepPattern();
		break;
	case 'C':
		sleep_time = v;
		break;
	default:
		LCDWriteLine("Bad cmd A,B,C,Dn *", 0);
	}
    sprintf(dbuffer,"st=%d sp=%d sl=%d",steps,run_speed,sleep_time);
    LCDWriteLine(dbuffer, 3);
}

/*
 * Console adaptors for the flexis framework
*/
/*
 * byte _console_kbhit(byte port)
 * Return 'true' if key waiting.
 */
byte _console_kbhit(byte port)
{
	word count;
	Serial_rxlen( port, &count);
	return (byte) count;
}
/*
 * 
 */
byte _console_ReadChar(byte port )
{
	byte data;
	Serial_rxbyte(port, &data);
	return data;
}
byte _console_WriteChar(byte port, byte c)
{
	word sent;
	while( TX_FULL == Serial_txbuf( port,&c, 1, &sent) )
			;
	return 0;
}
