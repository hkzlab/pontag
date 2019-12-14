#ifndef _AVR_PS2_MOUSE_HEADER_
#define _AVR_PS2_MOUSE_HEADER_

#include <stdint.h>

// Clock port MUST be the one corresponding to INT0 !

// Data port can be set at will
void ps2mouse_init(volatile uint8_t *dataPort, volatile uint8_t *dataDir, volatile uint8_t *dataPin, uint8_t pNum);
void ps2mouse_setCallback(void (*callback)(uint8_t *code, uint8_t count));
void ps2mouse_sendCommand(uint8_t *command, uint8_t length);

#endif /* _AVR_PS2_MOUSE_HEADER_ */
