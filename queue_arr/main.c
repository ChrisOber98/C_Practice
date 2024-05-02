#include "vector.h"
#include "queue_arr.h"

#include <stdio.h>

int main(int argc, char ** argv)
{
	Queue_arr * queue = queue_arr_init();

	queue_arr_is_empty(queue);

	queue_arr_enqueue(1, queue);

	queue_arr_is_full(queue);

	queue_arr_enqueue(2, queue);
	queue_arr_enqueue(3, queue);
	queue_arr_enqueue(4, queue);

	queue_arr_is_full(queue);

	queue_arr_enqueue(5, queue);

	queue_arr_is_full(queue);

	queue_arr_dequeue(queue);
	queue_arr_dequeue(queue);
	queue_arr_dequeue(queue);
	queue_arr_dequeue(queue);

	queue_arr_is_empty(queue);

	queue_arr_enqueue(2, queue);
	queue_arr_enqueue(3, queue);

	queue_arr_dequeue(queue);

	queue_arr_destroy(queue);

	return 0;
}