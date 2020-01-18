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
$Comp
L Connector:Conn_01x02_Male J1
U 1 1 5E2364F8
P 4000 7050
F 0 "J1" V 3850 7050 50  0000 R CNN
F 1 "External 5V" V 3950 7200 50  0000 R CNN
F 2 "" H 4000 7050 50  0001 C CNN
F 3 "~" H 4000 7050 50  0001 C CNN
	1    4000 7050
	0    -1   1    0   
$EndComp
$Comp
L Regulator_Linear:L78L05_TO92 U?
U 1 1 5E236C87
P 6450 5650
F 0 "U?" H 6450 5892 50  0000 C CNN
F 1 "L78L05_TO92" H 6450 5801 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 6450 5875 50  0001 C CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/15/55/e5/aa/23/5b/43/fd/CD00000446.pdf/files/CD00000446.pdf/jcr:content/translations/en.CD00000446.pdf" H 6450 5600 50  0001 C CNN
	1    6450 5650
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LM2936-3.3_TO92 U?
U 1 1 5E237B6A
P 7250 5650
F 0 "U?" H 7250 5892 50  0000 C CNN
F 1 "LM2936-3.3_TO92" H 7250 5801 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 7250 5875 50  0001 C CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm2936.pdf" H 7250 5600 50  0001 C CNN
	1    7250 5650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E23C7AB
P 4100 7500
F 0 "#PWR?" H 4100 7250 50  0001 C CNN
F 1 "GND" H 4200 7350 50  0000 C CNN
F 2 "" H 4100 7500 50  0001 C CNN
F 3 "" H 4100 7500 50  0001 C CNN
	1    4100 7500
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5E24164E
P 4000 7500
F 0 "#PWR?" H 4000 7350 50  0001 C CNN
F 1 "+5V" H 3900 7650 50  0000 C CNN
F 2 "" H 4000 7500 50  0001 C CNN
F 3 "" H 4000 7500 50  0001 C CNN
	1    4000 7500
	1    0    0    1   
$EndComp
$Comp
L Device:Jumper JP1
U 1 1 5E23692F
P 8400 5050
F 0 "JP1" H 8400 5314 50  0000 C CNN
F 1 "Internal 5V" H 8400 5223 50  0000 C CNN
F 2 "" H 8400 5050 50  0001 C CNN
F 3 "~" H 8400 5050 50  0001 C CNN
	1    8400 5050
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4148 D1
U 1 1 5E24D079
P 2950 7200
F 0 "D1" H 2800 7300 50  0000 C CNN
F 1 "1N4148" H 3050 7300 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 2950 7025 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/1N4148_1N4448.pdf" H 2950 7200 50  0001 C CNN
	1    2950 7200
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4148 D2
U 1 1 5E2543CF
P 2950 7400
F 0 "D2" H 2800 7500 50  0000 C CNN
F 1 "1N4148" H 3050 7500 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 2950 7225 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/1N4148_1N4448.pdf" H 2950 7400 50  0001 C CNN
	1    2950 7400
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4148 D3
U 1 1 5E254AA6
P 2950 7600
F 0 "D3" H 2800 7700 50  0000 C CNN
F 1 "1N4148" H 3050 7700 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 2950 7425 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/1N4148_1N4448.pdf" H 2950 7600 50  0001 C CNN
	1    2950 7600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 7200 3700 7200
Wire Wire Line
	3100 7400 3700 7400
Wire Wire Line
	3100 7600 3700 7600
Text Label 3700 7200 2    50   ~ 0
RS232-TX
Text Label 3700 7400 2    50   ~ 0
RS232-RTS
Text Label 3700 7600 2    50   ~ 0
RS232-DTR
Wire Wire Line
	2800 7200 2550 7200
Wire Wire Line
	2550 7200 2550 7400
Wire Wire Line
	2550 7600 2800 7600
Wire Wire Line
	2800 7400 2550 7400
Connection ~ 2550 7400
Wire Wire Line
	2550 7400 2550 7600
$Comp
L power:+12V #PWR?
U 1 1 5E25BC0B
P 2350 7450
F 0 "#PWR?" H 2350 7300 50  0001 C CNN
F 1 "+12V" H 2365 7623 50  0000 C CNN
F 2 "" H 2350 7450 50  0001 C CNN
F 3 "" H 2350 7450 50  0001 C CNN
	1    2350 7450
	1    0    0    1   
$EndComp
Wire Wire Line
	2550 7400 2350 7400
Wire Wire Line
	2350 7400 2350 7450
Wire Notes Line
	2250 7750 2250 6550
Text Notes 3400 6750 2    100  ~ 0
Power Ingress
Wire Wire Line
	4000 7250 4000 7500
Wire Wire Line
	4100 7250 4100 7500
Wire Notes Line
	2250 6550 4350 6550
Wire Notes Line
	4350 6550 4350 7750
Wire Notes Line
	4350 7750 2250 7750
$EndSCHEMATC
