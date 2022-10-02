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
L Connector:Conn_01x08_Female J5
U 1 1 60E7DD90
P 4800 2900
F 0 "J5" H 4692 2275 50  0000 C CNN
F 1 "Conn_01x08_Female" H 4692 2366 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 4800 2900 50  0001 C CNN
F 3 "~" H 4800 2900 50  0001 C CNN
	1    4800 2900
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x08_Female J6
U 1 1 60E80CC9
P 6750 2800
F 0 "J6" H 6778 2776 50  0000 L CNN
F 1 "Conn_01x08_Female" H 6778 2685 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 6750 2800 50  0001 C CNN
F 3 "~" H 6750 2800 50  0001 C CNN
	1    6750 2800
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 60E8B7D8
P 850 3550
F 0 "J1" H 768 3225 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 768 3316 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 850 3550 50  0001 C CNN
F 3 "~" H 850 3550 50  0001 C CNN
	1    850  3550
	-1   0    0    1   
$EndComp
$Comp
L Diode:1N4007 D1
U 1 1 60E8D58C
P 3150 2250
F 0 "D1" H 3150 2467 50  0000 C CNN
F 1 "1N4007" H 3150 2376 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 3150 2075 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 3150 2250 50  0001 C CNN
	1    3150 2250
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LM7805_TO220 U1
U 1 1 60E8E495
P 3150 2700
F 0 "U1" H 3150 2942 50  0000 C CNN
F 1 "LM7805_TO220" H 3150 2851 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 3150 2925 50  0001 C CIN
F 3 "https://www.onsemi.cn/PowerSolutions/document/MC7800-D.PDF" H 3150 2650 50  0001 C CNN
	1    3150 2700
	1    0    0    -1  
$EndComp
$Comp
L pspice:CAP C2
U 1 1 60E94815
P 2650 3150
F 0 "C2" H 2828 3196 50  0000 L CNN
F 1 "100nF" H 2828 3105 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 2650 3150 50  0001 C CNN
F 3 "~" H 2650 3150 50  0001 C CNN
	1    2650 3150
	1    0    0    -1  
$EndComp
$Comp
L pspice:CAP C3
U 1 1 60E95E9A
P 3600 3150
F 0 "C3" H 3778 3196 50  0000 L CNN
F 1 "10uF" H 3778 3105 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D8.0mm_P2.50mm" H 3600 3150 50  0001 C CNN
F 3 "~" H 3600 3150 50  0001 C CNN
	1    3600 3150
	1    0    0    -1  
$EndComp
$Comp
L pspice:CAP C4
U 1 1 60E96DB4
P 4200 3150
F 0 "C4" H 4378 3196 50  0000 L CNN
F 1 "100nF" H 4378 3105 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 4200 3150 50  0001 C CNN
F 3 "~" H 4200 3150 50  0001 C CNN
	1    4200 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 2700 3500 2700
Wire Wire Line
	4200 2700 4200 2900
Wire Wire Line
	3600 2900 3600 2700
Connection ~ 3600 2700
Wire Wire Line
	3600 2700 4200 2700
Wire Wire Line
	2850 2700 2800 2700
Wire Wire Line
	2150 2700 2150 2900
Wire Wire Line
	2650 2900 2650 2700
Connection ~ 2650 2700
Wire Wire Line
	2650 2700 2150 2700
Wire Wire Line
	3000 2250 2800 2250
Wire Wire Line
	2800 2250 2800 2700
Connection ~ 2800 2700
Wire Wire Line
	2800 2700 2650 2700
Wire Wire Line
	3300 2250 3500 2250
Wire Wire Line
	3500 2250 3500 2700
Connection ~ 3500 2700
Wire Wire Line
	3500 2700 3600 2700
Wire Wire Line
	2150 3400 2650 3400
Wire Wire Line
	3600 3400 3300 3400
Connection ~ 2650 3400
Wire Wire Line
	4200 3400 3600 3400
