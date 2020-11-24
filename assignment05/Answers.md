1. Create a function in “C” that allows swapping of two pointers.  
   1.Explain what the “main” function does in order to setup the input arguments prior to calling the swap_pointer() function?  
> Before we get to the call to swap the main function stores y, x, yPtr, and xPtr to the Stack.  When we get to the swap funtion but before branching to it, the main function does this  
   0x800'007c: 0xa902         ADD       R1, SP, #0x8  
   0x800'007e: 0xa803         ADD       R0, SP, #0xc  
The first line grabs the address of the stack at offset 0x8 and stores it into register R1.  That is the address of the yPtr in the stack.  The second line grabs the address of the stack at offset 0xC and stores that into register R0.  That is the address of the xPtr in the stack.  
   1. What are the values in R0 & R1 when swap_pointer() is called?  
   1. Share a screen shot of the local variables inside of “main” after the function swap_pointer() returns showing the values of the pointers and what they are pointing to (similar to the picture below).  
