#include <stdint.h>
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "ps2_mouse.h"
#include "ps22ser.h"

#include "uart.h"

#include "main.h"
#include "ps2_proto.h"

/* 
 * Default connections for 328p
 * PB1 - PS/2 Data port
 * PD2 - PS/2 Clock port
 * PD1 - Serial TX
 * PD0 - Serial RX (unused?)
 * PD3 - Serial RTS input (used to send hello packet)
 */

static volatile uint8_t ser_hello_toggle;

void setup_interrupts(void);

int main(void) {
    uint8_t serial_pkt_buf[4]; // Buffer for serial packets
    uint8_t converter_status; // Converter status
    uint8_t converter_result;

    // Set the pull-up resistor to all unused I/O ...
	DDRB &= 0x03;
	PORTB |= 0xFC;
	
	DDRC &= 0xC0;
	PORTC |= 0x3F;

	DDRD &= 0x06; // Make sure PD0,PD3-7 are input
	PORTD |= 0xF0; // Enable pullup resistors on PD4-7

	// Initialize serial port for output
	uart_init();
	stdout = &uart_output;
	stdin  = &uart_input;

    // Clear some vars
    converter_status = 0;
    ser_hello_toggle = 0;

    _delay_ms(50);

    //fprintf(stdout, "Now waiting...");

	ps2mouse_init(&PORTB, &DDRB, &PINB, 1);
    _delay_ms(100);

	ps2mouse_reset(); // This also enables interrupts

    uint8_t buf_counter = 0;
    uint8_t cur_counter = 0;
    uint8_t *ps2_buf;

    while(1) {
        if(ser_hello_toggle) {
            ser_hello_toggle = 0;
            uart_putchar(SER_HELLO_PKT, NULL);
        } else { // Normal run
            cur_counter = ps2mouse_getBufCounter();
            if(cur_counter != buf_counter) {
                ps2_buf = (uint8_t*)ps2mouse_getBuffer();
                buf_counter = cur_counter;
                converter_result = ps2bufToSer(ps2_buf, serial_pkt_buf, &converter_status);

                fprintf(stdout, "%.2X %.2X %.2X %.2X - %.2X\n", serial_pkt_buf[0], serial_pkt_buf[1], serial_pkt_buf[2], serial_pkt_buf[3], converter_result);
            }
        }
    }

    return 0;
}

void setup_interrupts(void) {
    // Enable INT1
#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega328P__)
	EIMSK |= (1 << INT1);
#elif defined (__AVR_ATtiny4313__)
	GIMSK |= (1 << INT1);
#elif defined (__AVR_ATmega8A__)
	GICR  |= (1 << INT1); // Enable INT1
#endif
}

ISR(INT1_vect) { // Manage INT1
    // Check for PD3 (RTS) to rise
    if (PIND & 0x08) ser_hello_toggle = 1; // Request the mouse to send its hello packet
}

