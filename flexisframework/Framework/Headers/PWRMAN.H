/*
 * PWRMAN.H
 *
 *  $Rev:: 201                       $:
 *  $Date:: 2012-09-23 21:32:06 -040#$:
 *  $Author:: jcdonelson             $:
  *  Created on: Sep 6, 2012
 *      Author: jdonelson
 */

#ifndef PWRMAN_H_
#define PWRMAN_H_
#define   EnterStopMode()  asm { mov3q #4,d0; bclr.b d0,SOPT1; nop; stop #0x2000; } /* Set STOP mode */


#define STOP2		1
#define STOP3		2
#define STOP4		4
#define WAIT		8
byte SetSTOPMode(byte which);

void powerModulesDown(unsigned long modules);
void powerModulesUp(unsigned long modules);
byte ReadResetSource();
/* Bits from reset source
#define SRS_LVD_MASK                    2U   // Low voltage detect.
#define SRS_LOC_MASK                    4U   // loss of clock
#define SRS_ILAD_MASK                   8U   // illegal address
#define SRS_ILOP_MASK                   16U  // Illegal opcode
#define SRS_COP_MASK                    32U  // COP Watchdog
#define SRS_PIN_MASK                    64U  // External reset pin
#define SRS_POR_MASK                    128U // Power on reset
 
 */
#define P_CMT  	SCGC1_CMT_MASK 
#define P_TPM2	SCGC1_TPM2_MASK 
#define P_TPM1	SCGC1_TPM1_MASK 
#define P_ADC	SCGC1_ADC_MASK 
#define P_I2C2	SCGC1_IIC2_MASK 
#define P_I2C1	SCGC1_IIC1_MASK 
#define P_SCI2	SCGC1_SCI2_MASK 
#define P_SCI1	SCGC1_SCI1_MASK 

#define P_SPI1 	SCGC2_SPI1_MASK  << 8
#define P_SPI2	SCGC2_SPI2_MASK  << 8
#define P_RTC 	SCGC2_RTC_MASK   << 8
#define P_ACMP	SCGC2_ACMP_MASK  << 8                 
#define P_KBI	SCGC2_KBI_MASK   << 8                  
#define P_IRQ	SCGC2_IRQ_MASK   << 8                   
#define P_FLS	SCGC2_FLS_MASK   << 8                   
#define P_USB	SCGC2_USB_MASK   << 8 

#define P_RNGA	SCGC3_RNGA_MASK  << 16


#endif /* PWRMAN_H_ */
