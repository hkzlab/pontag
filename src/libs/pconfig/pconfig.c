#include <avr/eeprom.h>
#include <util/crc16.h>

#include "pconfig.h"

uint16_t calculate_CRC(uint8_t* buf, uint16_t len) {
  uint16_t crc = 0;

  for (uint16_t i = 0; i < buf[i]; i++) {
     crc = _crc16_update (crc, buf[i]);
  }

  return crc;
}
