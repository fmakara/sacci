EESchema Schematic File Version 2  date 15/02/2016 09:58:35
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:sacci-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "15 feb 2016"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ATMEGA328-P IC1
U 1 1 56BE75B7
P 1800 3400
F 0 "IC1" H 1050 4650 40  0000 L BNN
F 1 "ATMEGA328-P" H 2200 2000 40  0000 L BNN
F 2 "DIL28" H 1800 3400 30  0000 C CIN
F 3 "" H 1800 3400 60  0000 C CNN
	1    1800 3400
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR01
U 1 1 56BE75C6
P 800 2200
F 0 "#PWR01" H 800 2290 20  0001 C CNN
F 1 "+5V" H 800 2290 30  0000 C CNN
F 2 "" H 800 2200 60  0000 C CNN
F 3 "" H 800 2200 60  0000 C CNN
	1    800  2200
	1    0    0    -1  
$EndComp
NoConn ~ 900  2900
$Comp
L GND #PWR02
U 1 1 56BE75DE
P 800 4700
F 0 "#PWR02" H 800 4700 30  0001 C CNN
F 1 "GND" H 800 4630 30  0001 C CNN
F 2 "" H 800 4700 60  0000 C CNN
F 3 "" H 800 4700 60  0000 C CNN
	1    800  4700
	1    0    0    -1  
$EndComp
$Comp
L AVR-ISP-10 CON1
U 1 1 56BE763E
P 3300 1100
F 0 "CON1" H 3130 1430 50  0000 C CNN
F 1 "AVR-ISP-10" H 2960 770 50  0000 L BNN
F 2 "AVR-ISP-10" V 2550 1150 50  0001 C CNN
F 3 "" H 3300 1100 60  0000 C CNN
	1    3300 1100
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR03
U 1 1 56BE767D
P 3750 1050
F 0 "#PWR03" H 3750 1050 30  0001 C CNN
F 1 "GND" H 3750 980 30  0001 C CNN
F 2 "" H 3750 1050 60  0000 C CNN
F 3 "" H 3750 1050 60  0000 C CNN
	1    3750 1050
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR04
U 1 1 56BE76DE
P 3100 700
F 0 "#PWR04" H 3100 790 20  0001 C CNN
F 1 "+5V" H 3100 790 30  0000 C CNN
F 2 "" H 3100 700 60  0000 C CNN
F 3 "" H 3100 700 60  0000 C CNN
	1    3100 700 
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 56BE7700
P 2800 1200
F 0 "R2" V 2880 1200 40  0000 C CNN
F 1 "10k" V 2807 1201 40  0000 C CNN
F 2 "~" V 2730 1200 30  0000 C CNN
F 3 "~" H 2800 1200 30  0000 C CNN
	1    2800 1200
	1    0    0    -1  
$EndComp
NoConn ~ 3200 1300
$Comp
L DISPLAY S1
U 1 1 56BE77C0
P 3650 6500
F 0 "S1" H 2600 7250 60  0000 C CNN
F 1 "DISPLAY" H 3900 5750 60  0000 C CNN
F 2 "~" H 3650 6500 60  0000 C CNN
F 3 "~" H 3650 6500 60  0000 C CNN
	1    3650 6500
	0    1    1    0   
$EndComp
NoConn ~ 3400 4700
NoConn ~ 3500 4700
NoConn ~ 3600 4700
NoConn ~ 3700 4700
$Comp
L GND #PWR05
U 1 1 56BE7AA5
P 4300 4650
F 0 "#PWR05" H 4300 4650 30  0001 C CNN
F 1 "GND" H 4300 4580 30  0001 C CNN
F 2 "" H 4300 4650 60  0000 C CNN
F 3 "" H 4300 4650 60  0000 C CNN
	1    4300 4650
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR06
U 1 1 56BE7AB4
P 4200 4650
F 0 "#PWR06" H 4200 4740 20  0001 C CNN
F 1 "+5V" H 4200 4740 30  0000 C CNN
F 2 "" H 4200 4650 60  0000 C CNN
F 3 "" H 4200 4650 60  0000 C CNN
	1    4200 4650
	1    0    0    -1  
$EndComp
$Comp
L POT RV1
U 1 1 56BE7B36
P 4700 4700
F 0 "RV1" H 4700 4600 50  0000 C CNN
F 1 "10k pot" H 4700 4700 50  0000 C CNN
F 2 "~" H 4700 4700 60  0000 C CNN
F 3 "~" H 4700 4700 60  0000 C CNN
	1    4700 4700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 56BE7B45
P 4950 4750
F 0 "#PWR07" H 4950 4750 30  0001 C CNN
F 1 "GND" H 4950 4680 30  0001 C CNN
F 2 "" H 4950 4750 60  0000 C CNN
F 3 "" H 4950 4750 60  0000 C CNN
	1    4950 4750
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR08
U 1 1 56BE7B54
P 4450 4650
F 0 "#PWR08" H 4450 4740 20  0001 C CNN
F 1 "+5V" H 4450 4740 30  0000 C CNN
F 2 "" H 4450 4650 60  0000 C CNN
F 3 "" H 4450 4650 60  0000 C CNN
	1    4450 4650
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P1
U 1 1 56BE7D84
P 2600 6250
F 0 "P1" V 2550 6250 40  0000 C CNN
F 1 "LED_DISPLAY" V 2650 6250 40  0000 C CNN
F 2 "~" H 2600 6250 60  0000 C CNN
F 3 "~" H 2600 6250 60  0000 C CNN
	1    2600 6250
	0    1    1    0   
