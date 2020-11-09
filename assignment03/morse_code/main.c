#if 1 //Morse code

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14))) // The 14 here is not the pin (like pb14 or pa5.  It is the offset for the ODR Register)

#define ORD5 (1 << 5) // If I use a 1 shifted to the left by 5 then I get a 1 with all zeros which is the bit postion I care about.   

int counter = 0;

void signal(int count, int isDot)
{
    int timeMax = 300000;
    if(1==isDot)
    {
        timeMax = 100000;
    }
    while (count > 0)
    {
        counter = 0;
        while (counter < 100000)
        {
            counter++;
        }
        
        GPIOA_ODR |= ORD5; 
        counter = 0; // reset counter
        while (counter < timeMax)
        {
            counter++;
        }
        GPIOA_ODR &= ~ORD5;
        count--;
    }
}

void padTime(int unitCount)
{
    while (unitCount > 0)
    {
        counter = 0;
        while (counter < 100000)
        {
            counter++;
        }
        unitCount--;
    }    
}

int main(void)
{    
    RCC_AHB2ENR |= 0x1; // I only want to set the first bit so I use OR  
    GPIOA_MODER &= 0xFFFFF7FF;  //GPIOA set to output 

    // Sarah
    // ...  ._  ._.  ._  ....
    
    while(1)
    {
        signal(3, 1);
        padTime(3);
        
        signal(1, 1);
        signal(1, 0);
        padTime(3);

        signal(1, 1);
        signal(1, 0);
        signal(1, 1);
        padTime(3);

        signal(1, 1);
        signal(1, 0);
        padTime(3);

        signal(4, 1);
        padTime(3);
        padTime(7);
    }
}
#endif


