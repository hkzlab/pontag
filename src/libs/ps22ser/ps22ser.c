#include "ps22ser.h"

uint8_t ps2bufToSer(const uint8_t *src, uint8_t *dst) {
    if(!(src[0] & 0x08)) return 0; // The only validation we can do, checking the single fixed bit in the first byte.
    uint8_t retval = 0x01;

    // Prepare the destination
    dst[0] = 0xC0;
    dst[1] = dst[2] = dst[3] = 0x80; // Clear the destination. Leave the first bit to 1 to simulate 7n2 (we're actually using 8n1)

    // Set the button status, ignore the middle one, for now
    dst[0] |= (src[0] & 0x01) << 5; // Left
    dst[0] |= (src[0] & 0x02) << 3; // Right

    // Now handle the middle one
    dst[3] |= (src[0] & 0x04) << 2; // Set the value of the 4th byte

    // TODO: Mouse wheel

    // PS/2 has 9-bit two's complement notation
    // Serial (microsoft) has 8-bit two's complement notation
    // We can ignore the least significant bit or...
    // ignore the most significant one.

    // We found out that this works best - Ignore the most significant bit
    // We need to invert Y
    int8_t y_mov = -((src[0] & 0x20) ? (0x80 | src[2]) : src[2]);

    // Movement - First byte
    dst[0] |= (src[1] & 0x40) >> 6; // X6
    dst[0] |= (y_mov >> 4) & 0x0C;
    dst[0] |= ((src[0] & 0x10) ? 0x02 : 0x00); // X7 - Sign
    // Movement - Second byte
    dst[1] |= (src[1] & 0x3F) >> 0; // X5-X0
    // Movement - Third byte
    dst[2] |= (y_mov & 0x3F) >> 0; // Y5-Y0

    // Let's ignore the overflow indicators for now

    return retval;
}
