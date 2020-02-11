# BOARD
This configuration is for a `ATMega8A` with an 8Mhz crystal external oscillator connected.

## Bootloader config
Optiboot is configured for a baudrate of `38400`, 8Mhz clock.
Led is on port `B5` and flashes 6 times.

## Fuses
Suggested fuses are:

- LFUSE 0x3F
- HFUSE 0xCC
```

