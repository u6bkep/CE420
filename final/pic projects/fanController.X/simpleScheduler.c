
#include <p24Fxxxx.h>
#include "simpleScheduler.h"
#include "mcc_generated_files/tmr1.h"


void (*secondCallbackPntr)(void);

void TMR1_CallBack(void)
{
    secondCallbackPntr();
}


void starScheduler(void (*secondCallback) () )
{
    secondCallbackPntr = secondCallback;
    
}
    
