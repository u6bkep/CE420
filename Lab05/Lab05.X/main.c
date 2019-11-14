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

#define PWM_PWR(x) (x==1? (OC4CONSET = 0x8000) : (OC4CONCLR = 0x8000))

void init_Timer4(void) 
{    
    T4CON = 0x0;           // Stop the timer and clear the control register,
    T4CON = 0b01111000;    // prescaler at 1:256,internal clock source, 32bit mode
    TMR4 = 0x0;            // Clear the timer register 
    PR4 = 0x2625a;         // Load the period register 
    IPC5SET = 0x0000000D;  // Set priority level = 3, subpriority level = 1
    IFS0CLR = 0x00100000;  // Clear the timer interrupt status flag 
    IEC0SET = 0x00100000;  // Enable timer interrupts
    T4CONSET = 0x8000;     // Start the timer
    
}

void init_PWM(void)
{
    OC4CON = 0x0000;                         // Turn off the OC1 when performing the setup
    OC4R = 0x0F00;                           // Initialize primary Compare register
    OC4RS = 0x0F00;                          // Initialize secondary Compare register
    OC4CON = 0x0006;                         // Configure for PWM mode without Fault pin
                                             // enabled
    PR2 = 0xffff;                            // Set period
                                             // Configure Timer2 interrupt. Note that in PWM mode, the 
                                             // corresponding source timer interrupt flag is asserted.
                                             // OC interrupt is not generated in PWM mode.
//    IFS0CLR = 0x00000100;                    // Clear the T2 interrupt flag
//    IEC0SET = 0x00000100;                    // Enable T2 interrupt
//    IPC2SET = 0x0000001C;                    // Set T2 interrupt priority to 7

    T2CONSET = 0x8000;                       // Enable Timer2
//    OC4CONSET = 0x8000;                      // Enable OC1
}

void send_PWM(signed int speed)
{
     /************************************
     * this function takes a speed value
     * in percentage from -100 to 100
     * and sets the pwm module accordingly
     ************************************/
   
    OC1RS = ((speed * 4) + 3000);
    //CCP4RB = ((speed * 4) + 3000);
    //CCP4CON1Lbits.CCPON = 1;   //Turn on MCCP module
}

//Timer4 interrupt handler 
void __ISR(_TIMER_5_VECTOR, IPL5SOFT) T5ISR(void) 
{
    mT5ClearIntFlag();
    
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
            segPower = ! segPower;
            PWM_PWR(segPower);
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
	init_Timer4();
    init_PWM();
    
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
                    segPower = 1;
                    PWM_PWR(0);
                }
                break;
                        
        }
    }
	
}