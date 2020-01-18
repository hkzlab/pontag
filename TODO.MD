# Code TODOs
- [X] Add ifdefs in code to differentiate between 328p at 16 and 8Mhz

# Board TODOs
- [ ] Support power from 5v header and from TX, RTS, DTR lines
- [ ] Make sure power sources are selected via header
- [ ] Consider adding a capacitor on the power line to survive small drops of power when toggling RTS/DTR lines
- [ ] If we wish to use 3.3v to power the AVR, we need to keep a 12v->5v regulator for the PS/2 mouse

# Misc TODOs
## Makefile
- [ ] For `Makefile.328_p` make sure AVR fuses are set to internal RC
- [ ] For `Makefile.8a` make sure fuses and `avrdude` options are correct for ATmega8A

## Bootloader
- [ ] Decide which bootloader to use (if any). E.g [optiboot](https://github.com/Optiboot/optiboot)
- [ ] If using the bootloader, how much time to wait before starting the program?
