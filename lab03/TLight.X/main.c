/* ************************************************************************** */
/** 
//Provide complete documentation ....


 */
/* ************************************************************************** */

#include <p32xxxx.h>
#include "TLights.h"

// configuration bit settings, Fcy=80MHz, Fpb=40MHz
#pragma config POSCMOD=XT, FNOSC=PRIPLL
#pragma config FPLLIDIV=DIV_2, FPLLMUL=MUL_20, FPLLODIV=DIV_1
#pragma config FPBDIV=DIV_2, FWDTEN=OFF, CP=OFF, BWP=OFF


//global variable
unsigned char mode = MODE1;    //system operating mode initialized to MODE1   

int main(void) {
    unsigned char i;
    unsigned char new_mode;
    initTLights();
    initButtons();
    
//    //If you want to test the timer you can uncomment the following while loop
//    while(1) {
//        testTimer();
//    }
//

    mode = MODE1;
    
	//implement an infinite while loop that reads the input buttons and sets the operating mode
	//of the traffic light based on the inputs
    
    while (1) 
    {
        mode = readButtons(mode);
        
        switch(mode)
        {
            case MODE1:
                mode1TLights();
                break;
            case MODE2:
                mode2TLights();
                break;
            case MODE3:
                mode3TLights();
                mode = MODE1;
                break;
        }
    }
    
    /*
    //test pattern 1
    while(1)
    {
        outputTLights(1,RED);
        msDelay(500);
        outputTLights(1,YELLOW);
        msDelay(500);
        outputTLights(1,GREEN);
        msDelay(500);
        outputTLights(1,WHITE);
        msDelay(500);
        outputTLights(2,RED);
        msDelay(500);
        outputTLights(2,YELLOW);
        msDelay(500);
        outputTLights(2,GREEN);
        msDelay(500);
        outputTLights(2,WHITE);
        msDelay(500);
    }*/
    /*
     //test pattern 2
    while(1)
    {
        multiplexColors(RED, YELLOW, GREEN, WHITE, 1000);
        multiplexColors(GREEN, WHITE, RED, YELLOW, 1000);
    }*/
}

