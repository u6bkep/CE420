/* 
 * File:   keypad.h
 * Author: ben
 *
 * Created on October 31, 2019, 9:30 AM
 */
#include <p32xxxx.h>

#ifndef KEYPAD_H
#define	KEYPAD_H

#ifdef	__cplusplus
extern "C" {
#endif

//CPU timings
#define CPU_FREQ 80000000
#define ONE_SEC_TICK (CPU_FREQ/2)
    
//port configuration values for input & output    
#define IN      1       
#define OUT     0
    
#define column1 PORTBbits.RB11
#define column2 PORTBbits.RB3
#define column3 PORTBbits.RB15
    
#define row1 PORTBbits.RB5
#define row2 PORTBbits.RB13
#define row3 PORTBbits.RB1
#define row4 PORTBbits.RB9

//function prototypes
void initKeypad(void);
char readKey(void);
void msDelay(unsigned int ms);
void Debounce (void);
    


#ifdef	__cplusplus
}
#endif

#endif	/* KEYPAD_H */

