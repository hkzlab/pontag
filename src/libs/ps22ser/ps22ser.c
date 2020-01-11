#include "ps22ser.h"

uint8_t ps2bufToSer(const uint8_t *src, uint8_t *dst, uint8_t *state) {
    if(!(src[0] & 0x08)) return 0; // The only validation we can do, checking the single fixed bit in the first byte.
    uint8_t retval = 0x01;

    // Prepare the destination
    dst[0] = 0xC0;
    dst[1] = dst[2] = dst[3] = 0x80; // Clear the destination. Leave the first bit to 1 to simulate 7n2 (we're actually using 8n1)

    // Set the button status, ignore the middle one, for now
    dst[0] |= (src[0] & 0x01) << 5; // Left
    dst[0] |= (src[0] & 0x02) << 3; // Right

    // Now handle the middle one
    uint8_t midb = src[0] & 0x04; // Middle button state
    if(midb) {
        retval |= 0x02; // We're going to use the 4th byte
        *state |= 0x01; // Save the state regarding the middle button state
    } else if (*state & 0x01) { // The button is not pressed, but it was before
        retval |= 0x02; // We're going to use the 4th byte
        *state &= 0xFE;
    }
    dst[3] |= midb << 3; // Set the value of the 4th byte

    // PS/2 has 9-bit two's complement notation
    // Serial (microsoft) has 8-bit two's complement notation
    // We can ignore the least significant bit or...
    // ignore the most significant one.

    // TEST 1 - Ignore the least significant bit
    // Movement - First byte
    //dst[0] |= (src[0] & 0x20) >> 2; // Y7
    //dst[0] |= (src[0] & 0x10) >> 3; // X7
    //dst[0] |= (src[2] & 0x80) >> 5; // Y6
    //dst[0] |= (src[1] & 0x80) >> 7; // X6
    // Movement - Second byte
    //dst[1] |= (src[1] & 0x7E) >> 1; // X5-X0
    // Movement - Third byte
    //dst[2] |= (src[2] & 0x7E) >> 1; // Y6-Y0

    // TEST 2 - Ignore the most significant bit
    // Movement - First byte
    dst[0] |= (src[2] & 0x40) >> 4; // Y6
    dst[0] |= (src[1] & 0x40) >> 6; // X6
    dst[0] |= ((src[0] & 0x20) ? 0x08 : 0x00); // Y7 - Sign
    dst[0] |= ((src[0] & 0x10) ? 0x02 : 0x00); // X7 - Sign
    // Movement - Second byte
    dst[1] |= (src[1] & 0x3F) >> 0; // X5-X0
    // Movement - Third byte
    dst[2] |= (src[2] & 0x3F) >> 0; // Y6-Y0

    // Let's ignore the overflow indicators for now

    return retval;
}
