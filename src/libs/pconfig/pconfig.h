#ifndef _PCONFIG_HEADER_
#define _PCONFIG_HEADER_

typedef struct {
    union {
        struct {
            uint8_t res : 3;
            uint8_t proto : 1;
        } c;
        uint8_t buf[4];
    } cfg_data;
    uint16_t crc;
} ConfigStruct;

#endif /*_PCONFIG_HEADER_*/