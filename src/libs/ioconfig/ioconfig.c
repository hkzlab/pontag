#include "ioconfig.h"

void io_init() {
    LEDDDR |= _BV(LED_P); // Make LED port an output
    LEDPORT &= ~(_BV(LED_P)); // Turn the LED off
    
    // Configure PS/2 ports as input and disable the pullups (will be external)
    PS2PORT &= ~(_BV(PS2CLK)|_BV(PS2DAT)); // Set the port to low level...
    PS2DDR &= ~(_BV(PS2CLK)|_BV(PS2DAT));  // ... and make it an input

    UARTPORT &= ~(_BV(UARTRX)); // Disable pullup on RX
    UARTDDR &= ~(_BV(UARTRX)); // Make RX an input
    UARTDDR |= _BV(UARTTX); // Make TX an output

    FLOWPORT &= ~(_BV(FLOWRTS)); // Disable pullup on RTS
    FLOWDDR &= ~(_BV(FLOWRTS)); // Make RTS an input

    // Setup the option header
    OPTDDR &= 0xC0; // PC0-5 as inputs
    OPTPORT |= 0x3F; // Enable pullups on PC0-5
}

