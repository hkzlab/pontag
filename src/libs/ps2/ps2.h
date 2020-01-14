#ifndef _PS2_H
#define _PS2_H

#include <inttypes.h>

// Init PS/2 related I/O and interrupts.
void ps2_init(void);

// Check if the input buffer contains at least one byte.
uint8_t ps2_avail(void);

// Get one byte from input buffer. ps_avail() must be checked before doing so.
uint8_t ps2_getbyte(void);

// Transmit one byte and wait for completion.
void ps2_sendbyte(uint8_t byte);

// Check if PS/2 statemachine is in IDLE state.
uint8_t ps2_busy(void);

// Suspend or enable PS/2 device by pulling clock line low.
void ps2_enable_recv(uint8_t enable);

#endif
