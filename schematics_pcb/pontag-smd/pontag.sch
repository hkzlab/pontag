EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Pontag Mouse Adapter (SMD)"
Date ""
Rev ""
Comp "HKZlab"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:Crystal Y1
U 1 1 5E22F58A
P 1600 7300
F 0 "Y1" V 1646 7169 50  0000 R CNN
F 1 "8.0Mhz" V 1555 7169 50  0000 R CNN
F 2 "Crystal:Crystal_SMD_HC49-SD" H 1600 7300 50  0001 C CNN
F 3 "~" H 1600 7300 50  0001 C CNN
	1    1600 7300
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R1
U 1 1 5E22FC65
P 1250 7300
F 0 "R1" H 1320 7346 50  0000 L CNN
F 1 "1M" H 1320 7255 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 1180 7300 50  0001 C CNN
F 3 "~" H 1250 7300 50  0001 C CNN
	1    1250 7300
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C1
U 1 1 5E2300A3
P 1000 7150
F 0 "C1" V 1229 7150 50  0000 C CNN
F 1 "22pF" V 1138 7150 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 1000 7150 50  0001 C CNN
F 3 "~" H 1000 7150 50  0001 C CNN
	1    1000 7150
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C2
U 1 1 5E230E1C
P 1000 7450
F 0 "C2" V 800 7450 50  0000 C CNN
F 1 "22pF" V 900 7450 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 1000 7450 50  0001 C CNN
F 3 "~" H 1000 7450 50  0001 C CNN
	1    1000 7450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1100 7150 1250 7150
Wire Wire Line
	1250 7150 1600 7150
Connection ~ 1250 7150
Wire Wire Line
	1600 7150 2100 7150
Connection ~ 1600 7150
Wire Wire Line
	1100 7450 1250 7450
Wire Wire Line
	1250 7450 1600 7450
Connection ~ 1250 7450
Wire Wire Line
	1600 7450 2100 7450
Connection ~ 1600 7450
Wire Wire Line
	900  7150 800  7150
Wire Wire Line
	800  7150 800  7300
Wire Wire Line
	800  7450 900  7450
$Comp
L power:GND #PWR0101
U 1 1 5E23224E
P 650 7350
F 0 "#PWR0101" H 650 7100 50  0001 C CNN
F 1 "GND" H 655 7177 50  0000 C CNN
F 2 "" H 650 7350 50  0001 C CNN
F 3 "" H 650 7350 50  0001 C CNN
	1    650  7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	650  7350 650  7300
Wire Wire Line
	650  7300 800  7300
Connection ~ 800  7300
Wire Wire Line
	800  7300 800  7450
Text Label 2100 7150 2    50   ~ 0
XTAL1
Text Label 2100 7450 2    50   ~ 0
XTAL2
Text Notes 650  6750 0    100  ~ 0
External Oscillator
Wire Notes Line
	550  6550 550  7750
Wire Notes Line
	550  7750 2200 7750
Text Notes 3400 6750 2    100  ~ 0
5V Regulation
$Comp
L power:GND #PWR0104
U 1 1 5E2EF703
P 750 5850
F 0 "#PWR0104" H 750 5600 50  0001 C CNN
F 1 "GND" H 900 5750 50  0000 C CNN
F 2 "" H 750 5850 50  0001 C CNN
F 3 "" H 750 5850 50  0001 C CNN
	1    750  5850
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J2
U 1 1 5E2E62E5
P 1550 5650
F 0 "J2" H 1500 5650 50  0000 R CNN
F 1 "External 12V" H 1850 5500 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1550 5650 50  0001 C CNN
F 3 "~" H 1550 5650 50  0001 C CNN
	1    1550 5650
	-1   0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0105
U 1 1 5E2D809B
P 750 5400
F 0 "#PWR0105" H 750 5250 50  0001 C CNN
F 1 "+12V" H 765 5528 50  0000 L CNN
F 2 "" H 750 5400 50  0001 C CNN
F 3 "" H 750 5400 50  0001 C CNN
	1    750  5400
	1    0    0    -1  
$EndComp
Text Notes 1700 4900 2    100  ~ 0
Power Ingress
Wire Notes Line
	2200 6550 550  6550
Wire Notes Line
	2200 7750 2200 6550
