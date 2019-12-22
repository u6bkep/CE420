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
Wire Wire Line
	1800 4150 1800 4050
$Comp
L PIC24FV16KM202-I_SP:PIC24FV16KM202-I_SP IC1
U 1 1 5D8BC3E2
P 1450 1300
F 0 "IC1" H 5200 1565 50  0000 C CNN
F 1 "PIC24FV16KM202-I_SP" H 5200 1474 50  0000 C CNN
F 2 "PIC24FV16KM202-I_SP:DIP794W56P254L3486H508Q28N" H 8800 1400 50  0001 L CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/33030a.pdf" H 8800 1300 50  0001 L CNN
F 4 "MICROCHIP - PIC24FV16KM202-I/SP - MCU, 16BIT, PIC24, 32MHZ, SPDIP-28" H 8800 1200 50  0001 L CNN "Description"
F 5 "5.08" H 8800 1100 50  0001 L CNN "Height"
F 6 "Microchip" H 8800 1000 50  0001 L CNN "Manufacturer_Name"
F 7 "PIC24FV16KM202-I/SP" H 8800 900 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "579-24FV16KM202I/SP" H 8800 800 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.com/Search/Refine.aspx?Keyword=579-24FV16KM202I%2FSP" H 8800 700 50  0001 L CNN "Mouser Price/Stock"
F 10 "1772530" H 8800 600 50  0001 L CNN "RS Part Number"
F 11 "http://uk.rs-online.com/web/p/products/1772530" H 8800 500 50  0001 L CNN "RS Price/Stock"
F 12 "70451531" H 8800 400 50  0001 L CNN "Allied_Number"
F 13 "https://www.alliedelec.com/microchip-technology-inc-pic24fv16km202-i-sp/70451531/" H 8800 300 50  0001 L CNN "Allied Price/Stock"
	1    1450 1300
	1    0    0    -1  
$EndComp
$Comp
L LED:APA102 D1
U 1 1 5D902724
P 3050 5600
F 0 "D1" H 3050 6081 50  0000 C CNN
F 1 "APA102" H 3050 5990 50  0000 C CNN
F 2 "LED_SMD:LED_RGB_5050-6" H 3100 5300 50  0001 L TNN
F 3 "http://www.led-color.com/upload/201506/APA102%20LED.pdf" H 3150 5225 50  0001 L TNN
	1    3050 5600
	1    0    0    -1  
$EndComp
$Comp
L LED:APA102 D2
U 1 1 5D9434E4
P 3650 5600
F 0 "D2" H 3650 6081 50  0000 C CNN
F 1 "APA102" H 3650 5990 50  0000 C CNN
F 2 "LED_SMD:LED_RGB_5050-6" H 3700 5300 50  0001 L TNN
F 3 "http://www.led-color.com/upload/201506/APA102%20LED.pdf" H 3750 5225 50  0001 L TNN
	1    3650 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 5300 3050 5300
Wire Wire Line
	2650 5900 3050 5900
$Comp
L LED:APA102 D3
U 1 1 5D95DB42
P 4250 5600
F 0 "D3" H 4250 6081 50  0000 C CNN
F 1 "APA102" H 4250 5990 50  0000 C CNN
F 2 "LED_SMD:LED_RGB_5050-6" H 4300 5300 50  0001 L TNN
F 3 "http://www.led-color.com/upload/201506/APA102%20LED.pdf" H 4350 5225 50  0001 L TNN
	1    4250 5600
	1    0    0    -1  
$EndComp
$Comp
L LED:APA102 D4
U 1 1 5D95EB07
P 4850 5600
F 0 "D4" H 4850 6081 50  0000 C CNN
F 1 "APA102" H 4850 5990 50  0000 C CNN
F 2 "LED_SMD:LED_RGB_5050-6" H 4900 5300 50  0001 L TNN
F 3 "http://www.led-color.com/upload/201506/APA102%20LED.pdf" H 4950 5225 50  0001 L TNN
	1    4850 5600
	1    0    0    -1  
$EndComp
$Comp
L LED:APA102 D5
U 1 1 5D95F6FD
P 5450 5600
F 0 "D5" H 5450 6081 50  0000 C CNN
F 1 "APA102" H 5450 5990 50  0000 C CNN
F 2 "LED_SMD:LED_RGB_5050-6" H 5500 5300 50  0001 L TNN
F 3 "http://www.led-color.com/upload/201506/APA102%20LED.pdf" H 5550 5225 50  0001 L TNN
	1    5450 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 5900 3650 5900
