/*
 * SCI1.H
 *
 *  Created on: Sep 27, 2010
 *      Author: jdonelson
 */

#ifndef SCI2_H_
#define SCI2_H_
void SCI2_Init(void);
byte SCI2_TXByte(byte data);
byte SCI2_RXByte(byte *data);
byte SCI2_TxBuffer(byte* data, word len, word *sent);
byte SCI2_RxCount(word *count);
byte SCI2_TxCount(word *count);

#define  TX_BUFFER_SIZE   80
#define  RX_BUFFER_SIZE   80
#define RX_EMPTY  2
#define TX_FULL   3
//
//
//
// 0 = 1200
// 1 = 2400
// 2 = 4800
// 3 = 9600
// 4 = 19200
// 5 =  38400
// 6 = 57600
// 7 = 115200
#define BAUD_1200   0
#define BAUD_2400   1
#define BAUD_4800   2
#define BAUD_9600   3
#define BAUD_19200  4
#define BAUD_38400  5
#define BAUD_57600  6
#define BAUD_115200 7

byte SCI2_SetBaudRate(byte Baud);
#endif /* SCI1_H_ */