Wire Notes Line
	2250 7750 2250 6550
$Comp
L Connector:DB9_Female_MountingHoles J3
U 1 1 5E3B36FB
P 9150 2300
F 0 "J3" V 9400 1950 50  0000 L CNN
F 1 "RS232 Port" V 9400 2250 50  0000 L CNN
F 2 "Connector_Dsub:DSUB-9_Female_EdgeMount_P2.77mm" H 9150 2300 50  0001 C CNN
F 3 " ~" H 9150 2300 50  0001 C CNN
	1    9150 2300
	0    1    1    0   
$EndComp
Wire Notes Line
	550  4700 550  6500
$Comp
L Device:LED D5
U 1 1 5E3C22C0
P 4250 2000
F 0 "D5" H 4243 1745 50  0000 C CNN
F 1 "LED" H 4243 1836 50  0000 C CNN
F 2 "LED_SMD:LED_1206_3216Metric" H 4250 2000 50  0001 C CNN
F 3 "~" H 4250 2000 50  0001 C CNN
	1    4250 2000
	-1   0    0    1   
$EndComp
Wire Wire Line
	900  5650 750  5650
Wire Wire Line
	1200 5650 1350 5650
Wire Wire Line
	750  5750 750  5850
Wire Wire Line
	750  5750 1350 5750
$Comp
L Device:R R2
U 1 1 5E3D1A5F
P 4650 2000
F 0 "R2" V 4857 2000 50  0000 C CNN
F 1 "470" V 4766 2000 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 4580 2000 50  0001 C CNN
F 3 "~" H 4650 2000 50  0001 C CNN
	1    4650 2000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4400 2000 4500 2000
$Comp
L power:GND #PWR0106
U 1 1 5E3EFA40
P 4900 2000
F 0 "#PWR0106" H 4900 1750 50  0001 C CNN
F 1 "GND" H 4905 1827 50  0000 C CNN
F 2 "" H 4900 2000 50  0001 C CNN
F 3 "" H 4900 2000 50  0001 C CNN
	1    4900 2000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4800 2000 4900 2000
Wire Wire Line
	3600 2900 4100 2900
Wire Wire Line
	3600 3000 4100 3000
Text Label 4100 2900 2    50   ~ 0
TTL-RX
Text Label 4100 3000 2    50   ~ 0
TTL-TX
Wire Wire Line
	3600 3200 4100 3200
Text Label 4100 3200 2    50   ~ 0
TTL-CTS
$Comp
L power:VCC #PWR0109
U 1 1 5E412B39
P 4400 7000
F 0 "#PWR0109" H 4400 6850 50  0001 C CNN
F 1 "VCC" H 4500 7100 50  0000 C CNN
F 2 "" H 4400 7000 50  0001 C CNN
F 3 "" H 4400 7000 50  0001 C CNN
	1    4400 7000
	1    0    0    -1  
$EndComp
Wire Notes Line
	4650 6550 4650 7750
Wire Notes Line
	2250 7750 4650 7750
Wire Notes Line
	2250 6550 4650 6550
$Comp
L Device:C C5
U 1 1 5E433F59
P 3200 5650
F 0 "C5" H 3315 5696 50  0000 L CNN
F 1 "100nF" H 3315 5605 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 3238 5500 50  0001 C CNN
F 3 "~" H 3200 5650 50  0001 C CNN
	1    3200 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 5E434F23
P 3650 5650
F 0 "C6" H 3765 5696 50  0000 L CNN
F 1 "100nF" H 3765 5605 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 3688 5500 50  0001 C CNN
F 3 "~" H 3650 5650 50  0001 C CNN
	1    3650 5650
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0112
U 1 1 5E4384CA
P 2900 5400
F 0 "#PWR0112" H 2900 5250 50  0001 C CNN
F 1 "VCC" H 3050 5500 50  0000 C CNN
F 2 "" H 2900 5400 50  0001 C CNN
F 3 "" H 2900 5400 50  0001 C CNN
	1    2900 5400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 5E438DAB
P 2900 5900
F 0 "#PWR0113" H 2900 5650 50  0001 C CNN
F 1 "GND" H 3050 5800 50  0000 C CNN
F 2 "" H 2900 5900 50  0001 C CNN
F 3 "" H 2900 5900 50  0001 C CNN
	1    2900 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 5450 4100 5500
