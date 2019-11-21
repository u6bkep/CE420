/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Kettering University

  @File Name
    UART.h

  @Summary
    Header file that defines the PIC32 UART interface functions.

  @Description
    
  @Author
    Girma Tewolde
  @Last modification
    11/11/2019 @ 3:30 PM
 */
/* ************************************************************************** */

#ifndef _UART_H    /* Guard against multiple inclusion */
#define _UART_H

//define configuration settings for UART
#define BRATE 1041 //U1BREG setting for ~9600 baud
#define U_ENABLE 0x8008 //enable UART1, BREGH=1, 1 stop, no parity
#define U_TXRX 0x1400

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

#include <p32xxxx.h>
#include <stdint.h>

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

//UART1 is connected to the chipKIT's USB-serial virtual COM port    
void initUART1(void);
uint8_t UART1_getchar(void);
void UART1_putchar(uint8_t c);
void UART1_putstr(uint8_t s[]);

//Bluetooth module is interfaced via UART2
void initUART2(void);
uint8_t UART2_getchar(void);
void UART2_putchar(uint8_t c);
void UART2_putstr(uint8_t s[]);


    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
