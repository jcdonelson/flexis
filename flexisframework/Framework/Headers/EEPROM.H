/*
 * EEPROM.H
 * Provides support for 2432 EEPROM.
 * Requires the I2C Modules. You must Initalize the I2C
 * module before using this code.
 *  $Rev:: 68                        $:
 *  $Date:: 2011-05-14 15:34:43 -040#$:
 *  $Author:: jcdonelson             $:
 */

#ifndef EEPROM_H_
#define EEPROM_H_
typedef struct _eeprom_write {
	word address;
	byte data[32];
} EEPROM_WRITE_BLOCK;
extern byte EEPROMReadBlock(word address, byte* data,word count);
extern byte EEPROMWriteBlock( byte*data, byte QuickReturn);
extern byte EEPROMTestBusy();
#define I2C_EEPROM_ModuleAddress 0xA4
#endif /* EEPROM_H_ */
