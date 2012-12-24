#include "../../Framework/Headers/RTC.H"
#include "../../Framework/Headers/SPEAKER.H"
#include "../../Framework/Headers/DIGITAL_IO.H"
#include "../../Framework/Headers/CLOCK.H"
#include "../../Framework/Headers/KEYBRD_LCD.H"
#include "../../Framework/Headers/SERIAL_B.H"
#include "../../Framework/Headers/EDGEINTS.H"
#include "../../Framework/Headers/PULSE.H"
#include "../../Framework/Headers/I2C_DRIVER.H"
#include "../../Framework/Headers/EEPROM.H"
#include "../../Framework/Headers/CONSOLE_IO.H"
#include "../../Framework/Headers/SERVO.H"
#include "../../Framework/Headers/PWRMAN.H"
void CLI(void);
void STI(void);
void setup(void);
void loop(void);
#define ENTER_CRITSEC() cli()
#define EXIT_CRITSEC()  sti()
#ifndef byte
#define byte unsigned char
#define word unsigned short
#define dword unsigned long
#endif

