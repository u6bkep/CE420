#include "sonar.h"



// returns the distance detected by the sonar device in centimeters
float sonarDistance(void)
{
    _CP0_SET_COUNT(0);
    unsigned int initialTime = _CP0_GET_COUNT();
    
    float returnValue = 0;
    lastSonarResponceTime =  secondCapture - firstCapture;
    if(lastSonarResponceTime > 0x173180);
    else
        returnValue = (lastSonarResponceTime ) / 40.0f / 58.0f; // TODO: finish writing math to turn ticks into microseconds
    
    runtime = _CP0_GET_COUNT() -  initialTime;
    
    return returnValue;
}



void initSonar()
{
    initOC5();
    //initIC4();
    running = TRUE;
}

void initOC5()
{
    // setup OC5 with timer 2
    OC5CON = 0x0000;                      // Turn off OC1 while doing setup. 
    OC5CON = 0x0004;                      // Configure for single pulse mode 
    OC5R = 0x0;                           // Initialize primary Compare Register 
    OC5RS = 0x190;                       // Initialize secondary Compare Register 
    
    mOC5ClearIntFlag();                 // Clear the OC1 interrupt flag
    mOC5IntEnable(1);                   // Enable OC1 interrupt
                                        // Set OC1 interrupt priority to 7,
    mOC5SetIntPriority(7);              // the highest level
    mOC5SetIntSubPriority(3);           // Set Subpriority to 3, maximum
    
    OC5CONSET = 0x8000;                   // Enable OC1
    
    
    T2CON = 0x0000;                       // Configure Timer2 for a prescaler of 1:1
    
    PR2 = 0x190;                         // Set period (PR2 is now 16-bits wide) 
                                          // set period to 10 us

                                          // configure int 

    T2CONSET = 0x8000;                    // Enable Timer 2
}

void initIC4(void)
{
 //settup input compare
    
    IC4CON = 0b0000001100100110;          // disable IC4 and configure 
  //IC4CON = 0b0000001000100001;
                                          // Simple Capture Event mode ? every edge, specified edge first and every edge thereafter
                                          // Input capture buffer is not empty
                                          // First Capture Edge is rising
                                          // timer3 is selected
            
    T2CON = 0x0008;                       // configure timer2 for 1:1 prescaler
                                          // 32 bit mode
                        
    PR2 = 0xffffffff;
    
    mIC4ClearIntFlag();                   // clear IC4 interrupt
    mIC4IntEnable(1);                     // enable IC4 interrupt
    mIC4SetIntPriority(7);                // Set IC4 interrupt priority to 7,
    mIC4SetIntSubPriority(3);             // Set Subpriority to 3, maximum
    
    IC4CONSET = 0x8000;
    T2CONSET = 0x8000;   
}

// Example code for Output Compare 1 ISR:

void __ISR(_OUTPUT_COMPARE_5_VECTOR, ipl7SOFT) OC5_IntHandler (void)
{
    initIC4();
    mOC5ClearIntFlag();                 // Clear the OC5 interrupt flag
}

void __ISR(_INPUT_CAPTURE_4_VECTOR, ipl7SOFT) IC4_IntHandler (void)
{
    

    firstCapture = IC4BUF;
    secondCapture = IC4BUF;
    initOC5();
    mIC4ClearIntFlag();                 // Clear the OC5 interrupt flag
    if(running)
        triggerPulse();
    
    
}