Connection ~ 3600 3400
Wire Wire Line
	3150 3000 3150 3400
Connection ~ 3150 3400
Wire Wire Line
	3150 3400 2650 3400
$Comp
L power:GND #PWR02
U 1 1 60E9E275
P 3300 3650
F 0 "#PWR02" H 3300 3400 50  0001 C CNN
F 1 "GND" H 3305 3477 50  0000 C CNN
F 2 "" H 3300 3650 50  0001 C CNN
F 3 "" H 3300 3650 50  0001 C CNN
	1    3300 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 3650 3300 3400
Connection ~ 3300 3400
Wire Wire Line
	3300 3400 3150 3400
Wire Wire Line
	6550 2600 6300 2600
Wire Wire Line
	6550 2700 6300 2700
Wire Wire Line
	6300 2800 6550 2800
Wire Wire Line
	6550 2900 6300 2900
Wire Wire Line
	6550 3000 6300 3000
Wire Wire Line
	6300 3100 6550 3100
Wire Wire Line
	5250 2700 5000 2700
Wire Wire Line
	5000 2800 5250 2800
Wire Wire Line
	5250 2900 5000 2900
Wire Wire Line
	5000 3000 5250 3000
Wire Wire Line
	5250 3100 5000 3100
Wire Wire Line
	5000 3200 5250 3200
NoConn ~ 6300 2500
Text GLabel 4350 2600 2    50   Input ~ 0
5V
Wire Wire Line
	4350 2600 4200 2600
Wire Wire Line
	4200 2600 4200 2700
Connection ~ 4200 2700
Text GLabel 5150 2150 0    50   Input ~ 0
5V
Wire Wire Line
	5250 2500 5250 2150
Wire Wire Line
	5250 2150 5150 2150
Text GLabel 2050 2600 0    50   Input ~ 0
12V
Wire Wire Line
	2050 2600 2150 2600
Wire Wire Line
	2150 2600 2150 2700
Connection ~ 2150 2700
Wire Wire Line
	5000 2600 5250 2600
$Comp
L Transistor_BJT:TIP122 Q3
U 1 1 60EB037B
P 7700 1450
F 0 "Q3" H 7907 1496 50  0000 L CNN
F 1 "TIP122" H 7907 1405 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 7900 1375 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/TIP120-D.PDF" H 7700 1450 50  0001 L CNN
	1    7700 1450
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP122 Q7
U 1 1 60EB108A
P 8900 1450
F 0 "Q7" H 9107 1496 50  0000 L CNN
F 1 "TIP122" H 9107 1405 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 9100 1375 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/TIP120-D.PDF" H 8900 1450 50  0001 L CNN
	1    8900 1450
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP122 Q4
U 1 1 60EB7976
P 7700 2450
F 0 "Q4" H 7907 2496 50  0000 L CNN
F 1 "TIP122" H 7907 2405 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 7900 2375 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/TIP120-D.PDF" H 7700 2450 50  0001 L CNN
	1    7700 2450
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP122 Q1
U 1 1 60EC8652
P 7450 4250
F 0 "Q1" H 7657 4296 50  0000 L CNN
F 1 "TIP122" H 7657 4205 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 7650 4175 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/TIP120-D.PDF" H 7450 4250 50  0001 L CNN
	1    7450 4250
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP122 Q5
U 1 1 60EC9FD2
P 8650 4250
F 0 "Q5" H 8857 4296 50  0000 L CNN
F 1 "TIP122" H 8857 4205 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 8850 4175 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/TIP120-D.PDF" H 8650 4250 50  0001 L CNN
	1    8650 4250
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP122 Q6
U 1 1 60ECC1AC
P 8650 5300
F 0 "Q6" H 8857 5346 50  0000 L CNN
F 1 "TIP122" H 8857 5255 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 8850 5225 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/TIP120-D.PDF" H 8650 5300 50  0001 L CNN
	1    8650 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 60ED0707
