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

    // Mouse wheel
    dst[3] |= (src[3] & 0x0F); // Just copy the 4 bits necessary for wheels

    // PS/2 has 9-bit two's complement notation
    // Serial (microsoft) has 8-bit two's complement notation

    // We need to invert Y
    int8_t y_mov = (-((src[0] & 0x20) ? (0x80 | src[2]) : (src[2] & 0x7F)));
    int8_t x_mov = ((src[0] & 0x10) ? (0x80 | src[1]) : (src[1] & 0x7F));

    y_mov |= (src[0] & 0x80) ? 0x7F : 0; 
    x_mov |= (src[0] & 0x40) ? 0x7F : 0; 

    // Movement - First byte
    dst[0] |= (x_mov >> 6) & 0x03; // X7,X6
    dst[0] |= (y_mov >> 4) & 0x0C; // Y7,Y6
    // Movement - Second byte
    dst[1] |= (x_mov & 0x3F); // X5-X0
    // Movement - Third byte
    dst[2] |= (y_mov & 0x3F); // Y5-Y0

    return retval;
}
