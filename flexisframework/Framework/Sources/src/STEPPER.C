/*
 * STEPPER.C
 *
 *  Created on: Apr 23, 2012
 *      Author: jdonelson
 *      
 *      
 *      
 * 	$Revision: 151 $
 *	$Date: 2012-07-28 23:50:07 -0400 (Sat, 28 Jul 2012) $
 *	$Author: jcdonelson $
 *
 *	$Header: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Sources/src/STEPPER.C 151 2012-07-29 03:50:07Z jcdonelson $
 *	$HeadURL: https://flexisframework.svn.sourceforge.net/svnroot/flexisframework/Framework/Sources/src/STEPPER.C $
 
 */

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "ALL.H"
#include "STEPPER.H"
const byte fullstep_table[5]=
 {
	4,
    MA_FWD | MB_REV,
    MA_FWD | MB_FWD,
    MA_REV | MB_FWD,
    MA_REV | MB_REV,
    
};
const byte wave_table[5]=
 {
	4,
    MA_FWD | MB_OFF,
    MA_OFF | MB_FWD,
    MA_REV | MB_OFF,
    MA_OFF | MB_REV,
    
};

const byte halfstep_table[9]=
{
   8,
   MA_FWD | MB_FWD,
   MA_FWD | MB_OFF,
   MA_FWD | MB_REV,
   MA_OFF | MB_REV,

   MA_REV | MB_REV,
   MA_REV | MB_OFF,
   MA_REV | MB_FWD,                                                                 
   MA_OFF | MB_FWD,
   
};
const byte halfstep_table2[9]=
{
   8,
   MA_FWD | MB_OFF,
   MA_FWD | MB_FWD,
   MA_OFF | MB_FWD,
   MA_REV | MB_FWD,

   MA_REV | MB_OFF,
   MA_REV | MB_REV,
   MA_OFF | MB_REV,                                                                 
   MA_FWD | MB_REV,
   
};

void STEPPERStepEnableDirection(STEPPER_CONTROL* sc);
void STEPPERStopEnableDirection(STEPPER_CONTROL* sc);
void STEPPERSetOutputState_Type_EnableDirection(STEPPER_CONTROL* sc);
byte STEPPERInit(STEPPER_CONTROL* sc)
{
	sc->state = 1;
    pinMode(sc->phaseAEnablePin,OUTPUT);
    pinMode(sc->phaseBEnablePin,OUTPUT);
    pinMode(sc->phaseADirectionPin,OUTPUT);
    pinMode(sc->phaseBDirectionPin,OUTPUT);
    if(sc->mode & STEPPER_MODE_USE_PWM)
    {
        sc->_setouputfunction =(void(*)(void*)) STEPPERSetOutputState_Type_EnableDirectionPWM;
        sc->_stopfunction =(void(*)(void*)) STEPPERStopEnableDirectionPWM;
    	
    }
    else
    {
    sc->_setouputfunction =(void(*)(void*)) STEPPERSetOutputState_Type_EnableDirection;
    sc->_stopfunction =(void(*)(void*)) STEPPERStopEnableDirection;
    }

	return 0;
}
void STEPPERSetOutputState_Type_EnableDirection(STEPPER_CONTROL* sc)
{
    if( sc->table[sc->state] & MA_OFF ) 
      digitalWrite(sc->phaseAEnablePin,0);
    else
      digitalWrite(sc->phaseAEnablePin,1);
    
    if( sc->table[sc->state] & MA_FWD  )
        digitalWrite(sc->phaseADirectionPin,1);
    else    
    	digitalWrite(sc->phaseADirectionPin,0);

    if( sc->table[sc->state] & MB_OFF )
    	digitalWrite(sc->phaseBEnablePin,0);
    else
    	digitalWrite(sc->phaseBEnablePin,1);
    
    if( sc->table[sc->state] & MB_FWD )
    	digitalWrite(sc->phaseBDirectionPin,1);
    else    
    	digitalWrite(sc->phaseBDirectionPin,0);
	
}
void STEPPERSetOutputState_Type_EnableDirectionPWM(STEPPER_CONTROL* sc)
{
    if( sc->table[sc->state] & MA_OFF ) 
      analogWrite(sc->phaseAEnablePin,0);
    else
    	analogWrite(sc->phaseAEnablePin,sc->PWMOnValue);
    
    if( sc->table[sc->state] & MA_FWD  )
    	analogWrite(sc->phaseADirectionPin,sc->PWMOnValue);
    else    
    	analogWrite(sc->phaseADirectionPin,0);

    if( sc->table[sc->state] & MB_OFF )
    	analogWrite(sc->phaseBEnablePin,0);
    else
    	analogWrite(sc->phaseBEnablePin,sc->PWMOnValue);
    
    if( sc->table[sc->state] & MB_FWD )
    	analogWrite(sc->phaseBDirectionPin,sc->PWMOnValue);
    else    
    	analogWrite(sc->phaseBDirectionPin,0);
	
}

void STEPPERStep(STEPPER_CONTROL* sc)
{
    // The table entry determines if a motor phase
    // should be on or off.
	
	//STEPPERSetOutputState_Type_EnableDirection(sc);
	sc->_setouputfunction(sc);
	
	// Advance the state thru the table.
    if( STEPPER_CLOCKWISE == sc->direction)
      {
          ++sc->state;
          // The first entry in the table is how many steps
          // are in the table.
          if( sc->state == (sc->table[0]+1))
          {
        	  // Since the first entry in the table is the count,
        	  // start at 1.
        	  sc->state = 1;
              
          }
      }
    else
      {
        --sc->state;
        // If we are in reverse, then 0 is the last state,
        // and we wrap back to the end of the table.
        if(0 == sc->state )
        {
        	// The first entry in the table is the number of entries.
        	sc->state = sc->table[0];
           
        }
      }
}

void STEPPERStopEnableDirection(STEPPER_CONTROL* sc)
{
    digitalWrite(sc->phaseAEnablePin,0);
    digitalWrite(sc->phaseBEnablePin,0);
	
}
void STEPPERStopEnableDirectionPWM(STEPPER_CONTROL* sc)
{
    analogWrite(sc->phaseAEnablePin,0);
    analogWrite(sc->phaseBEnablePin,0);
	
}
