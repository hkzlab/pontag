#include <stdint.h>
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "ps2_mouse.h"

#include "uart.h"

#include "main.h"


int main(void) {
    uint8_t commands[1];
	
    // Set the pull-up resistor to all unused I/O ...
	DDRB &= 0x03;
	PORTB |= 0xFC;
	
	DDRC &= 0xC0;
	PORTC |= 0x3F;

//	DDRD &= 0x0C;
	DDRD &= 0x0E;
//	PORTD |= 0xF3;
	PORTD |= 0xF0;

	// Initialize serial port for output
	uart_init();
	stdout = &uart_output;
	stdin  = &uart_input;
	
    _delay_ms(50);

    fprintf(stdout, "Now waiting...");

	ps2mouse_init(&PORTB, &DDRB, &PINB, 1);
    _delay_ms(100);

	commands[0] = 0xF6;
	ps2mouse_sendCommand(commands, 1); // This also enables interrupts
    _delay_ms(100);

	commands[0] = 0xF4;
	ps2mouse_sendCommand(commands, 1); // This also enables interrupts
    _delay_ms(100);

	while(1);

    return 0;
}