Wire Wire Line
	3650 5450 3650 5500
Connection ~ 3650 5450
Wire Wire Line
	3650 5450 4100 5450
Wire Wire Line
	3200 5450 3200 5500
Connection ~ 3200 5450
Wire Wire Line
	3200 5450 3650 5450
Wire Wire Line
	2900 5900 2900 5850
Wire Wire Line
	2900 5850 3200 5850
Wire Wire Line
	4100 5850 4100 5800
Wire Wire Line
	3650 5800 3650 5850
Connection ~ 3650 5850
Wire Wire Line
	3650 5850 4100 5850
Wire Wire Line
	3200 5800 3200 5850
Connection ~ 3200 5850
Wire Wire Line
	3200 5850 3650 5850
Wire Wire Line
	2900 5400 2900 5450
Wire Wire Line
	2900 5450 3200 5450
Wire Notes Line
	4650 4700 4650 6500
Wire Notes Line
	550  6500 4650 6500
Wire Notes Line
	550  4700 4650 4700
Wire Wire Line
	3600 3100 4100 3100
Wire Wire Line
	3600 3300 4100 3300
Text Label 4100 3100 2    50   ~ 0
PS2-CLOCK
Text Label 4100 3300 2    50   ~ 0
PS2-DATA
$Comp
L Switch:SW_Push SW1
U 1 1 5E47EC3B
P 6300 6050
F 0 "SW1" V 6100 6100 50  0000 L CNN
F 1 "Reset" V 6400 6150 50  0000 L CNN
F 2 "Button_Switch_SMD:SW_SPST_FSMSM" H 6300 6250 50  0001 C CNN
F 3 "~" H 6300 6250 50  0001 C CNN
	1    6300 6050
	0    1    1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 5E4BBEBC
P 4250 3100
F 0 "R4" V 4150 3050 50  0000 C CNN
F 1 "5K" V 4150 3200 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 4180 3100 50  0001 C CNN
F 3 "~" H 4250 3100 50  0001 C CNN
	1    4250 3100
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 5E4B26BA
P 4250 3300
F 0 "R3" V 4350 3250 50  0000 C CNN
F 1 "5K" V 4350 3400 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 4180 3300 50  0001 C CNN
F 3 "~" H 4250 3300 50  0001 C CNN
	1    4250 3300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 5E48BB1B
P 5650 7550
F 0 "#PWR0114" H 5650 7300 50  0001 C CNN
F 1 "GND" H 5550 7500 50  0000 R CNN
F 2 "" H 5650 7550 50  0001 C CNN
F 3 "" H 5650 7550 50  0001 C CNN
	1    5650 7550
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0115
U 1 1 5E489348
P 5250 7300
F 0 "#PWR0115" H 5250 7150 50  0001 C CNN
F 1 "VCC" V 5350 7300 50  0000 L CNN
F 2 "" H 5250 7300 50  0001 C CNN
F 3 "" H 5250 7300 50  0001 C CNN
	1    5250 7300
	0    -1   -1   0   
$EndComp
Text Label 6450 7400 2    50   ~ 0
PS2-DATA
Text Label 6450 7200 2    50   ~ 0
PS2-CLOCK
Wire Wire Line
	5950 7200 6450 7200
Wire Wire Line
	5950 7400 6450 7400
Wire Wire Line
	5350 7300 5250 7300
$Comp
L power:VCC #PWR0116
U 1 1 5E4E9A15
P 4500 3200
F 0 "#PWR0116" H 4500 3050 50  0001 C CNN
F 1 "VCC" V 4600 3200 50  0000 L CNN
F 2 "" H 4500 3200 50  0001 C CNN
F 3 "" H 4500 3200 50  0001 C CNN
	1    4500 3200
	0    1    -1   0   
$EndComp
Wire Wire Line
	4400 3100 4450 3100
Wire Wire Line
	4450 3100 4450 3200
Wire Wire Line
	4450 3300 4400 3300
Wire Wire Line
	4500 3200 4450 3200
Connection ~ 4450 3200
Wire Wire Line
	4450 3200 4450 3300
