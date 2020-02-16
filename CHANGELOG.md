# Changelog
## 1.0 branch
### 1.1.3 (2020.02.16)
- **FIX**: Add a timeout to READID and READSTATUS functions with a default return value. Some mouses seems not to respond to these commands (found a cheap *SAFEWAY* that did this) and this caused the board to reset.

### 1.1.2 (2020.02.16)
- **NEW**: Add DEBUG mode that can be enabled by shorting the 2nd config header to GND.

### 1.1.1 (2020.02.15)
- **FIX**: Correctly read device id even if the device sends an 0xFA or an 0xFC before the actual response

### 1.1.0 (2020.02.15)
- **FIX**: Correctly read mouse status even if the device sends an 0xFA (ACK) before the actual response

- **NEW**: Supports configuration via mouse buttons

### 1.0.2 (2020.02.14)
- **FIX**: Do not uselessly repeat the detection string when `RTS` is toggled

- **NEW**: Replace Logitech 3-button mouse support with Microsoft Wheel mouse support
- **NEW**: Add option to switch between wheel mouse and normal microsoft mouse using options header
- **NEW**: Support for PS/2 Wheel mouses with support for Intellimouse 4-byte protocol

- **MISC**: Added pcb libraries back in the repo

### 1.0.1 (2020.02.12)
- **FIX**: PONTAG now identifies itself as a 3 button Logitech mouse by sending the code `M3` when `RTS` is toggled

- **MISC**: Cleanup docs and reorganized board files

### 1.0.0 (2020.02.12)
- **NEW**: First version, with support for `ATMega328p` and `ATMega8a`

