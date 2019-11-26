/* 
 * File:   sonar.h
 * Author: ben
 *
 * Created on November 15, 2019, 10:41 AM
 */
#define _SUPPRESS_PLIB_WARNING
#define _DISABLE_OPENADC10_CONFIGPORT_WARNING

#include <p32xxxx.h>
#include <plib.h>

#ifndef SONAR_H
#define	SONAR_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    #define triggerPulse() OC5CONSET = 0x8000
    
    void initSonar();

    float sonarDistance(void);
    
    volatile unsigned  int firstCapture;
    volatile unsigned  int secondCapture;
    volatile int running;
    unsigned int runtime;
    
    void initOC5(void);
    void initIC4(void);
    
    volatile unsigned int lastSonarResponceTime;



#ifdef	__cplusplus
}
#endif

#endif	/* SONAR_H */