$EndComp
$Comp
L GND #PWR09
U 1 1 56BE7D91
P 2500 5850
F 0 "#PWR09" H 2500 5850 30  0001 C CNN
F 1 "GND" H 2500 5780 30  0001 C CNN
F 2 "" H 2500 5850 60  0000 C CNN
F 3 "" H 2500 5850 60  0000 C CNN
	1    2500 5850
	-1   0    0    1   
$EndComp
$Comp
L R R1
U 1 1 56BE7D9E
P 2700 5600
F 0 "R1" V 2780 5600 40  0000 C CNN
F 1 "500" V 2707 5601 40  0000 C CNN
F 2 "~" V 2630 5600 30  0000 C CNN
F 3 "~" H 2700 5600 30  0000 C CNN
	1    2700 5600
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR010
U 1 1 56BE7DAB
P 2700 5300
F 0 "#PWR010" H 2700 5390 20  0001 C CNN
F 1 "+5V" H 2700 5390 30  0000 C CNN
F 2 "" H 2700 5300 60  0000 C CNN
F 3 "" H 2700 5300 60  0000 C CNN
	1    2700 5300
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL X1
U 1 1 56BE7F1E
P 3900 2650
F 0 "X1" H 3900 2800 60  0000 C CNN
F 1 "16MHz" H 3900 2500 60  0000 C CNN
F 2 "~" H 3900 2650 60  0000 C CNN
F 3 "~" H 3900 2650 60  0000 C CNN
	1    3900 2650
	0    -1   -1   0   
$EndComp
$Comp
L MOC3021M IC2
U 1 1 56BE827E
P 5100 6800
F 0 "IC2" H 4886 6979 40  0000 C CNN
F 1 "MOC3021M" H 5200 6615 40  0000 C CNN
F 2 "DIP6" H 4936 6625 29  0000 C CNN
F 3 "" H 5100 6800 60  0000 C CNN
	1    5100 6800
	1    0    0    -1  
$EndComp
$Comp
L TRIAC U1
U 1 1 56BE828D
P 6200 6700
F 0 "U1" H 5950 7050 70  0000 C CNN
F 1 "TIC206" H 5900 6450 60  0000 C CNN
F 2 "~" H 6200 6700 60  0000 C CNN
F 3 "~" H 6200 6700 60  0000 C CNN
	1    6200 6700
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 56BE82A6
P 5800 6150
F 0 "R6" V 5880 6150 40  0000 C CNN
F 1 "470r" V 5807 6151 40  0000 C CNN
F 2 "~" V 5730 6150 30  0000 C CNN
F 3 "~" H 5800 6150 30  0000 C CNN
	1    5800 6150
	0    -1   -1   0   
$EndComp
$Comp
L R R3
U 1 1 56BE82C9
P 4700 5850
F 0 "R3" V 4780 5850 40  0000 C CNN
F 1 "220" V 4707 5851 40  0000 C CNN
F 2 "~" V 4630 5850 30  0000 C CNN
F 3 "~" H 4700 5850 30  0000 C CNN
	1    4700 5850
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR011
U 1 1 56BE82E2
P 4700 7000
F 0 "#PWR011" H 4700 7000 30  0001 C CNN
F 1 "GND" H 4700 6930 30  0001 C CNN
F 2 "" H 4700 7000 60  0000 C CNN
F 3 "" H 4700 7000 60  0000 C CNN
	1    4700 7000
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P6
U 1 1 56BE85FE
P 6700 7600
F 0 "P6" V 6650 7600 40  0000 C CNN
F 1 "Alim 110" V 6750 7600 40  0000 C CNN
F 2 "~" H 6700 7600 60  0000 C CNN
F 3 "~" H 6700 7600 60  0000 C CNN
	1    6700 7600
	0    1    1    0   
$EndComp
$Comp
L CONN_2 P5
U 1 1 56BE8617
P 6700 5700
F 0 "P5" V 6650 5700 40  0000 C CNN
F 1 "Trafo 110" V 6750 5700 40  0000 C CNN
F 2 "~" H 6700 5700 60  0000 C CNN
F 3 "~" H 6700 5700 60  0000 C CNN
	1    6700 5700
	0    -1   -1   0   
$EndComp
$Comp
L CONN_2 P7
U 1 1 56BE86DE
P 7350 6700
F 0 "P7" V 7300 6700 40  0000 C CNN
F 1 "Resistencia" V 7400 6700 40  0000 C CNN
F 2 "~" H 7350 6700 60  0000 C CNN
F 3 "~" H 7350 6700 60  0000 C CNN
	1    7350 6700
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P4
U 1 1 56BE8A76
P 6600 1100
F 0 "P4" V 6550 1100 40  0000 C CNN
F 1 "Trafo 9V" V 6650 1100 40  0000 C CNN
F 2 "~" H 6600 1100 60  0000 C CNN
F 3 "~" H 6600 1100 60  0000 C CNN
	1    6600 1100
	-1   0    0    1   
$EndComp
$Comp
L LED D1
U 1 1 56BE8A99
P 4700 6400
F 0 "D1" H 4700 6500 50  0000 C CNN
F 1 "LED_RES" H 4700 6300 50  0000 C CNN
F 2 "~" H 4700 6400 60  0000 C CNN
F 3 "~" H 4700 6400 60  0000 C CNN
	1    4700 6400
	0    1    1    0   
