/*
 * CLOCKS.C
 * Set up the main CPU clock to 48 MHz.
 *  $Rev:: 37                        $:
 *  $Date:: 2011-04-12 14:56:04 -040#$:
 *  $Author:: jcdonelson             $:
 *
 * 
 */

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "CLOCK.H"
#include "RTC.H"
#include "DIGITAL_IO.H"
#include "CONFIG.H"
void InitInternalClock(void);
void InitCLOCK12MHZ(void);
int OSCILLATOR_Fail = 0;
void InitRICH(void);
void InitCLOCK(void)
{
	InitRICH();
	return;
#if CLK12MHZ_XTAL == 1
	InitCLOCK12MHZ();
//	InitRTC();
#else
	InitInternalClock();
	InitRTCInternalClock();

#endif	
//	InitTPM1Counter();
}
/*
 * Enable the 12Mhz xtal oscillator and use the PLL
 * to crank it up to 48MHz.
 */
void InitCLOCK12MHZ(void)
{
	long counter = 0;
	// See chapter 7 of MCF51JMRM.pdf 
	// to completely understand this.
	// First start the 12 MHz XTAL oscillator up.
	// Set BDIV=0 RANGE=1,HGO=1,EREFS=1,ERCLKEN=1
	MCGC2 = 0x36;  
	
	// Wait for the osc to start up.
	while(MCGSC_OSCINIT == 0 && counter++ < 10000) 
		;
	if(counter > 10000)
	{
		OSCILLATOR_Fail = 1;
		return;
	}
	// Select the external ref clock (the 12 MHz oscillator).
	// set RDIV to divide by 8 - 12/8 = 1.5 MHz to feed the PLL
	// CLKS=10 RDIV=3 See 7.3.1
	// Also, enable the internal 32k ref clock so RTC can use it.
	MCGC1 = 0x98 | MCGC1_IRCLKEN_MASK ;
	
	// Wait for bit 3 to set and bit 2 to reset to indicate
	// external reference is selected.
	while((MCGSC & 0xC) != 0x8)
		;
	
	// Select the PLL with a x32 multiplier to give 48MHz
	// PLLS=1  VDIV=8 (x32) 1.5x32=48 See Table  7.3.6
	MCGC3 = 0x48;
	
	// Wait for the PLL to be selected
	while(MCGSC_PLLST == 0 )
		;
	
	// Wait for the PLL to lock.
	while(MCGSC_LOCK == 0)
		;
	
	// Clear bits 6 & 7 to 0 to select the PLL output as the CPU clock.
	MCGC1 &= ~0xC0; 
	
}
/*
 * Set the internal clock to 50.331648
 * Bus Clock = 25.165824
 */
void InitInternalClock(void)
{
	MCGC2 = 0x00; 
	MCGC1 = 0x06; 
	MCGC3 = 0x01; 
#ifdef CFV1	
	MCGC4 = 0x02;
#endif	
	while(!MCGSC_LOCK) 
		;
}

void InitRICH(void)
{
/* switch from FEI to FBE (FLL bypassed external) */ 
/* enable external clock source */
MCGC2 = MCGC2_HGO_MASK       /* oscillator in high gain mode */
      | MCGC2_EREFS_MASK   /* because crystal is being used */
      | MCGC2_RANGE_MASK   /* 12 MHz is in high freq range */
      | MCGC2_ERCLKEN_MASK;     /* activate external reference clock */
while (MCGSC_OSCINIT == 0)
;
/* select clock mode */
MCGC1 = (2<<6)         /* CLKS = 10 -> external reference clock. */
    | (3<<3);          /* RDIV = 3 -> 12MHz/8=1.5 MHz */

/* wait for mode change to be done */
while (MCGSC_IREFST != 0)
;
while (MCGSC_CLKST != 2)
;

/* switch from FBE to PBE (PLL bypassed internal) mode */
MCGC3=MCGC3_PLLS_MASK
    | (8<<0);     /* VDIV=6 -> multiply by 32 -> 1.5MHz * 32 = 48MHz */
while(MCGSC_PLLST != 1)
;
while(MCGSC_LOCK != 1)
;
/* finally switch from PBE to PEE (PLL enabled external mode) */
MCGC1 = (0<<6)         /* CLKS = 0 -> PLL or FLL output clock. */
      | (3<<3);        /* RDIV = 3 -> 12MHz/8=1.5 MHz */
while(MCGSC_CLKST!=3)
;

/* Now MCGOUT=48MHz, BUS_CLOCK=24MHz */  
//cpu_frequency = 48000000;
//bus_frequency = cpu_frequency/2;
//oscillator_frequency = 12000000;

// we read KBI1SC's initial value to determine if the debugger is attached
// N.B. this value must be set by the debugger's cmd file!
}
