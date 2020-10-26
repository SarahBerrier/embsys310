1. Inject 0x7FFFFFFF for the "counter" value in the variable window, then step thru the program only once to increment "counter".
   1. What is the value of the "counter" from the "Locals" window?
   1. What is the value of the "counter" in the "Registers" window?
   1. Please note down if the N and/or V flags are set in the APSR register. And explain why.


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
