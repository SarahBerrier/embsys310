#include "stack.h"

#define STACK_CAPACITY 3

// Backing store
int StackStore[STACK_CAPACITY];

// Pointers to stack elements for pushing and popping
int topIndex;
int stackSize;

// Initialize internals of the stack
void stack_init(void)
{
    topIndex = 0;
    stackSize = 0;
    
    for(int i=0; i < STACK_CAPACITY; i++)
    {
        StackStore[i] = 0;
    }
}
//error = -1
//success = 0

//true = 1, false = 0

int stack_push(int data)
{
    if (is_stack_full())
    {
        return -1;
    }
    
    StackStore[topIndex] = data;
    stackSize++;
    topIndex++;
    return 0;
}

int stack_pop(int* data)
{
    if(is_stack_empty())
    {
        return -1;
    }
    
    *data = StackStore[topIndex-1];
    StackStore[topIndex-1] = 0;
    stackSize--;
    topIndex--;
    
    return 0;
}

int is_stack_empty()
{
    return (0 == stackSize);
}

int is_stack_full()
{
    return (STACK_CAPACITY == stackSize);
}
