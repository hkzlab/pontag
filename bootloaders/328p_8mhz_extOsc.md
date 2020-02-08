# BOARD
This configuration is for a `ATMega328P` with an 8Mhz crystal external oscillator connected.

## Bootloader config
Optiboot is configured for a baudrate of `19200`, 8Mhz clock.
Led is on port `B5` and flashes twice.

## Fuses
Suggested fuses are:

- LFUSE 0xFF
- HFUSE 0xDE
- EFUSE 0xFC

### Example programming
```
avrdude  -c stk500v1 \
		-p atmega328p -P /dev/tty.usbserial-FTD61T6Q -b19200 \
		-e -u -U lock:w:0x3f:m -U efuse:w:0xFC:m -U hfuse:w:0xDE:m -U lfuse:w:0xFF:m \
		-U flash:w:optiboot_atmega328.hex -U lock:w:0x2f:m
```


