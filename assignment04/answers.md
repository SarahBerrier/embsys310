1. Follow the same steps as we did in the class to blink LED1 (PA5) at a visible rate using the bitband region to enable the clock to Port A, then answer the following:

What instructions does the compiler produce in assembly for “writing” to the GPIO bit when using bit-band address?  
> 0x800'0040: 0x2001         MOVS      R0, #1  
> 0x800'0042: 0x4913         LDR.N     R1, [PC, #0x4c]         ; 0x4242'0980  
> 0x800'0044: 0x6008         STR       R0, [R1]  

What were the instructions produced when writing to the GPIOx_ODR without using bitbanding?  
> 0x800'0040: 0x4814         LDR.N     R0, [PC, #0x50]         ; RCC_AHB2ENR  
> 0x800'0042: 0x6801         LDR       R1, [R0]  
> 0x800'0044: 0xf051 0x0101  ORRS.W    R1, R1, #1  
> 0x800'0048: 0x6001         STR       R1, [R0]  

2. Create a function “func1” with 5 arguments and call “func1” from within another function “func2”. Trace thru the assembler and note:

How does the calling function “func2” pass the values to the called function “func1”?  
> It stores them in registers R0, R1, R2, R3.  It seems to do it in reverse order.  So it starts with the last argument.  Since there are 5 values they first store a value in R0 but then push that to the stack pointer register SP.  Let me see what happens when there are 6 arguments.  Ok with six arguments, they push the last two arguments to the stack and then the remaining 4 arguments go to registers R0 - R3.  

What extra code did the compiler generate before calling the function “func1” with the multiple arguments?  
> It created the code to move the values into registers R0-R3.  It pushed the extra value to the stack.  And it branched to the function label.

What extra code did the compiler generate inside the called function “funct1” with the multiple list of arguments?  
>It pushes the return address for where to go after leaving the function to the stack.  It also pushes the values of registers R4 to R8 to the stack (I assume this is to save their values while I use those registers for other things).  R4-R8 had been empty though. It moves the value of R0 (which holds the value of the first fn argument) to R4.  Then it does this:   LDR       R5, [SP, #0x18]. I think this means that it is loading the value of the stack pointer at offset x18 into R5.  This is the only argument that had been pushed to the stack.  Super interesting that it knows the offset of that one value in the stack.  Seems non stack like.  

Any other observations?  
> All put above.

Bonus question - look at video minute 58.
