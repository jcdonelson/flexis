/*
 * STEPPER.H
 *
 *  Created on: Apr 23, 2012
 *      Author: jdonelson
 *      
 * 	$Revision: 305 $
 *	$Date: 2012-04-16 12:28:19 -0400 (Mon, 16 Apr 2012) $
 *	$Author: pl@jimdonelson.com $
 *
 *	$Header: https://seed1.projectlocker.com/jcdonelson/LaserCounter/svn/USBProjects/CFProjects/WORKSPACE/FOOTBED_1/Sources/main.c 305 2012-04-16 16:28:19Z pl@jimdonelson.com $
 *	$HeadURL: https://seed1.projectlocker.com/jcdonelson/LaserCounter/svn/USBProjects/CFProjects/WORKSPACE/FOOTBED_1/Sources/main.c $
       
 */

#ifndef STEPPER_H_
#define STEPPER_H_
/*
 * DEFINES AND MACROS
 */
#define MA_OFF  0x1
#define MA_FWD  0x2
#define MA_REV  0x4
#define MB_OFF  0x10
#define MB_FWD  0x20
#define MB_REV  0x40
#define STEPPER_CLOCKWISE	1
#define STEPPER_CCLOCKWISE	0
// This is for motor controllers that have
// Direction and Enable type inputs.
#define STEPPER_MODE_EN_DIR		1
#define STEPPER_MODE_USE_PWM	2
/*
 * DATA STRUCTURES
 */
typedef struct _stepper_control 
{
	byte direction;   				// 0 or 1 for CCW or CW.
	
	// The user can create a custom step table.
	byte const* table;				// pointer to a step table.
	
	// Pin numbers for digital I/O to the motor.
	// Motors controllers can be A+,A-,B+,B-
	// or enable/direction.
	union {
	byte phaseAEnablePin;			// I/O Pin for Phase A Enable or A+
	byte phaseAPlusPin;				// I/O Pin for Phase A Enable or A+
	};
	union {
	byte phaseADirectionPin;		// I/O Pin for Phase A Direction
	byte phaseAMinusPin;			// I/O Pin for Phase A Direction
	};
	union {
	byte phaseBEnablePin;			// I/O Pin for Phase B Enable or B+
	byte phaseBPlusPin;				// I/O Pin for Phase B Enable or B+
	};
	union {
	byte phaseBDirectionPin;		// I/O Pin for Phase B Enable or B+
	byte phaseBMinusPin;			// I/O Pin for Phase B Enable or B+
	};
	
	int PWMOnValue;
	byte mode;						// STEPPER_MODE_EN_DIR or A+,A-,B+,B-
	byte state;						// index into the table. Starts at 1
	
	// Function pointers for setting the output state
	// and stopping the motor.
	void (*_setouputfunction)(void* sc);
	void (*_stopfunction)(void* sc);
	
} STEPPER_CONTROL;
inline void STEPPERSetDirection(byte dir,STEPPER_CONTROL* sc)
{
	sc->direction = dir;
}

/*
 * FUNCTION PROTOTYPES
 */
void STEPPERStep(STEPPER_CONTROL* sc);
inline void STEPPERSetOutputState(STEPPER_CONTROL* sc)
{
	sc->_setouputfunction(sc);
}
inline void STEPPERStop(STEPPER_CONTROL* sc)
{
	sc->_stopfunction(sc);
}

inline byte STEPPERGetDirection(STEPPER_CONTROL* sc)
{
	return sc->direction;
}
void STEPPERSetOutputState_Type_EnableDirectionPWM(STEPPER_CONTROL* sc);
void STEPPERStopEnableDirectionPWM(STEPPER_CONTROL* sc);


//void STEPPERStepEnableDirection(STEPPER_CONTROL* sc);
byte STEPPERInit(STEPPER_CONTROL* sc);

extern const byte halfstep_table2[9];
extern const byte halfstep_table[9];
extern const byte wave_table[5];
extern const byte fullstep_table[5];




#endif /* STEPPER_H_ */
