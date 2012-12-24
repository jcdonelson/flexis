/*
 * LCD.H
 *
 *  Created on: Dec 28, 2010
 *      Author: jdonelson
 */

#ifndef LCD_H_
#define LCD_H_
void WriteLineLCD(char *string, byte line);
void InitLCD(int width);
void WriteByteLCD(byte data, byte rs);
void ClearLCD(void);
void SetCursorLCD( byte pos);
void WriteBufferLCD(char *string, int count, byte line);
int GetLCDWidth(void);


#endif /* LCD_H_ */
