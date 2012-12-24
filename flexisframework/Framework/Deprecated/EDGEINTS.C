/*
 * 	EDGEINTS.C
 *  Handles the dispatch of edge interrupts and pulse generation.
 */

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "../Headers/EDGEINTS.H"


#define RISING_EDGE  0x4
#define FALLING_EDGE 0x8
#define BOTH_EDGES   0xc

void InitEdgeInterrupt()
{
	if( 0 == (TPM1SC & 0x18))  	// See if CLK is 00
	  TPM1SC = 8; 			 	// CLKS can't be at 0 for this to work.

}

 
/*
 *    TPMxCnSC
 *    
 */
#define CHnIE  TPM1C0SC_CH0IE_MASK // Channels interrupt enable.
extern void EdgeCallBack(void);
PFNCALLBACK EdgeInterruptHandlers[8];
void ChannelInterruptHandler(byte which);

volatile byte* status_registers[]=
	{&TPM1C0SC,&TPM1C1SC,&TPM1C2SC,&TPM1C3SC,&TPM1C4SC,&TPM1C5SC,&TPM2C0SC}; 
volatile word* count_registers[]=
	{&TPM1C0V,&TPM1C1V,&TPM1C2V,&TPM1C3V,&TPM1C4V,&TPM1C5V,&TPM2C0V}; 
static byte init=0;
void SetTime(int which, int counts )
{
	if(which >= (sizeof(status_registers)/sizeof( byte*)))
		return;
	*count_registers[which] = (word) counts;
}
void attachInterrupt( int which, PFNCALLBACK cb, int mode)
{
	if(which >= (sizeof(status_registers)/sizeof( byte*)))
		return;
	EdgeInterruptHandlers[which] = cb;
	*status_registers[which] = CHnIE | (byte) mode;
	
}
void interruptMode(int which, int mode )
{
	if(which >= (sizeof(status_registers)/sizeof( byte*)))
		return;
	
	*status_registers[which] = CHnIE | (byte) mode;
	
}
void detachInterrupt(int which)
{
	if(which >= (sizeof(status_registers)/sizeof( byte*)))
		return;
	EdgeInterruptHandlers[which] = 0;
	*status_registers[which] = 0 ;

}
void noInterrupts()
{
	DisableInterrupts;
}
void interrupts(void)
{
	EnableInterrupts;
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

void ChannelInterruptHandler(byte which)
{
	if(EdgeInterruptHandlers[which])
		EdgeInterruptHandlers[which]();
	// Ack the interrupt.
	(void) *status_registers[which];
	*status_registers[which] &= ~0x80;
	
}




