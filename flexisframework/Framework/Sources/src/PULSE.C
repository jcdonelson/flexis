/*
 *  PULSE.C
 *  note: This can not be used when the on-board speaker is used.
 *
 *  $Rev:: 85                        $:
 *  $Date:: 2011-05-30 17:13:35 -040#$:
 *  $Author:: jcdonelson             $:
 * 
 */
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "PULSE.H"
#include "DIGITAL_IO.H"
#ifndef byte
#define byte unsigned char
#define word unsigned short
#define dword unsigned long
#endif
extern void InitTPM2Counter(void);
static volatile int pulseCount = 0;
void InitPulse(void)
{
	//D_PORTF,BIT4
	PTFDD |= 0x10;
	PTFD &= ~0x10;  
	// Set up the TPM for output pulses
	// In this usage, we can set the TMP divider and always set the duty
	// cycle to 50% to get a square wave at different frequencies.
	// TPMxSC - Section 22.3
	//    7                                            0
	// | TOF | TOIE | CPWMS  | CLKS | CLKS | PS | PS | PS |
	//    0      0      0       0      1      0    1    0
	// CLK = 01 = Bus Rate Clock
	//  PS = 010 = /4
	//
	TPM2SC = 0x8; // 24/1 = 24MHz
	// TPMxCnSC
	//    7        6      5      4       3       2       1   0
	// | CHnF  | CHnIE | MSnB | MSnA | ELSnB  | ELSnA  | 0 | 0 |
	//    0        0      1      0      1        0       0   0
	// MSnB = 1  Configure to Edge aligned PWM when CPWMS = 0.
	// ElsnB:EKSnA =  10 Clear Output on compare.
	// pin 8 PTF4
	TPM2C0SC = 0x28;  // Set to PWM
	TPM2MOD = 0;
	TPM2C0V = 0; // Off
}

void pulseOut(int pin,long frequency,long nPulses)
{
#if MCU_HCS08 == 0	
	pin = pin; // kill warning.
#endif	
	dword cntr_freq = 24000000;
	byte divide = 0;
	word cv = 0;
	
	volatile dword count_value =0;
	volatile dword rem = cntr_freq/(dword)(frequency);
	while(((cntr_freq/(dword)(frequency)) > 32767) && divide <= 7 )
	{
		++divide;
		cntr_freq >>= 1;
				
	}
	TPM2SC = 0x8 + divide;
	if( divide == 8)
	{
		divide = 0;
		cntr_freq = 785000;
		while(((cntr_freq/(dword)(frequency)) > 32767) && divide <= 7 )
		{
			++divide;
			cntr_freq >>= 1;
					
		}
		if( divide == 8)
			return;
		TPM2SC = 0x10 + divide;
	}

	count_value = (cntr_freq/(dword)(frequency))-1;
	cv = (word) count_value;
	//(void) TPM2C0SC;
	//TPM2C0SC &= ~0x80;
	//TPM2CNT = 0;
	TPM2C0SC = 0x28; // 
    TPM2CNT = 0;	 
	TPM2MOD =  cv;
	cv  = (word)count_value>>1;
	TPM2C0V = cv;
	
	if( nPulses > 0)
	{
		//TPM2C0SC = 0x14;
		pulseCount = nPulses + 1;
		// Enable the interrupt...
		TPM2C0SC |= 0x40;
		//TPM1SC_TOIE = 1;
	}
	else
	{   // Don't need to count, so disable the interrupt.
		//TPM2C0SC &= ~(TPM2C0SC_CH0IE_MASK);
	}
	TPM2C0V = cv;
}
void pulseStop(void)
{
	TPM2C0V = 0; // Off
}
int pulseRunning(void)
{
	return pulseCount;
}

interrupt VectorNumber_Vtpm2ch0 void TPM2_CH0(void);
interrupt VectorNumber_Vtpm2ch0 void TPM2_CH0(void)
{
	
	if(pulseCount)
		--pulseCount;
	if(0 == pulseCount)
	{
		TPM2C0V = 0; // Off
		TPM2C0SC = 0;
	}
	
	(void) TPM2C0SC;
	TPM2C0SC &= ~0x80;

}