P 8150 4400
F 0 "R5" H 8220 4446 50  0000 L CNN
F 1 "330" H 8220 4355 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8080 4400 50  0001 C CNN
F 3 "~" H 8150 4400 50  0001 C CNN
	1    8150 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 60ED1716
P 6950 4400
F 0 "R1" H 7020 4446 50  0000 L CNN
F 1 "R" H 7020 4355 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6880 4400 50  0001 C CNN
F 3 "~" H 6950 4400 50  0001 C CNN
	1    6950 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 60ED1E30
P 8150 5450
F 0 "R6" H 8220 5496 50  0000 L CNN
F 1 "330" H 8220 5405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8080 5450 50  0001 C CNN
F 3 "~" H 8150 5450 50  0001 C CNN
	1    8150 5450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 60ED2BEC
P 8400 1600
F 0 "R7" H 8470 1646 50  0000 L CNN
F 1 "330" H 8470 1555 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8330 1600 50  0001 C CNN
F 3 "~" H 8400 1600 50  0001 C CNN
	1    8400 1600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 60ED2E3F
P 7200 1600
F 0 "R3" H 7270 1646 50  0000 L CNN
F 1 "330" H 7270 1555 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7130 1600 50  0001 C CNN
F 3 "~" H 7200 1600 50  0001 C CNN
	1    7200 1600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 60ED30CD
P 7200 2600
F 0 "R4" H 7270 2646 50  0000 L CNN
F 1 "330" H 7270 2555 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7130 2600 50  0001 C CNN
F 3 "~" H 7200 2600 50  0001 C CNN
	1    7200 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 1450 7200 1450
Wire Wire Line
	8700 1450 8400 1450
Wire Wire Line
	7500 2450 7200 2450
Wire Wire Line
	7250 4250 6950 4250
Wire Wire Line
	8450 4250 8150 4250
Wire Wire Line
	8450 5300 8150 5300
$Comp
L Connector:Screw_Terminal_01x02 J13
U 1 1 60EF3F2B
P 7600 1100
F 0 "J13" H 7518 867 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 7518 866 50  0001 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 7600 1100 50  0001 C CNN
F 3 "~" H 7600 1100 50  0001 C CNN
	1    7600 1100
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J14
U 1 1 60EF8CB3
P 7600 2100
F 0 "J14" H 7518 1867 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 7518 1867 50  0001 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 7600 2100 50  0001 C CNN
F 3 "~" H 7600 2100 50  0001 C CNN
	1    7600 2100
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J23
U 1 1 60EF9A2A
P 8800 1100
F 0 "J23" H 8718 867 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 8718 866 50  0001 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 8800 1100 50  0001 C CNN
F 3 "~" H 8800 1100 50  0001 C CNN
	1    8800 1100
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J11
U 1 1 60EFA852
P 7350 3900
F 0 "J11" H 7268 3667 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 7268 3666 50  0001 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 7350 3900 50  0001 C CNN
F 3 "~" H 7350 3900 50  0001 C CNN
	1    7350 3900
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J21
U 1 1 60EFBD47
P 8550 3900
F 0 "J21" H 8468 3667 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 8468 3666 50  0001 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 8550 3900 50  0001 C CNN
F 3 "~" H 8550 3900 50  0001 C CNN
	1    8550 3900
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J22
U 1 1 60EFF331
P 8550 4950
F 0 "J22" H 8468 4717 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 8468 4716 50  0001 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 8550 4950 50  0001 C CNN
F 3 "~" H 8550 4950 50  0001 C CNN
	1    8550 4950
	-1   0    0    1   
$EndComp
Wire Wire Line
	8750 5100 8750 5050
Wire Wire Line
	8750 4050 8750 3950
Wire Wire Line
	7550 4050 7550 3950
Wire Wire Line
	7800 2100 7800 2200
Wire Wire Line
	9000 1250 9000 1100
Wire Wire Line
	7800 1100 7800 1250
Wire Wire Line
	7800 1000 7800 950 
