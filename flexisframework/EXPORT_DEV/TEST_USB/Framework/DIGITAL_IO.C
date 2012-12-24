/*
 * DIGITAL_IO.C
 * 
 * Most of the I/O functionality is here.
 * 
 *  $Rev:: 71                        $:
 *  $Date:: 2011-05-21 21:12:31 -040#$:
 *  $Author:: jcdonelson             $:
 *  This code is licensed under GPL, any version.
 */
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "../Headers/DIGITAL_IO.H"
#include "CONFIG.H"
void CLI(void);
void STI(void);
void ClearPin(int pin);
void ChannelInterruptHandler(byte ch);
extern void EdgeCallBack(void);
static void  PWMSetDutycycle( byte channel, word duty);
void  InitPWM(byte channel);
void ChannelSingleShotHandler(byte ch);
extern void InitTPM1Counter(void);
void SendPulse(byte ch, dword length);
extern word timer_modulus;

/*
 * Defines and Macros.
 */
#define BIAS_FACTOR  11  // Bits of bias for floating.


#ifndef PWM_MAX
#define PWM_MAX 256
#endif
#if CLK12MHZ_XTAL == 1
#define US_TO_TICKS_11 (dword)(24.0F * (1 <<11))
#define US_TO_TICKS_8 (dword)(24.0F * (1 <<8))
#else
#define US_TO_TICKS_11  (long long)(25.165824D * (1 <<16)) // 25.165824
#define US_TO_TICKS_8  	(dword)(25.165824F * (1 <<8)) // 25.165824
#endif
long long  us_to_ticks_11 = US_TO_TICKS_11;
long long  int_overhead_correction = (long long)(2.920F * (1<<16));
dword us_to_ticks_8 = US_TO_TICKS_8;

#define MODE_PWM 	0x10



#define GET_FLAGS(a) (a & 0xf)
#define GET_CHANNEL(a)((byte)(a >> 4) & 0xf)

//typedef void(*PFNCALLBACK)(void);
// Port I/O configuration.
typedef struct _pio 
{
	volatile byte* direction_register; 	// Address of Direction Register.
	volatile byte* data_register;      	// Address of Data Register.
	byte bit;                          	// Bit mask in port.
	byte flags;							// upper nibble determines if is a PWM or ADC pin, lower nibble is channel #
	volatile byte* pu_register;      	// Address of Pull-Up Register.
	volatile byte* ds_register;      	// Address of Drive Strength Register.
	volatile byte* sr_register;      	// Address of Slew Rate Register.
	volatile byte* fe_register;      	// Address of Filter Enable.
} PIO;
typedef struct _pioconfig {
	byte config;                       	// How it was configured.
	
} PIOCONFIG;
/*
 * Internal variables
 */
#ifndef ADC_BITS
#define ADC_BITS   12
#endif
static byte PWM_InitFlag = 0;
static dword pwm_scaler = 24000;
static word ADC_shift = 12 - ADC_BITS;
static byte analog_pin_selects=255;
static dword TPM1ChannelControl[6];
static PFNCALLBACK EdgeInterruptHandlers[9];
static byte init=0;
#define MINI   1
#ifndef MCU_HCS08
#define MCU_HCS08     0
#endif
#if MCU_HCS08 == 0
const IOREGS ioregisters[]={
{&PTADD,&PTAD,&PTAPE,&PTASE,&PTADS,&PTAIFE},		
{&PTBDD,&PTBD,&PTBPE,&PTBSE,&PTBDS,&PTBIFE},		
{&PTCDD,&PTCD,&PTCPE,&PTCSE,&PTCDS,&PTCIFE},		
{&PTDDD,&PTDD,&PTDPE,&PTDSE,&PTDDS,&PTDIFE},		
{&PTEDD,&PTED,&PTEPE,&PTESE,&PTEDS,&PTEIFE},
{&PTFDD,&PTFD,&PTFPE,&PTFSE,&PTFDS,&PTFIFE},
{&PTGDD,&PTGD,&PTGPE,&PTGSE,&PTGDS,&PTGIFE},
{&PTHDD,&PTHD,&PTHPE,&PTHSE,&PTHDS,&PTHIFE},
};
#else
const IOREGS ioregisters[]={
{&PTADD,&PTAD,&PTAPE,&PTASE,&PTADS},		
{&PTBDD,&PTBD,&PTBPE,&PTBSE,&PTBDS},		
{&PTCDD,&PTCD,&PTCPE,&PTCSE,&PTCDS},		
{&PTDDD,&PTDD,&PTDPE,&PTDSE,&PTDDS},		
{&PTEDD,&PTED,&PTEPE,&PTESE,&PTEDS},
{&PTFDD,&PTFD,&PTFPE,&PTFSE,&PTFDS},
{&PTGDD,&PTGD,&PTGPE,&PTGSE,&PTGDS},

};
#endif	


const IOPIN _baseiop_fb32[]={
		{D_PORTE,BIT2},// Shield 0 PTE1 TX
		{D_PORTE,BIT0},// Shield 1 PTE0 RX
		{D_PORTG,BIT3},// Shield 2 PTG3
		{D_PORTE,BIT2},// Shield 3 PTE2 TPM1CH0
		{D_PORTD,BIT2},// Shield 4 PTD2
		{D_PORTE,BIT3},// Shield 5 PTE3 TPM1CH1
		{D_PORTF,BIT0},// Shield 6 PTF0 TPM1CH2
		{D_PORTD,BIT1},// Shield 7 PTD1
		{D_PORTF,BIT4},// Shield 8 PTF4 (TPM2CH0)
		{D_PORTF,BIT1},// Shield 9 PTF1 TPM1CH3
		{D_PORTF,BIT2},// Shield 10 PTF2 TPM1CH4
		{D_PORTF,BIT3},// Shield 11 PTF3 TPM1CH5
		{D_PORTE,BIT4},// Shield 12 PTE4
		{D_PORTE,BIT6},// Shield 13 PTE6
		{D_PORTB,BIT0},// Shield 14 PTB0
		{D_PORTB,BIT1},// Shield 15 PTB1
		{D_PORTB,BIT2},// Shield 16 PTB2
		{D_PORTB,BIT3},// Shield 17 PTB3
		{D_PORTB,BIT4},// Shield 18 PTB4
		{D_PORTB,BIT5},// Shield 19 PTB5

		// Bonus pins
		{D_PORTB,BIT6},// Shield 20 
		{D_PORTB,BIT7},// Shield 21 
		{D_PORTG,BIT1},// Pin 22 RGB LED ENABLE (PTG1)
		{D_PORTC,BIT6},// Pin 23 PTC6
		{D_PORTF,BIT7},// Pin 24 PTF7
		{D_PORTD,BIT0},// Pin 25 PTC6		
};

