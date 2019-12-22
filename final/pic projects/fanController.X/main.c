/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system intialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.95-b-SNAPSHOT
        Device            :  PIC24FV16KM202
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36
        MPLAB 	          :  MPLAB X v5.10
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include <p24Fxxxx.h>
#include <libpic30.h>
#include <stdio.h>

#include "simpleScheduler.h"

#include "mcc_generated_files/mcc.h"

//chose what pattern to use
#define PATTERN 2

#define    FCY    2000000UL    // Instruction cycle frequency, Hz - required for __delayXXX() to work
#define __delay_ms(d) \
  { __delay32( (unsigned long) (((unsigned long long) d)*(FCY)/1000ULL)); }

#include "font5x7.h"

#define SPI_Data_Out LATAbits.LATA1
#define SPI_Clock LATAbits.LATA4
#define SPI_Chip_Select LATAbits.LATA3

#define dotstarFrameLenth 7
#define frameCount 3



void write_SPI(int iPattern)
{
    /*****************************************************
     * this function sends a max 2 byte string to the LCD
     *
     * the oporators are (1) what to set the RS pin to,
     * and (2) the 2 byte string.
     *****************************************************/
    int i = 0;                   //define local variables
    SPI_Chip_Select = 0;
        for(i = 0; i < 8; i++)   //8 time repeating loop to send all 8 bits
        {
         if((iPattern & 0x80) == 0x80) //check bit7 in pattern, and set or clear SPI_Data_Out accordingly
         {
             SPI_Data_Out_SetHigh();
         }
         else
         {
             SPI_Data_Out_SetLow();
         }
        SPI_Clock_SetLow();            //togle SPI_Clock
        SPI_Clock_SetHigh();
        iPattern = (iPattern << 1); //shift pattern left by 1
        }
    SPI_Chip_Select = 1;
}

typedef struct typePixel
{
    uint8_t brightnes;
    uint8_t red;
    uint8_t green;
    uint8_t blue;
}typePixel;



typedef struct typeDotstarFrame
{ 
    typePixel frame[dotstarFrameLenth];
}typeDotstarFrame;

const typeDotstarFrame blankFrame = {
    {
        {0b11111111,0x00,0x00,0x00},
        {0b11111111,0x00,0x00,0x00},
        {0b11111111,0x00,0x00,0x00},
        {0b11111111,0x00,0x00,0x00},
        {0b11111111,0x00,0x00,0x00},
        {0b11111111,0x00,0x00,0x00},
        {0b11111111,0x00,0x00,0x00}
        
    }
};

//store frames for display
const typeDotstarFrame rgbFrame0[frameCount] = {
    {{
        {0b11111111,0xff,0x00,0x00},
        {0b11111111,0x00,0xff,0x00},
        {0b11111111,0x00,0x00,0xff},
        {0b11111111,0xff,0x00,0x00},
        {0b11111111,0x00,0xff,0x00},
        {0b11111111,0x00,0x00,0xff},
        {0b11111111,0xff,0x00,0x00}
    }},
    {{
        {0b11111111,0x00,0xff,0x00},
        {0b11111111,0x00,0x00,0xff},
        {0b11111111,0xff,0x00,0x00},
        {0b11111111,0x00,0xff,0x00},
        {0b11111111,0x00,0x00,0xff},
        {0b11111111,0xff,0x00,0x00},
        {0b11111111,0x00,0xff,0x00}
    }},
    {{
        {0b11111111,0x00,0x00,0xff},
        {0b11111111,0xff,0x00,0x00},
        {0b11111111,0x00,0xff,0x00},
        {0b11111111,0x00,0x00,0xff},
        {0b11111111,0xff,0x00,0x00},
        {0b11111111,0x00,0xff,0x00},
        {0b11111111,0x00,0x00,0xff}
    }}
};

//store frames for display
const typeDotstarFrame rgbFrame1[frameCount] = {
    {{
        {0b11111111,0xff,0x00,0x00},
        {0b11111111,0xff,0x00,0x00},
        {0b11111111,0xff,0x00,0x00},
        {0b11111111,0xff,0x00,0x00},
        {0b11111111,0xff,0x00,0x00},
        {0b11111111,0xff,0x00,0x00},
        {0b11111111,0xff,0x00,0x00}
        
    }},
    {{
        {0b11111111,0x00,0xff,0x00},
        {0b11111111,0x00,0xff,0x00},
        {0b11111111,0x00,0xff,0x00},
        {0b11111111,0x00,0xff,0x00},
        {0b11111111,0x00,0xff,0x00},
        {0b11111111,0x00,0xff,0x00},
        {0b11111111,0x00,0xff,0x00}
        
    }},
    {{
        {0b11111111,0x00,0x00,0xff},
        {0b11111111,0x00,0x00,0xff},
        {0b11111111,0x00,0x00,0xff},
        {0b11111111,0x00,0x00,0xff},
        {0b11111111,0x00,0x00,0xff},
        {0b11111111,0x00,0x00,0xff},
        {0b11111111,0x00,0x00,0xff}
        
    }}
};