Wire Wire Line
	7800 750  8000 750 
Wire Wire Line
	9000 1000 9000 950 
Wire Wire Line
	9000 800  9200 800 
Wire Wire Line
	7800 2000 7900 2000
Wire Wire Line
	7900 2000 7900 1900
Wire Wire Line
	7900 1750 8000 1750
$Comp
L Diode:1N4007 D4
U 1 1 60F22B5A
P 8100 1100
F 0 "D4" V 8054 1180 50  0000 L CNN
F 1 "1N4007" V 8145 1180 50  0000 L CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 8100 925 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 8100 1100 50  0001 C CNN
	1    8100 1100
	0    1    1    0   
$EndComp
$Comp
L Diode:1N4007 D9
U 1 1 60F23CD9
P 9400 1100
F 0 "D9" V 9354 1180 50  0000 L CNN
F 1 "1N4007" V 9445 1180 50  0000 L CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 9400 925 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 9400 1100 50  0001 C CNN
	1    9400 1100
	0    1    1    0   
$EndComp
$Comp
L Diode:1N4007 D5
U 1 1 60F243F8
P 8100 2050
F 0 "D5" V 8054 2130 50  0000 L CNN
F 1 "1N4007" V 8145 2130 50  0000 L CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 8100 1875 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 8100 2050 50  0001 C CNN
	1    8100 2050
	0    1    1    0   
$EndComp
Wire Wire Line
	8100 2200 7800 2200
Connection ~ 7800 2200
Wire Wire Line
	7800 2200 7800 2250
Wire Wire Line
	8100 1900 7900 1900
Connection ~ 7900 1900
Wire Wire Line
	7900 1900 7900 1750
Wire Wire Line
	8100 950  7800 950 
Connection ~ 7800 950 
Wire Wire Line
	7800 950  7800 750 
Wire Wire Line
	8100 1250 7800 1250
Connection ~ 7800 1250
Wire Wire Line
	9400 950  9000 950 
Connection ~ 9000 950 
Wire Wire Line
	9000 950  9000 800 
Wire Wire Line
	9400 1250 9000 1250
Connection ~ 9000 1250
$Comp
L power:GND #PWR07
U 1 1 60F33702
P 7550 1650
F 0 "#PWR07" H 7550 1400 50  0001 C CNN
F 1 "GND" H 7555 1477 50  0000 C CNN
F 2 "" H 7550 1650 50  0001 C CNN
F 3 "" H 7550 1650 50  0001 C CNN
	1    7550 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 1650 7550 1650
$Comp
L power:GND #PWR011
U 1 1 60F364EC
P 8700 1650
F 0 "#PWR011" H 8700 1400 50  0001 C CNN
F 1 "GND" H 8705 1477 50  0000 C CNN
F 2 "" H 8700 1650 50  0001 C CNN
F 3 "" H 8700 1650 50  0001 C CNN
	1    8700 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	9000 1650 8700 1650
$Comp
L power:GND #PWR08
U 1 1 60F3DA7A
P 7550 2650
F 0 "#PWR08" H 7550 2400 50  0001 C CNN
F 1 "GND" H 7555 2477 50  0000 C CNN
F 2 "" H 7550 2650 50  0001 C CNN
F 3 "" H 7550 2650 50  0001 C CNN
	1    7550 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 2650 7550 2650
Wire Wire Line
	8750 4850 8750 4750
Wire Wire Line
	7850 3550 7550 3550
Wire Wire Line
	7550 3550 7550 3650
Wire Wire Line
	9100 3550 8750 3550
Wire Wire Line
	8750 3550 8750 3650
$Comp
L power:GND #PWR05
U 1 1 60F545EF
P 7300 4450
F 0 "#PWR05" H 7300 4200 50  0001 C CNN
F 1 "GND" H 7305 4277 50  0000 C CNN
F 2 "" H 7300 4450 50  0001 C CNN
F 3 "" H 7300 4450 50  0001 C CNN
	1    7300 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 4450 7300 4450