const IOPIN _baseiop1_nano[]={
		{D_PORTB,BIT0},// B0 0 Pin 1
		{D_PORTB,BIT1},// B1 1 Pin 2
		{D_PORTB,BIT2},// B2 2 Pin 3
		{D_PORTB,BIT3},// B3 3 Pin 4
		
		{D_PORTB,BIT4},// B4 4 Pin 6
		{D_PORTB,BIT5},// B5 5 Pin 7
		{D_PORTB,BIT6},// B6 6 Pin 8
		{D_PORTB,BIT7},// B7 7 Pin 9
		
		{D_PORTD,BIT0},// D0 8 Pin 10 
		{D_PORTD,BIT1},// D1 9 Pin 11 
		{D_PORTD,BIT2},// D2 10 Pin 14 
		{D_PORTD,BIT3},// D3 11 Pin 15 
		
		{D_PORTD,BIT4},// D4 12 Pin 16 
		{D_PORTG,BIT3},// G3 13 Pin 17 
		{D_PORTC,BIT0},// C0 14 Pin 18 SCL
		{D_PORTC,BIT1},// C1 15 Pin 19 SDA
		
		{D_PORTC,BIT5},// C5 16 Pin 21
		{D_PORTC,BIT3},// C3 17 Pin 22 
		{D_PORTF,BIT0},// F0 18 Pin 23 PTF0 TPM1CH2
		{D_PORTF,BIT1},// F1 19 Pin 24 PTF1 TPM1CH3 
		
		{D_PORTF,BIT2},// F2 20 Pin 25 PTF2 TPM1CH4
		{D_PORTF,BIT3},// F3 21 Pin 26 PTF3 TPM1CH5
		{D_PORTF,BIT4},// F4 22 Pin 27 PTF4 TPM2CH0
		{D_PORTC,BIT6},// C6 23 Pin 28 
		
		{D_PORTF,BIT7},// F7 24 Pin 29 
		{D_PORTE,BIT0},// E0 25 Pin 30 
		{D_PORTE,BIT1},// E1 26 Pin 31 
		
		{D_PORTE,BIT2},// E2 27 Pin 32 PTE2 TPM1CH0
		
		{D_PORTE,BIT3},// E3 28 Pin 33 PTE3 TPM1CH1
		
		{D_PORTE,BIT4},// E4 29 Pin 34 
		{D_PORTE,BIT5},// E5 30 Pin 35 
		{D_PORTE,BIT6},// E6 31 Pin 36 
		
		{D_PORTE,BIT7},// E7 32 Pin 37 
		
};

const IOPIN _baseiop_mini[]={
{D_PORTE,BIT2}, // Shield 0 PTE1 TX
{D_PORTE,BIT0}, // Shield 1 PTE0 RX
{D_PORTG,BIT3}, // Shield 2 PTG3
{D_PORTE,BIT2}, // Shield 3 PTE2 TPM1CH0
{D_PORTD,BIT2}, // Shield 4 PTD2
{D_PORTE,BIT3}, // Shield 5 PTE3 TPM1CH1
{D_PORTD,BIT0}, // Shield 6 PTD0
{D_PORTD,BIT1}, // Shield 7 PTD1
{D_PORTF,BIT4}, // Shield 8 PTF4 (TPM2CH0)
{D_PORTF,BIT1}, // Shield 9 PTF1 TPM1CH3
{D_PORTE,BIT7}, // Shield 10 PTE7
{D_PORTC,BIT0}, // Shield 11 PTC0 
{D_PORTC,BIT1}, // Shield 12 PTC1
{D_PORTE,BIT6}, // Shield 13 PTE6
{D_PORTC,BIT3}, // Shield 14 PTC3
{D_PORTE,BIT5}, // Shield 15 PTE5
{D_PORTE,BIT4}, // Shield 16 PTE4
{D_PORTC,BIT5}, // Shield 17 PTC5
{D_PORTB,BIT5}, // Shield 18 A0 PTB5
{D_PORTB,BIT4}, // Shield 19 A1 PTB4
{D_PORTB,BIT3}, // Shield 20 A2 PTB3
{D_PORTB,BIT2}, // Shield 21 A3 PTB2
{D_PORTB,BIT1}, // Shield 22 A4 PTB1
{D_PORTB,BIT0}, // Shield 23 A5 PTB0
{D_PORTF,BIT7}, // Shield 24  A5 (PTF7) 
{D_PORTC,BIT6}, // Shield 25 A4  (PTC6)
{D_PORTG,BIT2} // Shield 26 PTG2 EEPROM WP

};
IOPIN const *  _baseiop = &_baseiop_fb32[0];
int MAX_PIN = sizeof(_baseiop_fb32)/sizeof(IOPIN);
const int MINI_MAX = sizeof(_baseiop_mini)/sizeof(IOPIN);
DEFINE_SZ(_baseiop_mini)
const int FB_MAX =  sizeof(_baseiop_fb32)/sizeof(IOPIN);
const int NANO_MAX =  sizeof(_baseiop1_nano)/sizeof(IOPIN);
int setPIOTable(const IOPIN  *piotable, int max)
{
	_baseiop = piotable;
	MAX_PIN = max;
	return 0;
}
static dword round(long long  n,dword bits);
static dword round(long long n,dword bits)
{
	long long  fraction_part = n - ((n >> bits) << bits);
	n >>= bits;  		// Un-bias the value.
	// Now round it.
	if( fraction_part > ((1 << (bits -1))))
		++n;
	return (dword) n;	
}

