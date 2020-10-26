1. Inject 0x7FFFFFFF for the "counter" value in the variable window, then step thru the program only once to increment "counter".
   1. What is the value of the "counter" from the "Locals" window?
   > -2147483648
   1. What is the value of the "counter" in the "Registers" window?
   > 0x80000000
   1. Please note down if the N and/or V flags are set in the APSR register. And explain why.
   > Both the N and V flags are set to 1.  The N register is the negative flag and V is the overflow flag.  0x7FFFFFFF in binary is 0111 for the 7 and 1111 for all of the F's.  The first bit 0 showcased that the number was positive.  When we added 1 to that number it made all of the ones carry over into that first bit of 0 and gave us 0x80000000.  Which in binary is 1000 for the 8 and 0000 for all the rest.  Basically we overflowed our number into the first bit, which changed it from a postive number into a negaive number.  Hence N and V changed to 1 to showcase that the number is negative and that an overflow occurred.  


1. If your write all Fs (0XFFFFFFFF) in the Register value for "counter"then step thru the program once to increment "counter"
   1. What happens to the value of "counter" in the "Locals"window?
   1. Please note down if the N and/or V flags are set in the APSR register. And explain why.

1. Change the "counter" variable type in your code to "unsignedint". Inject the values "0x7FFFFFFF" then step thru the program to increment the "counter" once:
   1. What is the value of "counter" in the "Locals"window after incrementingfor each value?
   1. Please note down if the N and/or V flags are set in the APSR register. And explain why.

1. Change the "counter" variable type in your code to "unsigned". Inject the values "0xFFFFFFFF" then step thru the program to increment the "counter" once:
   1. What is the value of "counter" in the "Locals" window after incrementing for each value?
   1. Please note down if the N and/or V flags are set in the APSR register. And explain why.

1. Move the "counter’variable outside of main (at the top of the file):
   1. What is the scope of the variable "counter"?
   1. Is it still visible in the "Locals" view?
   1. In which window view can we track "counter" now?
   1. What is the address of the "counter" variablein memory?

1. Change the source code to the following, then run the program in the simulator:
   1. What isthe value of "counter"at the endof the program (halting at the return 0statement)
   1. Explain why the counter value has changed?

1. Change the setting of IAR to run the same program on the evaluation board
   1. What is the address where "counter" is stored? 
   1. Is the "counter" variable stored in RAM or ROM?
   1. What is the value of "counter" at the end of the program (halting at the return 0 statement).
