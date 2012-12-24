/*
 * KEYBRD_LCD.H
 *
 *  Specific support for the Keyboard, LCD, Button and RGB LED. 
 *  $Rev:: 68                        $:
 *  $Date:: 2011-05-14 15:34:43 -040#$:
 *  $Author:: jcdonelson             $:
 
 */


#ifndef KEYBRD_LCD_H_
#define KEYBRD_LCD_H_

void KPADInit(void);
//byte KBRDScan(void);
//byte BTNScan(void);
#define KPAD_NOCHAR   255
byte KPADReadChar(void);

void LCDWriteLine(char *string, byte line);
void LCDInit(int width,int lines);
void LCDWriteByte(byte data, byte rs);
void LCDClear(void);
void LCDSetCursor( byte pos);
void LCDWriteBuffer(char *string, int count, byte line);
int LCDGetWidth(void);
void BUTTONInit(void);
void BUTTONSetCallback(void(*fb)(int state));

#define RGB_ENABLE      22
#define RGB_GREEN       3
#define RGB_RED         5
#define RGB_BLUE        9
#define RGB_GREEN_PWM   0
#define RGB_RED_PWM     1
#define RGB_BLUE_PWM    3
#define RGB_ON          0
#define RGB_OFF         1
void RGBSetColor(dword rgb);
#endif 