Wire Notes Line
	4700 6550 4700 7750
Wire Notes Line
	4700 7750 6850 7750
Wire Notes Line
	6850 7750 6850 6550
Wire Notes Line
	6850 6550 4700 6550
Text Notes 6100 6750 2    100  ~ 0
PS/2 Connection
Wire Wire Line
	3600 1800 4050 1800
Text Label 4050 1800 2    50   ~ 0
MOSI
Wire Wire Line
	3600 1900 4050 1900
Text Label 4050 1900 2    50   ~ 0
MISO
Text Label 3800 2000 2    50   ~ 0
SCK
$Comp
L Device:R R5
U 1 1 5E5455BD
P 1950 1350
F 0 "R5" H 2050 1400 50  0000 C CNN
F 1 "10K" H 2150 1300 50  0000 R CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 1880 1350 50  0001 C CNN
F 3 "~" H 1950 1350 50  0001 C CNN
	1    1950 1350
	1    0    0    -1  
$EndComp
Wire Notes Line
	4700 4700 4700 6500
Wire Notes Line
	4700 6500 6850 6500
Wire Notes Line
	6850 6500 6850 4700
Wire Notes Line
	6850 4700 4700 4700
Text Notes 5700 4900 2    100  ~ 0
ISP & Reset
Wire Wire Line
	8350 5350 7800 5350
Text Label 7800 5350 0    50   ~ 0
TTL-CTS
Wire Wire Line
	9950 5350 10500 5350
Text Label 10500 5350 2    50   ~ 0
RS232-RTS
Wire Wire Line
	8350 5550 7800 5550
Text Label 7800 5550 0    50   ~ 0
TTL-RX
Wire Wire Line
	9950 5550 10500 5550
Text Label 10500 5550 2    50   ~ 0
RS232-TX
Wire Wire Line
	8350 5150 7800 5150
Wire Wire Line
	9950 5150 10500 5150
Text Label 7800 5150 0    50   ~ 0
TTL-TX
Text Label 10500 5150 2    50   ~ 0
RS232-RX
$Comp
L power:GND #PWR0121
U 1 1 5E606A90
P 9150 6150
F 0 "#PWR0121" H 9150 5900 50  0001 C CNN
F 1 "GND" H 9155 5977 50  0000 C CNN
F 2 "" H 9150 6150 50  0001 C CNN
F 3 "" H 9150 6150 50  0001 C CNN
	1    9150 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 6050 9150 6150
$Comp
L power:VCC #PWR0122
U 1 1 5E60B2B7
P 9150 3550
F 0 "#PWR0122" H 9150 3400 50  0001 C CNN
F 1 "VCC" H 9167 3723 50  0000 C CNN
F 2 "" H 9150 3550 50  0001 C CNN
F 3 "" H 9150 3550 50  0001 C CNN
	1    9150 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 3550 9150 3650
$Comp
L power:GND #PWR0123
U 1 1 5E60F64A
P 8200 4950
F 0 "#PWR0123" H 8200 4700 50  0001 C CNN
F 1 "GND" V 8205 4822 50  0000 R CNN
F 2 "" H 8200 4950 50  0001 C CNN
F 3 "" H 8200 4950 50  0001 C CNN
	1    8200 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	8350 4950 8200 4950
$Comp
L power:GND #PWR0124
U 1 1 5E618865
P 8450 2300
F 0 "#PWR0124" H 8450 2050 50  0001 C CNN
F 1 "GND" H 8455 2127 50  0000 C CNN
F 2 "" H 8450 2300 50  0001 C CNN
F 3 "" H 8450 2300 50  0001 C CNN
	1    8450 2300
	0    1    1    0   
$EndComp
Wire Wire Line
	8550 2300 8500 2300
Wire Wire Line
	8350 3950 8250 3950
Wire Wire Line
	8250 3950 8250 4000
Wire Wire Line
	8250 4200 8250 4250
Wire Wire Line
	8250 4250 8350 4250
Wire Wire Line
	9950 3950 10050 3950
Wire Wire Line
	10050 3950 10050 4000
Wire Wire Line
	10050 4200 10050 4250
Wire Wire Line
	10050 4250 9950 4250
Wire Wire Line
	10050 4750 9950 4750
