//provide complete documentation

#include <p32xxxx.h>
#include "keypad.h"
#include "uart.h"
#include "seven_seg.h"

// configuration bit settings, Fcy=80MHz, Fpb=40MHz
#pragma config POSCMOD=XT, FNOSC=PRIPLL
#pragma config FPLLIDIV=DIV_2, FPLLMUL=MUL_20, FPLLODIV=DIV_1
#pragma config FPBDIV=DIV_2, FWDTEN=OFF, CP=OFF, BWP=OFF

int main(void) {
    DDPCONbits.JTAGEN = 0;
    //declare any local variables you may need
    unsigned char number;
    
    initKeypad();   
    initUART1();
    init_Timer1();
	
    UART1_putstr("Hello, please enter keys on the keypad:");
    
	//add your code here
	
    //infinite loop
    while (1)
    {
        number = readKey();
        if(number != '\0')
        {
            UART1_putchar(number);
            
            if(number == '#' || number == '*')
                number = 0;
            
            segValues[3] = segValues[2];
            segValues[2] = segValues[1];
            segValues[1] = segValues[0];
            segValues[0] =  number;
        }
    }
	
}