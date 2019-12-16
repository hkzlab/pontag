#ifndef _PS2_PROTO_HEADER_
#define _PS2_PROTO_HEADER_

typedef enum {
    ACK = 0xfa,
    NACK = 0xfe,
    ERROR = 0xfc
} PS2_Mouse_Response;

typedef enum {
    MOUSE_ENABLE = 0xf4,
    MOUSE_DISABLE = 0xf5,
    SET_DEFAULTS = 0xf6,
    RESEND = 0xfe,
    RESET = 0xff // Responses: OK -> AA 00, ERROR -> FC 00
} PS2_Mouse_Command;

#endif /* _PS2_PROTO_HEADER_ */