$EndComp
$Comp
L CAPAPOL C5
U 1 1 56BE8C10
P 8000 1150
F 0 "C5" H 8050 1250 40  0000 L CNN
F 1 "100u" H 8050 1050 40  0000 L CNN
F 2 "~" H 8100 1000 30  0000 C CNN
F 3 "~" H 8000 1150 300 0000 C CNN
	1    8000 1150
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 56BE8C24
P 8350 1150
F 0 "C6" H 8350 1250 40  0000 L CNN
F 1 "100n" H 8356 1065 40  0000 L CNN
F 2 "~" H 8388 1000 30  0000 C CNN
F 3 "~" H 8350 1150 60  0000 C CNN
	1    8350 1150
	1    0    0    -1  
$EndComp
$Comp
L 7805 U2
U 1 1 56BE8DFE
P 8850 950
F 0 "U2" H 9000 754 60  0000 C CNN
F 1 "7805" H 8850 1150 60  0000 C CNN
F 2 "~" H 8850 950 60  0000 C CNN
F 3 "~" H 8850 950 60  0000 C CNN
	1    8850 950 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 56BE8EF8
P 8850 1450
F 0 "#PWR012" H 8850 1450 30  0001 C CNN
F 1 "GND" H 8850 1380 30  0001 C CNN
F 2 "" H 8850 1450 60  0000 C CNN
F 3 "" H 8850 1450 60  0000 C CNN
	1    8850 1450
	1    0    0    -1  
$EndComp
$Comp
L C C7
U 1 1 56BE8F8F
P 9350 1150
F 0 "C7" H 9350 1250 40  0000 L CNN
F 1 "100n" H 9356 1065 40  0000 L CNN
F 2 "~" H 9388 1000 30  0000 C CNN
F 3 "~" H 9350 1150 60  0000 C CNN
	1    9350 1150
	1    0    0    -1  
$EndComp
$Comp
L CAPAPOL C8
U 1 1 56BE8F95
P 9600 1150
F 0 "C8" H 9650 1250 40  0000 L CNN
F 1 "100u" H 9650 1050 40  0000 L CNN
F 2 "~" H 9700 1000 30  0000 C CNN
F 3 "~" H 9600 1150 300 0000 C CNN
	1    9600 1150
	1    0    0    -1  
$EndComp
$Comp
L C C9
U 1 1 56BE8F9B
P 9850 1150
F 0 "C9" H 9850 1250 40  0000 L CNN
F 1 "100n" H 9856 1065 40  0000 L CNN
F 2 "~" H 9888 1000 30  0000 C CNN
F 3 "~" H 9850 1150 60  0000 C CNN
	1    9850 1150
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR013
U 1 1 56BE92BE
P 9500 850
F 0 "#PWR013" H 9500 940 20  0001 C CNN
F 1 "+5V" H 9500 940 30  0000 C CNN
F 2 "" H 9500 850 60  0000 C CNN
F 3 "" H 9500 850 60  0000 C CNN
	1    9500 850 
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P2
U 1 1 56BE95CF
P 6000 1450
F 0 "P2" V 5950 1450 40  0000 C CNN
F 1 "Term 1" V 6050 1450 40  0000 C CNN
F 2 "~" H 6000 1450 60  0000 C CNN
F 3 "~" H 6000 1450 60  0000 C CNN
	1    6000 1450
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR014
U 1 1 56BE95F2
P 5600 750
F 0 "#PWR014" H 5600 840 20  0001 C CNN
F 1 "+5V" H 5600 840 30  0000 C CNN
F 2 "" H 5600 750 60  0000 C CNN
F 3 "" H 5600 750 60  0000 C CNN
	1    5600 750 
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 56BE960B
P 5600 1050
F 0 "R4" V 5680 1050 40  0000 C CNN
F 1 "10k" V 5607 1051 40  0000 C CNN
F 2 "~" V 5530 1050 30  0000 C CNN
F 3 "~" H 5600 1050 30  0000 C CNN
	1    5600 1050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 56BE9629
P 5600 1600
F 0 "#PWR015" H 5600 1600 30  0001 C CNN
F 1 "GND" H 5600 1530 30  0001 C CNN
F 2 "" H 5600 1600 60  0000 C CNN
F 3 "" H 5600 1600 60  0000 C CNN
	1    5600 1600
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 56BE9638
P 5300 1350
F 0 "C3" H 5300 1450 40  0000 L CNN
F 1 "100n" H 5306 1265 40  0000 L CNN
F 2 "~" H 5338 1200 30  0000 C CNN
F 3 "~" H 5300 1350 60  0000 C CNN
	1    5300 1350
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P3
U 1 1 56BE9989
P 6000 2500
F 0 "P3" V 5950 2500 40  0000 C CNN
F 1 "Term 1" V 6050 2500 40  0000 C CNN
F 2 "~" H 6000 2500 60  0000 C CNN
F 3 "~" H 6000 2500 60  0000 C CNN
	1    6000 2500
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR016
U 1 1 56BE998F
P 5600 1800
F 0 "#PWR016" H 5600 1890 20  0001 C CNN
F 1 "+5V" H 5600 1890 30  0000 C CNN
F 2 "" H 5600 1800 60  0000 C CNN
F 3 "" H 5600 1800 60  0000 C CNN
	1    5600 1800
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 56BE9995
P 5600 2100
F 0 "R5" V 5680 2100 40  0000 C CNN
F 1 "10k" V 5607 2101 40  0000 C CNN
F 2 "~" V 5530 2100 30  0000 C CNN
F 3 "~" H 5600 2100 30  0000 C CNN
	1    5600 2100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR017
