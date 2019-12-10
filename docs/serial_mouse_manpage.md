# Serial Mouse Interface
The following text is taken from the linux [man page](https://www.systutorials.com/docs/linux/man/4-mouse/) about the serial mouse interface.

## Introduction
The pinout of the usual 9 pin plug as used for serial mice is:
```
pin name  used for
2   RX	  Data
3   TX	  -12 V, Imax = 10 mA
4   DTR	  +12 V, Imax = 10 mA
7   RTS	  +12 V, Imax = 10 mA
5   GND	  Ground
```
This is the specification, in fact 9 V suffices with most mice.

### Initialization
The mouse driver can recognize a mouse by **dropping RTS to low and raising it again**.
About **14 ms** later the mouse will send **0x4D** ('M') on the data line.
After a further **63 ms**, a Microsoft-compatible 3-button mouse will send **0x33** ('3').
The relative mouse movement is sent as dx (positive means right) and dy (positive means down).

#### Speed selection
Various mice can operate at different speeds.
To select speeds, cycle through the speeds 9600, 4800, 2400, and 1200 bit/s, each time writing the two characters from the table below and waiting **100 ms**.
The following table shows available speeds and the strings that select them:
```
bit/s   string
9600    *q
4800    *p
2400    *o
1200    *n
```
The first byte of a data packet can be used for synchronization purposes.
