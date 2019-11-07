// seven_seg.c 
//this is an incomplete program code for the seven segment device driver code
#include "seven_seg.h"   //assuming you named your header file this way

//Example -- initialize Timer1 to trigger interrupts every 1ms 
void init_Timer1(void) { 
TMR1 = 0x0000; //clear timer register
PR1 = xxxx; //set the period
//init interrupts 
mT1SetIntPriority(5);   //group priority set to 5
mT1ClearIntFlag(); 
// configure for multi-vectored mode and enable system interrupt 
INTEnableSystemMultiVectoredInt();
mT1IntEnable(1);    //enable T1 interrupts
T1CON = xxxx;   //enable timer, set prescaler to 1:8 
}
//Timer1 interrupt handler 
//it is used to refresh the 7-segment displays every 1ms 
void __ISR(_TIMER_1_VECTOR, IPL5SOFT) T1ISR(void) 
{
mT1ClearIntFlag();
}