U 1 1 56BE999B
P 5600 2650
F 0 "#PWR017" H 5600 2650 30  0001 C CNN
F 1 "GND" H 5600 2580 30  0001 C CNN
F 2 "" H 5600 2650 60  0000 C CNN
F 3 "" H 5600 2650 60  0000 C CNN
	1    5600 2650
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 56BE99A1
P 5300 2400
F 0 "C4" H 5300 2500 40  0000 L CNN
F 1 "100n" H 5306 2315 40  0000 L CNN
F 2 "~" H 5338 2250 30  0000 C CNN
F 3 "~" H 5300 2400 60  0000 C CNN
	1    5300 2400
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW1
U 1 1 56BEA078
P 6250 4350
F 0 "SW1" H 6400 4460 50  0000 C CNN
F 1 "SW_PUSH" H 6250 4270 50  0000 C CNN
F 2 "~" H 6250 4350 60  0000 C CNN
F 3 "~" H 6250 4350 60  0000 C CNN
	1    6250 4350
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW2
U 1 1 56BEA087
P 6250 4650
F 0 "SW2" H 6400 4760 50  0000 C CNN
F 1 "SW_PUSH" H 6250 4570 50  0000 C CNN
F 2 "~" H 6250 4650 60  0000 C CNN
F 3 "~" H 6250 4650 60  0000 C CNN
	1    6250 4650
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW3
U 1 1 56BEA096
P 6250 4950
F 0 "SW3" H 6400 5060 50  0000 C CNN
F 1 "SW_PUSH" H 6250 4870 50  0000 C CNN
F 2 "~" H 6250 4950 60  0000 C CNN
F 3 "~" H 6250 4950 60  0000 C CNN
	1    6250 4950
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW4
U 1 1 56BEA0A5
P 6250 5250
F 0 "SW4" H 6400 5360 50  0000 C CNN
F 1 "SW_PUSH" H 6250 5170 50  0000 C CNN
F 2 "~" H 6250 5250 60  0000 C CNN
F 3 "~" H 6250 5250 60  0000 C CNN
	1    6250 5250
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 K1
U 1 1 56BEA34E
P 7350 3100
F 0 "K1" V 7300 3100 50  0000 C CNN
F 1 "SW_TOP" V 7400 3100 40  0000 C CNN
F 2 "~" H 7350 3100 60  0000 C CNN
F 3 "~" H 7350 3100 60  0000 C CNN
	1    7350 3100
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 K2
U 1 1 56BEA35D
P 7350 3550
F 0 "K2" V 7300 3550 50  0000 C CNN
F 1 "SW_BOT" V 7400 3550 40  0000 C CNN
F 2 "~" H 7350 3550 60  0000 C CNN
F 3 "~" H 7350 3550 60  0000 C CNN
	1    7350 3550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR018
U 1 1 56BEA38A
P 6900 3000
F 0 "#PWR018" H 6900 3000 30  0001 C CNN
F 1 "GND" H 6900 2930 30  0001 C CNN
F 2 "" H 6900 3000 60  0000 C CNN
F 3 "" H 6900 3000 60  0000 C CNN
	1    6900 3000
	0    1    1    0   
$EndComp
$Comp
L GND #PWR019
U 1 1 56BEA399
P 6900 3450
F 0 "#PWR019" H 6900 3450 30  0001 C CNN
F 1 "GND" H 6900 3380 30  0001 C CNN
F 2 "" H 6900 3450 60  0000 C CNN
F 3 "" H 6900 3450 60  0000 C CNN
	1    6900 3450
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR020
U 1 1 56BEA3A8
P 6900 3650
F 0 "#PWR020" H 6900 3740 20  0001 C CNN
F 1 "+5V" H 6900 3740 30  0000 C CNN
F 2 "" H 6900 3650 60  0000 C CNN
F 3 "" H 6900 3650 60  0000 C CNN
	1    6900 3650
	0    -1   -1   0   
$EndComp
$Comp
L +5V #PWR021
U 1 1 56BEA3B7
P 6900 3200
F 0 "#PWR021" H 6900 3290 20  0001 C CNN
F 1 "+5V" H 6900 3290 30  0000 C CNN
F 2 "" H 6900 3200 60  0000 C CNN
F 3 "" H 6900 3200 60  0000 C CNN
	1    6900 3200
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR022
U 1 1 56BEAB17
P 6600 5300
F 0 "#PWR022" H 6600 5300 30  0001 C CNN
F 1 "GND" H 6600 5230 30  0001 C CNN
F 2 "" H 6600 5300 60  0000 C CNN
F 3 "" H 6600 5300 60  0000 C CNN
	1    6600 5300
	1    0    0    -1  
$EndComp
$Comp
L MOSFET_N Q2
U 1 1 56BE9B59
P 9000 4600
F 0 "Q2" H 9010 4770 60  0000 R CNN
F 1 "BC338" H 9010 4450 60  0000 R CNN
F 2 "~" H 9000 4600 60  0000 C CNN
F 3 "~" H 9000 4600 60  0000 C CNN
	1    9000 4600
	1    0    0    -1  
$EndComp
$Comp
L MOSFET_N Q4
U 1 1 56BE9B68
P 9900 4600
F 0 "Q4" H 9910 4770 60  0000 R CNN
F 1 "BC338" H 9910 4450 60  0000 R CNN
F 2 "~" H 9900 4600 60  0000 C CNN
F 3 "~" H 9900 4600 60  0000 C CNN
	1    9900 4600
	1    0    0    -1  