static volatile byte *TPMChannelStatus[]=
{
		&TPM1C0SC,&TPM1C1SC,&TPM1C2SC,&TPM1C3SC,&TPM1C4SC,&TPM1C5SC//,&TPM2C0SC,&TPM2C1SC
};
static volatile word *TPM1ChannelValue[]=
{
		&TPM1C0V,&TPM1C1V,&TPM1C2V,&TPM1C3V,&TPM1C4V,&TPM1C5V//,&TPM2C0V,&TPM2C1V
};

void pinMode( int pin, int direction)
{
    if( pin > MAX_PIN )
	  return;
    // If this is also an analog pin, take the pin back.
	if(_baseiop[pin].portindex == PORTB)
		APCTL1 &= ~_baseiop[pin].bitno;
	if(_baseiop[pin].portindex == PORTD &&  _baseiop[pin].bitno < BIT5  )
	{ 
		if(_baseiop[pin].bitno < BIT2)
			APCTL2 &= ~_baseiop[pin].bitno;
		else if(_baseiop[pin].bitno > BIT2)
			APCTL2 &= ~(_baseiop[pin].bitno>>1);
	}
		
	if( OUTPUT & direction )
	{
		*ioregisters[_baseiop[pin].portindex].direction |= _baseiop[pin].bitno;
  
	}
	else
	{
		*ioregisters[_baseiop[pin].portindex].direction &=~( _baseiop[pin].bitno);
		*ioregisters[_baseiop[pin].portindex].pullup |= _baseiop[pin].bitno;
	}
		
}
typedef struct _pinmodes {
	int port;
	int bit;
	int function;
	volatile byte *configport;
	int data;
}PINMODES;
#define CLRBIT 1
#define CLRALL 2
#define KBIBIT 4
static const PINMODES pinmodeclear[]= {
	{PORTD,BIT0,CLRBIT,&APCTL2,1}, // ADPC8
	{PORTD,BIT1,CLRBIT,&APCTL2,2}, // ADCP9
	{PORTD,BIT3,CLRBIT,&APCTL2,4}, // ADCP10
	{PORTD,BIT4,CLRBIT,&APCTL2,8}, // ADPC11
#if MCU_HCS08 == 0
	{PORTG,BIT0,CLRBIT,&KBI1PE,1}, // KBI1P0
	{PORTG,BIT1,CLRBIT,&KBI1PE,2}, // KBI1P1
	{PORTG,BIT0,CLRBIT,&KBI1PE,4}, // KBI1P2
	{PORTG,BIT0,CLRBIT,&KBI1PE,8}, // KBI1P3
	{PORTG,BIT0,CLRBIT,&KBI1PE,0x10}, // KBI1P4
	{PORTG,BIT0,CLRBIT,&KBI1PE,0x20}, // KBI1P5
	{PORTG,BIT0,CLRBIT,&KBI1PE,0x40}, // KBI1P6
	{PORTG,BIT0,CLRBIT,&KBI1PE,0x80}, // KBI1P7
#endif	
	{PORTE,BIT2,CLRALL,&TPM1C0SC,0}, // PTE2 TPM1-CH0
	{PORTE,BIT3,CLRALL,&TPM1C1SC,0}, // PTE3 TPM1-CH1
	{PORTF,BIT0,CLRALL,&TPM1C2SC,0}, // PTF0 TPM1-CH2
	{PORTF,BIT1,CLRALL,&TPM1C3SC,0}, // PTF1 TPM1-CH3
	{PORTF,BIT2,CLRALL,&TPM1C4SC,0}, // PTF2 TPM1-CH4
	{PORTF,BIT3,CLRALL,&TPM1C5SC,0}, // PTF3 TPM1-CH5
//	{PORTF,BIT5,CLRALL,&TPM2C0SC,0}, // PTF4 TPM2-CH0
//	{PORTF,BIT5,CLRALL,&TPM2C1SC,0}, // PTF5 TPM2-CH1

	0
};

//{PORT,PIN#,flags,data}
void ClearPin(int pin)
{
	int i;
return;
	// This function removes all secondary flags set for a pin
    // If this is also an analog pin, take the pin back.
	if(_baseiop[pin].portindex == PORTB)
	{
		APCTL1 &= ~_baseiop[pin].bitno;
	}
	 for( i = 0 ; pinmodeclear[i].port ;++i)
	 {
		 if( _baseiop[pin].portindex ==  pinmodeclear[i].port 
			&& 	_baseiop[pin].bitno ==  pinmodeclear[i].bit )
		 {
			 switch( pinmodeclear[i].function)
			 {
			 case CLRALL:
				 *pinmodeclear[i].configport = 0; 
				 break;
			 case CLRBIT:
				 *pinmodeclear[i].configport &= ~pinmodeclear[i].data;
				 break;
			 }
		 }
	 }
	// 
}
void pinModeEx( int pin, int direction)
{
    if( pin > MAX_PIN )
	  return;
    
	
	if( OUTPUT & direction )
	{
		*ioregisters[_baseiop[pin].portindex].direction |= _baseiop[pin].bitno;
	}
	else
	{
		*ioregisters[_baseiop[pin].portindex].direction &=~( _baseiop[pin].bitno);
	}
	if(direction & HI_DRIVE)
	{
		*ioregisters[_baseiop[pin].portindex].drive |= _baseiop[pin].bitno;
	}
	else
	{
		*ioregisters[_baseiop[pin].portindex].drive &= ~_baseiop[pin].bitno;
	}
	if(direction & SLEW_RATE)
	{
		*ioregisters[_baseiop[pin].portindex].slewrate |= _baseiop[pin].bitno;
	}
	else
	{
		*ioregisters[_baseiop[pin].portindex].slewrate &= ~_baseiop[pin].bitno;
	}
	if(direction & PULL_UP)
	{
		*ioregisters[_baseiop[pin].portindex].pullup |= _baseiop[pin].bitno;
	}
	else
	{
		*ioregisters[_baseiop[pin].portindex].pullup &= ~_baseiop[pin].bitno;
	}
	if(direction & INPUT_FILTER)
	{
		*ioregisters[_baseiop[pin].portindex].filter |= _baseiop[pin].bitno;
	}
	else
	{
		*ioregisters[_baseiop[pin].portindex].filter &= ~_baseiop[pin].bitno;
	}
		
}

