/*
 * I2C_LED.c
 * Logical driver for I2C Led Module
 *  Created on: Aug 21, 2010
 *      Author: jdonelson
 */
#include "common.h"
#include "I2C_LED.H"

byte __decoder[]={
ZERO_SEGS,  ONE_SEGS,TWO_SEGS,THREE_SEGS,FOUR_SEGS,FIVE_SEGS,
SIX_SEGS,SEVEN_SEGS,EIGHT_SEGS,NINE_SEGS,A_SEGS,B_SEGS,C_SEGS,D_SEGS,
E_SEGS,F_SEGS
};
static word sent;
static byte led_message[6]= {0x00,0x77,C_SEGS,D_SEGS,E_SEGS ,F_SEGS };
static byte _decimalpoint = NO_DECIMAL_POINT ;
//====================================================
//   ledSetDigits(byte* digits)
//
//   The 4 bytes in the array are decoded and sent to
//   the LEDS
//====================================================
byte ledSetDigits(byte* digits)
{
	int i = 0;
	I2C_SetAddress(I2C_LED_ModuleAddress);
	for( i = 0; i < 4 ; ++i)
	{
		led_message[i+2] = __decoder[ digits[i] ];
		if(i == _decimalpoint)
			led_message[i+2] |= 0x80;
	}
	I2C_SendData(led_message,6,&sent);
	return NO_ERROR;
}

//====================================================
// void ledSetDecimalPoint(byte d)
//
//  0-3 Sets if and where the decimal point will be
//  Any other value turns it off.
//====================================================
void ledSetDecimalPoint(byte d)
{
	_decimalpoint = d;
}
//====================================================
// byte ledSetDecimalInt(int d)
//
// Write the first 4 digits of a decimal number.
//====================================================
byte ledSetDecimalInt(int d)
{
	byte data[4];
	int t;
	int i;
	for( i = 0 ; i < 4 ; ++i)
	{
	   t = d/10;
	   t *= 10;
	   data[i] =(unsigned char)( d - t);
	   d /= 10;
	}
	ledSetDigits(data);
	return NO_ERROR;
}