$Comp
L power:GND #PWR0125
U 1 1 5E2AE81F
P 10350 4750
F 0 "#PWR0125" H 10350 4500 50  0001 C CNN
F 1 "GND" V 10355 4622 50  0000 R CNN
F 2 "" H 10350 4750 50  0001 C CNN
F 3 "" H 10350 4750 50  0001 C CNN
	1    10350 4750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	10250 4750 10350 4750
Wire Wire Line
	9950 4450 10050 4450
$Comp
L power:VCC #PWR0126
U 1 1 5E2C7B95
P 10350 4450
F 0 "#PWR0126" H 10350 4300 50  0001 C CNN
F 1 "VCC" V 10367 4578 50  0000 L CNN
F 2 "" H 10350 4450 50  0001 C CNN
F 3 "" H 10350 4450 50  0001 C CNN
	1    10350 4450
	0    1    1    0   
$EndComp
Wire Wire Line
	10250 4450 10350 4450
Wire Notes Line
	6950 6500 11150 6500
Wire Notes Line
	11150 6500 11150 2800
Wire Notes Line
	11150 2800 6950 2800
Wire Notes Line
	6950 2800 6950 6500
Text Notes 7050 3000 0    100  ~ 0
TTL-RS232 Level conversion
Wire Wire Line
	9350 2000 9350 1250
Text Label 9350 1250 3    50   ~ 0
RS232-RX
Wire Wire Line
	9150 2000 9150 1250
Text Label 9150 1250 3    50   ~ 0
RS232-TX
Wire Wire Line
	8750 2000 8750 1900
Wire Wire Line
	8750 1900 8500 1900
Wire Wire Line
	8500 1900 8500 2300
Connection ~ 8500 2300
Wire Wire Line
	8500 2300 8450 2300
Wire Wire Line
	9250 2000 9250 1250
Text Label 9250 1250 3    50   ~ 0
RS232-RTS
Wire Wire Line
	8950 2000 8950 1250
Text Label 8950 1250 3    50   ~ 0
RS232-DTR
Wire Notes Line
	6950 2750 11150 2750
Wire Notes Line
	11150 2750 11150 550 
Wire Notes Line
	11150 550  6950 550 
Wire Notes Line
	6950 550  6950 2750
Text Notes 7050 750  0    100  ~ 0
RS232 Port
Wire Wire Line
	3600 2400 4950 2400
Wire Wire Line
	3600 2300 4950 2300
Wire Wire Line
	3600 2200 4950 2200
$Comp
L power:GND #PWR0127
U 1 1 5E39BF23
P 5600 2300
F 0 "#PWR0127" H 5600 2050 50  0001 C CNN
F 1 "GND" H 5605 2127 50  0000 C CNN
F 2 "" H 5600 2300 50  0001 C CNN
F 3 "" H 5600 2300 50  0001 C CNN
	1    5600 2300
	0    -1   -1   0   
$EndComp
Wire Notes Line
	6850 4650 550  4650
Wire Notes Line
	550  550  6850 550 
Wire Notes Line
	6850 550  6850 4650
Text Notes 650  750  0    100  ~ 0
AVR Microcontroller
$Comp
L 4x1md_symbols:Mini-DIN_6pins_ver2 J4
U 1 1 5E3C81A7
P 5650 7300
F 0 "J4" H 5650 7635 50  0000 C CNN
F 1 "PS/2 Mouse" H 5650 7544 50  0000 C CNN
F 2 "4x1md_footprints:Connector_Mini-DIN_Female_6Pin_2rows" H 5650 7543 50  0001 C CNN
F 3 "" H 5650 7320 50  0001 C CNN
	1    5650 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 7500 5650 7550
Wire Wire Line
	6550 7300 6550 7550
Wire Wire Line
	6550 7550 5650 7550
Wire Wire Line
	5950 7300 6550 7300
Connection ~ 5650 7550
$Comp
L Device:C_Small C8
U 1 1 5E4ACEE5
P 8250 4100
F 0 "C8" H 8342 4146 50  0000 L CNN
F 1 "100nF" H 8342 4055 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 8250 4100 50  0001 C CNN
F 3 "~" H 8250 4100 50  0001 C CNN
	1    8250 4100
	1    0    0    -1  
