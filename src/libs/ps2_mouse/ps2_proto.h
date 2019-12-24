#ifndef _PS2_PROTO_HEADER_
#define _PS2_PROTO_HEADER_

#define PS2_MOUSE_RESP_ACK 0xfa
#define PS2_MOUSE_RESP_NACK 0xfe
#define PS2_MOUSE_RESP_ERROR 0xfc

#define PS2_MOUSE_CMD_READID 0xf2
#define PS2_MOUSE_CMD_ENABLE 0xf4
#define PS2_MOUSE_CMD_DISABLE 0xf5
#define PS2_MOUSE_CMD_SET_DEFAULTS 0xf6
#define PS2_MOUSE_CMD_RESEND 0xfe
#define PS2_MOUSE_CMD_RESET 0xff // Responses: OK -> AA 00, ERROR -> FC 00

typedef struct {
    int16_t x, y;
    uint8_t x_overflow : 1;
    uint8_t y_overflow : 1;
    uint8_t left_button : 1;
    uint8_t middle_button : 1;
    uint8_t right_button : 1;
} PS2_Mouse_Frame;

#endif /* _PS2_PROTO_HEADER_ */
