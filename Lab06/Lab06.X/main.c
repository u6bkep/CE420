/* ************************************************************************** */
/** Provide complete documentation for your program

/* ************************************************************************** */


//suppress plib warnings
#define _SUPPRESS_PLIB_WARNING
#define _DISABLE_OPENADC10_CONFIGPORT_WARNING

#define CPU_FREQ 80000000
#define ONE_SEC_TICK (CPU_FREQ/2)

#include <p32xxxx.h>
#include <plib.h>
#include "sonar.h"
#include "SH1106.h"
//#include "BT_UART.h"

// configuration bit settings, Fcy=80MHz, Fpb=40MHz
#pragma config POSCMOD=XT, FNOSC=PRIPLL
#pragma config FPLLIDIV=DIV_2, FPLLMUL=MUL_20, FPLLODIV=DIV_1 
#pragma config FPBDIV=DIV_2, FWDTEN=OFF, CP=OFF, BWP=OFF

//generate time delay for the specified amount of milliseconds
void msDelay(unsigned int ms) 
{
    // Convert ms microseconds into how many clock ticks it will take
    unsigned int ticks = ms * ( ONE_SEC_TICK /1000);
//    ms *= TIMER_FREQ / 1000000 ; // Core Timer updates every 2 ticks

    _CP0_SET_COUNT(0); // Set Core Timer count to 0

    while (ticks > _CP0_GET_COUNT()); // Wait until Core Timer count reaches the number we calculated earlier
}


void main(void){
    char res[20]; 
     
    initSPI2();         //initialize SPI2 for OLED
    initUART2();		//initialize UART2 for Bluetooth communication
    initSonar();
	//send message to the Bluetooth user
    UART2_putstr("Connection Successful\n");	
    UART2_putstr("Send command to choose operating mode\n");
//    UART2_putstr("renaming bluetooth device...\n");
//    UART2_putstr("AT+NAMECHIP_KIT8");
	
	//initialize OLED and print sensor measurments
//    SH1106_begin();
//    SH1106_clear(oled_buf);
//	SH1106_string(0, 10, "Ultrasonic Sensor ", 15, 0, oled_buf);
//    SH1106_string(0, 30, "Dist:       ", 15, 0, oled_buf);
//    float distance = sonarDistance();    //measure distance
//    sprintf(res, "%5.2f cm", distance);     
//    SH1106_string(60, 30, res, 15, 0, oled_buf);
//    SH1106_display(oled_buf);		//display measurement on OLED
    
    while(1)
    {
        triggerPulse();
        msDelay(1);
//        float distance = sonarDistance();    //measure distance
//        sprintf(res, "%5.2f cm %d` ticks", distance, lastSonarResponceTime);
//        UART2_putstr(res);
//        UART2_putchar('\n');
    }
	
//    mIC5CaptureReady()
//    mIC5ReadCapture();
    
	//modify this main program to make the program run indefinitely 
	//while handling the different operating modes requested by the user


	
}
