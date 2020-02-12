#include <stdint.h>
#include <avr/io.h>
#include <avr/wdt.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>

#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#include "ioconfig.h"
#include "ps2.h"
#include "ps2_mouse.h"
#include "ps22ser.h"

#include "uart.h"

#include "main.h"

#define PS2_PKT_SIZE 3

static const uint8_t logitech_detect_pkt[] PROGMEM = "M3"; 

static volatile uint8_t rts_disable_xmit = 0;
static void rts_init(void);

int main(void) {
    uint8_t serial_pkt_buf[4]; // Buffer for serial packets
    uint8_t ps2_pkt_buf[PS2_PKT_SIZE]; // Buffer for ps/2 packets
    uint8_t converter_status; // PS/2 -> Serial conversion state var, used to keep track of state during iteration
    uint8_t converter_result; // Instanteneous result of the conversion
    uint8_t ps2_buf_counter = 0;

#if defined (__AVR_ATmega328P__)
    wdt_enable(WDTO_4S); // Enable the watchdog to reset in 4 seconds...
#elif defined (__AVR_ATmega8A__)
    wdt_enable(WDTO_2S); // Enable the watchdog to reset in 2 seconds...
#endif

    // Initialize the I/O and communications
    io_init();
    rts_init();
    ps2_init();

    // First watchdog kick
    wdt_reset();

    // Initialize serial port
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;

    // Enable interrupts
    sei();

    // Clear some vars
    converter_status = 0;
    rts_disable_xmit = 0;

    // Initialize the mouse
    mouse_init();

    wdt_reset(); // Another kick

    while(1) {
        wdt_reset(); // Kick the watchdog

        while(ps2_avail()) {
            ps2_pkt_buf[ps2_buf_counter] = ps2_getbyte();
            ps2_buf_counter = (ps2_buf_counter + 1) % PS2_PKT_SIZE;

            if(!ps2_buf_counter) {
                converter_result = ps2bufToSer(ps2_pkt_buf, serial_pkt_buf, &converter_status);

                if(converter_result && !rts_disable_xmit) {
                    ps2_enable_recv(0); // Ok, stop receiving for now

                    //printf("%.2X %.2X %.2X\n", ps2_pkt_buf[0], ps2_pkt_buf[1], ps2_pkt_buf[2]);
                    // Transmit the converted data to the serial port
                    uart_putchar(serial_pkt_buf[0], NULL);
                    uart_putchar(serial_pkt_buf[1], NULL);
                    uart_putchar(serial_pkt_buf[2], NULL);
                    if(converter_result & 0x02) uart_putchar(serial_pkt_buf[3], NULL); // Send the fourth byte, according to the Logitech serial protocol

                    ps2_enable_recv(1); // Back to getting data!
                }
            }
        }
    }

    return 0;
}

static void rts_init(void) {
    // Enable INT1, and have it toggle at any logical level change
#if defined (__AVR_ATmega328P__)
    // Toggle at the rising edge
    EICRA |= (1 << ISC10);
    EICRA &= ~(1 << ISC11);
    EIMSK |= (1 << INT1);
#elif defined (__AVR_ATmega8A__)
    MCUCR |= (1 << ISC10);
    MCUCR &= ~(1 << ISC11);
    GICR  |= (1 << INT1);
#endif
}

ISR(INT1_vect) { // Manage INT1
    uint8_t count = 50;
    uint8_t pktb = '\0';
    uint8_t pkt_idx = 0;

    rts_disable_xmit = 1; // Avoid further transmission from the code in the main loop

    while(count--) {
        // Send the detection packet
        pktb = pgm_read_byte(&logitech_detect_pkt[pkt_idx++]);
        while(pktb != '\0') {
            uart_putchar(pgm_read_byte(pktb), NULL);
            pktb = pgm_read_byte(&logitech_detect_pkt[pkt_idx++]);
        }

    	_delay_ms(50);
    }

    rts_disable_xmit = 0; // Allow transmission again
}

