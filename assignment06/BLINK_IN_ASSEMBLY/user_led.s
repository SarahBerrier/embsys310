/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay                    // delay() is defined outside this file

    PUBLIC control_user_led1        // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : control_user_led1
Description     : - Uses Peripheral registers at base 0x4800.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

GPIOA_BASE  EQU 0x48000000
GPIOA_ODR   EQU 0x14
GPIOA_BIT_5 EQU 0x20 // decimal 32

control_user_led1
    PUSH        {R0}                    // push our state param to the stack
    PUSH        {R1}                    // push our duration param to the stack
    PUSH        {R14}                   // push LR to the stack because delay will change it
    MOVS        R0, R1                  // save the delay variable value to R0 to be passed to delay
    BL          delay                   // branch to delay label
    POP         {R14}                   // pop LR from the stack
    POP         {R1}                    // pop our duration param back to R1
    POP         {R0}                    // pop our state param back to R0
    CMP         R0, #1                  // check if LED_ON == state, check if our state param = 1
    BNE         checkOff                // if state param is not equal to 1 (on state), branch to checkOff label
    LDR         R2, =GPIOA_BASE         // otherwise set the led to on, start by setting the GPIO port a base address into R2
    LDR         R3, [R2, #GPIOA_ODR]    // R3 = GPIOA->ODR
    ORR         R3, R3, #GPIOA_BIT_5    // Set output pin to high
    STR         R3, [R2, #GPIOA_ODR]    // Write the output data register 
    B           theEnd

checkOff
    CMP         R0, #0                  // check if LED_OFF == state, check if our state param = 0
    BNE         theEnd                  // if not equal to 0, leave the function
    LDR         R2, =GPIOA_BASE         // otherwise set the led to off, start by setting the GPIO port a base address into R2
    LDR         R3, [R2, #GPIOA_ODR]    // R3 = GPIOA->ODR
    BIC         R3, R3, #GPIOA_BIT_5    // Set output pin to low
    STR         R3, [R2, #GPIOA_ODR]    // Write the output data register

theEnd
    BX          LR                      // branch to the location in LR, which is the return location after this function is executed

    END
