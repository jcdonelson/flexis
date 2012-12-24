/*
 * DIGITAL_IO.H
 * GPL License
 *  $Rev:: 156                       $:
 *  $Date:: 2012-09-07 16:51:54 -040#$:
 *  $Author:: jcdonelson             $:
 */

#ifndef DIGITAL_IO_H_
#define DIGITAL_IO_H_
#define INPUT			1
#define OUTPUT  		2
#define HI_DRIVE 		4
#define SLEW_RATE 		8
#define INPUT_FILTER	16
#define PULL_UP         32	
typedef struct _iopin {
	byte portindex;
	volatile byte *data;
	byte bitno;
}IOPIN;

void InitTPM1Counter(void);
void pinMode( int pin, int direction);
void pinModeEx( int pin, int config);

void digitalWrite( int pin, int value );
int  digitalRead(int pin);
void analogWrite(int pin, int value);
int analogRead(int pin);
void portMode(int port, int direction);
int portRead(int port);
void portWrite(int port, int value);
void portModeEx(byte* pins,int direction, int bits);
void portWriteEx(byte* pins, int value, int bits);
int portReadEx(byte* pins, int bits);


long micros(void);
long millis(void);
void delay(int delayms);
void delayMicroseconds(int delayus);
void singleshotPulse(int pin, dword time_us);


/*
 *    EDGEINTS.H
 */
#define LOW 		1
#define CHANGE 		2
#define RISING 		4
#define FALLING 	8
#define HIGH		16
// Output compare.
#define TOGGLE  	0x14
#define CLEAR	 	0x8
#define SET   		0x1c
typedef void(*PFNCALLBACK)(void);
typedef void(*PFNCALLBACKEX)(void* context);
void InitEdgeInterrupt();
void attachInterrupt( int which, PFNCALLBACK cb, int mode);
// Extended function with user parameter.
void attachInterruptEx( int ch, PFNCALLBACKEX cb, int mode,void* context);

void detachInterrupt(int which);
void interruptMode(int which, int mode );
void SetTime(int which, int counts );
void noInterrupts();
void interrupts(void);



/*
 * PIO Tables
 */

// Helper macros to build PIO tables.
#define BEGIN_PIO_TABLE(n) const IOPIN n[]={
#define PIO_ENTRY(p,b) {p,b},
#define DEFINE_SZ(n)  const int _sz ## n = sizeof(n)/sizeof(IOPIN);
#define END_PIO_TABLE(n) }; const int _sz ## n = sizeof(n)/sizeof(IOPIN);
#define PIO_TABLE(n) &n[0],_sz ## n

// USed to set predefined tables.
const  IOPIN _baseiop_mini[];
const  IOPIN _baseiop1_nano[];
const  IOPIN _baseiop_fb32[];
extern const int MINI_MAX;
extern const int FB_MAX;
extern const int NANO_MAX;
#define MINI_PIO  &_baseiop_mini[0],MINI_MAX
#define NANO_PIO  &_baseiop1_nano[0],NANO_MAX
#define FB32_PIO  &_baseiop_fb32[0],FB_MAX

int setPIOTable(const  IOPIN *piotable, int max);

#define INPUT		1
#define OUTPUT  	2
#define HI_DRIVE 	4

#define CH00			0
#define CH01			0x10
#define CH02			0x20
#define CH03			0x30
#define CH04			0x40
#define CH05			0x50
#define CH06			0x60
#define CH07			0x70
#define CH08			0x80
#define CH09			0x90
#define CH10			0xA0
#define CH11			0xB0
#define CH12			0xC0

#define BIT0		1
#define BIT1		2
#define BIT2		4
#define BIT3		8
#define BIT4		0x10
#define BIT5		0x20
#define BIT6		0x40
#define BIT7		0x80
//
typedef struct _ioregs {
	volatile byte *direction;
	volatile byte *data;
	volatile byte *pullup;
	volatile byte *slewrate;
	volatile byte *drive;
	volatile byte *filter;
	byte anaflags;
	byte pwmflags;
	
} IOREGS;

// Indexes into the port table.
#define PORTA			0
#define PORTB			1
#define PORTC			2
#define PORTD			3
#define PORTE			4
#define PORTF			5
#define PORTG			6
#define PORTH			7

// These are used only to build the PIO table.
#define D_PORTA			PORTA,&PTAD
#define D_PORTB			PORTB,&PTBD
#define D_PORTC			PORTC,&PTCD
#define D_PORTD			PORTD,&PTDD
#define D_PORTE			PORTE,&PTED
#define D_PORTF			PORTF,&PTFD
#define D_PORTG			PORTG,&PTGD
#define D_PORTH			PORTH,&PTHD




#endif /* DIGITAL_IO_H_ */