$EndComp
$Comp
L MOSFET_P Q3
U 1 1 56BE9B86
P 9900 3600
F 0 "Q3" H 9900 3790 60  0000 R CNN
F 1 "BC328" H 9900 3420 60  0000 R CNN
F 2 "~" H 9900 3600 60  0000 C CNN
F 3 "~" H 9900 3600 60  0000 C CNN
	1    9900 3600
	1    0    0    -1  
$EndComp
$Comp
L +9V #PWR023
U 1 1 56BE9B95
P 8200 850
F 0 "#PWR023" H 8200 820 20  0001 C CNN
F 1 "+9V" H 8200 960 30  0000 C CNN
F 2 "" H 8200 850 60  0000 C CNN
F 3 "" H 8200 850 60  0000 C CNN
	1    8200 850 
	1    0    0    -1  
$EndComp
$Comp
L +9V #PWR024
U 1 1 56BE9E0C
P 9650 3250
F 0 "#PWR024" H 9650 3220 20  0001 C CNN
F 1 "+9V" H 9650 3360 30  0000 C CNN
F 2 "" H 9650 3250 60  0000 C CNN
F 3 "" H 9650 3250 60  0000 C CNN
	1    9650 3250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR025
U 1 1 56BE9FA4
P 9350 4900
F 0 "#PWR025" H 9350 4900 30  0001 C CNN
F 1 "GND" H 9350 4830 30  0001 C CNN
F 2 "" H 9350 4900 60  0000 C CNN
F 3 "" H 9350 4900 60  0000 C CNN
	1    9350 4900
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P8
U 1 1 56BEA73F
P 11050 4100
F 0 "P8" V 11000 4100 40  0000 C CNN
F 1 "motor 1" V 11100 4100 40  0000 C CNN
F 2 "~" H 11050 4100 60  0000 C CNN
F 3 "~" H 11050 4100 60  0000 C CNN
	1    11050 4100
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 56BEAABE
P 8350 4300
F 0 "R7" V 8430 4300 40  0000 C CNN
F 1 "330" V 8357 4301 40  0000 C CNN
F 2 "~" V 8280 4300 30  0000 C CNN
F 3 "~" H 8350 4300 30  0000 C CNN
	1    8350 4300
	0    -1   -1   0   
$EndComp
$Comp
L R R8
U 1 1 56BEAACD
P 8350 4600
F 0 "R8" V 8430 4600 40  0000 C CNN
F 1 "330" V 8357 4601 40  0000 C CNN
F 2 "~" V 8280 4600 30  0000 C CNN
F 3 "~" H 8350 4600 30  0000 C CNN
	1    8350 4600
	0    -1   -1   0   
$EndComp
Text Label 6800 6400 0    60   ~ 0
AC1
Text Label 6600 6450 0    60   ~ 0
AC2
Text Label 6900 6150 0    60   ~ 0
AC3
$Comp
L MOSFET_P Q1
U 1 1 56BE9B77
P 9000 3600
F 0 "Q1" H 9000 3790 60  0000 R CNN
F 1 "BC328" H 9000 3420 60  0000 R CNN
F 2 "~" H 9000 3600 60  0000 C CNN
F 3 "~" H 9000 3600 60  0000 C CNN
	1    9000 3600
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 56BF9458
P 9450 3600
F 0 "R9" V 9530 3600 40  0000 C CNN
F 1 "330" V 9457 3601 40  0000 C CNN
F 2 "~" V 9380 3600 30  0000 C CNN
F 3 "~" H 9450 3600 30  0000 C CNN
	1    9450 3600
	0    1    1    0   
$EndComp
$Comp
L R R10
U 1 1 56BF9599
P 9500 3900
F 0 "R10" V 9580 3900 40  0000 C CNN
F 1 "330" V 9507 3901 40  0000 C CNN
F 2 "~" V 9430 3900 30  0000 C CNN
F 3 "~" H 9500 3900 30  0000 C CNN
	1    9500 3900
	0    1    1    0   
$EndComp
$Comp
L DIODE D4
U 1 1 56BF996F
P 10250 4550
F 0 "D4" H 10250 4650 40  0000 C CNN
F 1 "1n4148" H 10250 4450 40  0000 C CNN
F 2 "~" H 10250 4550 60  0000 C CNN
F 3 "~" H 10250 4550 60  0000 C CNN
	1    10250 4550
	0    -1   -1   0   
$EndComp
$Comp
L DIODE D3
U 1 1 56BF997C
P 10250 3600
F 0 "D3" H 10250 3700 40  0000 C CNN
F 1 "1n4148" H 10250 3500 40  0000 C CNN
F 2 "~" H 10250 3600 60  0000 C CNN
F 3 "~" H 10250 3600 60  0000 C CNN
	1    10250 3600
	0    -1   -1   0   
$EndComp
$Comp
L DIODE D5
U 1 1 56BF9982
P 10500 3600
F 0 "D5" H 10500 3700 40  0000 C CNN
F 1 "1n4148" H 10500 3500 40  0000 C CNN
F 2 "~" H 10500 3600 60  0000 C CNN
F 3 "~" H 10500 3600 60  0000 C CNN
	1    10500 3600
	0    -1   -1   0   
$EndComp
$Comp
L DIODE D6
U 1 1 56BF9988
P 10500 4550
F 0 "D6" H 10500 4650 40  0000 C CNN
F 1 "1n4148" H 10500 4450 40  0000 C CNN
F 2 "~" H 10500 4550 60  0000 C CNN
F 3 "~" H 10500 4550 60  0000 C CNN
	1    10500 4550
	0    -1   -1   0   
