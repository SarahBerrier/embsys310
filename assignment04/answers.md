1. Follow the same steps as we did in the class to blink LED1 (PA5) at a visible rate using the bitband region to enable the clock to Port A, then answer the following:

What instructions does the compiler produce in assembly for “writing” to the GPIO bit?  
when using bit-band address?
> 0x800'0040: 0x2001         MOVS      R0, #1  
> 0x800'0042: 0x4913         LDR.N     R1, [PC, #0x4c]         ; 0x4242'0980  
> 0x800'0044: 0x6008         STR       R0, [R1]  
What were the instructions produced when writing to the GPIOx_ODR without using bitbanding?  
> 0x800'0040: 0x4814         LDR.N     R0, [PC, #0x50]         ; RCC_AHB2ENR  
> 0x800'0042: 0x6801         LDR       R1, [R0]  
> 0x800'0044: 0xf051 0x0101  ORRS.W    R1, R1, #1  
> 0x800'0048: 0x6001         STR       R1, [R0]  
2. Create a function “func1” with 5 arguments and call “func1” from within another function
“func2”. Trace thru the assembler and note:
   1. How does the calling function “func2” pass the values to the called function “func1”?
   1. What extra code did the compiler generate before calling the function “func1” with the
multiple arguments?
   1. What extra code did the compiler generate inside the called function “funct1” with the
multiple list of arguments?
   1. Any other observations?
   
Bonus question - look at video minute 58.
