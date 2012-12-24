/*
 *  ALL_SOURCE_S08.C
 *
 *  Includes all the source files into a projects.
 * 	Use this file so if new files are added, this file will be updated and the files
 *  will be included.
 *  Excludes files that are not support for S08
 *  $Rev:: 63                        $:
 *  $Date:: 2011-05-10 22:07:33 -040#$:
 *  $Author:: jcdonelson             $:

*/

#ifndef MCU_HCS08
#define MCU_HCS08		1
#endif
//
#include "../../Framework/Sources/src/CLOCK.C"
//#include "../../Framework/Sources/src/CONSOLE_IO.C"
#include "../../Framework/Sources/src/COUNTER.C"
#include "../../Framework/Sources/src/DIGITAL_IO.C"
#include "../../Framework/Sources/src/EEPROM.C"
#include "../../Framework/Sources/src/I2C_DRIVER.C"
//#include "../../Framework/Sources/src/MCF51_support.c"

#include "../../Framework/Sources/src/PULSE.C"
#include "../../Framework/Sources/src/RTC.C"
#include "../../Framework/Sources/src/SERIAL_B.c"
#include "../../Framework/Sources/src/SERVO.c"
#include "../../Framework/Sources/src/SPEAKER.C"
#include "../../Framework/Sources/src/KEYBRD_LCD.C"
#include "../../Framework/HCS08/HCS08_support.c"






