// seven_seg.c 
//this is an incomplete program code for the seven segment device driver code
#include "seven_seg.h"   //assuming you named your header file this way

//Example -- initialize Timer1 to trigger interrupts every 1ms 
void init_Timer1(void) { 
    TMR1 = 0x0000; //clear timer register
    PR1 = 40000000; //set the period
    
    //init interrupts 
    mT1SetIntPriority(5);   //group priority set to 5
    mT1ClearIntFlag(); 
    // configure for multi-vectored mode and enable system interrupt 
    INTEnableSystemMultiVectoredInt();
    mT1IntEnable(1);    //enable T1 interrupts
    T1CON = 0x8038;   //enable timer, set prescaler to 1:8 
}

void set7Seg(char numbers[4])
{
    segValues[0] = numbers[0];
    segValues[1] = numbers[1];
    segValues[2] = numbers[2];
    segValues[3] = numbers[3];
    
}

//Timer1 interrupt handler 
//it is used to refresh the 7-segment displays every 1ms 
void __ISR(_TIMER_1_VECTOR, IPL5SOFT) T1ISR(void) 
{
    mT1ClearIntFlag();
   
    
    PORTEbits = segLookup[segValues[segState]];
    //PORTECLR = ~ segLookup[segValues[segState]];
    
    switch(segState)
    {
        case 0:
            PORTDbits.RD2 = 0;
            PORTDbits.RD9 = 0;
            break;
        case 1:
            PORTDbits.RD2 = 1;
            PORTDbits.RD9 = 0;
            break;
        case 2:
            PORTDbits.RD2 = 0;
            PORTDbits.RD9 = 1;
            break;
        case 3:
            PORTDbits.RD2 = 1;
            PORTDbits.RD9 = 1;
            break;
    }
    
    segState++;
    if(segState > 3)
    {
        segState = 0;
    }
}