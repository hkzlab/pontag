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

void setup_detection_interrupt(void);

int main(void) {
    uint8_t serial_pkt_buf[4]; // Buffer for serial packets
    uint8_t converter_status; // PS/2 -> Serial conversion state var, used to keep track of state during iteration
    uint8_t converter_result; // Instanteneous result of the conversion

    /**
     * We will do the following
     * 1 - Set all unused I/O as input with pull-up enabled
     * 2 - Setup the pins for the serial port: TX output, RX input (without pullup), RTS (INT1) as input, without pullup
     * 3 - Setup the pins for PS/2 communication: CLOCK input with pullup, DATA input with pullup (will be managed by PS/2 code)
     * 
     * ATMega328p
     * - UART RX : PD0
     * - UART TX : PD1
     * - UART RTS : PD3
     * - PS/2 CLOCK : PD2
     * - PS/2 DATA : PB1
     * 
     * ATMega 8a
     * - UART RX : PD0
     * - UART TX : PD1
     * - UART RTS : PD3
     * - PS/2 CLOCK : PD2
     * - PS/2 DATA : PB1
     * 
     * ATTiny4313
     * - UART RX : PD0
     * - UART TX : PD1
     * - UART RTS : PD3
     * - PS/2 CLOCK : PD2
     * - PS/2 DATA : PB1
     * 
     */

    // Set the pull-up resistor to all unused I/O ...
    DDRB &= 0x01; // PB1-7 as input...
    PORTB = 0xFC; // ...and with pull-up on 2-7

#if defined (__AVR_ATmega8A__) || defined (__AVR_ATmega328P__)
    DDRC &= 0xC0; // PC0-5 as input...
    PORTC = 0x3F; // ...and with pull-up
#endif

    DDRD &= 0x02; // PD0,PD2-7 as input...
    PORTD |= 0xF0; // ...but enable pullup only on PD4-7

    // Initialize serial port
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;

    // Clear some vars
    converter_status = 0;

    _delay_ms(50);


    ps2mouse_init(&PORTB, &DDRB, &PINB, 1);
    _delay_ms(100);

    setup_detection_interrupt();

    ps2mouse_reset(); // This also enables interrupts

    uint8_t buf_counter = 0;
    uint8_t cur_counter = 0;
    uint8_t *ps2_buf;

    while(1) {
            cur_counter = ps2mouse_getBufCounter();
            if(cur_counter != buf_counter) {
                ps2_buf = (uint8_t*)ps2mouse_getBuffer();
                buf_counter = cur_counter;
                converter_result = ps2bufToSer(ps2_buf, serial_pkt_buf, &converter_status);

                if(converter_result) {
                    // Transmit the converted data to the serial port
                    uart_putchar(serial_pkt_buf[0], NULL);
                    uart_putchar(serial_pkt_buf[1], NULL);
                    uart_putchar(serial_pkt_buf[2], NULL);
                    if(converter_result & 0x02) uart_putchar(serial_pkt_buf[3], NULL); // Send the fourth byte, according to the Logitech serial protocol
                }
            }
    }

    return 0;
}

void setup_detection_interrupt(void) {
    // Enable INT1, and have it toggle at any logical level change
#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega328P__)
    // Toggle at the rising edge
    EICRA |= (1 << ISC10);
    EICRA |= (1 << ISC11);
    EIMSK |= (1 << INT1);
#elif defined (__AVR_ATtiny4313__)
    MCUCR |= (1 << ISC10);
    MCUCR &= ~(1 << ISC11);
    GIMSK |= (1 << INT1);
#elif defined (__AVR_ATmega8A__)
    MCUCR |= (1 << ISC10);
    MCUCR &= ~(1 << ISC11);
    GICR  |= (1 << INT1);
#endif
}

ISR(INT1_vect) { // Manage INT1
    _delay_ms(150);
    uart_putchar(SER_HELLO_PKT, NULL);
}

