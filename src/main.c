#include <stdint.h>
#include <avr/io.h>
#include <avr/wdt.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "ioconfig.h"
#include "ps2.h"
#include "ps22ser.h"

#include "uart.h"

#include "main.h"
#include "ps2_proto.h"

void setup_detection_interrupt(void);

int main(void) {
    uint8_t serial_pkt_buf[4]; // Buffer for serial packets
    uint8_t converter_status; // PS/2 -> Serial conversion state var, used to keep track of state during iteration
    uint8_t converter_result; // Instanteneous result of the conversion

    //wdt_enable(WDTO_2S); // Enable the watchdog to reset in 2 seconds...

    // Initialize the I/O 
    io_init();

    // Initialize serial port
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;

    // Clear some vars
    converter_status = 0;

    // First watchdog kick
    //wdt_reset(); 

    //ps2mouse_init(&PORTB, &DDRB, &PINB, 1);
    setup_detection_interrupt();
    //ps2mouse_reset(); // This also enables interrupts

    //wdt_reset(); // Another kick

    uint8_t buf_counter = 0;
    uint8_t cur_counter = 0;
    uint8_t *ps2_buf;

    while(1) {
	    //wdt_reset(); // Kick the watchdog

            /*cur_counter = ps2mouse_getBufCounter();
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
            }*/
    }

    return 0;
}

void setup_detection_interrupt(void) {
    // Enable INT1, and have it toggle at any logical level change
#if defined (__AVR_ATmega328P__)
    // Toggle at the rising edge
    EICRA |= (1 << ISC10);
    EICRA |= (1 << ISC11);
    EIMSK |= (1 << INT1);
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

