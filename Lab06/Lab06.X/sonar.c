#include "sonar.h"

// returns the distance detected by the sonar device in centimeters
float sonarDistance(void)
{
    if(lastSonarResponceTime > 0x7A12)
        return 0;
    else
        return (lastSonarResponceTime ) * 1.4 / 58; // TODO: finish writing math to turn ticks into microseconds
}

void initSonar()
{
    // setup OC5 with timer 2
    T2CON = 0x0000;                       // Configure Timer2 for a prescaler of 1:1
    OC5CON = 0x0000;                      // Turn off OC1 while doing setup. 
    OC5CON = 0x0004;                      // Configure for single pulse mode 
    OC5R = 0x0;                        // Initialize primary Compare Register 
    OC5RS = 0x190;                       // Initialize secondary Compare Register 
    PR2 = 0x190;                         // Set period (PR2 is now 16-bits wide) 
                                          // set period to 10 us

                                          // configure int 
    
    //IFS0CLR = 0b100000;                 // Clear the OC1 interrupt flag 
    mOC5ClearIntFlag();
    //IFS0SET = 0x00000040;               // Enable OC1 interrupt 
    mOC5IntEnable(1);
    //IPC1SET = 0x001C0000;                 // Set OC1 interrupt priority to 7,
    mOC5SetIntPriority(7);                // the highest level
    //IPC1SET = 0x00030000;                 // Set Subpriority to 3, maximum
    mOC5SetIntSubPriority(3);

    T2CONSET = 0x8000;                    // Enable Timer 2
    OC5CONSET = 0x8000;                   // Enable OC1
    
    
    //settup input compare
    
//    IC4CON = 0b0000001000100110;          // disable IC4 and configure 
//                                          // Simple Capture Event mode ? every edge, specified edge first and every edge thereafter
//                                          // Input capture buffer is not empty
//                                          // First Capture Edge is rising
//                                          // timer3 is selected
//            
//    T3CON = 0x0050;                       // configure timer3 for 1:32 prescaler
//                                          // sonar should give values 
//                                          // between 0xBB.8 and 0xB98C
//                                          // values lager than 0x7A12 can be ignored
//            
//    mIC4ClearIntFlag();                   // clear IC4 interrupt
//    mIC4IntEnable(1);                     // enable IC4 interrupt
//    mIC4SetIntPriority(7);                // Set IC4 interrupt priority to 7,
//    mIC4SetIntSubPriority(3);             // Set Subpriority to 3, maximum
}

// Example code for Output Compare 1 ISR:

void __ISR(_OUTPUT_COMPARE_5_VECTOR, ipl7SOFT) OC5_IntHandler (void)
{
    mOC5ClearIntFlag();                 // Clear the OC5 interrupt flag
}

//void __ISR(_INPUT_CAPTURE_4_VECTOR, ipl7SOFT) IC4_IntHandler (void)
//{
//    mIC4ClearIntFlag();                 // Clear the OC5 interrupt flag
//
//    int firstCapture = IC4BUF;
//    int secondCapture = IC4BUF;
//    
//    lastSonarResponceTime = firstCapture - secondCapture;
//}

void triggerPulse(void)
{
    OC5CONSET = 0x8000;
}