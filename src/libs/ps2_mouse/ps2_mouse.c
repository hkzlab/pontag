#include "ps2_mouse.h"

#include <util/delay.h>

#include "ps2.h"


static void mouse_flush(uint8_t pace);

static void mouse_flush(uint8_t pace) {
    _delay_ms(pace); 
    do {
        if (ps2_avail()) ps2_getbyte();
        _delay_ms(pace); 
    } while (ps2_avail());
}

uint8_t mouse_reset(void) {
    uint8_t i, b = 33;
    const uint8_t ntries = 11;

    // send reset command    
    ps2_sendbyte(PS2_MOUSE_CMD_RESET);
    ps2_sendbyte(PS2_MOUSE_CMD_RESET);
    ps2_sendbyte(PS2_MOUSE_CMD_RESET);
    
    // wait for some time for mouse self-test to complete
    for (i = 0; i < ntries; i++) {
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
    mouse_flush(0);
    
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


