/*
    *Push: Adds an element to the top of the stack.
    *Pop: Removes the top element from the stack.
    *Peek (or Top): Returns the top element of the stack without removing it.
    IsEmpty: Checks if the stack is empty.
    IsFull (if the stack has a fixed size): Checks if the stack is full.
    Size (or Count): Returns the number of elements in the stack.
    Clear: Removes all elements from the stack, leaving it empty.
*/

#include "stack_arr.h"
#include "vector.h"

#include <stdio.h>

int main(int argc, char ** argv)
{
	Stack * stack_arr = init_stack();

	stack_push(12, stack_arr);
	stack_push(3, stack_arr);
	stack_push(4, stack_arr);

	stack_pop(stack_arr);
	stack_pop(stack_arr);
	stack_pop(stack_arr);
	stack_pop(stack_arr);

	stack_push(4, stack_arr);

	stack_peek(stack_arr);

	stack_free(stack_arr);

	return 0;
}