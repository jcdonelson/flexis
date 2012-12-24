/*
 * CONFIG.H
 *
 *  Created on: Mar 7, 2011
 *      Author: jdonelson
 *  This file configures various aspects of the framework
 *  start off by copying one of the versions into
 *  the projects Project_Headers and rename CONFIG.H
 */

#ifndef CONFIG_H_
#define CONFIG_H_
#define FB32		1
#define NANO32		0
#define MINI32		0
/*
 *   CLK12MHZ_XTAL - Set if XTAL is used or internal osc.
 *   if 1 will use 12Mhz XTAL boosted to 48 MHz.
 *   if 0 will use internal clock at 50.331648 
 */
#ifndef byte
#define byte unsigned char
#define dword unsigned long
#endif
#define MCU_HCS08		0
/*
 * If set to 0 use internal clock.
 */
#define CLK12MHZ_XTAL   1
/*
 * PWM_MAX - Sets the range for PWM
 *  typical value 256 for 8 bits, 1024 for 10 bits
 *  4096 for 12 bits.
 */
#define PWM_MAX 1024
/*
 * ADC_BITS - This determine how many bit the ADC will return.
 * Currently the ADC is always set up for 12 bits.
 * Range = 8,9,10,11,12
 */
#define ADC_BITS 10
/*
 *   This determines what printf will do.
 *   if CONSOLE_IO_SUPPORT is 0 printf will do
 *   nothing. If 1 then it will print to the Console
 *   window in Eclipse. 
 *   CONSOLE_LCD_SUPPORT   - Also write to LCD
 *   CONSOLE_SCI1_SUPPORT  - Also write to Serial port 1
 *   CONSOLE_SCI2_SUPPORT  - Also write to Serial port 2
 */
#define CONSOLE_IO_SUPPORT  1

#define CONSOLE_LCD_SUPPORT  0 
#define CONSOLE_SCI1_SUPPORT  1 
#define CONSOLE_SCI2_SUPPORT  0 
/*
 * 
 */
#define NO_PRINTF    1

#endif /* CONFIG_H_ */
