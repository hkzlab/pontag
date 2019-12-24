#ifndef _AVR_PS2_MOUSE_HEADER_
#define _AVR_PS2_MOUSE_HEADER_

#include <stdint.h>

#define DATA_BUFFER_SIZE 3

// Clock port MUST be the one corresponding to INT0 !

// Data port can be set at will
void ps2mouse_init(volatile uint8_t *dataPort, volatile uint8_t *dataDir, volatile uint8_t *dataPin, uint8_t pNum);
void ps2mouse_sendCommand(uint8_t *command, uint8_t length);
void ps2mouse_reset(void);
uint8_t ps2mouse_getBufCounter(void);
volatile uint8_t *ps2mouse_getBuffer(void);

#endif /* _AVR_PS2_MOUSE_HEADER_ */