Connection ~ 3050 5900
Connection ~ 4250 5900
Wire Wire Line
	4250 5900 4850 5900
Connection ~ 4850 5900
Wire Wire Line
	4850 5900 5450 5900
Wire Wire Line
	3650 5900 4250 5900
Connection ~ 3650 5900
Wire Wire Line
	3050 5300 3650 5300
Connection ~ 3050 5300
Connection ~ 3650 5300
Wire Wire Line
	3650 5300 4250 5300
Connection ~ 4250 5300
Wire Wire Line
	4250 5300 4850 5300
Connection ~ 4850 5300
Wire Wire Line
	4850 5300 5450 5300
Text GLabel 1050 4050 0    50   Input ~ 0
vcc
Text GLabel 2600 5300 0    50   Input ~ 0
vcc
Text GLabel 9650 1300 2    50   Input ~ 0
vcc
Text GLabel 5150 4100 2    50   Input ~ 0
vcc
Text GLabel 5150 4200 2    50   Input ~ 0
GND
Text GLabel 2650 5900 0    50   Input ~ 0
GND
Text GLabel 9650 1400 2    50   Input ~ 0
GND
$Comp
L fan-pcb-rescue:3144_hall_effect_sensor-Sensor U1
U 1 1 5D9A6407
P 1750 3500
F 0 "U1" H 1928 3213 50  0000 L CNN
F 1 "3144_hall_effect_sensor" H 1928 3122 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92Flat" H 1750 3500 50  0001 C CNN
F 3 "" H 1750 3500 50  0001 C CNN
	1    1750 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 4050 1500 4050
$Comp
L fan-pcb-rescue:SH-M08-Device U2
U 1 1 5D9B6C53
P 4000 3800
F 0 "U2" H 3962 3875 50  0000 C CNN
F 1 "SH-M08" H 3962 3784 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Horizontal" H 4050 3750 50  0001 C CNN
F 3 "" H 4050 3750 50  0001 C CNN
	1    4000 3800
	1    0    0    -1  
$EndComp
Text GLabel 1250 1500 0    50   Input ~ 0
spi_data
Text GLabel 1250 2100 0    50   Input ~ 0
spi_clock
Text GLabel 9650 2500 2    50   Input ~ 0
TXD
Text GLabel 9650 1800 2    50   Input ~ 0
RXD
Text GLabel 9650 1600 2    50   Input ~ 0
hall_affect_sensor
Wire Wire Line
	8950 1600 9650 1600
Wire Wire Line
	8950 1800 9650 1800
Wire Wire Line
	8950 2500 9650 2500
$Comp
L pspice:R R1
U 1 1 5D8EB393
P 1800 4400
F 0 "R1" H 1868 4446 50  0000 L CNN
F 1 "10k" H 1868 4355 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 1800 4400 50  0001 C CNN
F 3 "~" H 1800 4400 50  0001 C CNN
	1    1800 4400
	-1   0    0    1   
$EndComp
Wire Wire Line
	1200 4050 1200 4650
Wire Wire Line
	1200 4650 1800 4650
Text GLabel 1500 4200 0    50   Input ~ 0
GND
Wire Wire Line
	1650 4050 1650 4200
Wire Wire Line
	1650 4200 1500 4200
Text GLabel 4350 4250 2    50   Input ~ 0
RXD
Text GLabel 4350 4350 2    50   Input ~ 0
TXD
Text GLabel 4350 4050 2    50   Input ~ 0
vcc
Text GLabel 4350 4150 2    50   Input ~ 0
GND
Wire Wire Line
	4150 4050 4350 4050
Wire Wire Line
	4150 4150 4350 4150
Wire Wire Line
	4150 4250 4350 4250
Wire Wire Line
	4150 4350 4350 4350
Text GLabel 2000 4150 2    50   Input ~ 0
hall_affect_sensor
Wire Wire Line
	2000 4150 1800 4150
Connection ~ 1800 4150
Wire Wire Line
	1200 4050 1050 4050
Connection ~ 1200 4050
Wire Wire Line
	1450 1500 1250 1500