void digitalWrite( int pin, int value )
{
    if( pin > MAX_PIN )
	  return;
    
    if( value )
    	*_baseiop[pin].data |= _baseiop[pin].bitno;
    else
    	*_baseiop[pin].data &= ~_baseiop[pin].bitno;
	
}
int digitalRead(int pin)
{
    if( pin > MAX_PIN )
	  return -1;
    
    if(*_baseiop[pin].data & _baseiop[pin].bitno )
    	return 1;
    else
    	return 0;	
	
} 
void portModeEx(byte* pins,int direction, int bits)
{
	int i;
	for( i = 0 ; i  < bits ; ++i)
		pinModeEx((int) pins[i], direction);
}
void portWriteEx(byte* pins, int value, int bits)
{
	int i = 0;
	for( i = 0 ; i < bits ; ++i)
	{
		digitalWrite(pins[i], value & 1);
		value >>= 1;
	}
}
int portReadEx(byte* pins, int bits)
{
	int value = 0;
	int i;
	for( i = bits-1 ; i > -1 ; --i)
	{
		value |= digitalRead(pins[i]);
		value <<= 1;
	}
	return value;
}


void portMode(int port, int direction)
{
	int start;
	int i;
	if( port > 1)
		return;
	start = (port == 0)? 0:8;
	for(i = start ; i < start + 8 ; ++i)
		pinMode(i, direction);
		
}
int portRead(int port)
{
	int value = 0;
	int start;
	int i;
	if( port > 1)
		return;
	start = (port == 0)? 0:8;
	for(i = start ; i < start + 8 ; ++i)
	{
		value |= portRead(i) << (i - start); 
	
	}
	return value;
}
void portWrite(int port, int value)
{
	int start;
	int i;
	
	if( port > 1)
		return;
	
	start = (port == 0)? 0:8;
	for( i = 0 ; i < start+8 ; ++i)
	{
		digitalWrite(i, value & 1);
		value >>= 1;
	}

	
}


/*
 * Analog Functions.
 */
const IOPIN _iop_TIMERS[]={
{D_PORTE,BIT2},//  PTE2 TPM1CH0
{D_PORTE,BIT3},//  PTE3 TPM1CH1
{D_PORTF,BIT0},//  PTF0 TPM1CH2
{D_PORTF,BIT1},//  PTF1 TPM1CH3
{D_PORTF,BIT2},//  PTF2 TPM1CH4
{D_PORTF,BIT3},//  PTF3 TPM1CH5
{D_PORTF,BIT4},//  PTF4 (TPM2CH0)
};
/*
 * PWM Functions
 */
void analogWrite(int ch, int value)
{
	if( ch > 7)
		return;
	
	if(*TPMChannelStatus[ch] != 0x28)
		InitPWM((byte)ch);
	PWMSetDutycycle((byte)  ch, (word) value);
}
extern void InitTPM2Counter(void);
// This sets up a channel on TPM1
void InitPWM(byte channel)
{
  
	  
  if( channel < 6 && !PWM_InitFlag & 1 )
  {
	    InitTPM1Counter();
		pwm_scaler = (((dword)timer_modulus+1)<<10) / (dword) PWM_MAX;
		PWM_InitFlag |= 1;
  }
  else if(channel > 5 && !PWM_InitFlag & 2)
  {
	  //InitTPM2Counter();
	  pwm_scaler = (((dword)timer_modulus+1)<<10) / (dword) PWM_MAX;
	  PWM_InitFlag |= 2;
  }
	// Set the channel to PWM
	*TPMChannelStatus[channel] = 0x28;
	// Init Duty cycle to 0;
	*TPM1ChannelValue[channel] = 0;
	
}
// 0 - 256 = 0-100% duty cycle.
static void PWMSetDutycycle( byte channel, word duty)
{
	dword count = (dword) duty;
	  if( channel > 5 )
		  return;
	  count *= pwm_scaler;
	  count >>= 10;
	  *TPM1ChannelValue[channel] = (word)(count);
}
/*
 * ADC Functions
 */
static void InitADC(void)
{
	// Section 21.3.1
	// | COCO | AIEN | ADCO | C | C  C  C  C |
	// COCO = Conversion Complete
	// AIEN = Interrupt Enable
	// ADC0 = C0ntinous Converion
	// C = Channel Select. (all 1's disables module)
	ADCSC1 =  0x1F;
	
	// disable triggers and compare, software trigger.
	ADCSC2 =  0x00;               

	// Section 21.3.7
	// ADCCFG Register
	// | LOWPWR | ADIV1 | ADIV0 | LNGSAMP | MODE1 | MODE0 | CLK1 | CL2 |
	// ADIV 0=/1 1=/2 2=/4 3=/8
	// MODE 0= 8Bit 1=12Bit 2=10Bit 3=X
	// CLK  0=Bus 1=Bus/2 2=ALT CLK 3=Async Clk
	// The asynchronous clock (ADACK): 
	// This clock is generated from a clock source within the ADC
	// | 0   1 1  1 |  0 1   1 1 |
	//   P  ADIV  L   MODE  CLK  
	ADCCFG =  0x77;   // Set to  

}


