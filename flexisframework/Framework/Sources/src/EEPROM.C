
/*
 * EEPROM.C
 * 
 * 
 *  $Rev:: 68                        $:
 *  $Date:: 2011-05-14 15:34:43 -040#$:
 *  $Author:: jcdonelson             $:
 * This code is licensed under GPL, any version.
 */
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "EEPROM.h"
#include "I2C_DRIVER.h"




/*
 * TestEEPROMBusy() - Tries to send address 0 to see if you get a NACK
 * this will happen while the EEPROM is writing a block. This takes about
 * 5ms.
 */
byte EEPROMTestBusy()
{
	word address = 0;
	int i;
	
	for( i = 0; I2CGetRemainingSendBytes() > 0  && i < 10000 ; ++i)
		;
	while( ERROR_BUSBUSY == I2CSend((byte*) &address,2) )
		   ;
	while(I2CGetRemainingSendBytes() > 0)
		;
	return I2CGetLastError();
}
byte EEPROMWriteBlock( byte*data, byte QuickReturn)
{
   
        PTGDD |= 4;
        PTGD  &= ~4;
	while( ERROR_BUSBUSY ==  I2CSend(data,34) )
		   ;

	if(QuickReturn)
		return;
	while( EEPROMTestBusy() != 0)
		;
	return 0;
	
}
byte EEPROMReadBlock(word address, byte*data,word count)
{
	
	while( ERROR_BUSBUSY == I2CSend((byte*)&address,2) )
		   ;
        while(I2CGetRemainingSendBytes() > 0)
                ;

	while( ERROR_BUSBUSY == I2CRecieve(data,count) )
		   ;

	return 0;
	
}
