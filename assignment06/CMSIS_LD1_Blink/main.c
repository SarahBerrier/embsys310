#include "stm32l475xx.h"

// class demo = LED2 aka PB14
// HW = LED1 aka PA5 aka

volatile int counter=0;

void main(void)
{
    // RCC Base Address: 0x40021000
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // Address offset: 0x4C
    // Set bit[0] to 1
    // 1. Enable clock to Peripheral
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    
    // GPIOA Base Address: 0x48000000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[11:10] to 0x01  so --> 0x20 // To enable PA5 as output
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    while(1)
    {
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }

        GPIOA->ODR |= GPIO_ODR_OD5;
            
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }

        GPIOA->ODR &= ~GPIO_ODR_OD5;
    }
}