$Comp
L power:GND #PWR09
U 1 1 60F579DF
P 8500 4450
F 0 "#PWR09" H 8500 4200 50  0001 C CNN
F 1 "GND" H 8505 4277 50  0000 C CNN
F 2 "" H 8500 4450 50  0001 C CNN
F 3 "" H 8500 4450 50  0001 C CNN
	1    8500 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 4450 8500 4450
$Comp
L power:GND #PWR010
U 1 1 60F5E15E
P 8500 5500
F 0 "#PWR010" H 8500 5250 50  0001 C CNN
F 1 "GND" H 8505 5327 50  0000 C CNN
F 2 "" H 8500 5500 50  0001 C CNN
F 3 "" H 8500 5500 50  0001 C CNN
	1    8500 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 5500 8500 5500
$Comp
L Connector:Conn_01x01_Female J9
U 1 1 60F660DB
P 7200 1950
F 0 "J9" V 7092 1998 50  0000 L CNN
F 1 "Conn_01x01_Female" H 7092 1816 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 7200 1950 50  0001 C CNN
F 3 "~" H 7200 1950 50  0001 C CNN
	1    7200 1950
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x01_Female J10
U 1 1 60F668AD
P 7200 2950
F 0 "J10" V 7092 2998 50  0000 L CNN
F 1 "Conn_01x01_Female" H 7092 2816 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 7200 2950 50  0001 C CNN
F 3 "~" H 7200 2950 50  0001 C CNN
	1    7200 2950
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x01_Female J7
U 1 1 60F68CE1
P 6950 4750
F 0 "J7" V 6842 4798 50  0000 L CNN
F 1 "Conn_01x01_Female" H 6842 4616 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 6950 4750 50  0001 C CNN
F 3 "~" H 6950 4750 50  0001 C CNN
	1    6950 4750
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x01_Female J17
U 1 1 60F69716
P 8150 4750
F 0 "J17" V 8042 4798 50  0000 L CNN
F 1 "Conn_01x01_Female" H 8042 4616 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 8150 4750 50  0001 C CNN
F 3 "~" H 8150 4750 50  0001 C CNN
	1    8150 4750
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x01_Female J18
U 1 1 60F6A535
P 8150 5800
F 0 "J18" V 8042 5848 50  0000 L CNN
F 1 "Conn_01x01_Female" H 8042 5666 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 8150 5800 50  0001 C CNN
F 3 "~" H 8150 5800 50  0001 C CNN
	1    8150 5800
	0    1    1    0   
$EndComp
$Comp
L Diode:1N4007 D2
U 1 1 60F6C106
P 7750 3800
F 0 "D2" V 7704 3880 50  0000 L CNN
F 1 "1N4007" V 7795 3880 50  0000 L CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 7750 3625 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 7750 3800 50  0001 C CNN
	1    7750 3800
	0    1    1    0   
$EndComp
Wire Wire Line
	7750 3650 7550 3650
Connection ~ 7550 3650
Wire Wire Line
	7550 3650 7550 3800
Wire Wire Line
	7750 3950 7550 3950
Connection ~ 7550 3950
Wire Wire Line
	7550 3950 7550 3900
$Comp
L Diode:1N4007 D6
U 1 1 60F72C59
P 9000 3800
F 0 "D6" V 8954 3880 50  0000 L CNN
F 1 "1N4007" V 9045 3880 50  0000 L CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 9000 3625 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 9000 3800 50  0001 C CNN
	1    9000 3800
	0    1    1    0   
$EndComp
Wire Wire Line
	9000 3950 8750 3950
Connection ~ 8750 3950
Wire Wire Line
	8750 3950 8750 3900
Wire Wire Line
	9000 3650 8750 3650
Connection ~ 8750 3650
Wire Wire Line
	8750 3650 8750 3800