Wire Wire Line
	1250 2100 1450 2100
Text GLabel 2750 5500 0    50   Input ~ 0
spi_data
Text GLabel 2750 5600 0    50   Input ~ 0
spi_clock
$Comp
L Connector:Conn_01x02_Female J1
U 1 1 5D8DDAC3
P 4950 4200
F 0 "J1" H 4842 3875 50  0000 C CNN
F 1 "Conn_01x02_Female" H 4842 3966 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4950 4200 50  0001 C CNN
F 3 "~" H 4950 4200 50  0001 C CNN
	1    4950 4200
	-1   0    0    1   
$EndComp
$Comp
L LED:APA102 D6
U 1 1 5DC8F538
P 6050 5600
F 0 "D6" H 6050 6081 50  0000 C CNN
F 1 "APA102" H 6050 5990 50  0000 C CNN
F 2 "LED_SMD:LED_RGB_5050-6" H 6100 5300 50  0001 L TNN
F 3 "http://www.led-color.com/upload/201506/APA102%20LED.pdf" H 6150 5225 50  0001 L TNN
	1    6050 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 5900 6050 5900
Wire Wire Line
	5450 5300 6050 5300
$Comp
L LED:APA102 D7
U 1 1 5DE3DA7D
P 6650 5600
F 0 "D7" H 6650 6081 50  0000 C CNN
F 1 "APA102" H 6650 5990 50  0000 C CNN
F 2 "LED_SMD:LED_RGB_5050-6" H 6700 5300 50  0001 L TNN
F 3 "http://www.led-color.com/upload/201506/APA102%20LED.pdf" H 6750 5225 50  0001 L TNN
	1    6650 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 5900 6650 5900
Wire Wire Line
	6050 5300 6650 5300
$Comp
L fan-pcb-rescue:PICkit3_header-Connector H1
U 1 1 5DE5E5F1
P 6150 3650
F 0 "H1" H 6083 3775 50  0000 C CNN
F 1 "PICkit3_header" H 6083 3684 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Horizontal" H 6150 3650 50  0001 C CNN
F 3 "" H 6150 3650 50  0001 C CNN
	1    6150 3650
	1    0    0    -1  
$EndComp
Text GLabel 6600 3900 2    50   Input ~ 0
vcc
Wire Wire Line
	6350 3900 6600 3900
Text GLabel 6600 3750 2    50   Input ~ 0
Vpp
Wire Wire Line
	6350 3750 6600 3750
Text GLabel 1250 1300 0    50   Input ~ 0
Vpp
Wire Wire Line
	1250 1300 1450 1300
Wire Wire Line
	6350 4350 6600 4350
Wire Wire Line
	6350 4200 6600 4200
Text GLabel 6600 4350 2    50   Input ~ 0
PGC
Text GLabel 6600 4200 2    50   Input ~ 0
PGD
Wire Wire Line
	6350 4050 6600 4050
Text GLabel 6600 4050 2    50   Input ~ 0
GND
Text GLabel 1250 1700 0    50   Input ~ 0
PGC
Text GLabel 1250 1600 0    50   Input ~ 0
PGD
Wire Wire Line
	1250 1600 1450 1600
Wire Wire Line
	1250 1700 1450 1700
Wire Wire Line
	9650 1300 8950 1300
Wire Wire Line
	9650 1400 8950 1400
$Comp
L Device:C C1
U 1 1 5DEA8FF9
P 8100 3850
F 0 "C1" H 8215 3896 50  0000 L CNN
F 1 ".1uf" H 8215 3805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8138 3700 50  0001 C CNN
F 3 "~" H 8100 3850 50  0001 C CNN
	1    8100 3850
	1    0    0    -1  
$EndComp
Text GLabel 8450 3700 2    50   Input ~ 0
vcc
Text GLabel 8450 4000 2    50   Input ~ 0
GND
Wire Wire Line
	8100 3700 8450 3700
Wire Wire Line
	8100 4000 8450 4000
Text GLabel 1250 2500 0    50   Input ~ 0
vcc
Wire Wire Line
	1250 2500 1450 2500
Text GLabel 1250 2000 0    50   Input ~ 0
GND
Wire Wire Line
	1250 2000 1450 2000
$EndSCHEMATC