$EndComp
$Comp
L C C1
U 1 1 56BFD8B9
P 10200 1150
F 0 "C1" H 10200 1250 40  0000 L CNN
F 1 "100n" H 10206 1065 40  0000 L CNN
F 2 "~" H 10238 1000 30  0000 C CNN
F 3 "~" H 10200 1150 60  0000 C CNN
	1    10200 1150
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 56BFD8BF
P 10450 1150
F 0 "C2" H 10450 1250 40  0000 L CNN
F 1 "100n" H 10456 1065 40  0000 L CNN
F 2 "~" H 10488 1000 30  0000 C CNN
F 3 "~" H 10450 1150 60  0000 C CNN
	1    10450 1150
	1    0    0    -1  
$EndComp
$Comp
L C C10
U 1 1 56BFD8C5
P 10700 1150
F 0 "C10" H 10700 1250 40  0000 L CNN
F 1 "100n" H 10706 1065 40  0000 L CNN
F 2 "~" H 10738 1000 30  0000 C CNN
F 3 "~" H 10700 1150 60  0000 C CNN
	1    10700 1150
	1    0    0    -1  
$EndComp
$Comp
L DIODE D2
U 1 1 56C1BE65
P 7450 800
F 0 "D2" H 7450 900 40  0000 C CNN
F 1 "1n4001" H 7450 700 40  0000 C CNN
F 2 "~" H 7450 800 60  0000 C CNN
F 3 "~" H 7450 800 60  0000 C CNN
	1    7450 800 
	1    0    0    -1  
$EndComp
$Comp
L DIODE D7
U 1 1 56C1BE77
P 7450 1050
F 0 "D7" H 7450 1150 40  0000 C CNN
F 1 "1n4001" H 7450 950 40  0000 C CNN
F 2 "~" H 7450 1050 60  0000 C CNN
F 3 "~" H 7450 1050 60  0000 C CNN
	1    7450 1050
	1    0    0    -1  
$EndComp
$Comp
L DIODE D8
U 1 1 56C1BE7D
P 7450 1300
F 0 "D8" H 7450 1400 40  0000 C CNN
F 1 "1n4001" H 7450 1200 40  0000 C CNN
F 2 "~" H 7450 1300 60  0000 C CNN
F 3 "~" H 7450 1300 60  0000 C CNN
	1    7450 1300
	-1   0    0    1   
$EndComp
$Comp
L DIODE D9
U 1 1 56C1BE83
P 7450 1500
F 0 "D9" H 7450 1600 40  0000 C CNN
F 1 "1n4001" H 7450 1400 40  0000 C CNN
F 2 "~" H 7450 1500 60  0000 C CNN
F 3 "~" H 7450 1500 60  0000 C CNN
	1    7450 1500
	-1   0    0    1   
$EndComp
$Comp
L PWR_FLAG #FLG026
U 1 1 56C1D1F5
P 7900 850
F 0 "#FLG026" H 7900 945 30  0001 C CNN
F 1 "PWR_FLAG" H 7900 1030 30  0000 C CNN
F 2 "" H 7900 850 60  0000 C CNN
F 3 "" H 7900 850 60  0000 C CNN
	1    7900 850 
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG027
U 1 1 56C1D204
P 7900 1450
F 0 "#FLG027" H 7900 1545 30  0001 C CNN
F 1 "PWR_FLAG" H 7900 1630 30  0000 C CNN
F 2 "" H 7900 1450 60  0000 C CNN
F 3 "" H 7900 1450 60  0000 C CNN
	1    7900 1450
	-1   0    0    1   
$EndComp
Wire Wire Line
	900  2300 800  2300
Wire Wire Line
	800  2200 800  2600
Wire Wire Line
	800  2600 900  2600
Connection ~ 800  2300
Wire Wire Line
	900  4600 800  4600
Wire Wire Line
	800  4500 800  4700
Wire Wire Line
	900  4500 800  4500
Connection ~ 800  4600
Wire Wire Line
	3100 2600 3100 1300
Wire Wire Line
	2800 2600 3100 2600
Wire Wire Line
	3300 1300 3300 3750
Wire Wire Line
	3300 3750 2800 3750
Wire Wire Line
	3400 1300 3400 2800
Wire Wire Line
	3400 2800 2800 2800
Wire Wire Line
	2800 2700 3500 2700
Wire Wire Line
	3500 2700 3500 1300
Wire Wire Line
	3500 750  3500 1050
Wire Wire Line
	3200 750  3750 750 
Wire Wire Line
	3750 750  3750 1050
Wire Wire Line
	3400 1050 3400 750 
Connection ~ 3500 750 
Wire Wire Line
	3300 1050 3300 750 
Connection ~ 3400 750 
Wire Wire Line
	3200 1050 3200 750 
Connection ~ 3300 750 
Wire Wire Line
	3100 700  3100 1050
Wire Wire Line
	3300 1600 2800 1600
Wire Wire Line
	2800 1600 2800 1450
Connection ~ 3300 1600
Wire Wire Line
	2800 950  2800 750 
Wire Wire Line
	2800 750  3100 750 
Connection ~ 3100 750 
Wire Wire Line
	3000 4700 3000 2600
Connection ~ 3000 2600
Wire Wire Line
	3100 4700 3100 4650
Wire Wire Line
	3100 4650 3050 4650
Wire Wire Line
	3050 4650 3050 2500
Wire Wire Line
	3050 2500 2800 2500
