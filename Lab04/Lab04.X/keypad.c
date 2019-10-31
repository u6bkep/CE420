
#include "keypad.h"

void initKeypad(void)
{
    DDPCONbits.JTAGEN = 0; // disable the JTAG port
    AD1PCFGSET = 0xffffffff;
    
    //configure columns as outputs
    TRISBbits.TRISB11 = OUT;
    TRISBbits.TRISB3 = OUT;
    TRISBbits.TRISB15 = OUT;
    
    //configure rows as inputs
    TRISBbits.TRISB5 = IN;
    TRISBbits.TRISB13 = IN;
    TRISBbits.TRISB1 = IN;
    TRISBbits.TRISB9 = IN;
    
    // set outputs to default value of on
    column1 = 1;
    column2 = 1;
    column3 = 1;
}

char readKey(void)
{
    char returnVal = NULL;
    
    column1 = 0;
    if(row1 == 0)
        returnVal = '1';
    else if(row2 == 0)
        returnVal = '2';
    else if(row3 == 0)
        returnVal = '3';
    
    column2 = 0;
    if(row1 == 0)
        returnVal = '1';
    else if(row2 == 0)
        returnVal = '2';
    else if(row3 == 0)
        returnVal = '3';
    
    column3 = 0;
    if(row1 == 0)
        returnVal = '1';
    else if(row2 == 0)
        returnVal = '2';
    else if(row3 == 0)
        returnVal = '3';
    
    
    
}