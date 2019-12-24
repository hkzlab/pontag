#ifndef _AVR_EXPERIMENTS_DEFINES_
#define _AVR_EXPERIMENTS_DEFINES_

#if defined (__AVR_ATmega128__) // Apparently, devs forgot to add these...
// UBRR0 has split registers
#define UBRR1 _SFR_MEM16(0x99)
#endif

// token pasting
#define token_paste2_int(x, y) x ## y
#define token_paste2(x, y) token_paste2_int(x, y)
#define token_paste3_int(x, y, z) x ## y ## z
#define token_paste3(x, y, z) token_paste3_int(x, y, z)

#endif /* _AVR_EXPERIMENTS_DEFINES_ */
