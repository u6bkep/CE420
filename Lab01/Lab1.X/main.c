#include <p24Fxxxx.h>
int delay;
int main()
{
    
    TRISA = 0;
    PORTA = 0x00;
    while(1) {
        PORTA ++;
        delay = 100;
        while(delay--);
    }
}