// A
int analogRead(int ch)
{
	static volatile byte channel;
    
    // If this is not an ADC pin, then don't try to read from it!
	if( ch > 12 && ch != 26 && ch != 27)
		return -1;
		
    if(analog_pin_selects == 255)
    {
    	InitADC();
    	analog_pin_selects =0;
    }
    if( ch < 12)
    {
		// Pin select the channels we are using.
		if( ch < 8 )
			APCTL1 |= 1 << ch;
		else
			APCTL2 |= 1 << (ch-8);
    }
    	
	// Setting the channel starts the conversion.
	ADCSC1 =(byte) ch;
	// Wait for COCO (COnversion COmplete)
	while( (ADCSC1 & ADCSC1_COCO_MASK ) == 0 )
		;
	
	return ADCR >> ADC_shift; // Make correct number of bits.

    

}
/*
 * edge interrupts and tpm interrupt handlers.
 */
/*
 * The channels status for  the interrupts handle:
 * 0xFFFFF - Edge interrupt pending.
 * 
 */

#define CHnIE  		TPM1C0SC_CH0IE_MASK // Channels interrupt enable.
#define SET_HIGH  	0x1C 				// Set the output high on match
#define SET_LOW  	0x18				// Set the output low  on match
/*
 * SendPulse(int pin, dword length)
 * pin = A pin on a timer channel
 * length = ticks for the pulse (scaling is done elsewhere)
 */
 void SendPulse(byte ch, dword length)
{
	dword count;
	TPM1ChannelControl[ch] = 0;
	// Clear the status register.
	*TPMChannelStatus[ch];
	*TPMChannelStatus[ch]=0;
	// we can't handle an overflow too small because the count goes past before
	// we can set it.... 24 = about 1 us.
	if( (length > (dword)timer_modulus) && ((length - timer_modulus) < 32) )
		length = timer_modulus;
	// force the bit high.
	*TPMChannelStatus[ch] = SET_HIGH;
	*TPM1ChannelValue[ch] =(word) TPM1CNT;
	
	// wait for it to go high
	while(0 == (*TPMChannelStatus[ch] & 0x80))
		;
	// If greater than the timer modulus, the we will need multiple interrupts.
	if(length > (dword)timer_modulus)
	{
		// Save the remainder for the interrupt to set the next timeout.
		TPM1ChannelControl[ch] = length - (dword)timer_modulus;
		// We will go for one complete rollover.
		// Add to current value of the time.
		count =(dword) (TPM1CNT + timer_modulus);
		// If will over flow, compute the difference.
		if( count > timer_modulus)
			count -= timer_modulus;
		// Set when we want the next interrupt.
		*TPM1ChannelValue[ch] =(word) count;
		// Enable the interrupt on time out, but leave it high.
		*TPMChannelStatus[ch] = SET_HIGH | CHnIE;
		
	}
	else
	{
		CLI();
		// set the channel up for clear output on compare.
		count =(dword) (TPM1CNT + length);
		if( count > timer_modulus)
			count -= timer_modulus;
		*TPM1ChannelValue[ch] =(word) count;
		
		*TPMChannelStatus[ch] =SET_LOW;
		STI();
	}
	
}
 //
 // CH0=
 //
void singleshotPulse(int ch, dword time_us)
{
	long long counts;
	
	
	
	if(ch >= (sizeof(TPMChannelStatus)/sizeof( byte*)) || ch < 0)
		return;
	if( time_us > 1010)
	{	
		// Correct for times longer that 1MS.
		counts = (long long) time_us/1000;
		counts *= int_overhead_correction;
		// we gain about 3us for each interrupt.
		time_us -= (dword) round(counts,16);
	}
#if CLK12MHZ_XTAL == 1	
	counts = time_us *24;
#else	
	counts = ((long long)time_us *  us_to_ticks_11);
	counts = round(counts,16);
#endif
	counts -= 1;
	SendPulse((byte) ch, (dword)counts);
	
}
static void SetTime(int ch, int counts )
{
	if(ch >= (sizeof(TPMChannelStatus)/sizeof( byte*)) || ch < 0)
		return;
	
	*TPM1ChannelValue[ch] = (word) counts;
}
/*
 *   attachInterrupt - Sets up for and edge interrupt
 *   from TPM1 ch 0-5.
 */
#define RISING_EDGE  0x4
#define FALLING_EDGE 0x8
#define BOTH_EDGES   0xc

void attachInterrupt( int ch, PFNCALLBACK cb, int mode)
{
	if( ch == 6) 
	{  
#if MCU_HCS08 == 0		
		// PTG3 KBI1P7
		KBI1PE |= 0x80;
		if( mode == RISING || mode == HIGH)
			KBI1ES |= 0x80;
		else
			KBI1ES &= ~0x80;
		EdgeInterruptHandlers[7] = cb;
		if( mode == HIGH || mode == LOW)
			KBI1SC_KBIMOD =  1;
		KBI1SC_KBIE = 1;
#endif		
		return;
	}
	if(ch >= (sizeof(TPMChannelStatus)/sizeof( byte*)))
		return;
	switch(mode)
	{
	case RISING:
		mode = RISING_EDGE;
		break;
	case CHANGE:
		mode = BOTH_EDGES;
		break;
	case FALLING:
		mode = FALLING_EDGE;
		break;
	default:
		return;
	}
	TPM1ChannelControl[ch] = 0xFFFF;
	EdgeInterruptHandlers[ch] = cb;
	*TPMChannelStatus[ch] = CHnIE | (byte) mode;
	
}
void interruptMode(int which, int mode )
{
	if(which >= (sizeof(TPMChannelStatus)/sizeof( byte*)))
		return;
	
	*TPMChannelStatus[which] = CHnIE | (byte) mode;
	
}
void detachInterrupt(int which)
{
	if(which >= (sizeof(TPMChannelStatus)/sizeof( byte*)))
		return;
	EdgeInterruptHandlers[which] = 0;
	*TPMChannelStatus[which] = 0 ;

}
void noInterrupts()
{
	DisableInterrupts;
}
void interrupts(void)
{
	EnableInterrupts;
}