$EndComp
$Comp
L MCU_Microchip_ATmega:ATmega8A-AU U3
U 1 1 5E4B5120
P 3000 2600
F 0 "U3" H 2550 3950 50  0000 C CNN
F 1 "ATmega8A-AU" H 3400 3950 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 3000 2600 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/Microchip%208bit%20mcu%20AVR%20ATmega8A%20data%20sheet%2040001974A.pdf" H 3000 2600 50  0001 C CNN
	1    3000 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 1700 2050 1700
Wire Wire Line
	2400 1900 2050 1900
Text Label 2050 1700 0    50   ~ 0
XTAL1
Text Label 2050 1900 0    50   ~ 0
XTAL2
Wire Wire Line
	3000 4000 3000 4050
Wire Wire Line
	3000 4050 3050 4050
Wire Wire Line
	3100 4050 3100 4000
$Comp
L power:GND #PWR0102
U 1 1 5E4CB75F
P 3050 4150
F 0 "#PWR0102" H 3050 3900 50  0001 C CNN
F 1 "GND" H 3055 3977 50  0000 C CNN
F 2 "" H 3050 4150 50  0001 C CNN
F 3 "" H 3050 4150 50  0001 C CNN
	1    3050 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 4050 3050 4150
Connection ~ 3050 4050
Wire Wire Line
	3050 4050 3100 4050
$Comp
L power:VCC #PWR0103
U 1 1 5E4D28ED
P 3050 1050
F 0 "#PWR0103" H 3050 900 50  0001 C CNN
F 1 "VCC" H 3067 1223 50  0000 C CNN
F 2 "" H 3050 1050 50  0001 C CNN
F 3 "" H 3050 1050 50  0001 C CNN
	1    3050 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 1200 3000 1150
Wire Wire Line
	3000 1150 3050 1150
Wire Wire Line
	3100 1150 3100 1200
Wire Wire Line
	3050 1150 3050 1050
Connection ~ 3050 1150
Wire Wire Line
	3050 1150 3100 1150
Wire Wire Line
	2400 2100 1800 2100
Wire Wire Line
	1800 2100 1800 1150
Wire Wire Line
	1800 1150 1950 1150
Connection ~ 3000 1150
Wire Wire Line
	1950 1200 1950 1150
Connection ~ 1950 1150
Wire Wire Line
	1950 1150 3000 1150
Wire Wire Line
	1950 1500 2400 1500
Text Label 2100 1500 0    50   ~ 0
RESET
Wire Wire Line
	2400 2300 2300 2300
Wire Wire Line
	2300 2300 2300 2350
Wire Wire Line
	2300 2400 2400 2400
Wire Wire Line
	2300 2350 2150 2350
Wire Wire Line
	2150 2350 2150 4050
Wire Wire Line
	2150 4050 3000 4050
Connection ~ 2300 2350
Wire Wire Line
	2300 2350 2300 2400
Connection ~ 3000 4050
Wire Notes Line
	550  4650 550  550 
$Comp
L Device:C_Small C9
U 1 1 5E5C85B6
P 10050 4100
F 0 "C9" H 10142 4146 50  0000 L CNN
F 1 "100nF" H 10142 4055 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 10050 4100 50  0001 C CNN
F 3 "~" H 10050 4100 50  0001 C CNN
	1    10050 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C10
U 1 1 5E5D0F84
P 10150 4450
F 0 "C10" V 10200 4500 50  0000 L CNN
F 1 "100nF" V 10200 4150 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 10150 4450 50  0001 C CNN
F 3 "~" H 10150 4450 50  0001 C CNN
	1    10150 4450
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C11
U 1 1 5E5E8791
P 10150 4750
F 0 "C11" V 10200 4800 50  0000 L CNN
F 1 "100nF" V 10200 4450 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 10150 4750 50  0001 C CNN
F 3 "~" H 10150 4750 50  0001 C CNN
	1    10150 4750
	0    -1   -1   0   
$EndComp
$Comp
L Interface_UART:MAX232 U4
U 1 1 5E46876B
P 9150 4850
F 0 "U4" H 8600 5900 50  0000 C CNN
F 1 "MAX232A" H 9600 5900 50  0000 C CNN
F 2 "Package_SO:SOIC-16_4.55x10.3mm_P1.27mm" H 9200 3800 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/max232.pdf" H 9150 4950 50  0001 C CNN
	1    9150 4850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C7
