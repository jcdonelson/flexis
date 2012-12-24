/*
 * MOTORCMDS.C
 *
 *  Created on: Aug 12, 2012
 *      Author: jdonelson
 */



#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include <ansi_parms.h>
#include <stdio.h>
#include <string.h> 
#include <ctype.h>
#include <stdlib.h>
#include "ALL.H"
#include "CONFIG.H"
#include "STEPPER.H"
#include "CONSOLE.H"
#include "SHELL.H"
#include "MCURESETCF.H"
#include "ENCODER.H"
#include "SERVOMOTOR.H"
#include "MOTORCMDS.H"
extern HCONSOLE _console_data;
extern HSHELL hShell;
extern SERVOMOTOR* _motors[];
byte help(char* cmd)
{
	cmd;
	CONSOLEWritestring(&_console_data, "This is the 'help' command\r\n");
	SHELLShowHelp(&hShell);
	return 0;
}

byte ResetMCU(char* cmd)
{
	cmd;
	MCURESET;
	return 0;
}

extern char dummy[10];
extern byte  nMotors;
byte ServoDirection(char* cmd)
{
	int which,direction;
	sscanf(cmd,"%s %d %d",dummy,&which,&direction);
	
	if(which >= 0 && which < nMotors - 1 )
	{
		SERVOMOTORSetDirection(_motors[which],(byte)direction);
	}

	printf("Direction set to: %s\r\n",(direction == 1) ? "CLW" : "CCLW");
	
}
byte ServoMotorsOff(char*)
{
	int i;
	for( i = 0 ; i < nMotors ; ++i)
		SERVOMOTORSetSpeed(_motors[i],0);
	return 0;
}
byte SetPwmDutyCycle(char* cmd)
{
	int which,duty;
	
	if( 3 != sscanf(cmd,"%s %d %d",dummy,&which,&duty)  )
	{
		   printf("Bad args channel 0/1 duty 0-100\r\n");
		   return 0;
		
	}
	if(which >= 0 && which < nMotors - 1 )
	{
		SERVOMOTORSetSpeed(_motors[which],duty);
	}
	else
	{
		   printf("channel out of range\r\n");
		
	}
}
