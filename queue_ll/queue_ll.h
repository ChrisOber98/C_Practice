#ifndef QUEUE_LL_H_
#define QUEUE_LL_H_

#include "dll.h"

typedef struct Queue_ll
{
	DoublyLinkedList * queue;
}Queue_ll;

Queue_ll * queue_ll_init();

void queue_ll_print();

//enqueue(value) - adds value at a position at the tail
void queue_ll_enque(int element, Queue_ll * q);

//dequeue() - returns value and removes least recently added element (front)
int queue_ll_dequeue(Queue_ll * q);

//empty()
int queue_ll_empty(Queue_ll * q);

void queue_ll_free(Queue_ll * q);


#endif
