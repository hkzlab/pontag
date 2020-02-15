#include <avr/eeprom.h>
#include <util/crc16.h>

#include "pconfig.h"

#define EEPROM_ADDRESS_CFG 0x00

static uint16_t calculate_CRC(uint8_t* buf, uint16_t len);
static void reset_cfg(ConfigStruct *cfg);

uint8_t read_perm_config(ConfigStruct *cfg) {
    uint16_t calc_crc = 0;
    eeprom_read_block(cfg, (uint8_t*)EEPROM_ADDRESS_CFG, sizeof(ConfigStruct));

    calc_crc = calculate_CRC(cfg->cfg_data.buf, sizeof(cfg->cfg_data.buf));
    if(calc_crc != cfg->crc) { // Corrupted or invalid config
        reset_cfg(cfg); // Reset it
        return 0;
    } else return 1;
}

void write_perm_config(ConfigStruct *cfg) {
    cfg->crc = calculate_CRC(cfg->cfg_data.buf, sizeof(cfg->cfg_data.buf)); // Update CRC

    // TODO: Store on EEPROM
}

static uint16_t calculate_CRC(uint8_t* buf, uint16_t len) {
    uint16_t crc = 0;

    for (uint16_t i = 0; i < buf[i]; i++) {
        crc = _crc16_update (crc, buf[i]);
    }

    return crc;
}

static void reset_cfg(ConfigStruct *cfg) {
    // TODO: Set defaults

    cfg->crc = calculate_CRC(cfg->cfg_data.buf, sizeof(cfg->cfg_data.buf));
}

