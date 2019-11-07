/* ************************************************************************** */
/** 
  @Company
    Kettering University

  @File Name
    uart.c

  @Summary
    Implements the functions that support the UART serial output communication

  @Description
     
  @Author
    Girma Tewolde
  @Last modification
    10/28/2019 @ 3:30 PM
 
 */
/* ************************************************************************** */

#include "uart.h"

void initUART1(void)
{
    U1BRG = BRATE; //initialize the baud rate generator
    U1MODE = U_ENABLE; //initialize the UART module
    U1STA = U_TXRX; //enable TX & RX
}

void UART1_putchar(uint8_t c) { //send a character to UART1
    while (U1STAbits.UTXBF == 1); //wait until transmitter buffer becomes empty
    U1TXREG = c;    //write character to TX data register
}
void UART1_putstr(uint8_t s[]) { //send a null-terminated string to UART1
    while (s[0] != 0) {
        UART1_putchar(s[0]);
        s++;
    }
}

/* *****************************************************************************
 End of File
 */