void ChannelInterruptHandler(byte ch)
{
	if( 0xFFFF == TPM1ChannelControl[ch])
	{
		if(EdgeInterruptHandlers[ch])
			EdgeInterruptHandlers[ch]();
	}
	else
	{
		 ChannelSingleShotHandler(ch);
	}
	// Ack the interrupt.
	(void) *TPMChannelStatus[ch];
	*TPMChannelStatus[ch] &= ~0x80;
	
}
void ChannelSingleShotHandler(byte ch)
{
	dword count;
	
	// If greater than the timer modulus, the we will need multiple interrupts.
	// we can't handle an overflow too small because the count goes past before
	// we can set it.... 24 = about 1 us.
	if( (TPM1ChannelControl[ch] > (dword)timer_modulus) &&
			((TPM1ChannelControl[ch] - (dword)timer_modulus) < 32) )
		TPM1ChannelControl[ch] = (dword)timer_modulus;

	if(TPM1ChannelControl[ch] > (dword)timer_modulus)
	{
		if(TPM1ChannelControl[ch] > (dword)timer_modulus)
			TPM1ChannelControl[ch] -=  (dword)timer_modulus;
		count =(dword) (TPM1CNT + timer_modulus);
		if( count > timer_modulus)
			count -= timer_modulus;
		*TPM1ChannelValue[ch] =(word) count;
		
	}
	else
	{
		// set the channel up for clear output on compare.
		if(TPM1ChannelControl[ch] < 32)
			TPM1ChannelControl[ch] = 33;
		count =(dword) (TPM1CNT + TPM1ChannelControl[ch]);
		if( count > timer_modulus)
			count -= timer_modulus;
		*TPM1ChannelValue[ch] =(word) count;
		
		*TPMChannelStatus[ch] =SET_LOW;
	}
	
}
/*
 * Interrupt Handlers.
 */
interrupt VectorNumber_Vkeyboard void KBIInterrupt(void);
interrupt VectorNumber_Vkeyboard void KBIInterrupt(void)
{
	if(EdgeInterruptHandlers[7])
		EdgeInterruptHandlers[7]();
#if MCU_HCS08 == 0	
	(void) KBI1SC;
	KBI1SC_KBACK = 1;
#endif
	
}

interrupt VectorNumber_Vtpm1ch0 void TPM1_CH0(void);
interrupt VectorNumber_Vtpm1ch0 void TPM1_CH0(void)
{

	ChannelInterruptHandler(0);
}
interrupt VectorNumber_Vtpm1ch1 void TPM1_CH1(void);
interrupt VectorNumber_Vtpm1ch1 void TPM1_CH1(void)
{
	ChannelInterruptHandler(1);
	
}
interrupt VectorNumber_Vtpm1ch2 void TPM1_CH2(void);
interrupt VectorNumber_Vtpm1ch2 void TPM1_CH2(void)
{
	ChannelInterruptHandler(2); 
	
}
interrupt VectorNumber_Vtpm1ch3 void TPM1_CH3(void);
interrupt VectorNumber_Vtpm1ch3 void TPM1_CH3(void)
{
	ChannelInterruptHandler(3);
	
}
interrupt VectorNumber_Vtpm1ch4 void TPM1_CH4(void);
interrupt VectorNumber_Vtpm1ch4 void TPM1_CH4(void)
{
	ChannelInterruptHandler(4);
	
}
interrupt VectorNumber_Vtpm1ch5 void TPM1_CH5(void);
interrupt VectorNumber_Vtpm1ch5 void TPM1_CH5(void)
{
	ChannelInterruptHandler(5);
}

#ifdef COMMENTOUT
// This table is in flash
//static const PIO _digital_config[]=
//{

BEGIN_PIO_TABLE(_digital_config)	

