#include <assert.h>
#include "stack.h"

int main()
{
    int result1;
    int result2;
    int testValue;
    
    
    // *******************************************************************
    // Test1: is_empty function from an empty stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    testValue = 3;
    stack_init();
    
    // Act:
    result1 = is_stack_empty();
    
    // Assert:
    assert(1 == result1);

    // *******************************************************************
    // Test2: Pop an item from an empty stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    testValue = 3;
    stack_init();
    
    // Act:
    result1 = stack_pop(&testValue);
    
    // Assert:
    assert(-1 == result1);
    assert(3 == testValue);

    // *******************************************************************
    // Test3: Successfully pop an item from the stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    testValue = 3;
    stack_init();
    
    // Act:
    result1 = stack_push(44);
    result2 = stack_pop(&testValue);
    
    // Assert:
    assert(0 == result1);
    assert(0 == result2);
    assert(44 == testValue);
    
    // *******************************************************************
    // Test4: is_empty function from a non empty stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    result2 = 42;
    stack_init();
    
    // Act:
    result1 = stack_push(44);
    result2 = is_stack_empty();
    
    // Assert:
    assert(0 == result1);
    assert(0 == result2);
    
    // *******************************************************************
    // Test5: Fill stack, then get all items.
    // *******************************************************************
    // Arrange:
    testValue = 99;
    stack_init();
    
    // Act:
    stack_push(33);
    stack_push(44);
    stack_push(55);                                    
    
    // Assert:
    assert(0 == stack_pop(&testValue));
    assert(55 == testValue);

    assert(0 == stack_pop(&testValue));
    assert(44 == testValue);

    assert(0 == stack_pop(&testValue));
    assert(33 == testValue);

    // *******************************************************************
    // Test6: Fill stack, then put one more item, should fail
    // *******************************************************************
    // Arrange:
    testValue = 99;
    stack_init();
    
    // Act:
    stack_push(33);
    stack_push(44);
    stack_push(55);                                    
    
    // Assert:
    assert(-1 == stack_push(66));
    
    assert(0 == stack_pop(&testValue));
    assert(55 == testValue);

    assert(0 == stack_pop(&testValue));
    assert(44 == testValue);

    assert(0 == stack_pop(&testValue));
    assert(33 == testValue);

    // ***********************************************************************
    // Test7: Fill stack, retrieve one item, then add item, then retieve all
    // ***********************************************************************
    // Arrange:
    testValue = 99;
    stack_init();
    
    // Act:
    stack_push(33);
    stack_push(44);
    stack_push(55);                                    
    
    // Assert:
    assert(0 == stack_pop(&testValue));
    assert(55 == testValue);

    assert(0 == stack_push(77));

    assert(0 == stack_pop(&testValue));
    assert(77 == testValue);

    assert(0 == stack_pop(&testValue));
    assert(44 == testValue);

    assert(0 == stack_pop(&testValue));
    assert(33 == testValue);

    // ***********************************************************************
    // Test8: Fill stack and retrieve all items. Do it twice in a row.
    // ***********************************************************************
    // Arrange:
    testValue = 99;
    stack_init();
    
    // Act:
    stack_push(33);
    stack_push(44);
    stack_push(55);                                    
    
    // Assert:
    assert(0 == stack_pop(&testValue));
    assert(55 == testValue);

    assert(0 == stack_pop(&testValue));
    assert(44 == testValue);

    assert(0 == stack_pop(&testValue));
    assert(33 == testValue);

    assert(0 == stack_push(66));
    assert(0 == stack_push(77));
    assert(0 == stack_push(88));
    
    assert(-1 == stack_push(111));

    assert(0 == stack_pop(&testValue));
    assert(88 == testValue);

    assert(0 == stack_pop(&testValue));
    assert(77 == testValue);

    assert(0 == stack_pop(&testValue));
    assert(66 == testValue);
    
    return 0;
}
