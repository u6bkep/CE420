
#include "keypad.h"

void initKeypad(void)
{
    DDPCONbits.JTAGEN = 0; // disable the JTAG port
    AD1PCFGSET = 0xFFFF; //set all PORTB as digital
    
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
    
    //check first column
    column1 = 0;
    if(row1 == 0)
    {
        msDelay(12);
        Debounce();
        returnVal = '1';   
    }
    else if(row2 == 0)
    {
        msDelay(12);
        Debounce();
        returnVal = '4';
    }
    else if(row3 == 0)
    {
        msDelay(12);
        Debounce();
        returnVal = '7';
    }
    else if(row4 == 0)
    {
        msDelay(12);
        Debounce();
        returnVal = '*';
    }
    //reset column
    column1 = 1;
        
    //check second column
    column2 = 0;
    if(row1 == 0)
    {
        msDelay(12);
        Debounce();
        returnVal = '2';
    }
    else if(row2 == 0)
    {
        msDelay(12);
        Debounce();
        returnVal = '5';
    }
    else if(row3 == 0)
    {
        msDelay(12);
        Debounce();
        returnVal = '8';
    }
    else if(row4 == 0)
    {
        msDelay(12);
        Debounce();
        returnVal = '0';
    }
    //reset column
    column2 = 1;
    
    ////check third column
    column3 = 0;
    if(row1 == 0)
    {
        msDelay(12);
        Debounce();
        returnVal = '3';
    }
    else if(row2 == 0)
    {
        msDelay(12);
        Debounce();
        returnVal = '6';
    }
    else if(row3 == 0)
    {
        msDelay(12);
        Debounce();
        returnVal = '9';
    }
    else if(row4 == 0)
    {
        msDelay(12);
        Debounce();
        returnVal = '#';
    }
    //reset column
    column3 = 1;
    msDelay(12);
    returnVal = '\0';
    
    return returnVal;
}

//setup the time delay
void msDelay(unsinged int ms)
{
    //figures out how many clock cycles it will go through in ms miliseconds
    unsigned int tick = ms * (ONE_SEC_TICK / 1000);
     
    //set the core timer count to 0
    _CP0_SET_COUNT(0);
    
    //waits until the core timer reaches the target value
    while(tick > _CP0_SET_COUNT());
}

void Debounce (void)
{
    column1 = 0;
    column2 = 0;
    column3 = 0;
    
    while ((row1 == 0) || (row2 == 0) || (row3 == 0) || (row4 == 0))
{
    //do nothing
}
    //reset all columns
    column1 = 1;
    column2 = 1;
    column3 = 1;
}