PIOENTRY(PTEDD,PTED,BIT2,NO_ALTF,NOCH,PTEPE,PTEDS,PTESE) // Shield 0 PTE1 TX
PIOENTRY(PTEDD,PTED,BIT0,NO_ALTF,NOCH,PTEPE,PTEDS,PTESE) // Shield 1 PTE0 RX
PIOENTRY(PTGDD,PTGD,BIT3,NO_ALTF,NOCH,PTGPE,PTGDS,PTGSE) // Shield 2 PTG3
PIOENTRY(PTEDD,PTED,BIT2,PWM_PIN,CH00,PTEPE,PTEDS,PTESE) // Shield 3 PTE2 TPM1CH0
PIOENTRY(PTDDD,PTDD,BIT2,NO_ALTF,NOCH,PTDPE,PTDDS,PTDSE) // Shield 4 PTD2
PIOENTRY(PTEDD,PTED,BIT3,PWM_PIN,CH01,PTEPE,PTEDS,PTESE) // Shield 5 PTE3 TPM1CH1
PIOENTRY(PTFDD,PTFD,BIT0,PWM_PIN,CH02,PTFPE,PTFDS,PTFSE) // Shield 6 PTF0 TPM1CH2
PIOENTRY(PTDDD,PTDD,BIT1,NO_ALTF,NOCH,PTDPE,PTDDS,PTDSE) // Shield 7 PTD1
PIOENTRY(PTFDD,PTFD,BIT4,NO_ALTF,NOCH,PTFPE,PTFDS,PTFSE) // Shield 8 PTF4 (TPM2CH0)
PIOENTRY(PTFDD,PTFD,BIT1,PWM_PIN,CH03,PTFPE,PTFDS,PTFSE) // Shield 9 PTF1 TPM1CH3
PIOENTRY(PTFDD,PTFD,BIT2,PWM_PIN,CH04,PTFPE,PTEDS,PTDSE) // Shield 10 PTF2 TPM1CH4
PIOENTRY(PTFDD,PTFD,BIT3,PWM_PIN,CH05,PTFPE,PTEDS,PTDSE) // Shield 11 PTF3 TPM1CH5
PIOENTRY(PTEDD,PTED,BIT4,NO_ALTF,NOCH,PTEPE,PTEDS,PTESE) // Shield 12 PTE4
PIOENTRY(PTEDD,PTED,BIT6,NO_ALTF,NOCH,PTEPE,PTEDS,PTDSE) // Shield 13 PTE6
PIOENTRY(PTBDD,PTBD,BIT0,ADC_PIN,CH00,PTBPE,PTBDS,PTBSE) // Shield 14 PTB0
PIOENTRY(PTBDD,PTBD,BIT1,ADC_PIN,CH01,PTBPE,PTBDS,PTBSE) // Shield 15 PTB1
PIOENTRY(PTBDD,PTBD,BIT2,ADC_PIN,CH02,PTBPE,PTBDS,PTBSE) // Shield 16 PTB2
PIOENTRY(PTBDD,PTBD,BIT3,ADC_PIN,CH03,PTBPE,PTBDS,PTBSE) // Shield 17 PTB3
PIOENTRY(PTBDD,PTBD,BIT4,ADC_PIN,CH04,PTBPE,PTBDS,PTBSE) // Shield 18 PTB4
PIOENTRY(PTBDD,PTBD,BIT5,ADC_PIN,CH05,PTBPE,PTBDS,PTBSE) // Shield 19 PTB5

// Bonus pins
PIOENTRY(PTBDD,PTBD,BIT6,ADC_PIN,CH06,PTBPE,PTBDS,PTBSE) // Shield 20 
PIOENTRY(PTBDD,PTBD,BIT7,ADC_PIN,CH07,PTBPE,PTBDS,PTBSE) // Shield 21 
PIOENTRY(PTGDD,PTGD,BIT1,NO_ALTF,NOCH,PTGPE,PTGDS,PTGSE)// Pin 22 RGB LED ENABLE (PTG1)
PIOENTRY(PTCDD,PTCD,BIT6,NO_ALTF,NOCH,PTCPE,PTCDS,PTCSE)// Pin 23 PTC6
PIOENTRY(PTFDD,PTFD,BIT7,NO_ALTF,NOCH,PTFPE,PTFDS,PTFSE)// Pin 24 PTF7
PIOENTRY(PTDDD,PTDD,BIT0,NO_ALTF,NOCH,PTDPE,PTDDS,PTDSE)// Pin 25 PTC6

