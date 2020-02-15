#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <util/delay.h>

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>

#include "ioconfig.h"
#include "ps2.h"
#include "ps2_mouse.h"
#include "ps22ser.h"

#include "uart.h"

#include "main.h"

#define PS2_WHL_PKT_SIZE 4
#define PS2_STD_PKT_SIZE 3

typedef union {
    struct {
        uint8_t msproto : 1;
	uint8_t unused : 5;
    } u;
    uint8_t header;
} Options;

static void rts_init(void);

static void setLED(uint8_t status);

static void sendMSPkt(void);
static void sendMSWheelPkt(void);

// Vars
static volatile uint8_t rts_disable_xmit = 0;
static void (* volatile sendDetectPkt)(void) = &sendMSWheelPkt;

int main(void) {
    Options opts;

    uint8_t serial_pkt_buf[4]; // Buffer for serial packets
    uint8_t ps2_pkt_buf[PS2_WHL_PKT_SIZE] = {0x00, 0x00, 0x00, 0x00}; // Buffer for ps/2 packets
    uint8_t converter_result; // Instanteneous result of the conversion
    uint8_t ps2_buf_counter = 0;
    uint8_t mouse_ext = 0; // Is the mouse PS/2++ compatible?
    uint8_t ps2_pkt_size = 0;

#if defined (__AVR_ATmega328P__)
    wdt_enable(WDTO_4S); // Enable the watchdog to reset in 4 seconds...
#elif defined (__AVR_ATmega8A__)
    wdt_enable(WDTO_2S); // Enable the watchdog to reset in 2 seconds...
#endif

    // Initialize the I/O and communications
    io_init();
    
    // Read the option header
    opts.header = OPTPIN;
    if(!opts.u.msproto) sendDetectPkt = sendMSPkt; // Else will remain the default

    // Initialize RTS interrupt and PS2
    rts_init();
    ps2_init();

    // First watchdog kick
    wdt_reset();

    // TODO: Read the config header here

    // Initialize serial port
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;

    // Enable interrupts
    sei();

    // Clear some vars
    rts_disable_xmit = 0;

    setLED(1); // Turn the LED on

    mouse_ext = mouse_init(opts.u.msproto) & MOUSE_EXT_MASK; // Initialize the mouse

    // Set the PS/2 packet size
    if(mouse_ext) ps2_pkt_size = PS2_WHL_PKT_SIZE;
    else ps2_pkt_size = PS2_STD_PKT_SIZE;

    wdt_reset(); // kick the watchdog again...

    setLED(0); // Turn the LED off

    while(1) {
        wdt_reset(); // Kick the watchdog

        while(ps2_avail()) {
            ps2_pkt_buf[ps2_buf_counter] = ps2_getbyte();
            ps2_buf_counter = (ps2_buf_counter + 1) % ps2_pkt_size;

            if(!ps2_buf_counter) {
                converter_result = ps2bufToSer(ps2_pkt_buf, serial_pkt_buf);

                if(converter_result && !rts_disable_xmit) {
                    ps2_enable_recv(0); // Ok, stop receiving for now

                    //printf("%.2X %.2X %.2X\n", ps2_pkt_buf[0], ps2_pkt_buf[1], ps2_pkt_buf[2]);
                    // Transmit the converted data to the serial port
                    uart_putchar(serial_pkt_buf[0], NULL);
                    uart_putchar(serial_pkt_buf[1], NULL);
                    uart_putchar(serial_pkt_buf[2], NULL);
                    if(opts.u.msproto) uart_putchar(serial_pkt_buf[3], NULL); // Send the fourth byte, according to the Microsoft Wheel mouse specs

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

static void setLED(uint8_t status) {
    if(!status) LEDPORT &= ~(_BV(LED_P)); // Turn the LED off
    else LEDPORT |= _BV(LED_P); // Turn the LED on
}

ISR(INT1_vect) { // Manage INT1
    uint8_t count = 10;

    rts_disable_xmit = 1; // Avoid further transmission from the code in the main loop

    while(count--) {
	sendDetectPkt();

    	_delay_ms(50);
    }

    rts_disable_xmit = 0; // Allow transmission again
}

static void sendMSPkt(void) {
     uart_putchar('M', NULL);
}

static void sendMSWheelPkt(void) {
     uart_putchar('M', NULL);
     uart_putchar('Z', NULL);
     uart_putchar('@', NULL);
     uart_putchar(0x00, NULL);
     uart_putchar(0x00, NULL);
     uart_putchar(0x00, NULL);
}