U 1 1 5E5FF5E9
P 4100 5650
F 0 "C7" H 4215 5696 50  0000 L CNN
F 1 "1.0uF" H 4215 5605 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 4138 5500 50  0001 C CNN
F 3 "~" H 4100 5650 50  0001 C CNN
	1    4100 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 2000 4100 2000
$Comp
L Device:Jumper_NC_Small JP1
U 1 1 5E66F5A3
P 4100 7050
F 0 "JP1" H 4100 7262 50  0000 C CNN
F 1 "Internal 5V" H 4100 7171 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 4100 7050 50  0001 C CNN
F 3 "~" H 4100 7050 50  0001 C CNN
	1    4100 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 7050 4400 7050
Wire Wire Line
	4400 7050 4400 7000
$Comp
L Connector:Conn_01x02_Male J1
U 1 1 5E67D658
P 2400 5650
F 0 "J1" H 2350 5650 50  0000 R CNN
F 1 "External 5V" H 2700 5500 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 2400 5650 50  0001 C CNN
F 3 "~" H 2400 5650 50  0001 C CNN
	1    2400 5650
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5E67E4EF
P 2000 5900
F 0 "#PWR0107" H 2000 5650 50  0001 C CNN
F 1 "GND" H 2150 5800 50  0000 C CNN
F 2 "" H 2000 5900 50  0001 C CNN
F 3 "" H 2000 5900 50  0001 C CNN
	1    2000 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 5750 2000 5750
Wire Wire Line
	2000 5750 2000 5900
$Comp
L power:VCC #PWR0108
U 1 1 5E685D57
P 2000 5400
F 0 "#PWR0108" H 2000 5250 50  0001 C CNN
F 1 "VCC" H 2150 5500 50  0000 C CNN
F 2 "" H 2000 5400 50  0001 C CNN
F 3 "" H 2000 5400 50  0001 C CNN
	1    2000 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 5400 2000 5650
Wire Wire Line
	2000 5650 2200 5650
$Comp
L Regulator_Linear:LP2985-5.0 U1
U 1 1 5E68E215
P 3200 7150
F 0 "U1" H 3200 7492 50  0000 C CNN
F 1 "LP2985-5.0" H 3200 7401 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 3200 7475 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lp2985.pdf" H 3200 7150 50  0001 C CNN
	1    3200 7150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 7050 2700 7050
Wire Wire Line
	2700 7050 2700 7100
Wire Wire Line
	2700 7150 2800 7150
$Comp
L Device:C_Small C3
U 1 1 5E697387
P 2600 7250
F 0 "C3" H 2400 7300 50  0000 L CNN
F 1 "1.0uF" H 2300 7200 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 2600 7250 50  0001 C CNN
F 3 "~" H 2600 7250 50  0001 C CNN
	1    2600 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 7100 2600 7100
Wire Wire Line
	2600 7100 2600 7150
Connection ~ 2700 7100
Wire Wire Line
	2700 7100 2700 7150
$Comp
L power:GND #PWR0110
U 1 1 5E6A0B6E
P 3200 7550
F 0 "#PWR0110" H 3200 7300 50  0001 C CNN
F 1 "GND" H 3050 7450 50  0000 C CNN
F 2 "" H 3200 7550 50  0001 C CNN
F 3 "" H 3200 7550 50  0001 C CNN
	1    3200 7550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 7450 3200 7500
Wire Wire Line
	2600 7350 2600 7500
Wire Wire Line
	2600 7500 3200 7500
Connection ~ 3200 7500
Wire Wire Line
	3200 7500 3200 7550
$Comp
L power:+12V #PWR0111
U 1 1 5E6B23B4
P 2600 6900
F 0 "#PWR0111" H 2600 6750 50  0001 C CNN
F 1 "+12V" H 2450 6950 50  0000 C CNN
F 2 "" H 2600 6900 50  0001 C CNN
F 3 "" H 2600 6900 50  0001 C CNN
	1    2600 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 6900 2600 7100
