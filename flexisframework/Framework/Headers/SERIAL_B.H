/*
 * SERIAL_B.H
 * Support for both serial ports.
 *
 *  $Rev:: 46                        $:
 *  $Date:: 2011-04-18 09:41:32 -040#$:
 *  $Author:: jcdonelson             $:
 */

#ifndef SERIAL_H_
#define SERIAL_H_
#define SCI1	0
#define SCI2	1
void SendString(int port,char *s);
void Serial_Init(int port);
byte Serial_setbaudrate(int port,byte Baud);

byte Serial_rxbyte(int port, byte *data);
byte Serial_txbuf(int port,byte* data, word len, word *sent);
byte Serial_txbyte(int port,byte data);

byte Serial_txlen(int port, word *count);
byte Serial_rxlen(int port, word *count);

#define  TX_BUFFER_SIZE   80
#define  RX_BUFFER_SIZE   80
#define RX_EMPTY  	2
#define TX_FULL   	3
#define SCI1		0
#define SCI2		1
#define BAD_BAUD_RATE	1
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


#endif /* SCI1_H_ */
