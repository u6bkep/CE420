/*
 * File:   main.c
 * Author: ben
 *
 * Created on December 17, 2019, 5:05 PM
 */


#include <p24Fxxxx.h>
#include "mcc_generated_files/mcc.h"

#include <libpic30.h>
#define    FCY    2000000UL    // Instruction cycle frequency, Hz - required for __delayXXX() to work
#define __delay_ms(d) \
  { __delay32( (unsigned long) (((unsigned long long) d)*(FCY)/1000ULL)); }

void send_PWM(signed int speed)
{
     /************************************
     * this function takes a speed value
     * in percentage from -100 to 100
     * and sets the pwm module accordingly
     ************************************/
    SCCP4_COMPARE_DualCompareValueSet(0,((speed * 4) + 3000));
    //CCP4RB = ((speed * 4) + 3000);
    //CCP4CON1Lbits.CCPON = 1;   //Turn on MCCP module
}

int main(void) 
{
    SYSTEM_Initialize();
    SCCP4_COMPARE_Start();
    
    send_PWM(150);
    __delay_ms(5000);
    send_PWM(-150);
    __delay_ms(5000);

    
    //send_PWM(0);
    //__delay_ms(5000);
    send_PWM(-134); //2644
    //SCCP4_COMPARE_DualCompareValueSet(0,2639);
    
    
    //SCCP4_COMPARE_Stop();
    
    while(1)
    {
        
    }
    
    return 0;
}
