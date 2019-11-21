/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Kettering University

  @File Name
    UART.c

  @Summary
    Header file that defines the PIC32 UART interface functions.

  @Description
    
  @Author
    Girma Tewolde
  @Last modification
    11/11/2019 @ 3:30 PM
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "UART.h"


void initUART1(void)
{
    U1BRG = BRATE;
    U1MODE = U_ENABLE;
    U1STA = U_TXRX;
}

void UART1_putchar(uint8_t c){
    while (U1STAbits.UTXBF == 1)
    {} //wait until transmitter buffer becomes empty 
    U1TXREG = c; //write character to tx data register
}
void UART1_putstr(uint8_t s[]) { //send a null-terminated string to UART1 
    while (s[0] != 0){
        UART1_putchar(s[0]);
        s++; 
    }
}

uint8_t UART1_getchar(void){
    if(U1STAbits.URXDA == 1)
        return U1RXREG;
    else 
        return 0;
}

void initUART2(void)
{
    U2BRG = BRATE;
    U2MODE = U_ENABLE;
    U2STA = U_TXRX;
}

void UART2_putchar(uint8_t c){
    while (U2STAbits.UTXBF == 1)
    {} //wait until transmitter buffer becomes empty 
    U2TXREG = c; //write character to tx data register
}
void UART2_putstr(uint8_t s[]) { //send a null-terminated string to UART1 
    while (s[0] != 0){
        UART2_putchar(s[0]);
        s++; 
    }
}

uint8_t UART2_getchar(void){
    if(U2STAbits.URXDA == 1)
        return U2RXREG;
    else 
        return 0;
}



/* *****************************************************************************
 End of File
 */
