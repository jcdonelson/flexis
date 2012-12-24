/*
 * loop_stepper_fb32.c
 */

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include <ansi_parms.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "math.h"

#include "ALL.H"

// Prototypes for our functions.
void RTCTickCallback(void);
void setup(void);
void loop(void);
// New line again
int counter = 0;	// Determine when 1/2 a second is up.
int blink_state=0;	// Toggles with XOR
#ifdef BOARD_A
int motor_a_pwm = 10;
int motor_a_dir = 13;
int motor_b_pwm = 9;
int motor_b_dir = 12;
#else
int motor_a_pwm = 3;
int motor_a_dir = 12;
int motor_b_pwm = 11;
int motor_b_dir = 13;
#endif
#define MA_OFF  0x1
#define MA_FWD  0x2
#define MA_REV  0x4
#define MB_OFF  0x10
#define MB_FWD  0x20
#define MB_REV  0x40
#define CLOCKWISE         1
#define CCLOCKWISE         0
const byte fullstep_table[5]=
 {
   4,
    MA_FWD | MB_REV,
    MA_FWD | MB_FWD,
    MA_REV | MB_FWD,
    MA_REV | MB_REV,
    
};
const byte wave_table[5]=
 {
   4,
    MA_FWD | MB_OFF,
    MA_OFF | MB_FWD,
    MA_REV | MB_OFF,
    MA_OFF | MB_REV,
    
};

const byte halfstep_table[9]=
{
   8,
   MA_FWD | MB_FWD,
   MA_FWD | MB_OFF,
   MA_FWD | MB_REV,
   MA_OFF | MB_REV,

   MA_REV | MB_REV,
   MA_REV | MB_OFF,
   MA_REV | MB_FWD,                                                                 
   MA_OFF | MB_FWD,
   
};
const byte halfstep_table2[9]=
{
   8,
   MA_FWD | MB_OFF,
   MA_FWD | MB_FWD,
   MA_OFF | MB_FWD,
   MA_REV | MB_FWD,

   MA_REV | MB_OFF,
   MA_REV | MB_REV,
   MA_OFF | MB_REV,                                                                 
   MA_FWD | MB_REV,
   
};

int speed = 8;
int state = 1;
int direction = CCLOCKWISE;
byte const* table = &fullstep_table[0];
int step_counter=0;
int  sleep_counter = 0;
void RTCTickCallback(void)
{
    ++counter;		// Increment the 1 ms counter.
    if( speed == 0)
    {
      digitalWrite(motor_a_pwm,0);
      digitalWrite(motor_b_pwm,0);
      counter = 0;
    
    }
    else
    if(counter >= speed )	// 
    {
      --step_counter;
        counter = 0;            // reset the counter so we start over
        if( table[state] & MA_OFF ) 
        {
          digitalWrite(motor_a_pwm,0);
        }
        else
          digitalWrite(motor_a_pwm,1);
        
        if( table[state] & MA_FWD )
            digitalWrite(motor_a_dir,1);
        else    
          digitalWrite(motor_a_dir,0);

        if( table[state] & MB_OFF )
          digitalWrite(motor_b_pwm,0);
        else
          digitalWrite(motor_b_pwm,1);
        
        if( table[state] & MB_FWD )
            digitalWrite(motor_b_dir,1);
        else    
          digitalWrite(motor_b_dir,0);
        
        if( CLOCKWISE == direction)
          {
              ++state;
              if( state == (table[0]+1))
                {
                  state = 1;
                  
                }
          }
        else
          {
            --state;
            if(0 == state )
              {
                state = table[0];
               
              }
          }
    }
    
    if( step_counter == 0)
      {
        
        speed = 0;
        counter = 0;
        digitalWrite(motor_a_pwm,0);
        digitalWrite(motor_b_pwm,0);
         
      }
    if(sleep_counter > 0)
      --sleep_counter;
}
#define MODE_STEP   0
#define MODE_SLEEP  1
#define MODE_STOP   2
int mode = MODE_STEP;
int steps = 80;
int sleep_time = 200;
int run_speed = 5;
void setup(void)
{
    // Initialize the LED pin to output.
    pinMode(motor_b_dir,OUTPUT);
    pinMode(motor_b_pwm,OUTPUT);
    pinMode(motor_a_dir,OUTPUT);
    pinMode(motor_a_pwm,OUTPUT);
    
    // 0 turns the LED on.
    digitalWrite(motor_b_pwm,0);
    digitalWrite(motor_a_pwm,0);
    RTCSetPeriod(250);
    LCDInit(20,4);
    KPADInit();
    LCDClear();
    LCDWriteLine("*** Ready ***", 0);
    LCDWriteLine("A=st B=sp C=sl D=md", 2);
    speed = run_speed;
    step_counter = steps;

    
}
void  keybrdCmd(char *lcd_msg);
void loop(void)
{
  char c;
  static char lcd_msg[20];
  static byte lcd_index = 0;

  if(KPAD_NOCHAR != (c = KPADReadChar()))
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
  if( MODE_STEP == mode && 0 == step_counter )
    {
      mode = MODE_SLEEP;
      sleep_counter = sleep_time;
      direction ^= 1;
      
    }
  if( MODE_SLEEP == mode && 0 == sleep_counter )
    {
      mode = MODE_STEP;
      step_counter = steps;
      speed = run_speed;
    }
 
  
  
}
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
	char dbuffer[20];
	
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
