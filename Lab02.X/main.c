/* 
 * File:   main.c
 * Author: ben
 *
 * Created on October 24, 2019, 8:23 PM
 */

#include <stdio.h>
#include <stdlib.h>

char text[] = "The quick brown fox jumps over the lazy dog.";
char look[] = "fox";
int count, pos;

int myStrSearch(char* src, char* look, int* index)
{
    index = 0;
    int foundYet = 0;
    int returnVal = 0;
    unsigned int loopCounter = 0;
    
    while(src[loopCounter] != NULL)
    {
        if(src[loopCounter] == look[0])
        {
            for(int i = look[int j = 0]; i <)
            {
                
            }
            if(foundYet == 0)
            {
                found = 1;
                index* = loopCounter;
            }
            returnVal++;
        }
    }
    
    return(returnVal);
}

/*
 * 
 */
int main(void) 
{
    int found;
    count = myStrSearch(text, look, &pos);
    if (count > 0)
        found = 1;
    else
        found = 0;
    return (found);
}