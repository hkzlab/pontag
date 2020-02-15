# PONTAG
## Introduction
PONTAG is a board that converts a PS/2 mouse into a serial mouse that can be used on old IBM PC and clones, which lacked PS/2 ports but had plenty of serial interfaces (especially if expansion cards are installed).

## Features & Limitations
* Supports 3 buttons+wheel PS/2 mouses and converts their protocol to RS232 serial usable on old PC systems.
* The board requires an external power supply between 8V and 12V to power the MCU and mouse


## Supported protocols
PONTAG emulates a Microsoft 3-buttons Wheel serial mouse by default and transmits the `0x4D 0x5A 0x40 0x00 0x00 0x00` detection string when RTS signal is toggled.

The boards are tested with [CuteMouse](http://cutemouse.sourceforge.net/).


