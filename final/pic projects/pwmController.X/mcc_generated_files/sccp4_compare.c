/**
  SCCP4 Generated Driver File 

  @Company
    Microchip Technology Inc.

  @File Name
    sccp4.c

  @Summary
    This is the generated driver implementation file for the SCCP4 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides implementations for driver APIs for SCCP4. 
    Generation Information : 
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.95-b-SNAPSHOT
        Device            :  PIC24FV16KM202
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36
        MPLAB             :  MPLAB X v5.10
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

#include "sccp4_compare.h"

/** OC Mode.

  @Summary
    Defines the OC Mode.

  @Description
    This data type defines the OC Mode of operation.

*/

static uint16_t         gSCCP4Mode;

/**
  Section: Driver Interface
*/


void SCCP4_COMPARE_Initialize (void)
{
    // CCPON enabled; MOD Dual Edge Compare, Buffered; CCSEL disabled; CCPSIDL disabled; TMR32 16 Bit; CCPSLP disabled; TMRPS 1:1; CLKSEL FOSC/2; TMRSYNC disabled; 
    CCP4CON1L = (0x8005 & 0x7FFF); //Disabling CCPON bit
    //RTRGEN disabled; ALTSYNC disabled; ONESHOT disabled; TRIGEN disabled; IOPS Each Time Base Period Match; SYNC None; OPSRC Timer Interrupt Event; 
    CCP4CON1H = 0x00;
    //ASDGM disabled; SSDG disabled; ASDG 0; PWMRSEN disabled; 
    CCP4CON2L = 0x00;
    //ICGSM Level-Sensitive mode; ICSEL IC4; AUXOUT Disabled; OCAEN enabled; OENSYNC disabled; 
    CCP4CON2H = 0x100;
    //OETRIG disabled; OSCNT None; POLACE disabled; PSSACE Tri-state; 
    CCP4CON3H = 0x00;
    //ICDIS disabled; SCEVT disabled; TRSET disabled; ICOV disabled; ASEVT disabled; TRIG disabled; ICGARM disabled; TRCLR disabled; 
    CCP4STATL = 0x00;
    //TMR 0; 
    CCP4TMRL = 0x00;
    //TMR 0; 
    CCP4TMRH = 0x00;
    //PR 40000; 
    CCP4PRL = 0x9C40;
    //PR 0; 
    CCP4PRH = 0x00;
    //CMP 0; 
    CCP4RAL = 0x00;
    //CMP 12288; 
    CCP4RBL = 0x3000;
    //BUF 0; 
    CCP4BUFL = 0x00;
    //BUF 0; 
    CCP4BUFH = 0x00;

    CCP4CON1Lbits.CCPON = 0x1; //Enabling CCP

    gSCCP4Mode = CCP4CON1Lbits.MOD;

}

void __attribute__ ((weak)) SCCP4_COMPARE_CallBack(void)
{
    // Add your custom callback code here
}

void SCCP4_COMPARE_Tasks( void )
{
    if(IFS0bits.CCP4IF)
    {
		// SCCP4 COMPARE callback function 
		SCCP4_COMPARE_CallBack();
		
        IFS0bits.CCP4IF = 0;
    }
}

void __attribute__ ((weak)) SCCP4_COMPARE_TimerCallBack(void)
{
    // Add your custom callback code here
}


void SCCP4_COMPARE_TimerTasks( void )
{
    if(IFS1bits.CCT4IF)
    {
		// SCCP4 COMPARE Timer callback function 
		SCCP4_COMPARE_TimerCallBack();
	
        IFS1bits.CCT4IF = 0;
    }
}

void SCCP4_COMPARE_Start( void )
{
    /* Start the Timer */
    CCP4CON1Lbits.CCPON = true;
}

void SCCP4_COMPARE_Stop( void )
{
    /* Start the Timer */
    CCP4CON1Lbits.CCPON = false;
}

void SCCP4_COMPARE_SingleCompare16ValueSet( uint16_t value )
{   
    CCP4RAL = value;
}


void SCCP4_COMPARE_DualCompareValueSet( uint16_t priVal, uint16_t secVal )
{

    CCP4RAL = priVal;

    CCP4RBL = secVal;
}

void SCCP4_COMPARE_DualEdgeBufferedConfig( uint16_t priVal, uint16_t secVal )
{

    CCP4RAL = priVal;

    CCP4RBL = secVal;
}

void SCCP4_COMPARE_CenterAlignedPWMConfig( uint16_t priVal, uint16_t secVal )
{

    CCP4RAL = priVal;

    CCP4RBL = secVal;
}

void SCCP4_COMPARE_EdgeAlignedPWMConfig( uint16_t priVal, uint16_t secVal )
{

    CCP4RAL = priVal;

    CCP4RBL = secVal;
}

void SCCP4_COMPARE_VariableFrequencyPulseConfig( uint16_t priVal )
{
    CCP4RAL = priVal;
}

bool SCCP4_COMPARE_IsCompareCycleComplete( void )
{
    return(IFS0bits.CCP4IF);
}

bool SCCP4_COMPARE_TriggerStatusGet( void )
{
    return( CCP4STATLbits.TRIG );
    
}

void SCCP4_COMPARE_TriggerStatusSet( void )
{
    CCP4STATLbits.TRSET = 1;
}

void SCCP4_COMPARE_TriggerStatusClear( void )
{
    /* Clears the trigger status */
    CCP4STATLbits.TRCLR = 0;
}

bool SCCP4_COMPARE_SingleCompareStatusGet( void )
{
    return( CCP4STATLbits.SCEVT );
}

void SCCP4_COMPARE_SingleCompareStatusClear( void )
{
    /* Clears the trigger status */
    CCP4STATLbits.SCEVT = 0;
    
}
/**
 End of File
*/
