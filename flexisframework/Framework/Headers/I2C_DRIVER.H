/*
 * I2C_DRIVER.h
 *
 *  $Rev:: 63                        $:
 *  $Date:: 2011-05-10 22:07:33 -040#$:
 *  $Author:: jcdonelson             $:
 */

#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_



__interrupt void I2CInterruptHandler(void);

#define ERROR_NONE              0
#define ERROR_BUSBUSY           1
#define ERROR_NOTREADY          2
#define ERROR_NAK               4
#define ERROR_ARB_LOSS          8
#define I2C_RecvChar(Chr) I2C_RecvBlock((Chr), (word)1, (word*)&I2C_SndRcvTemp)
byte I2CSetBaudrate(int rate_khz);
byte I2CSend(byte* data,word size);
byte I2CRecieve(byte* data,word size);
word I2CGetRemainingSendBytes(void);
word I2CGetRemainingRecieveBytes(void);
void I2CSetDeviceAddress(byte address);
byte I2CGetLastError();
byte I2CGetStatus(void);
byte I2CInit(void);
byte I2CGetLastError(void);
byte I2CSendAddress(void);


#endif /* I2C_DRIVER_H_ */
