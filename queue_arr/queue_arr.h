#ifndef QUEUE_ARR_H_
#define QUEUE_ARR_H_

#include "vector.h"

typedef struct Queue_arr{
	int end;
	Vector * arr;
}Queue_arr;


//INIT AND DESTROY FUNCS FOR QUEUE IMPLEMENTED WITH ARRAY
Queue_arr * queue_arr_init();
void queue_arr_destroy(Queue_arr * q);

//adds item at end of available storage
void queue_arr_enqueue(int element, Queue_arr * q);

//Returns value and removes least recently added element
int queue_arr_dequeue(Queue_arr * q);

//Returns 1 if empty -1 if not empty
int queue_arr_is_empty(Queue_arr * q); 

//Return 1 if full -1 if not full
int queue_arr_is_full(Queue_arr * q); 

#endif