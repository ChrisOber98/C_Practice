/*
    enqueue(value) - adds item at end of available storage
    dequeue() - returns value and removes least recently added element
    empty()
    full()
*/

#include "queue_arr.h"

#include <stdlib.h>
#include <stdio.h>

Queue_arr * queue_arr_init()
{
	printf("---INITING QUEUE--\n");
	Queue_arr * q = (Queue_arr*)malloc(sizeof(Queue_arr));

	q->end = -1;

	q->arr = vect_init();

	return q;
}

void queue_arr_destroy(Queue_arr * q)
{
	printf("---DESTROYING QUEUE--\n");
	vect_fin(q->arr);
	free(q);
}

//adds item at end of available storage
void queue_arr_enqueue(int element, Queue_arr * q)
{
	printf("---QUEUE ENQUING %d--\n", element);
	vect_insert_at(0, element, q->arr);
	q->end += 1;
}

//returns value and removes least recently added element
int queue_arr_dequeue(Queue_arr * q)
{
	if(q->end == -1)
	{
		printf("QUEUE IS EMPTY CANT DEQUE.\n\n");
		return -999;
	}

	printf("---QUEUE DEQUEUEING--\n");
	int ret = vect_delete_at(q->end, q->arr);
	q->end -= 1;
	return ret;
}

//Returns 1 if empty -1 if not empty
int queue_arr_is_empty(Queue_arr * q)
{
	if(q->end <= -1)
	{
		printf("ITS EMPTY!\n\n");
		return 1;
	}
	else
	{
		printf("ITS NOT EMPTY!\n\n");
		return -1;
	}
}

//Returns 1 if full -1 if not fulll
int queue_arr_is_full(Queue_arr * q)
{
	if(q->end == q->arr->capacity - 1)
	{
		printf("ITS FULL!\n\n");
		return 1;
	}
	else
	{
		printf("ITS NOT FULL!\n\n");
		return -1;
	}	
}