#include "delay.h"

extern volatile uint32_t counter;

void delay(uint32_t delayInMilliseconds)
{
    counter = delayInMilliseconds;
    
    while (counter > 0)
    {
    } 
}