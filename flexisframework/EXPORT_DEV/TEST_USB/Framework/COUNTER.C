/*
* COUNTER.C
*
* This is to implement the user counter and delay.
* 
*  $Rev:: 44                        $:
*  $Date:: 2011-04-18 08:18:30 -040#$:
*  $Author:: jcdonelson             $:
* This code is licensed under GPL, any version.
 */
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "DIGITAL_IO.H"
#include "CONFIG.H"
void CLI(void);
void STI(void);
#ifndef CLK12MHZ_XTAL
#define CLK12MHZ_XTAL   1
#endif
#if CLK12MHZ_XTAL == 1 
#define TIMER_MODULUS 24000-1
#define CLOCK_FACTOR  24
#else
#define TIMER_MODULUS 25165
#define CLOCK_FACTOR  25
#endif
void InitTPM2Counter(void);
word timer_modulus = TIMER_MODULUS;

static dword microseconds;
void InitTPM1Counter(void);
/*
 * Set up for 1ms interrupt
 * 24Mhz / 24000 = 1Khz = 1ms
 */
void InitTPM1Counter(void)
{
	// Divide by 24000 = 1MS
	TPM1MOD = timer_modulus;

	// | TOF | TOIE | CPWMS | CLKS1 | CLKS 0 | PS1 | PS2 | PS3 |
	// TOF = Timer overflow TOIE = Interrupt enable CPWMS = center algin
	// CLKS = 0=No clock 1=Bus Clk 2=Fixed Sys clk 3=external clk
	// PS = Prescale 0=/1 1=/2 2=/4 3=8 4=/16 5=/32  6=/54 7=/128
	TPM1SC_CLKSB = 0; 
	TPM1SC_CLKSA = 1;
	
	// Set prescaler to '0' = /1
	TPM1SC &= ~7;
	// Enable Timer overflow interrupt
	TPM1SC_TOIE = 1;
	
}
void InitTPM2Counter(void)
{
	// Divide by 24000 = 1MS
	TPM2MOD = timer_modulus;

	// | TOF | TOIE | CPWMS | CLKS1 | CLKS 0 | PS1 | PS2 | PS3 |
	// TOF = Timer overflow TOIE = Interrupt enable CPWMS = center algin
	// CLKS = 0=No clock 1=Bus Clk 2=Fixed Sys clk 3=external clk
	// PS = Prescale 0=/1 1=/2 2=/4 3=8 4=/16 5=/32  6=/54 7=/128
	TPM2SC_CLKSB = 0; 
	TPM2SC_CLKSA = 1;
	
	// Set prescaler to '0' = /1
	TPM2SC &= ~7;
	
}
/*
 * Timer over flow interrupt
 */
interrupt VectorNumber_Vtpm1ovf void TPM1OverFlow(void);
interrupt VectorNumber_Vtpm1ovf void TPM1OverFlow(void)
{
	microseconds += 1000;
	// Clear the interrupt.
	(void)TPM1SC;
	TPM1SC &= ~TPM1SC_TOF_MASK;
}
/*
 * 
 */
long micros()
{
	// each tick is 41.66666... nano seconds (1/24E6)
	// /24 = microseconds
	long micros;
	// On V1 this would be atomic, but on HCS08 it won't
	//CLI();
	micros =(long)  microseconds;
	//STI();
	// The count registers are safely interlocked.
	micros += (TPM1CNT/CLOCK_FACTOR);
	return micros;
}
long millis()
{
	long micros;
	// On V1 this would be atomic, but on HCS08 it won't
	//CLI();
	micros =(long)  microseconds;
	//STI();
	return micros/1000;
}
void delay(int delayms)
{
	long start = millis();
	
	while( (millis() - start) < delayms)
		;

}
void delayMicroseconds(int delayus)
{
	long start = micros();
	while((micros() - start) < delayus)
		;
}
