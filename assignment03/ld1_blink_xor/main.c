#if 0  //LD2 Class

int counter = 0;

int main()
{
    *((unsigned int*)0x4002104C) = 0x02;  // RCC_AHB2ENR: Enable clock to GPIOB
    
    // GPIOB Base address: 0x48000400
    *((unsigned int*)0x48000400) = 0xDFFFFEBF; // GPIOB_MODER: Set GPIOB to output
 
    while(1)
    {
        counter = 0;
        while (counter < 100000)
        {
            counter++;
        }
        *((unsigned int*)0x48000414) = 0x4000;      // GPIOB_ODR: Turn LED2 (PB14) on
        
        counter = 0; // reset counter
        while (counter < 100000)
        {
            counter++;
        }
        *((unsigned int*)0x48000414) = 0x0000;      // GPIOB_ODR: Turn LED2 (PB14) on
    }

}
#endif

#if 0 //LD2 Class

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOB_BASE 0x48000400
#define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE + 0x0)))
#define GPIOB_ODR (*((unsigned int*)(GPIOB_BASE + 0x14)))

int counter = 0;

int main(void)
{
    
    RCC_AHB2ENR = 0x2; //RCC_AHB2ENR : Enable clock to GPIOB (it is 2 in this case because because GPIOB is in the second register position 2 in binary is 0010)
    GPIOB_MODER = 0xDFFFFEBF;  //GPIOB base address : 0x48000400
    
    while(1)
    {
        
        counter = 0;
        while (counter < 100000)
        {
            counter++;
        }
        
        GPIOB_ODR = 0x4000; // we do 4000 because the 4th postion in hex is registers 15,14,13,12.  This is PB14, note the 14.  0100 is 4
        counter = 0; // reset counter
        while (counter < 100000)
        {
            counter++;
        }
        GPIOB_ODR = 0x0;
    }
}
#endif

#if 0 //LD1 HW

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14))) // The 14 here is not the pin (like pb14 or pa5.  It is the offset for the ODR Register)

int counter = 0;

int main(void)
{
    
    RCC_AHB2ENR = 0x1; //RCC_AHB2ENR : Enable clock to GPIOA (was 0x2 for GPIOB) (it is 1 in this case because because GPIOA is in the first register position. 1 in binary is 0001)
    GPIOA_MODER = 0xABFFF7FF;  //GPIOA set to output (0xABFFFFFF is the reset value, we change the 3rd F(1111) to a 7(0111)) because pa5 is on the 5th pin which according to documenation is registers 10 and 11.  
    
    while(1)
    {
        
        counter = 0;
        while (counter < 100000)
        {
            counter++;
        }
        
        GPIOA_ODR = 0x20; // we do 20 because the 2nd postion in hex is registers 7,6,5,4.  This is PA5, note the 5.  0010 is 2
        counter = 0; // reset counter
        while (counter < 100000)
        {
            counter++;
        }
        GPIOA_ODR = 0x0;
    }
}
#endif

#if 1 //LD1 HW XOR

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14))) // The 14 here is not the pin (like pb14 or pa5.  It is the offset for the ODR Register)

#define ORD5 (1 << 5) // If I use a 1 shifted to the left by 5 then I get a 1 with all zeros which is the bit postion I care about.   

int counter = 0;

int main(void)
{
    
    RCC_AHB2ENR |= 0x1; // I only want to set the first bit so I use OR  
    GPIOA_MODER &= 0xFFFFF7FF;  //GPIOA set to output 
    
    while(1)
    {
        
        counter = 0;
        while (counter < 100000)
        {
            counter++;
        }
        
        GPIOA_ODR ^= ORD5; 
    }
}
#endif


