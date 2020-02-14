#ifndef _PS2_MOUSE_HEADER_
#define _PS2_MOUSE_HEADER_

#include <stdint.h>

#define PS2_MOUSE_RESP_ACK 0xfa
#define PS2_MOUSE_RESP_NAK 0xfe
#define PS2_MOUSE_RESP_ERROR 0xfc
#define PS2_MOUSE_RESP_RESETOK 0xaa

#define PS2_MOUSE_CMD_READEXTID 0xd0
#define PS2_MOUSE_CMD_READ2NDID 0xe1
#define PS2_MOUSE_CMD_SCALNG11 0xe6
#define PS2_MOUSE_CMD_SCALNG21 0xe7
#define PS2_MOUSE_CMD_SET_RESOLUTION 0xe8
#define PS2_MOUSE_CMD_STATREQ 0xe9
#define PS2_MOUSE_CMD_READDATA 0xeb
#define PS2_MOUSE_CMD_CLEARECHO 0xec
#define PS2_MOUSE_CMD_SETECHO 0xee
#define PS2_MOUSE_CMD_REMOTEMODE 0xf0
#define PS2_MOUSE_CMD_READID 0xf2
#define PS2_MOUSE_CMD_SAMPLERATE 0xf3
#define PS2_MOUSE_CMD_ENABLE 0xf4
#define PS2_MOUSE_CMD_DISABLE 0xf5
#define PS2_MOUSE_CMD_SET_DEFAULTS 0xf6
#define PS2_MOUSE_CMD_RESEND 0xfe
#define PS2_MOUSE_CMD_RESET 0xff


#define MOUSE_EXT_MASK 0x08
#define MOUSE_BTN_MASK 0x07

/**
 * Resets, initializes and configures the mouse
 * @param ext If != 0 enable the check for a PS/2++ compatible mouse
 * @return The status of the buttons in the 3 Least Significant Bits, 0 in the 4th bit if a normal mouse is detected, 1 if a PS/2++ compatible mouse is detected
 */
uint8_t mouse_init(uint8_t ext);

uint8_t mouse_reset(void);
int16_t mouse_command(uint8_t cmd, uint8_t wait);
void mouse_setres(uint8_t res);

#endif /* _PS2_MOUSE_HEADER_ */
