#ifndef _IOCONFIG_H_
#define _IOCONFIG_H_

// I/O port definitions

#include <avr/io.h>

#define PS2PORT PORTD           // PS2 port
#define PS2PIN  PIND            // PS2 input
#define PS2DDR  DDRD            // PS2 data direction
#define PS2CLK  2               // PS2CLK is pin 2
#define PS2DAT  4               // PS2DAT is pin 4

#define PS2_RXBUF_LEN  16       // PS2 receive buffer size

#define UARTPORT PORTD		// UART port
#define UARTPIN  PIND		// UART input
#define UARTDDR  DDRD		// UART direction
#define UARTRX   0		// UART RX is pin 0
#define UARTTX   1		// UART TX is pin 1

#define FLOWPORT PORTD		// Flow control port
#define FLOWPIN  PIND		// Flow control input
#define FLOWDDR  DDRD		// Flow control direction
#define FLOWRTS  3		// RTS is pin 3

#define LEDPORT	 PORTB
#define LEDPIN   PINB
#define LEDDDR   DDRB
#define LED_P    5

// PC0-5 are used as option header
#define OPTPORT  PORTC
#define OPTPIN   PINC
#define OPTDDR   DDRC

void io_init(void);

#endif /* _IOCONFIG_H_ */
