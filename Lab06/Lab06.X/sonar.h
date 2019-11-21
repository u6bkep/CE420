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
    

    
    void initSonar();

    float sonarDistance(void);
    
    void triggerPulse(void);
    
    volatile int lastSonarResponceTime;



#ifdef	__cplusplus
}
#endif

#endif	/* SONAR_H */

