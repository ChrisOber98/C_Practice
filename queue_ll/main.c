/*	
    enqueue(value) - adds value at a position at the tail
    dequeue() - returns value and removes least recently added element (front)
    empty()
*/

#include "dll.h"
#include "queue_ll.h"

#include <stdio.h>

int main(int argc, char ** argv)
{
	Queue_ll * q = queue_ll_init();

	if (queue_ll_empty(q) == 1)
	{
		printf("EMPTY!\n\n");
	}
	else
	{
		printf("NOT EMPTY!\n\n");
	}

	queue_ll_print(q);

	queue_ll_enque(12, q);
	queue_ll_enque(23, q);
	queue_ll_enque(34, q);

	queue_ll_dequeue(q);
	queue_ll_dequeue(q);
	queue_ll_dequeue(q);
	queue_ll_dequeue(q);

	queue_ll_enque(12, q);
	queue_ll_enque(23, q);
	queue_ll_enque(34, q);

	queue_ll_dequeue(q);
	queue_ll_dequeue(q);

	if (queue_ll_empty(q) == 1)
	{
		printf("EMPTY!\n\n");
	}
	else
	{
		printf("NOT EMPTY!\n\n");
	}

	queue_ll_free(q);

	return 0;
}