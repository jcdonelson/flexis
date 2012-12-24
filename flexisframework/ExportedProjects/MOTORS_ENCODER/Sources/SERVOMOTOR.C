/*
 * SERVOMOTOR.C
 *
 *  Created on: Aug 12, 2012
 *      Author: jdonelson
 */
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#include "ALL.H"
#include "ENCODER.H"
#include "SERVOMOTOR.H"




void SERVOMOTORInit(SERVOMOTOR* servo)
{
	pinMode(servo->DirectionChannel,OUTPUT);
	digitalWrite(servo->DirectionChannel,servo->direction);
	analogWrite(servo->PWMChannel,0);
}
void SERVOMOTORSetSpeed(SERVOMOTOR* servo,int speed)
{
	analogWrite(servo->PWMChannel,speed);
}
void SERVOMOTORSetDirection(SERVOMOTOR* servo,byte dir)
{
	servo->direction = dir;
	digitalWrite(servo->DirectionChannel, dir);
}
byte SERVOMOTORGetDirection(SERVOMOTOR* servo)
{
	return servo->direction;
}



