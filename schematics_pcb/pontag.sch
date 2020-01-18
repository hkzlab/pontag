EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
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
F 2 "" H 1600 7300 50  0001 C CNN
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
F 2 "" V 1180 7300 50  0001 C CNN
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
F 2 "" H 1000 7150 50  0001 C CNN
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
F 2 "" H 1000 7450 50  0001 C CNN
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
L power:GND #PWR?
U 1 1 5E23224E
P 650 7350
F 0 "#PWR?" H 650 7100 50  0001 C CNN
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
Wire Notes Line
	2200 7750 2200 6550
Wire Notes Line
	2200 6550 550  6550
$EndSCHEMATC
