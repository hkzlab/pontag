#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <util/delay.h>

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#include "ioconfig.h"
#include "ps2.h"
#include "ps2_mouse.h"
#include "ps22ser.h"
#include "pconfig.h"

#include "uart.h"
#include "millis.h"

#include "main.h"

#define VERSION "1.2.0"

#define SLEEP_DELAY_TIME 120000 // 120 seconds without movement before we put the micro to sleep

#define PS2_WHL_PKT_SIZE 4
#define PS2_STD_PKT_SIZE 3

typedef union {
    struct {
        uint8_t default_proto : 1; // if 1, default protocol is enabled, if 0, MS protocol is forced
        uint8_t powersave : 1; // if 1, we enable powersave after 2 minutes idle
        uint8_t standard_mode : 1; // if 1, the board runs normally, if 0, the board enters debug mode
        uint8_t wheel_detect : 1; // if 1, we try PS/2 wheel detection
        uint8_t unused : 2;
    } u;
    uint8_t header;
} HeaderOptions;

static void rts_init(void);

static void setLED(uint8_t status);
static void blinkLED(uint8_t times, uint8_t fast); // Blink the led X times either fast (50ms) or slow (100ms)
static void soft_reset(void);

static void update_configuration(uint8_t buttons, ConfigStruct *cfg);

static void sendMSPkt(void);
static void sendMSWheelPkt(void);
static void sendDebugPkt(void);

static void sleepMode(uint8_t debug);

// Vars
static volatile uint8_t rts_disable_xmit = 0;
static void (* volatile sendDetectPkt)(void) = &sendMSWheelPkt;

int main(void) {
    HeaderOptions opts;
    ConfigStruct cfg;

    uint8_t serial_pkt_buf[4]; // Buffer for serial packets
    uint8_t ps2_pkt_buf[PS2_WHL_PKT_SIZE] = {0x00, 0x00, 0x00, 0x00}; // Buffer for ps/2 packets
    uint8_t converter_result; // Instanteneous result of the conversion
    uint8_t ps2_buf_counter = 0;
    uint8_t init_res = 0; // Init codes
    uint8_t ps2_pkt_size = 0;

    uint8_t cfg_force_ms = 0;

#if defined (__AVR_ATmega328P__)
    wdt_enable(WDTO_4S); // Enable the watchdog to reset in 4 seconds...
#elif defined (__AVR_ATmega8A__)
    wdt_enable(WDTO_2S); // Enable the watchdog to reset in 2 seconds...
#endif

    // Initialize the I/O and communications
    io_init();

    // Read the option header
    opts.header = OPTPIN;
    // Read the config from EEPROM
    read_perm_config(&cfg);
    
    // Option header always wins over stored config
    if(!opts.u.default_proto || cfg.cfg_data.c.proto) cfg_force_ms = 1; // We're enforcing simple Microsoft protocol
    else cfg_force_ms = 0; // Enable mouse wheel protocol

    // Set which type of identification code we'll send
    if(!opts.u.standard_mode) sendDetectPkt = sendDebugPkt;
    else if(cfg_force_ms) sendDetectPkt = sendMSPkt;

    // Initialize RTS interrupt and PS2
    rts_init();
    ps2_init();

    // First watchdog kick
    wdt_reset();

    // Initialize serial port
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;

    // Initialize millisecond counter
    millis_init();

    // Enable interrupts
    sei();

    // Clear some vars
    rts_disable_xmit = 0;

    setLED(1); // Turn the LED on

    uart_enable();

    if(!opts.u.standard_mode) {
        wdt_reset();
        printf(" Board initialized! - %s\n", VERSION);
        printf(" -- hdr -> proto:%u standard:%u pwrsave:%u wheel:%u\n", opts.u.default_proto, opts.u.standard_mode, opts.u.powersave, opts.u.wheel_detect);
        printf(" -- cfg -> proto:%u res:%u\n", cfg.cfg_data.c.proto, cfg.cfg_data.c.res);
        printf(" -- Initializing PS/2 Mouse\n");
        wdt_reset();
    }

    init_res = mouse_init(cfg.cfg_data.c.res, opts.u.wheel_detect); // Initialize the mouse

    if(!opts.u.standard_mode) printf(" -- Initializing result %02X\n", init_res);
    
    // Check if we need to update the configuration
    update_configuration(init_res & MOUSE_BTN_MASK, &cfg);

    // Set the PS/2 packet size
    if(init_res & MOUSE_EXT_MASK) ps2_pkt_size = PS2_WHL_PKT_SIZE;
    else ps2_pkt_size = PS2_STD_PKT_SIZE;

    wdt_reset(); // kick the watchdog again...

    // Notify which mouse we found
    if (init_res & MOUSE_ERR_MASK) blinkLED(2, 1);
    else if(init_res & MOUSE_EXT_MASK) blinkLED(25, 1);
    else blinkLED(10, 1);

    uint32_t last_pkt_time = millis();
    uint32_t now = last_pkt_time;

    while(1) {
        now = millis();
        if(now < last_pkt_time) last_pkt_time = now; // Rollover...

        wdt_reset(); // Kick the watchdog

        while(ps2_avail()) {
            last_pkt_time = now;

            ps2_pkt_buf[ps2_buf_counter] = ps2_getbyte();
            
            // Wait for a packet that has fixed bit 3 at 1, this is an attempt at a resync
            if(!ps2_buf_counter && !(ps2_pkt_buf[ps2_buf_counter] & 0x08)) continue;

            ps2_buf_counter = (ps2_buf_counter + 1) % ps2_pkt_size;

            if(!ps2_buf_counter) {
                converter_result = ps2bufToSer(ps2_pkt_buf, serial_pkt_buf);

                if(converter_result && !rts_disable_xmit) {
                    ps2_enable_recv(0); // Ok, stop receiving for now

                    // debug prints
                    if(!opts.u.standard_mode) {
                        printf("PS/2  <-- %02X %02X %02X %02X\n", ps2_pkt_buf[0], ps2_pkt_buf[1], ps2_pkt_buf[2], ps2_pkt_buf[3]);
                        printf("RS232 --> %02X %02X %02X %02X\n\n", serial_pkt_buf[0], serial_pkt_buf[1], serial_pkt_buf[2], serial_pkt_buf[3]);
                    } else { // Running normally
                        // Transmit the converted data to the serial port
                        uart_putchar(serial_pkt_buf[0], NULL);
                        uart_putchar(serial_pkt_buf[1], NULL);
                        uart_putchar(serial_pkt_buf[2], NULL);
                        if(!cfg_force_ms) uart_putchar(serial_pkt_buf[3], NULL); // Send the fourth byte, according to the Microsoft Wheel mouse specs
                    }

                    ps2_enable_recv(1); // Back to getting data!
                }
            }
        }

        if(!opts.u.powersave && ((now - last_pkt_time) > SLEEP_DELAY_TIME)) { 
            sleepMode(!opts.u.standard_mode);
            last_pkt_time = millis();
            ps2_buf_counter = 0;
        }
    }

    return 0;
}