Connection ~ 2600 7100
$Comp
L Device:C_Small C4
U 1 1 5E6BB74A
P 3750 7250
F 0 "C4" H 3550 7300 50  0000 L CNN
F 1 "10nF" H 3550 7200 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 3750 7250 50  0001 C CNN
F 3 "~" H 3750 7250 50  0001 C CNN
	1    3750 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 7150 3750 7150
Wire Wire Line
	3200 7500 3750 7500
Wire Wire Line
	3750 7500 3750 7350
$Comp
L Device:C_Small C12
U 1 1 5E6E14B7
P 3900 7250
F 0 "C12" H 4000 7300 50  0000 L CNN
F 1 "2.2uF" H 4000 7200 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 3900 7250 50  0001 C CNN
F 3 "~" H 3900 7250 50  0001 C CNN
	1    3900 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 7050 3900 7150
Wire Wire Line
	3900 7050 4000 7050
Wire Wire Line
	3900 7500 3900 7350
Wire Wire Line
	3750 7500 3900 7500
Connection ~ 3750 7500
Wire Wire Line
	3600 7050 3900 7050
Connection ~ 3900 7050
Text Notes 3950 7700 0    28   ~ 0
2.2uF for C12 is the minimum\nfor stability. A capacitor with\na stable ESR between 0.01 and\n1.0 in the operating range\nof 0-100C is required.
Wire Wire Line
	750  5400 750  5650
$Comp
L Diode:BAT48ZFILM D4
U 1 1 5E754C82
P 1050 5650
F 0 "D4" H 1050 5866 50  0000 C CNN
F 1 "BAT48ZFILM" H 1050 5775 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 1050 5475 50  0001 C CNN
F 3 "www.st.com/resource/en/datasheet/bat48.pdf" H 1050 5650 50  0001 C CNN
	1    1050 5650
	1    0    0    -1  
$EndComp
Text Label 3650 7050 0    50   ~ 0
REG_5V
$Comp
L power:VCC #PWR?
U 1 1 5E4A21A6
P 5400 5150
F 0 "#PWR?" H 5400 5000 50  0001 C CNN
F 1 "VCC" H 5417 5323 50  0000 C CNN
F 2 "" H 5400 5150 50  0001 C CNN
F 3 "" H 5400 5150 50  0001 C CNN
	1    5400 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 5550 6200 5550
Wire Wire Line
	5900 5750 6200 5750
Text Label 6200 5550 2    50   ~ 0
MISO
Text Label 6200 5750 2    50   ~ 0
SCK
Text Label 6200 5650 2    50   ~ 0
MOSI
Text Label 6200 5850 2    50   ~ 0
RESET
Wire Wire Line
	5900 5850 6300 5850
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J7
U 1 1 5E506A36
P 5150 2300
F 0 "J7" H 5200 2617 50  0000 C CNN
F 1 "Extra" H 5200 2526 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x03_P2.54mm_Vertical" H 5150 2300 50  0001 C CNN
F 3 "~" H 5150 2300 50  0001 C CNN
	1    5150 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 2300 5550 2300
Wire Wire Line
	5450 2200 5550 2200
Wire Wire Line
	5550 2200 5550 2300
Connection ~ 5550 2300
Wire Wire Line
	5550 2300 5600 2300
Wire Wire Line
	5450 2400 5550 2400
Wire Wire Line
	5550 2400 5550 2300
Wire Wire Line
	5400 5150 5400 5250
Wire Wire Line
	5900 5650 6200 5650
$Comp
L Connector:AVR-ISP-6 J5
U 1 1 5E4DFCE1
P 5500 5750
F 0 "J5" H 5171 5846 50  0000 R CNN
F 1 "AVR-ISP-6" H 5171 5755 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" V 5250 5800 50  0001 C CNN
F 3 " ~" H 4225 5200 50  0001 C CNN
	1    5500 5750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E54C3E0
P 5400 6250
F 0 "#PWR?" H 5400 6000 50  0001 C CNN
F 1 "GND" H 5405 6077 50  0000 C CNN
F 2 "" H 5400 6250 50  0001 C CNN
F 3 "" H 5400 6250 50  0001 C CNN
	1    5400 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 6150 5400 6250
Wire Wire Line
	6300 6250 5400 6250
Connection ~ 5400 6250
$EndSCHEMATC
