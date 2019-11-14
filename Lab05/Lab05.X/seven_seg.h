//seven_seg.h 
//this is incomplete template shows the include section for the seven_seg header file 

#include <p32xxxx.h>

//suppress plib warnings 
#define _SUPPRESS_PLIB_WARNING 
#define _DISABLE_OPENADC10_CONFIGPORT_WARNING

static char segLookup[] = {~0b00111111, ~0b00000110, ~0b01011011, ~0b01001111, ~0b01100110, ~0b01101101, ~0b01111101, ~0b00000111, ~0b01111111, ~0b01100111, 0xff};


//static char segLookup[] = {0b00000001, 0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b01000000, 0b10000000, 0b11111111, 0b00000000};

#include <plib.h>

volatile unsigned int segState = 0;
volatile unsigned int segValues[] = {0,0,0,0};
volatile unsigned int segPower;

#define IN      1       
#define OUT     0