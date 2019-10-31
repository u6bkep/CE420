/* ************************************************************************** */
/** 
  @Company
    Kettering University

  @File Name
    TLights.c

  @Summary
    Implements the functions necessary for the traffic light control

  @Description
    
  @Author
    Girma Tewolde
  @Last modification
    10/15/2019 @ 6:24 PM
 */
/* ************************************************************************** */

#include <p32xxxx.h>
#include "TLights.h"

//For testing timer function, toggle RED and GREEN LEDs on one of the light sets
void testTimer(void) {
    enableTLights(); 
    outputTLights(1, RED);
    msDelay(1000);
    outputTLights(1, GREEN);
    msDelay(1000);
}

//initialize the pushbutton switches (configure port direction)
void initButtons(void) {
    //configure the button pins as inputs
	S1_dir = IN;                           //S1
	S2_dir = IN;							//S2
    
}

//read the switches inputs
//Input: the current operating mode of the lights is provided as input parameter
//output: the new operating mode of the traffic lights returned
//make sure you handle key bounce issues with software delays for debouncing
//disable the LEDs (turn off their power) while button is held down  
unsigned char readButtons(unsigned char mode) {
    //the switches are active low
	//check if S2 is pressed ... to enter MODE3 

	if(S2 == 0)
    {
        mode = MODE3;
    }
	
	
	
	
	//check if S1 is pressed to toggle between MODE1 and MODE2
    

	else if(S1 == 0)
    {
        if(mode == MODE1)
            mode = MODE2;
        else
            mode = MODE1;
    }
	
    // disable light and wait for button to be released
	disableTLights();
	while((S1 == 0) || (S2 == 0));
	enableTLights();
    
    return mode;
}

//initialize the traffic lights
//configure the I/O pin directions that control the decoder devices that in turn
//drive the LEDs
//Also configure the I/O pin direction for the LED power pin which is controlled
//by the MOSFET switch
void initTLights(void) {
    //configure decoder pins as outputs
    //Dec1 pins as outputs

	Dec1bit0_dir = OUT;
    Dec1bit1_dir = OUT;
    
    //Dec2 pins as outputs

    Dec2bit0_dir = OUT;
    Dec2bit1_dir = OUT;
    //configure LED enable pin as output
    LEDs_EN_dir = OUT;
	
}

//enable the lights by activating the MOSFET switch (active low signal))
void enableTLights(void) {
    //Enable LEDs ... controlled by active low MOSFET
    LEDs_EN = 0;
	
}

//disable the lights by deactivating the MOSFET switch (active low signal))
void disableTLights(void) {
    //Disable LEDs ... controlled by active low MOSFET
    LEDs_EN = 1;
	
}

//control lights
//lightNum -- specifies which light set to control (1 or 2)
//color -- specifies what color to turn on (RED, YELLOW, GREEN, WHITE)
void outputTLights(unsigned char lightNum, unsigned char color)
{
    if(lightNum == 0)
        disableTLights();
    if (lightNum == 1) {
        //control the light that is controlled by Dec1
        enableTLights();
        Dec1bit0 = color >> 0;
        Dec1bit1 = color >> 1;
    }
    if (lightNum == 2) {
        //control the light that is controlled by Dec2
        enableTLights();
        Dec2bit0 = color >> 0;
        Dec2bit1 = color >> 1;
    }    
}

//runs the lights in operating mode MODE1
void mode1TLights(void) {

    enableTLights();
    outputTLights(1, GREEN);
    outputTLights(2,RED);
    msDelay(4000);
    outputTLights(1,YELLOW);
    msDelay(1000);
    outputTLights(1,RED);
    outputTLights(2,GREEN);
    msDelay(4000);
    outputTLights(2,YELLOW);
    msDelay(1000);
}

//runs the lights in operating mode MODE2
void mode2TLights(void) {

    enableTLights();
    outputTLights(1,RED);
    outputTLights(2,RED);
    msDelay(500);
    
    
    outputTLights(0,RED);
    msDelay(500);
    
    
    enableTLights();
    outputTLights(1,RED);
    outputTLights(2,RED);
    msDelay(500);
    
    
    outputTLights(0,RED);
    
    msDelay(500);
    
}

//runs the lights in operating mode MODE3
void mode3TLights(void) 
{
    
    mode1TLights();
    outputTLights(1,RED);
    outputTLights(2,RED);
    msDelay(1000);
    multiplexColors(RED, WHITE, RED, WHITE, 5000);
    for(int i = 0; i < 6; i++)
    {
        outputTLights(1,RED);
        outputTLights(2,RED);
        msDelay(500);
        multiplexColors(RED, WHITE, RED, WHITE, 500);
    }
    
}

//generate time delay for the specified amount of milliseconds
void msDelay(unsigned int ms) {
    // Convert ms microseconds into how many clock ticks it will take
    unsigned int ticks = ms * (ONE_SEC_TICKS/1000);
//    ms *= TIMER_FREQ / 1000000 ; // Core Timer updates every 2 ticks

    _CP0_SET_COUNT(0); // Set Core Timer count to 0

    while (ticks > _CP0_GET_COUNT()); // Wait until Core Timer count reaches the number we calculated earlier
}

//run two colors on the same light for a given time
void multiplexColors(unsigned char color1_1, unsigned char color1_2,
                     unsigned char color2_1, unsigned char color2_2, unsigned int ms)
{
    //ensure LEDs are enabled
    enableTLights();
    
    // Convert ms microseconds into how many clock ticks it will take
    unsigned int ticks = ms * (ONE_SEC_TICKS/1000);

    _CP0_SET_COUNT(0); // Set Core Timer count to 0

    // Wait until Core Timer count reaches the number we calculated earlier
    while (ticks > _CP0_GET_COUNT()) 
    {
        outputTLights(1, color1_1);
        outputTLights(1, color1_2);
        outputTLights(2, color2_1);
        outputTLights(2, color2_2);
    }
    
    
}