Wire Wire Line
	3200 4700 3200 4600
Wire Wire Line
	3200 4600 3150 4600
Wire Wire Line
	3150 4600 3150 2400
Wire Wire Line
	3150 2400 2800 2400
Wire Wire Line
	2800 2300 3250 2300
Wire Wire Line
	3250 2300 3250 4550
Wire Wire Line
	3250 4550 3300 4550
Wire Wire Line
	3300 4550 3300 4700
Wire Wire Line
	3800 4700 3800 4500
Wire Wire Line
	3800 4500 2950 4500
Wire Wire Line
	2950 4500 2950 4600
Wire Wire Line
	2950 4600 2800 4600
Wire Wire Line
	3900 4700 3900 4450
Wire Wire Line
	3900 4450 2900 4450
Wire Wire Line
	2900 4450 2900 4500
Wire Wire Line
	2900 4500 2800 4500
Wire Wire Line
	2800 4400 4000 4400
Wire Wire Line
	4000 4400 4000 4700
Wire Wire Line
	4300 4650 4300 4700
Wire Wire Line
	4200 4650 4200 4700
Wire Wire Line
	4950 4700 4950 4750
Wire Wire Line
	4450 4700 4450 4650
Wire Wire Line
	4700 4550 4700 4450
Wire Wire Line
	4700 4450 4100 4450
Wire Wire Line
	4100 4450 4100 4700
Wire Wire Line
	2700 5850 2700 5900
Wire Wire Line
	2500 5900 2500 5850
Wire Wire Line
	2700 5300 2700 5350
Wire Wire Line
	3900 3000 3900 2950
Wire Wire Line
	3900 2300 3900 2350
Wire Wire Line
	3600 2300 3600 2900
Wire Wire Line
	3600 2900 2800 2900
Wire Wire Line
	4750 6900 4700 6900
Wire Wire Line
	4700 6900 4700 7000
Wire Wire Line
	4750 6700 4700 6700
Wire Wire Line
	4700 6700 4700 6600
Wire Wire Line
	4700 6100 4700 6200
Wire Wire Line
	5450 6900 5700 6900
Wire Wire Line
	6200 6300 6200 6150
Wire Wire Line
	6050 6150 6900 6150
Wire Wire Line
	5450 6700 5500 6700
Wire Wire Line
	5550 6150 5500 6150
Wire Wire Line
	5500 6150 5500 6700
Wire Wire Line
	6600 6050 6600 7250
Wire Wire Line
	6800 6050 6800 7250
Wire Wire Line
	7000 6800 6800 6800
Connection ~ 6800 6800
Wire Wire Line
	7000 6600 6900 6600
Wire Wire Line
	6900 6600 6900 6150
Connection ~ 6200 6150
Wire Wire Line
	6200 6950 6200 7050
Wire Wire Line
	6200 7050 6600 7050
Connection ~ 6600 7050
Wire Wire Line
	8000 1400 8000 1350
Wire Wire Line
	8350 1400 8350 1350
Connection ~ 8000 1400
Wire Wire Line
	7750 900  8450 900 
Wire Wire Line
	8350 900  8350 950 
Wire Wire Line
	8000 950  8000 900 
Connection ~ 8000 900 
Connection ~ 8350 900 
Wire Wire Line
	8850 1200 8850 1450
Connection ~ 8350 1400
Connection ~ 8850 1400
Wire Wire Line
	9350 1400 9350 1350
Wire Wire Line
	9600 1400 9600 1350
Connection ~ 9350 1400
Wire Wire Line
	9850 1400 9850 1350
Connection ~ 9600 1400
Wire Wire Line
	9350 950  9350 900 
Connection ~ 9350 900 
Wire Wire Line
	9600 900  9600 950 
Connection ~ 9600 900 
Wire Wire Line
	5300 1550 5650 1550
Wire Wire Line
	5600 1600 5600 1550
Connection ~ 5600 1550
Wire Wire Line
	5500 1350 5650 1350
Wire Wire Line
	5600 1350 5600 1300
Wire Wire Line
	5500 1100 5500 1350
Connection ~ 5600 1350
Wire Wire Line
	5100 1100 5500 1100
Wire Wire Line
	5300 1100 5300 1150
Wire Wire Line
	5600 800  5600 750 
Wire Wire Line
	5300 2600 5650 2600
Wire Wire Line
	5600 2650 5600 2600
Connection ~ 5600 2600
Wire Wire Line
	5500 2400 5650 2400
Wire Wire Line
	5600 2400 5600 2350
Wire Wire Line
	5500 2150 5500 2400
Connection ~ 5600 2400
Wire Wire Line
	5150 2150 5500 2150
Wire Wire Line
	5300 2150 5300 2200
Wire Wire Line
	5600 1850 5600 1800
Wire Wire Line
	5100 1100 5100 3150
Wire Wire Line
	5100 3150 2800 3150
Connection ~ 5300 1100
Wire Wire Line
	5150 2150 5150 3250
Wire Wire Line
	5150 3250 2800 3250
Connection ~ 5300 2150
Wire Wire Line
	2800 3650 5100 3650
Wire Wire Line
	5100 3650 5100 5600
Wire Wire Line
	5100 5600 4700 5600
Wire Wire Line
	5950 5250 5550 5250
Wire Wire Line
	5550 5250 5550 4300
Wire Wire Line
	5550 4300 2800 4300
Wire Wire Line
	5650 4000 5650 4950
Wire Wire Line
	5650 4950 5950 4950
Wire Wire Line
	5750 4650 5950 4650
