/*
 * I2C_LED.H
 *
 *  Created on: Aug 21, 2010
 *      Author: jdonelson
 */

#ifndef I2C_LED_H_
#define I2C_LED_H_
/* Writes the array to the LEDS */
byte ledSetDigits(byte* digits);
byte ledSetDecimalInt(int d);
#define NO_DECIMAL_POINT  0xff
void ledSetDecimalPoint(byte place);
#define ZERO_SEGS    1+2+4+8+0x10+0x20
#define ONE_SEGS     2+4
#define TWO_SEGS     1+2+0x40+0x10+8
#define THREE_SEGS   1+2+4+8+0x40
#define FOUR_SEGS   2+4+0x40+0x20
#define FIVE_SEGS   1+0x20+0x40+4+8
#define SIX_SEGS    0x20+0x10+8+4+0x40
#define SEVEN_SEGS  1+2+4
#define EIGHT_SEGS   0x7F
#define NINE_SEGS   1+2+4+0x40+0x20
#define A_SEGS      1+2+4+0x20+0x10+0x40
#define B_SEGS      0x20+0x10+8+4+0x40
#define C_SEGS      1+0x20+0x10+8
#define D_SEGS      2+4+8+0x10+0x40
#define E_SEGS      1+0x20+0x10+8+0x40
#define F_SEGS      1+0x20+0x40+0x10



#endif /* I2C_LED_H_ */
