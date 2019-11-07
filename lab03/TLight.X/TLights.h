/* ************************************************************************** */
/** 
  @Company
    Kettering University

  @File Name
    TLights.h

  @Summary
    Defines the I/O pins and function prototypes for the traffic light control

  @Description
    This header file defines the I/O pins used by the traffic light control
    circuit, and provides the function prototypes.
  @Author
    Girma Tewolde
  @Last modification
    10/15/2019 @ 6:24 PM
 */
/* ************************************************************************** */

#ifndef _TLIGHTS__H    /* Guard against multiple inclusion */
#define _TLIGHTS_H

#include <p32xxxx.h>

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

#define CPU_FREQ    80000000
#define ONE_SEC_TICKS (CPU_FREQ/2)
    
    

//port configuration values for input & output    
#define IN      1       
#define OUT     0
    
//definition of pins for pushbutton switches
#define S1      PORTDbits.RD8   //pin 2 on chipKIT UNO32/uc32 
#define S1_dir  TRISDbits.TRISD8      
#define S2      PORTDbits.RD0   //pin 3 on chipKIT UNO32/uc32 
#define S2_dir  TRISDbits.TRISD0
    
#define LEDs_EN     PORTDbits.RD4  //used to enable the traffic light LEDs
#define LEDs_EN_dir TRISDbits.TRISD4
    
//2-to-4 decoder inputs to select from Y0, Y1, Y2, Y3 (active low)
#define Dec1bit0     PORTDbits.RD2
#define Dec1bit0_dir TRISDbits.TRISD2       
#define Dec1bit1     PORTDbits.RD9
#define Dec1bit1_dir TRISDbits.TRISD9

//2-to-4 decoder inputs to select from Z0, Z1, Z2, Z3 (active low)
#define Dec2bit0     PORTFbits.RF1
#define Dec2bit0_dir TRISFbits.TRISF1
#define Dec2bit1     PORTDbits.RD1
#define Dec2bit1_dir TRISDbits.TRISD1    

//define the four light colors
#define RED     0
#define YELLOW  1
#define GREEN   2
#define WHITE   3

//define the three operating modes
#define MODE1   1
#define MODE2   2
#define MODE3   3
   
void msDelay(unsigned int ms);
void testTimer(void);
void initButtons(void);
unsigned char readButtons(unsigned char);
void initTLights(void);
void enableTLights(void);
void disableTLights(void);
void outputTLights(unsigned char lightNum, unsigned char color);
void mode1TLights(void);
void mode2TLights(void);
void mode3TLights(void);
void multiplexColors(unsigned char color1_1, unsigned char color1_2,
                     unsigned char color2_1, unsigned char color2_2, unsigned int ms);


/* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _TLIGHTS__H */

