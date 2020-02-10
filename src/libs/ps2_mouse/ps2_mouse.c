#include "ps2_mouse.h"

#include <avr/wdt.h>
#include <util/delay.h>

#include "ps2.h"


static void mouse_flush_fast(void);
static void mouse_flush_med(void);
static void mouse_flush_slow(void);

static void mouse_flush_fast(void) {
    _delay_ms(0);
    do {
        if (ps2_avail()) ps2_getbyte();
        _delay_ms(0);
    } while (ps2_avail());
}

static void mouse_flush_med(void) {
    _delay_ms(22);
    do {
        if (ps2_avail()) ps2_getbyte();
        _delay_ms(22);
    } while (ps2_avail());
}

static void mouse_flush_slow(void) {
    _delay_ms(100);
    do {
        if (ps2_avail()) ps2_getbyte();
        _delay_ms(100);
    } while (ps2_avail());
}

uint8_t mouse_reset(void) {
    uint8_t i, b = 33;
    const uint8_t ntries = 11;

    mouse_flush_fast();

    // Disable the mouse, you never know....
    ps2_sendbyte(PS2_MOUSE_CMD_DISABLE);
    mouse_flush_fast();

    // send reset command
    ps2_sendbyte(PS2_MOUSE_CMD_RESET);
    ps2_sendbyte(PS2_MOUSE_CMD_RESET);
    ps2_sendbyte(PS2_MOUSE_CMD_RESET);

    // Enable it
    ps2_sendbyte(PS2_MOUSE_CMD_ENABLE);

    // wait for some time for mouse self-test to complete
    for (i = 0; i < ntries; i++) {
	wdt_reset();
        _delay_ms(250);
        if (ps2_avail()) {
            b = ps2_getbyte();
            if (b == PS2_MOUSE_RESP_RESETOK) {
                break;
            } else {
                i = ntries;
                break;
            }
        }
    }

    if (i == ntries) return -1;

    // flush the rest of reponse, most likely mouse id == 0
    _delay_ms(100);
    mouse_flush_fast();

    return 0;

}

int16_t mouse_command(uint8_t cmd, uint8_t wait) {
    int16_t response = -1;

    ps2_sendbyte(cmd);
    if (wait) {
        _delay_ms(22);
        if (ps2_avail()) response = ps2_getbyte();
    }

    return response;
}

void mouse_setres(uint8_t res) {
    mouse_command(PS2_MOUSE_CMD_DISABLE, 1);

    mouse_command(PS2_MOUSE_CMD_SET_RESOLUTION, 1);
    mouse_command(res, 1); // 0 = 1, 1 = 2, 2 = 4, 3 = 8 counts/mm

    mouse_command(PS2_MOUSE_CMD_ENABLE, 1);
}

uint8_t mouse_init() {
    uint8_t buttons = 0;

    ps2_enable_recv(1);

    while(!mouse_reset());
    mouse_command(PS2_MOUSE_CMD_DISABLE, 1);
    mouse_command(PS2_MOUSE_CMD_SET_DEFAULTS, 1);
//    mouse_command(PS2_MOUSE_CMD_SCALNG21, 1);
    mouse_command(PS2_MOUSE_CMD_SCALNG11, 1);

    mouse_command(PS2_MOUSE_CMD_SET_RESOLUTION, 1);
//    mouse_command(1, 1);             // 0 = 1, 1 = 2, 2 = 4, 3 = 8 counts/mm
    mouse_command(2, 1);             // 0 = 1, 1 = 2, 2 = 4, 3 = 8 counts/mm

    mouse_command(PS2_MOUSE_CMD_STATREQ, 1);
    _delay_ms(22);

    if (ps2_avail()) buttons = ps2_getbyte() & 0x07;

    mouse_flush_med();

    mouse_command(PS2_MOUSE_CMD_ENABLE, 1);

    mouse_flush_slow();

    return buttons;
}

