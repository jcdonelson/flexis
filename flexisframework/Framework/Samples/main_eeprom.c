///////////////////////////////////////////////////////////////////////
//
// Framework Unit Test 1
// Jim Donelson 10/10
//
///////////////////////////////////////////////////////////////////////

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include <stdio.h>
#include <ansi_parms.h>
#include "ALL.H"
void EdgeCallBack(void);
void SetLeds(byte data);
void  RTC_handler(void);
void SendString(char *s);
int out_test_pin = 19;
int in_test_pin = 13;
int serial_port = SCI1;


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
 int blink_state = 1;
 // 1MS tick. 
 int freq_counter = 0;
int last_count = 0;
int one_sec_counter = 0;
 void  RTC_handler(void)
{
	volatile int read_data;
	volatile byte c;
	//SongRTCCallback();
    //read_data = analogRead(7);
    //c =  ScanKeyboard();
    ++one_sec_counter;
    //digitalWrite(out_test_pin, read_data);
    blink_state ^= 1;
    ++pwm_counter;
   // digitalWrite(13,blink_state);
    if( pwm_counter == 5)
    {   pwm_counter = 0;
    	//pulseOut(8,5000,5);
    }
  --UserDelay;
  
 
  ++time_counter;
  if( 1000 == time_counter ) 
  {
	  //STI();
      time_counter = 0;
      last_count = freq_counter;
     freq_counter = 0;
      //CLI();
    
  }
}
 typedef int (*pfn)(int a,int b, int c, int d, int e);
 
int TestFunction(int a, int b, int c, int d, int e)
{
	int rc = 0;
	if( a == 5)
		rc = 10;
	else if(b == 6)
		rc = 3;
	rc = rc + a + b + c + d + e;
	return rc;
}
 volatile pfn callf = TestFunction;
 interrupt VectorNumber_Vtrap0  void TRAP_0(void)
 {
	 dword s,p0,p1,p2;
		asm {
			move.l D0,s
			move.l D1,p0
			move.l D2,p1
			move.l D3,p2
		}
	 
 }

