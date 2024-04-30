#include "queue_ll.h"

#include <stdio.h>
#include <stdlib.h>

Queue_ll * queue_ll_init()
{
	Queue_ll * q = (struct Queue_ll *)malloc(sizeof(Queue_ll));
	q->queue = dll_init();

	return q;
}

void queue_ll_print(Queue_ll * q)
{
	dll_print(q->queue);
}

void queue_ll_enque(int element, Queue_ll * q)
{
	printf("---INSERTING %d TO FRONT OF Queue---\n", element);
	dll_insert_front(element, &(q->queue));
}

int queue_ll_dequeue(Queue_ll * q)
{
	printf("---DEQUEING FROM Queue---\n");

	int ret = dll_delete_back(&(q->queue));

	printf("RETURNED: %d.\n\n", ret);

	return ret;
}

int queue_ll_empty(Queue_ll * q)
{
	return dll_is_empty(&(q->queue));
}

void queue_ll_free(Queue_ll * q)
{
	dll_free(&(q->queue));
	free(q);
}