$Comp
L Diode:1N4007 D7
U 1 1 60F79D6C
P 9000 4900
F 0 "D7" V 8954 4980 50  0000 L CNN
F 1 "1N4007" V 9045 4980 50  0000 L CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 9000 4725 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 9000 4900 50  0001 C CNN
	1    9000 4900
	0    1    1    0   
$EndComp
Wire Wire Line
	9000 4750 8750 4750
Connection ~ 8750 4750
Wire Wire Line
	8750 4750 8750 4650
Wire Wire Line
	9000 5050 8750 5050
Connection ~ 8750 5050
Wire Wire Line
	8750 5050 8750 4950
$Comp
L Connector:Conn_01x01_Female J16
U 1 1 60F897CF
P 8050 3550
F 0 "J16" H 8078 3530 50  0000 L CNN
F 1 "Conn_01x01_Female" H 7942 3416 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 8050 3550 50  0001 C CNN
F 3 "~" H 8050 3550 50  0001 C CNN
	1    8050 3550
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J26
U 1 1 60F8A1A0
P 9300 3550
F 0 "J26" H 9328 3530 50  0000 L CNN
F 1 "Conn_01x01_Female" H 9192 3416 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 9300 3550 50  0001 C CNN
F 3 "~" H 9300 3550 50  0001 C CNN
	1    9300 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 4650 9050 4650
$Comp
L Connector:Conn_01x01_Female J25
U 1 1 60F8C044
P 9250 4650
F 0 "J25" H 9278 4630 50  0000 L CNN
F 1 "Conn_01x01_Female" H 9142 4516 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 9250 4650 50  0001 C CNN
F 3 "~" H 9250 4650 50  0001 C CNN
	1    9250 4650
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x05_Female J2
U 1 1 60F8D0E5
P 2700 4800
F 0 "J2" H 2728 4780 50  0000 L CNN
F 1 "Conn_01x05_Female" H 2728 4735 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 2700 4800 50  0001 C CNN
F 3 "~" H 2700 4800 50  0001 C CNN
	1    2700 4800
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x05_Female J3
U 1 1 60F8EE87
P 3350 4800
F 0 "J3" H 3378 4780 50  0000 L CNN
F 1 "Conn_01x05_Female" H 3378 4735 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 3350 4800 50  0001 C CNN
F 3 "~" H 3350 4800 50  0001 C CNN
	1    3350 4800
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x05_Female J4
U 1 1 60F9368B
P 3950 4800
F 0 "J4" H 3978 4780 50  0000 L CNN
F 1 "Conn_01x05_Female" H 3978 4735 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 3950 4800 50  0001 C CNN
F 3 "~" H 3950 4800 50  0001 C CNN
	1    3950 4800
	1    0    0    -1  
$EndComp
Text GLabel 2500 4350 1    50   Input ~ 0
5V
Wire Wire Line
	2500 4350 2500 4600
Connection ~ 2500 4600
Wire Wire Line
	2500 4600 2500 4700
Connection ~ 2500 4700
Wire Wire Line
	2500 4700 2500 4800
Connection ~ 2500 4800
Wire Wire Line
	2500 4800 2500 4900
Connection ~ 2500 4900
Wire Wire Line
	2500 4900 2500 5000
Text GLabel 3150 4350 1    50   Input ~ 0
12V
Wire Wire Line
	3150 4350 3150 4600
Connection ~ 3150 4600
Wire Wire Line
	3150 4600 3150 4700
Connection ~ 3150 4700
Wire Wire Line
	3150 4700 3150 4800
Connection ~ 3150 4800
Wire Wire Line
	3150 4800 3150 4900
Connection ~ 3150 4900
Wire Wire Line
	3150 4900 3150 5000
$Comp
L power:GND #PWR03
U 1 1 60F9BD6B
P 3750 5200
F 0 "#PWR03" H 3750 4950 50  0001 C CNN
F 1 "GND" H 3755 5027 50  0000 C CNN
F 2 "" H 3750 5200 50  0001 C CNN
F 3 "" H 3750 5200 50  0001 C CNN
	1    3750 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 4600 3750 4700