/*
{&PTGDD,&PTGD,BIT3,NO_ALTF|NOCH,&PTGPE,&PTGDS,&PTGSE},			// Shield 2 PTG3
{&PTEDD,&PTED,BIT2,PWM_PIN|CH00,&PTEPE,&PTEDS,&PTESE},  	// Shield 3 PTE2 TPM1CH0
{&PTEDD,&PTED,BIT0,NO_ALTF|NOCH,&PTEPE,&PTEDS,&PTESE},  			// Shield 1 PTE0 RX
{&PTEDD,&PTED,2,0,&PTEPE,&PTEDS,&PTESE},		// Shield 0 PTE1 TX
{&PTDDD,&PTDD,BIT2,NO_ALTF|NOCH,&PTDPE,&PTDDS,&PTDSE},   			// Shield 4 PTD2
{&PTEDD,&PTED,BIT3,PWM_PIN|CH01,&PTEPE,&PTEDS,&PTESE},	// Shield 5 PTE3 TPM1CH1
{&PTFDD,&PTFD,BIT0,PWM_PIN|CH02,&PTFPE,&PTFDS,&PTFSE},	// Shield 6 PTF0 TPM1CH2
{&PTDDD,&PTDD,BIT1,NO_ALTF|NOCH,&PTDPE,&PTDDS,&PTDSE},   			// Shield 7 PTD1
{&PTFDD,&PTFD,BIT4,NO_ALTF|NOCH,&PTFPE,&PTFDS,&PTFSE},	// Shield 8 PTF4 (TPM2CH0)
{&PTFDD,&PTFD,BIT1,PWM_PIN|CH03,&PTFPE,&PTFDS,&PTFSE},	// Shield 9 PTF1 TPM1CH3
{&PTFDD,&PTFD,BIT2,PWM_PIN|CH04,&PTFPE,&PTFDS,&PTFSE},	// Shield 10 PTF2 TPM1CH4
{&PTFDD,&PTFD,BIT3,PWM_PIN|CH05,&PTFPE,&PTFDS,&PTFSE},	// Shield 11 PTF3 TPM1CH5
{&PTEDD,&PTED,BIT4,NO_ALTF|NOCH,&PTEPE,&PTEDS,&PTESE},			// Shield 12 PTE4
{&PTEDD,&PTED,BIT6,NO_ALTF|NOCH,&PTEPE,&PTEDS,&PTDSE},			// Shield 13 PTE6
// Analog pins also can be used a digital pins
{&PTBDD,&PTBD,BIT0,ADC_PIN|CH00,&PTBPE,&PTBDS,&PTBSE},	// Shield 14 PTB0
{&PTBDD,&PTBD,BIT1,ADC_PIN|CH01,&PTBPE,&PTBDS,&PTBSE},	// Shield 15 
{&PTBDD,&PTBD,BIT2,ADC_PIN|CH02,&PTBPE,&PTBDS,&PTBSE},	// Shield 16 
{&PTBDD,&PTBD,BIT3,ADC_PIN|CH03,&PTBPE,&PTBDS,&PTBSE},	// Shield 17 
{&PTBDD,&PTBD,BIT4,ADC_PIN|CH04,&PTBPE,&PTBDS,&PTBSE},// Shield 18 
{&PTBDD,&PTBD,BIT5,ADC_PIN|CH05,&PTBPE,&PTBDS,&PTBSE},// Shield 19 

// Bonus pins
{&PTBDD,&PTBD,0x40,ADC_PIN|CH06,&PTBPE,&PTBDS,&PTBSE},// Shield 20 
{&PTBDD,&PTBD,0x80,ADC_PIN|CH07,&PTBPE,&PTBDS,&PTBSE},// Shield 21 

{&PTGDD,&PTGD,2,NO_ALTF|NOCH,&PTGPE,&PTGDS,&PTGSE},// Pin 22 RGB LED ENABLE (PTG1)
*/
BEGIN_PIO_TABLE(_digital_config)	
PIOENTRY(PTEDD,PTED,BIT2,NO_ALTF,NOCH,PTEPE,PTEDS,PTESE) // Shield 0 PTE1 TX
PIOENTRY(PTEDD,PTED,BIT0,NO_ALTF,NOCH,PTEPE,PTEDS,PTESE) // Shield 1 PTE0 RX
PIOENTRY(PTGDD,PTGD,BIT3,NO_ALTF,NOCH,PTGPE,PTGDS,PTGSE) // Shield 2 PTG3
PIOENTRY(PTEDD,PTED,BIT2,PWM_PIN,CH00,PTEPE,PTEDS,PTESE) // Shield 3 PTE2 TPM1CH0
PIOENTRY(PTDDD,PTDD,BIT2,NO_ALTF,NOCH,PTDPE,PTDDS,PTDSE) // Shield 4 PTD2
PIOENTRY(PTEDD,PTED,BIT3,PWM_PIN,CH01,PTEPE,PTEDS,PTESE) // Shield 5 PTE3 TPM1CH1
PIOENTRY(PTDDD,PTDD,BIT0,NO_ALTF,NOCH,PTDPE,PTDDS,PTDSE) // Shield 6 PTD0
PIOENTRY(PTDDD,PTDD,BIT1,NO_ALTF,NOCH,PTDPE,PTDDS,PTDSE) // Shield 7 PTD1
PIOENTRY(PTFDD,PTFD,BIT4,NO_ALTF,NOCH,PTFPE,PTFDS,PTFSE) // Shield 8 PTF4 (TPM2CH0)
PIOENTRY(PTFDD,PTFD,BIT1,PWM_PIN,CH03,PTFPE,PTFDS,PTFSE) // Shield 9 PTF1 TPM1CH3
PIOENTRY(PTEDD,PTED,BIT7,PWM_PIN,CH04,PTEPE,PTEDS,PTESE) // Shield 10 PTE7
PIOENTRY(PTCDD,PTCD,BIT0,NO_ALTF,NOCH,PTCPE,PTCDS,PTCSE) // Shield 11 PTC0 
PIOENTRY(PTCDD,PTCD,BIT1,NO_ALTF,NOCH,PTCPE,PTCDS,PTCSE) // Shield 12 PTC1
PIOENTRY(PTEDD,PTED,BIT6,NO_ALTF,NOCH,PTEPE,PTEDS,PTDSE) // Shield 13 PTE6
PIOENTRY(PTCDD,PTCD,BIT3,NO_ALTF,NOCH,PTCPE,PTCDS,PTCSE) // Shield 14 PTC3
PIOENTRY(PTEDD,PTED,BIT5,NO_ALTF,NOCH,PTEPE,PTEDS,PTDSE) // Shield 15 PTE5
PIOENTRY(PTEDD,PTED,BIT4,NO_ALTF,NOCH,PTEPE,PTEDS,PTDSE) // Shield 16 PTE4
PIOENTRY(PTCDD,PTCD,BIT5,NO_ALTF,NOCH,PTCPE,PTCDS,PTCSE) // Shield 17 PTC5
PIOENTRY(PTBDD,PTBD,BIT5,ADC_PIN,CH05,PTBPE,PTBDS,PTBSE) // Shield 18 A0 PTB5
PIOENTRY(PTBDD,PTBD,BIT4,ADC_PIN,CH04,PTBPE,PTBDS,PTBSE) // Shield 19 A1 PTB4

// Bonus pins
PIOENTRY(PTBDD,PTBD,BIT3,ADC_PIN,CH03,PTBPE,PTBDS,PTBSE) // Shield 20 A2 PTB3
PIOENTRY(PTBDD,PTBD,BIT2,ADC_PIN,CH02,PTBPE,PTBDS,PTBSE) // Shield 21 A3 PTB2
PIOENTRY(PTBDD,PTBD,BIT1,ADC_PIN,CH01,PTBPE,PTBDS,PTBSE) // Shield 22 A4 PTB0
PIOENTRY(PTBDD,PTBD,BIT0,ADC_PIN,CH00,PTBPE,PTBDS,PTBSE) // Shield 23 A5 PTB0
PIOENTRY(PTFDD,PTFD,BIT7,NO_ALTF,NOCH,PTFPE,PTFDS,PTFSE) // Shield 24  A5 (PTF7) 
PIOENTRY(PTCDD,PTCD,BIT6,NO_ALTF,NOCH,PTCPE,PTCDS,PTCSE) // Shield 25 A4  (PTC6)
PIOENTRY(PTGDD,PTGD,BIT2,NO_ALTF,NOCH,PTGPE,PTGDS,PTGSE) // Shield 26 PTG2 EEPROM WP
END_PIO_TABLE()
#endif
