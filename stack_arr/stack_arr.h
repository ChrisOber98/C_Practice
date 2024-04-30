#ifndef STACK_ARR_H_
#define STACK_ARR_H_

#include "vector.h"

typedef struct Stack
{
	int top;
	Vector * stack_arr;
}Stack;

Stack * init_stack();

//1. Push: Adds an element to the top of the stack. 1.
void stack_push(int element, Stack * st);

//2. Pop: Removes the top element from the stack. 2.
void stack_pop(Stack * st);

//3. Peek (or Top): Returns the top element of the stack without removing it. 3.
int stack_peek(Stack * st);

void stack_free();


#endif