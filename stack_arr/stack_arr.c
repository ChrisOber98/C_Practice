#include "stack_arr.h"
#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

Stack * init_stack()
{
	Stack * stack_array = (Stack *)malloc(sizeof(Stack));
	stack_array->top = -1;
	stack_array->stack_arr = vect_init();

	return stack_array;
}

void stack_push(int element, Stack * st)
{
	vect_insert_at(0, element, st->stack_arr);
	st->top += 1;
}

void stack_pop(Stack * st)
{
	if(st->top < 0)
	{
		printf("STACK IS EMPTY!\n\n");
		return;
	}

	vect_delete_at(st->top,st->stack_arr);
	st->top -= 1;
}

int stack_peek(Stack * st)
{
	return vect_at(st->top, st->stack_arr);
}

void stack_free(Stack * st)
{
	free(st->stack_arr);
	free(st);
}