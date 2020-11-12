
#if 0  // LD2 --> PB14 -- In Class
#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOB_BASE 0x48000400
#define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE + 0x00)))
#define GPIOB_ODR (*((unsigned int*)(GPIOB_BASE + 0x14)))

volatile int counter=0;
//int counter=0;

#define ORD14 (1<<14)

void main(void)
{
    // RCC Base Address: 0x40021000
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // Address offset: 0x4C
    // Set bit[1] to 1
    // 1. Enable clock to Peripheral
    //RCC_AHB2ENR |= 0x2;
    RCC_AHB2ENR = RCC_AHB2ENR | 0x2;
    *((unsigned int*)((0x42000000 ) + (0x2104C * 32) + (1 *4))) = 0x1;
    
    // GPIOB Base Address: 0x48000400
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[29:28] to 0x01  so --> 0x400 // To enable PB14 as output
    GPIOB_MODER &= 0xDFFFFFFF;

    // GPIOB Base Address: 0x48000400
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[14] to 1 --> 0x4000; // Turn LED ON
    // Set bit[14] to 0 --> 0x0; // Turn LED OFF

    while(1)
    {
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }

        GPIOB_ODR |= ORD14;
            
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }

        GPIOB_ODR &= ~ORD14;
    }
}
#endif

#if 1  // LD1 --> PA5 -- Homework
#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14))) // The 14 here is not the pin (like pb14 or pa5.  It is the offset for the ODR Register)

volatile int counter=0;
#define ORD5 (1 << 5) // If I use a 1 shifted to the left by 5 then I get a 1 with all zeros which is the bit postion I care about.   

void main(void)
{
    // RCC Base Address: 0x40021000
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // Address offset: 0x4C
    // Set bit[0] to 1
    // 1. Enable clock to Peripheral
    //RCC_AHB2ENR |= 0x1;
    //RCC_AHB2ENR = RCC_AHB2ENR | 0x1;
    //bit_word_addr= bit_band_base+ (byte_offset*32) + (bit_number*4)
    *((unsigned int*)((0x42000000 ) + (0x2104C * 32) + (0 *4))) = 0x1;
    
    // GPIOA Base Address: 0x48000000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[11:10] to 0x01  so --> 0x20 // To enable PA5 as output
    GPIOA_MODER &= 0xFFFFF7FF;

    // GPIOA Base Address: 0x48000000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[5] to 1 --> 0x20; // Turn LED ON
    // Set bit[5] to 0 --> 0x0; // Turn LED OFF

    while(1)
    {
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }

        GPIOA_ODR |= ORD5;
            
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }

        GPIOA_ODR &= ~ORD5;
    }
}
#endif