int SERVICE_0(dword s,dword param0,dword param1,dword param2)
{
	asm {
		move.l param0,D1
		move.l param1,D2
		move.l param2,D3
		trap #0
	}
	return 0;
}
void SendString(char *s) 
{
   while(*s) 
   {
//       while(TX_FULL == SCI1_TXByte(*s) )
 //           ;
       while(TX_FULL == Serial_txbyte(serial_port,*s))
       ;
       ++s;
   }
}
long last_time =0;
long difference = 0;
void EdgeCallBack(void)
{
	long now = micros();
	difference = now - last_time;
	++freq_counter;
	last_time = now;
/*	
	if(freq_counter == 1000)
	{
		freq_counter = 0;
		blink_state ^= 1;
		digitalWrite(13,blink_state);
	}
*/
}
volatile byte rc;
char buffer[80];
char message[] ="Testing 1 2 3!";
volatile int j=0;
extern void asm_function(int a);
byte motor_dir = 1;
byte motor_speed = 255;
#define I2C_EEPROM_ModuleAddress 0xA4
byte I2C_SendBuffer[34];
byte I2C_ReadBuffer[34];
word write_address= 0;
EEPROM_WRITE_BLOCK eeprom_write_data;
void SetSendData(word address,byte data)
{
	int i;
	I2C_SendBuffer[0] = (byte)(address>>8);
	I2C_SendBuffer[1] = (byte)(address & 0xFF);
	for( i = 2 ; i < 34 ; ++i)
	{
		I2C_SendBuffer[i] = data;
	}
}
void SetSendDataEx(EEPROM_WRITE_BLOCK* eeprom_write_data,word address,byte data)
{
	int i;
	eeprom_write_data->address = address;
	for( i = 0 ; i < 32 ; ++i)
	{
		eeprom_write_data->data[i] = data;
	}
}
static word sent;
byte I2CStatus = 0;
void main(void) 
{
 
 volatile int i = 0;
	byte rxdata;
	byte txtest = 0;
	
	SOPT1 = 0x10; // Disable watch dog.
	rxdata ^= 3;
	rc = 0xf3;
//	asm_function(3);
	asm {
		
		
		move.l #0x40000000,D0
		movec D0,cpucr
		clr D0
		cmpi.b #45,D0
		move.b rc,D0
		move.b #0b10101110,D0
		FF1 D0
		lea rc,A0
		move.b (A0),D1
		cmpa #rc,A0
		beq LABEL1
		nop
LABEL1:		
		
		
	}
	rc = callf(1,2,5,23,13);
	rc = callf(3,7,9,6,99);
	//i = 4/j;
	InitCLOCK();
	SetRTCUserCallback(RTC_handler);
	InitTPM1Counter();
	pinMode(8,OUTPUT);
	digitalWrite(8,0);
	InitPulse();
	InitLCD(8);
	Serial_Init(0);
//	printf("Testing 1 2 3! %d  \n", CONSOLE_SCI);
	SERVICE_0(0x1f1f1f,0x1111111,0x22222222,0x33333333);
	
	EnableInterrupts; /* enable interrupts */
	
	InitRTC();
	I2CInit();
	I2CSetDeviceAddress(I2C_EEPROM_ModuleAddress);
	
	WriteLineLCD("                ", 1);
	WriteLineLCD("Starting  ", 0);
	WriteLineLCD("Count    ", 1);
//	InitEdgeInterrupt();
//	attachInterrupt( 0, EdgeCallBack, RISING_EDGE);
	/* include your code here */
//	pulseOut(8,1000000,0);
	pinMode(13,OUTPUT);
	digitalWrite(13,1);
	pinMode(4,OUTPUT);
	digitalWrite(4,1);
	pinMode(12,OUTPUT);
	digitalWrite(12,1);
	pinMode(13,OUTPUT);
	digitalWrite(12,0);
	//pinMode(3,OUTPUT);
	//digitalWrite(3,1);
	analogWrite(3,motor_speed);
    for(;;) {
	  char c;
	  char lcd_msg[16]; 
	  byte lcd_index = 0;
	  /*
	 if( pwm_counter == 0)
	 {
		 pulseOut(8,5000,5);
	 }
	 */
	  if( one_sec_counter > 1000)
	  {
		  motor_dir  ^= 1;
		  if(1 == motor_dir  )
		  {
		  if(motor_speed == 0)
			  motor_speed = 255;
		  motor_speed -= 16;
		  analogWrite(3,motor_speed);
		  }
		  if (motor_dir )
		  {
				digitalWrite(12,1);
				digitalWrite(13,0);
			  
		  }
		  else
		  {
				digitalWrite(12,0);
				digitalWrite(13,1);
			  
		  }
		  int l;
		  //pulseOut(8,1000000,5);
		  //STI();
		  l =last_count;
		  //CLI();
		  sprintf(buffer,"%d        ",l);
			SendString(buffer);
			SendString(" Hertz\r\n");
			WriteLineLCD(buffer, 0);
			sprintf(buffer,"%ld",difference);
			WriteLineLCD("        ", 1);
			WriteLineLCD(buffer, 1);
			SendString(buffer);
			SendString(" uSecs\r\n");
			//WriteLineLCD("Hertz       ", 1);
			one_sec_counter = 0;
			
			//I2CStatus = I2CGetLastError();
			SetSendDataEx(&eeprom_write_data, write_address,(byte) write_address);
			WriteEEPROMBlock((byte *)&eeprom_write_data,0);
			ReadEEPROMBlock(write_address, &I2C_ReadBuffer[0],32);
			write_address += 32;
			if( write_address >= 0x1FFF)
				write_address = 0;
			
	  }

	  rc = 2;
	  rc  = Serial_rxbyte(serial_port, &rxdata);
	  Serial_txbyte(serial_port,'A');
      if( 0 == rc ) 
      {
          (void) Serial_txbyte(serial_port,rxdata);
          if( rxdata == '\r' )
        	  (void) Serial_txbyte(serial_port,'\n');
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
