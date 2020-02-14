#ifndef _PS22SER_HEADER_
#define _PS22SER_HEADER_

#include <stdint.h>

/**
 * This function converts a 3-byte PS/2 mouse packet into a 3 or 4 bytes
 * Microsoft/Logitech serial protocol
 * @param src Pointer to a 3-byte uint8_t buffer that contains the PS/2 mouse packet
 * @param dst Pointer to a 4-byte uint8_t buffer that will contain the converted response in serial protocol
 * @return Bitmask that returns the state of the conversion. If 0, the conversion did not work else, the conversion was performed. If `((value & 0x2) != 0)` then the conversion used 4 bytes.
 */
uint8_t ps2bufToSer(const uint8_t *src, uint8_t *dst);

#endif /* _PS22SER_HEADER_ */