const typePixel startFrame = {0x00,0x00,0x00,0x00};
const typePixel endFrame = {0xff,0xff,0xff,0xff};

void writeDotstarPixel(typePixel pixel)
{
    write_SPI(pixel.brightnes);
    write_SPI(pixel.red);
    write_SPI(pixel.green);
    write_SPI(pixel.blue);
}

void writeDotstarFrame(typeDotstarFrame frame)
{
    writeDotstarPixel(startFrame);
    
    for(int i = 0; i < dotstarFrameLenth; i++)
    {
        writeDotstarPixel(frame.frame[i]);
    }
    
    writeDotstarPixel(endFrame);
}

void send_PWM(signed int speed)
{
     /************************************
     * this function takes a speed value
     * in percentage from -100 to 100
     * and sets the pwm module accordingly
     ************************************/
    SCCP4_COMPARE_DualCompareValueSet(0,((speed * 4) + 3000));
    //CCP4RB = ((speed * 4) + 3000);
    //CCP4CON1Lbits.CCPON = 1;   //Turn on MCCP module
}
  
//display a character onto the spinning LEDs
void renderChar(char charactor)
{
    typeDotstarFrame charframe;
    for(int i = 0; i < frameCount; i++)
    {
        for(int j = 0; j < frameCount; j ++)
        {
            typePixel tempPixel;
            if(font5x7data[charactor - FONT_CHAR_FIRST][i] && 1<<j)
            {
                tempPixel.brightnes = 0xFF;
                tempPixel.red = 0x55;
                tempPixel.blue = 0x55;
                tempPixel.green = 0x55;
            }
            else                
            {
                tempPixel.brightnes = 0xFF;
                tempPixel.red = 0x00;
                tempPixel.blue = 0x00;
                tempPixel.green = 0x00;
            }
            charframe.frame[j] = tempPixel;
        }
        writeDotstarFrame(charframe);
    }
    
    
}

  
  
  
    // declare global variables
  
  uint8_t volatile LedState = 0;
  int volatile frameCounter = 0;
  int volatile running = 1;
  int volatile patternChoice = 0;
  
  
  void EX_INT1_CallBack(void)
  {
      if(running)
      {
        switch(patternChoice)
        {
            case 0:
                writeDotstarFrame(rgbFrame0[0]);
                __delay_ms(30);
                writeDotstarFrame(rgbFrame0[1]);
                __delay_ms(30);
                writeDotstarFrame(rgbFrame0[2]);
                __delay_ms(30);
                writeDotstarFrame(blankFrame);
                break;

            case 1:
                writeDotstarFrame(rgbFrame1[0]);
                __delay_ms(30);
                writeDotstarFrame(rgbFrame1[1]);
                __delay_ms(30);
                writeDotstarFrame(rgbFrame1[2]);
                __delay_ms(30);
                writeDotstarFrame(blankFrame);
                break;
        }
      }  
  }
  
  
void secondMethod()
{
    if(running)
    {
        if(LedState == 0)
        {
            LedState = 1;
            //send_PWM(10);
            LED_SetHigh();
        }
        else
        {
            LedState = 0;
            //send_PWM(-10);
            LED_SetLow();
        }
    }
    
}

/*
                         Main application
 */
int main(void)
{
    
    // initialize the device
    SYSTEM_Initialize();
    //SCCP4_COMPARE_Start();
    
    starScheduler(&secondMethod);
  
    printf("starting\n");
    printf("\nusage:\np: pause\nr: resume\n0-1: select pattern\n");
    
    while(1)
    {
        //read uart and echo
        char charactor = UART1_Read();
        UART1_Write(charactor);
        
        // perform actions based on user input
        switch(charactor)
        {
            case 'P':
            case 'p':
                running = 0;
                renderChar(' ');
                printf("paused");
                break;
                
            case 'R':
            case 'r':
                running = 1;
                printf("running");
                break;
                
            case '0':
                patternChoice = 0;
                printf("pattern 0 selected");
                break;
                
            case '1':
                patternChoice = 1;
                printf("pattern 1 selected");
                break;
            default:
                printf("\nusage:\np: pause\nr: resume\n0-1: select pattern\n");

        }
                
    }

    return 1;

 }
/**
 End of File
*/

