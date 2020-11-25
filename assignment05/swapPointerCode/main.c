#include "delay.h"

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOB_BASE 0x48000400
#define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE + 0x00)))
#define GPIOB_ODR (*((unsigned int*)(GPIOB_BASE + 0x14)))


#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

//volatile int counter=0;
int counter=0;

#define ORD14   (1<<14)
#define ORD5    (1<<5)


#if 1
void swap(int** x, int** y);

void swap(int** x, int** y)
{
    // swapping the values
//    int temp = *x;
//    *x = *y;
//    *y = temp;
        
    // swapping the pointers
    int* tempPtr= *x;
    *x = *y;
    *y = tempPtr;
    
    
}

int main(void)
{
    int x = 2000000;
    int y = 1000000;
    
    int* xPtr = &x;
    int* yPtr = &y;
    
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    RCC_AHB2ENR |= 0x3;
  
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    GPIOB_MODER &= 0xDFFFFFFF;
    
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    GPIOA_MODER &= 0xFFFFF7FF;

    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    while(1)
    {
        swap(&xPtr, &yPtr);

        GPIOB_ODR |= ORD14;
        delay(x);

        GPIOB_ODR &= ~ORD14;
        delay(y);
    }
}
#endif
