//provide complete documentation

#include <p32xxxx.h>
#include "keypad.h"
#include "uart.h"
#include "seven_seg.h"

// configuration bit settings, Fcy=80MHz, Fpb=40MHz
#pragma config POSCMOD=XT, FNOSC=PRIPLL
#pragma config FPLLIDIV=DIV_2, FPLLMUL=MUL_20, FPLLODIV=DIV_1
#pragma config FPBDIV=DIV_2, FWDTEN=OFF, CP=OFF, BWP=OFF

volatile int minutes;
volatile int seconds;
volatile int state = 0;

void init_Timer2(void) { 
//    TMR2 = 0x0000; //clear timer register
//    PR2 = 400000; //set the period
//    
//    //init interrupts 
//    mT2SetIntPriority(5);   //group priority set to 5
//    mT2ClearIntFlag(); 
//    // configure for multi-vectored mode and enable system interrupt 
//    //INTEnableSystemMultiVectoredInt();
//    mT2IntEnable(1);    //enable T1 interrupts
//    T2CON = 0x8038;   //enable timer, set prescaler to 1:8 
    
    T2CON = 0x0;           // Stop the timer and clear the control register,
    T2CON = 0b01111000;    // prescaler at 1:256,internal clock source, 32bit mode
    TMR2 = 0x0;            // Clear the timer register 
    PR2 = 0x2625a;      // Load the period register 
    IPC3SET = 0x0000000D;  // Set priority level = 3, subpriority level = 1
    IFS0CLR = 0x00001000;  // Clear the timer interrupt status flag 
    IEC0SET = 0x00001000;  // Enable timer interrupts
    T2CONSET = 0x8000;     // Start the timer
}

//Timer2 interrupt handler 
void __ISR(_TIMER_3_VECTOR, IPL5SOFT) T2ISR(void) 
{
    mT3ClearIntFlag();
    
    switch(state)
    {
        case 0:

            break;
        case 1:

            if(seconds == 0)
            {
                if(minutes == 0)
                {
                    state = 2;

                }
                else
                {
                    minutes--;

                    //new values for the minute display segments
                    segValues[0] = minutes / 10;
                    segValues[1] = minutes % 10;

                    //start seconds on 60 for end of minute
                    seconds = 60;
                    //updates the vlaues for the second display segments
                    segValues[2] = seconds / 10;
                    segValues[3] = seconds % 10;
                }
            }
            else
            {
                seconds--;

                //new values for the second display segments
                segValues[2] = seconds / 10;
                segValues[3] = seconds % 10;
            }
            break;
            
        case 2:
            segPower = ~segPower;
            break;
    }



    
    
}

int main(void) {
    DDPCONbits.JTAGEN = 0;
    //declare any local variables you may need
    unsigned char number;
    
    initKeypad();   
    initUART1();
    init7Seg();
	init_Timer2();
    
    UART1_putstr("Hello, please enter keys on the keypad:");
    
	//add your code here
	
    //infinite loop
    while (1)
    {
        number = readKey();
        if(number != '\0')
        switch(state)
        {
            case 0:
                
                if(number == '*')
                        break;
                
                else if(number == '#')
                {
                    state = 1;
                }
                else
                {
                    UART1_putchar(number);

                    segValues[0] = segValues[1];
                    segValues[1] = segValues[2];
                    segValues[2] = segValues[3];
                    segValues[3] =  number -0x30;
                    minutes = (segValues[0] * 10) + segValues[1];
                    seconds = (segValues[2] * 10) + segValues[3];
                }
                break;
            case 1:
                if(number == '#')
                {
                    state = 0;
                }
            case 2:
                if(number == '#')
                {
                    state = 0;
                }
                break;
                        
        }
    }
	
}