Wire Wire Line
	5750 3900 5750 4650
Wire Wire Line
	5950 4350 5850 4350
Wire Wire Line
	5850 4350 5850 3550
Wire Wire Line
	5850 3550 2800 3550
Wire Wire Line
	7000 3100 6600 3100
Wire Wire Line
	6600 3100 6600 3350
Wire Wire Line
	6600 3350 2800 3350
Wire Wire Line
	6600 3450 6600 3550
Wire Wire Line
	7000 3650 6900 3650
Wire Wire Line
	6600 3450 2800 3450
Wire Wire Line
	7000 3200 6900 3200
Wire Wire Line
	6900 3450 7000 3450
Wire Wire Line
	6900 3000 7000 3000
Wire Wire Line
	6600 3550 7000 3550
Wire Wire Line
	6600 5250 6550 5250
Wire Wire Line
	6600 4350 6600 5300
Wire Wire Line
	6550 4950 6600 4950
Connection ~ 6600 5250
Wire Wire Line
	6600 4650 6550 4650
Connection ~ 6600 4950
Wire Wire Line
	6600 4350 6550 4350
Connection ~ 6600 4650
Wire Wire Line
	8200 850  8200 900 
Connection ~ 8200 900 
Wire Wire Line
	9250 900  10700 900 
Wire Wire Line
	9850 900  9850 950 
Wire Wire Line
	9500 850  9500 900 
Connection ~ 9500 900 
Wire Wire Line
	9100 3400 9100 3350
Wire Wire Line
	9100 3350 10500 3350
Wire Wire Line
	10000 3350 10000 3400
Wire Wire Line
	9650 3250 9650 3350
Connection ~ 9650 3350
Wire Wire Line
	9350 4900 9350 4850
Wire Wire Line
	9100 4800 9100 4850
Wire Wire Line
	9100 4850 10500 4850
Wire Wire Line
	10000 4850 10000 4800
Connection ~ 9350 4850
Wire Wire Line
	9100 3800 9100 4400
Wire Wire Line
	10000 3800 10000 4400
Wire Wire Line
	9200 3850 9100 3850
Connection ~ 9100 3850
Wire Wire Line
	8800 3600 8800 3900
Connection ~ 10000 3900
Wire Wire Line
	7450 4100 7450 4600
Wire Wire Line
	9650 4300 9650 4600
Wire Wire Line
	9650 4600 9700 4600
Wire Wire Line
	9100 4000 10700 4000
Connection ~ 9100 4000
Wire Wire Line
	10000 4200 10700 4200
Connection ~ 10000 4200
Wire Wire Line
	8800 4600 8600 4600
Wire Wire Line
	8600 4300 9650 4300
Wire Wire Line
	7550 4300 8100 4300
Wire Wire Line
	7450 4600 8100 4600
Wire Wire Line
	9200 3600 9200 3850
Wire Wire Line
	10000 3900 9750 3900
Wire Wire Line
	8800 3900 9250 3900
Wire Wire Line
	10500 3800 10500 4350
Connection ~ 10500 4200
Wire Wire Line
	10250 3800 10250 4350
Connection ~ 10250 4000
Wire Wire Line
	10250 4850 10250 4750
Connection ~ 10000 4850
Wire Wire Line
	10500 4850 10500 4750
Connection ~ 10250 4850
Wire Wire Line
	10250 3350 10250 3400
Connection ~ 10000 3350
Wire Wire Line
	10500 3350 10500 3400
Connection ~ 10250 3350
Wire Wire Line
	2800 4000 5650 4000
Wire Wire Line
	5750 3900 2800 3900
Wire Wire Line
	2800 4100 7450 4100
Wire Wire Line
	7550 4200 2800 4200
Wire Wire Line
	7550 4200 7550 4300
Wire Wire Line
	3900 3000 2800 3000
Wire Wire Line
	3900 2300 3600 2300
Wire Wire Line
	10200 1400 10200 1350
Wire Wire Line
	10700 1400 10700 1350
Wire Wire Line
	7700 1400 10700 1400
Connection ~ 10200 1400
Wire Wire Line
	10450 1350 10450 1400
Connection ~ 10450 1400
Wire Wire Line
	10700 900  10700 950 
Wire Wire Line
	10200 900  10200 950 
Wire Wire Line
	10450 950  10450 900 
Connection ~ 10450 900 
Connection ~ 10200 900 
Wire Wire Line
	7650 1300 7700 1300
Wire Wire Line
	7700 1300 7700 1500
Wire Wire Line
	7700 1500 7650 1500
Connection ~ 7700 1400
Wire Wire Line
	7750 1050 7650 1050
Wire Wire Line
	7750 800  7750 1050
Wire Wire Line
	7750 800  7650 800 
Connection ~ 7750 900 
Wire Wire Line
	7150 1500 7250 1500
Wire Wire Line
	7150 1050 7150 1500
Wire Wire Line
	7150 1050 7250 1050
Wire Wire Line
	7200 1300 7250 1300
Wire Wire Line
	7200 800  7200 1300
Wire Wire Line
	7200 800  7250 800 
Wire Wire Line
	6950 1000 7200 1000
Connection ~ 7200 1000
Wire Wire Line
	6950 1200 7150 1200
Connection ~ 7150 1200
Connection ~ 9850 900 
Connection ~ 9850 1400
Wire Wire Line
	7900 1450 7900 1400
Connection ~ 7900 1400
Wire Wire Line
	7900 850  7900 900 
Connection ~ 7900 900 
$EndSCHEMATC
