/* ************************************************************************** */
/** Provide complete documentation for your program

/* ************************************************************************** */


//suppress plib warnings
#define _SUPPRESS_PLIB_WARNING
#define _DISABLE_OPENADC10_CONFIGPORT_WARNING

#include <p32xxxx.h>
#include <plib.h>
#include "sonar.h"
#include "SH1106.h"
#include "BT_UART.h"

// configuration bit settings, Fcy=80MHz, Fpb=40MHz
#pragma config POSCMOD=XT, FNOSC=PRIPLL
#pragma config FPLLIDIV=DIV_2, FPLLMUL=MUL_20, FPLLODIV=DIV_1 
#pragma config FPBDIV=DIV_2, FWDTEN=OFF, CP=OFF, BWP=OFF

void main(void){
    char res[20]; 
     
    initSPI2();         //initialize SPI2 for OLED
    initUART2();		//initialize UART2 for Bluetooth communication
	//send message to the Bluetooth user
    UART2_putstr("Connection Successful\n");	
    UART2_putstr("Send command to choose operating mode\n");
	
	//initialize OLED and print sensor measurments
    SH1106_begin();
    SH1106_clear(oled_buf);
	SH1106_string(0, 10, "Ultrasonic Sensor ", 15, 0, oled_buf);
    SH1106_string(0, 30, "Dist:       ", 15, 0, oled_buf);
    distance = sonarDistance();    //measure distance
    sprintf(res, "%5.2f cm", distance);     
    SH1106_string(60, 30, res, 15, 0, oled_buf);
    SH1106_display(oled_buf);		//display measurement on OLED
	
	//modify this main program to make the program run indefinitely 
	//while handling the different operating modes requested by the user


	
}