static void rts_init(void) {
    // Enable INT1, and have it toggle at any logical level change
#if defined (__AVR_ATmega328P__)
    // Toggle at the rising edge
    EICRA |= _BV(ISC10);
    EICRA &= ~_BV(ISC11);
    EIMSK |= _BV(INT1);
#elif defined (__AVR_ATmega8A__)
    MCUCR |= _BV(ISC10);
    MCUCR &= ~_BV(ISC11);
    GICR  |= _BV(INT1);
#endif
}

static void setLED(uint8_t status) {
    if(!status) LEDPORT &= ~(_BV(LED_P)); // Turn the LED off
    else LEDPORT |= _BV(LED_P); // Turn the LED on
}

static void blinkLED(uint8_t times, uint8_t fast) {
    setLED(0);

    while(times--) {
        wdt_reset();

        setLED(1);
        fast ? _delay_ms(50) : _delay_ms(100);
        setLED(0);
        fast ? _delay_ms(50) : _delay_ms(100);
    }
}

ISR(INT1_vect) { // Manage INT1
    rts_disable_xmit = 1; // Avoid further transmission from the code in the main loop

    sendDetectPkt();
    _delay_ms(10);

    rts_disable_xmit = 0; // Allow transmission again
}

static void sendMSPkt(void) {
    uart_putchar('M' | 0x80, NULL);
}

static void sendMSWheelPkt(void) {
    uart_putchar('M' | 0x80, NULL);
    uart_putchar('Z' | 0x80, NULL);
    uart_putchar('@' | 0x80, NULL);
    uart_putchar(0x80, NULL);
    uart_putchar(0x80, NULL);
    uart_putchar(0x80, NULL);
}

static void sendDebugPkt(void) {
    printf("DETECT_PKT\n");
}

static void update_configuration(uint8_t buttons, ConfigStruct *cfg) {
    switch(buttons & 0x05) { // Ignore middle button for now
        case 5: // Both buttons pressed, reset to defaults
            reset_perm_config(cfg);
            write_perm_config(cfg);
            blinkLED(15, 0);
            soft_reset();
            break;
        case 4: // Left button, change protocol
            cfg->cfg_data.c.proto = !(cfg->cfg_data.c.proto);
            write_perm_config(cfg);
            blinkLED(15, 0);
            soft_reset();
            break;
        case 1: // Right button, change resolution
            cfg->cfg_data.c.res = (cfg->cfg_data.c.res + 1) % 4;
            write_perm_config(cfg);
            blinkLED(15, 0);
            soft_reset();
            break;
        case 0: // Nothing to do
        default:
            break;   
    }
}

static void soft_reset(void) {
    wdt_enable(WDTO_15MS);  
    while(1); // This will reset the unit
}

void sleepMode(uint8_t debug) {
    if(debug) printf("sleepMode() - Sleeping!!!\n\n");

    wdt_disable();

    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    cli();

    // Set INT0 to interrupt on low level (falling edge won't work)
#if defined (__AVR_ATmega8A__)
    MCUCR &= ~(_BV(ISC01) | _BV(ISC00));
#elif defined (__AVR_ATmega328P__)
    EICRA &= ~(_BV(ISC01) | _BV(ISC00));
#endif

    // Go to sleep now...
    sleep_enable();
    sei();
    sleep_cpu();
    sleep_disable();

    // Restore interrupt on falling edge for INT0
#if defined (__AVR_ATmega8A__)
    MCUCR |= _BV(ISC01);
#elif defined (__AVR_ATmega328P__)
    EICRA |= _BV(ISC01);
#endif

#if defined (__AVR_ATmega328P__)
    wdt_enable(WDTO_4S); // Enable the watchdog to reset in 4 seconds...
#elif defined (__AVR_ATmega8A__)
    wdt_enable(WDTO_2S); // Enable the watchdog to reset in 2 seconds...
#endif    
    
    if(debug) printf("sleepMode() - Woken Up!!!\n\n");
}
