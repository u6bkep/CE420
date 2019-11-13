//seven_seg.h 
//this is incomplete template shows the include section for the seven_seg header file 

#include <p32xxxx.h>

//suppress plib warnings 
#define _SUPPRESS_PLIB_WARNING 
#define _DISABLE_OPENADC10_CONFIGPORT_WARNING

static char segLookup[] = {11111100, 01100000, 11011010, 11110010, 01100110, 10110110, 10111110, 11100000, 11111110, 11100110};

#include <plib.h>

volatile int segState = 0;
volatile int segValues[] = {0,0,0,0};