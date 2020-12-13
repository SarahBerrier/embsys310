#include "stm32l475xx.h"
#include "delay.h"

// Class minute 01:15:00 shows question 1b to set up the vector table.
// Class minute 00:21:00 shows question 2, which is how to set up the map
// Class minute 00:23:21 is when Tamer showcases where to find the rom and ram size

#define SYS_CLOCK_HZ 4000000u   // Default clock after startup
                                // Section 3.11 in STM32L475 datasheet DS10969

volatile uint32_t counter = 0;

void SysTick_Initialize(void);

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

    SysTick_Initialize();
    
    while(1)
    {
        delay(3000);

        GPIOA->ODR |= GPIO_ODR_OD5;
            
        delay(3000);

        GPIOA->ODR &= ~GPIO_ODR_OD5;
    }
}

// Class minute 2:30:00 is good for looking through the following funtions with Tamer

void SysTick_Initialize(void)
{
    SysTick->LOAD = (SYS_CLOCK_HZ/1000) - 1;   // 0xE000E014 - Counts down to 0.  //dividing by 1000 to go for milliseconds instead of seconds.
    SysTick->VAL = 0x0;                        // 0xE000E018 - Clears initial value
    SysTick->CTRL = 0x7;                       // 0xE000E010 - Enable interrupts
}

void SysTick_Handler(void)
{
    __disable_irq();
    counter--;
    __enable_irq();
}