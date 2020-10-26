1. Inject 0x7FFFFFFF for the "counter" value in the variable window, then step thru the program only once to increment "counter".
   1. What is the value of the "counter" from the "Locals" window?
   > -2147483648
   1. What is the value of the "counter" in the "Registers" window?
   > 0x80000000
   1. Please note down if the N and/or V flags are set in the APSR register. And explain why.
   > Both the N and V flags are set to 1.  The N register is the negative flag and V is the overflow flag.  0x7FFFFFFF in binary is 0111 for the 7 and 1111 for all of the F's.  The first bit 0 showcased that the number was positive.  When we added 1 to that number it made all of the ones carry over into that first bit of 0 and gave us 0x80000000.  Which in binary is 1000 for the 8 and 0000 for all the rest.  Basically we overflowed our number into the first bit, which changed it from a postive number into a negaive number.  Hence N and V changed to 1 to showcase that the number is negative and that an overflow occurred.  


1. If your write all Fs (0xFFFFFFFF) in the Register value for "counter" then step thru the program once to increment "counter"
   1. What happens to the value of "counter" in the "Locals" window?
   > It goes from -1 to become 0
   1. Please note down if the N and/or V flags are set in the APSR register. And explain why.
   > Both the N and V flags are set to 0.  0XFFFFFFFF in binary is all 1s.  If we add a 1 to that we carry over every spot to become all zeros.  Therefore the N flag is not set because the most significant bit is not set.  I did not understand why the overflow wasn't set.  I would expect the bit to the left of our first bit to be incremented incorrectly.  I looked in the books and couldn't find an explanation.  Found this youtube video:  https://www.youtube.com/watch?v=d6w027jfQ64.  "The overlow flag is set when the most significant bit is changed by adding two numbers with the same sign or subracting two numbers with opposite signs.  Overflow never occurs when the sign of two addition opperands are different or the sign of two subtraction operands are the same."  So in this case we are adding 1 to -1.  The signs are different and so the overflow flag is not set.  I do still wonder about the bit in memory to the left of the most significant bit.

1. Change the "counter" variable type in your code to "unsigned int". Inject the values "0x7FFFFFFF" then step thru the program to increment the "counter" once:
   1. What is the value of "counter" in the "Locals" window after incrementing for each value?
   > 2147483648
   1. Please note down if the N and/or V flags are set in the APSR register. And explain why.
   > The N and V flags are both set.  The N is set because the most significant bit is 1.  The video I linked in the last question says:  "The overflow flag is meaningless and normally ignored when unsigned numbers are added or subtracted."  This link (http://c-jump.com/CIS77/CPU/Overflow/lecture.html) says:  "When two unsigned numbers are added, overflow occurs if there is a carry out of the leftmost bit."  In this case there is no carry out so I am not sure why it is set.

1. Change the "counter" variable type in your code to "unsigned". Inject the values "0xFFFFFFFF" then step thru the program to increment the "counter" once:
   1. What is the value of "counter" in the "Locals" window after incrementing for each value?
   > 0
   1. Please note down if the N and/or V flags are set in the APSR register. And explain why.
   > The value of counter with the value 0xFFFFFFFF is 4294967295. 0xFFFFFFFF is binary all 1s.  When we add a 1 to that it is all set to 0s.  The negative flag is not set because the most significant bit is not set.  The overflow flag is not set but I don't understand why because in this case we do have a carry out.  1111 + 0001 = 10000.  

1. Move the "counter’ variable outside of main (at the top of the file):
   1. What is the scope of the variable "counter"?
   > Global
   1. Is it still visible in the "Locals" view?
   > No
   1. In which window view can we track "counter" now?
   > Watch
   1. What is the address of the "counter" variable in memory?
   > 0x20000000

1. Change the source code as suggested, then run the program in the simulator:
   1. What is the value of "counter" at the end of the program (halting at the return 0 statement)
   > 4
   1. Explain why the counter value has changed?
   > The pointer is pointing to the memory location of counter.  It would appear that our RAM memory addresses start at 0x20000000.  When we set our pointer to that address the effect it had was to set the pointer to point to the same memory location as the counter global variable.     

1. Change the setting of IAR to run the same program on the evaluation board
   1. What is the address where "counter" is stored? 
   1. Is the "counter" variable stored in RAM or ROM?
   1. What is the value of "counter" at the end of the program (halting at the return 0 statement).
