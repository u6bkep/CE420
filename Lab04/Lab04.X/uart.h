/* ************************************************************************** */
/** 
  @Company
    Kettering University

  @File Name
    uart.h

  @Summary
    Defines the parameters used to configure the UART for serial output function

  @Description
    This header file defines the serial communication protocol parameters
    for the PIC32 UART port, and provides the prototypes for the serial
    output functions.
 
  @Author
    Girma Tewolde
  @Last modification
    10/28/2019 @ 3:30 PM
 
 */
/* ************************************************************************** */

#ifndef _UART_H    /* Guard against multiple inclusion */
#define _UART_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include <p32xxxx.h>

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

 
//define UART configuration constants
#define BRATE 1041 //U1BREG setting for ~9600 baud
#define U_ENABLE 0x8008 //enable UART, BREGH=1, 1 stop, no parity
#define U_TXRX 0x1400 //enable RX and TX, clear all flags

void initUART1(void);
void UART1_putchar(uint8_t c);
void UART1_putstr(uint8_t *s);

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _UART_H */

/* *****************************************************************************
 End of File
 */