Connection ~ 3750 4700
Wire Wire Line
	3750 4700 3750 4800
Connection ~ 3750 4800
Wire Wire Line
	3750 4800 3750 4900
Connection ~ 3750 4900
Wire Wire Line
	3750 4900 3750 5000
Connection ~ 3750 5000
Wire Wire Line
	3750 5000 3750 5200
$Comp
L power:GND #PWR04
U 1 1 60FC8F12
P 6350 3400
F 0 "#PWR04" H 6350 3150 50  0001 C CNN
F 1 "GND" H 6355 3227 50  0000 C CNN
F 2 "" H 6350 3400 50  0001 C CNN
F 3 "" H 6350 3400 50  0001 C CNN
	1    6350 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 3200 6350 3200
Wire Wire Line
	6350 3200 6350 3400
NoConn ~ 6550 3200
NoConn ~ 6550 2500
NoConn ~ 5000 2500
Text GLabel 1300 3700 1    50   Input ~ 0
12V
Wire Wire Line
	1300 3000 1300 3250
$Comp
L power:GND #PWR01
U 1 1 60EABFBD
P 1300 3250
F 0 "#PWR01" H 1300 3000 50  0001 C CNN
F 1 "GND" H 1305 3077 50  0000 C CNN
F 2 "" H 1300 3250 50  0001 C CNN
F 3 "" H 1300 3250 50  0001 C CNN
	1    1300 3250
	1    0    0    -1  
$EndComp
$Comp
L pspice:CAP C1
U 1 1 60E92B28
P 2150 3150
F 0 "C1" H 2328 3196 50  0000 L CNN
F 1 "0.22uF" H 2328 3105 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 2150 3150 50  0001 C CNN
F 3 "~" H 2150 3150 50  0001 C CNN
	1    2150 3150
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1050 3550 1050 3900
Wire Wire Line
	1050 3900 1300 3900
Wire Wire Line
	1300 3900 1300 3700
Wire Wire Line
	1050 3450 1050 3000
Wire Wire Line
	1050 3000 1300 3000
$Comp
L Connector:Conn_01x01_Female J27
U 1 1 60F4DDC5
P 8200 750
F 0 "J27" V 8092 798 50  0000 L CNN
F 1 "Conn_01x01_Female" H 8092 616 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 8200 750 50  0001 C CNN
F 3 "~" H 8200 750 50  0001 C CNN
	1    8200 750 
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J28
U 1 1 60F4F9AE
P 9400 800
F 0 "J28" V 9292 848 50  0000 L CNN
F 1 "Conn_01x01_Female" H 9292 666 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 9400 800 50  0001 C CNN
F 3 "~" H 9400 800 50  0001 C CNN
	1    9400 800 
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J29
U 1 1 60F6E992
P 8200 1750
F 0 "J29" V 8092 1798 50  0000 L CNN
F 1 "Conn_01x01_Female" H 8092 1616 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 8200 1750 50  0001 C CNN
F 3 "~" H 8200 1750 50  0001 C CNN
	1    8200 1750
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J19
U 1 1 60F61F80
P 8400 1950
F 0 "J19" V 8292 1998 50  0000 L CNN
F 1 "Conn_01x01_Female" H 8292 1816 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 8400 1950 50  0001 C CNN
F 3 "~" H 8400 1950 50  0001 C CNN
	1    8400 1950
	0    1    1    0   
$EndComp
$Comp
L RF_Module:ESP32CAM U2
U 1 1 60E77BEB
P 5800 2750
F 0 "U2" H 5775 3225 50  0000 C CNN
F 1 "ESP32CAM" H 5775 3134 50  0000 C CNN
F 2 "RF_Module:ESP32CAM" H 5800 2750 50  0001 C CNN
F 3 "" H 5800 2750 50  0001 C CNN
	1    5800 2750
	1    0    0    -1  
$EndComp
$EndSCHEMATC
