# BOARD
This configuration is for a `ATMega328P` with an 8Mhz crystal external oscillator connected.

## Bootloader config
Optiboot is configured for a baudrate of `38400`, 8Mhz clock.
Led is on port `B5` and flashes twice.

## Fuses
Suggested fuses are:

- LFUSE 0xFF
- HFUSE 0xDE
- EFUSE 0xFC

### Example programming
```
avrdude  -c dragon_isp -p atmega328p -e -u -U efuse:w:0xFC:m -U hfuse:w:0xDE:m -U lfuse:w:0xFF:m -U flash:w:optiboot_atmega328.hex
```

You can then access it via the serial port:
```
avrdude  -c arduino -p atmega328p -P /dev/ttyUSB0 -b38400
```

