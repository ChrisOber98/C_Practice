#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdbool.h>

typedef struct Vector
{
	int * arr;
	int capacity;
	int size;
}Vector;

//----------Constructor and deconstructor----------
Vector * vector_init();
void vector_deinit(Vector * vect);

//----------size() - Return number of items----------
int vector_size(Vector * vect);

//----------capacity() - Return number of items it can hold----------
int vector_capacity(Vector * vect);

//----------is_empty() - return True if vector is empty false otherwise----------
bool vector_is_empty(Vector * vect);

//----------resize() - double capacity and realloc memory for vector----------
void vector_resize(Vector * vect);

//----------push() - place element at back of array----------
void vector_push(int element, Vector * vect);

//----------at(index) - returns the item at a given index, blows up if index out of bounds----------
int vector_at(int index, int * value, Vector * vect);

//----------displays content of vector----------
void vector_display(Vector * vect);

//----------at(index) - returns the item at a given index, blows up if index out of bounds----------
int vector_insert(int index, int element, Vector * vect);

//----------pop() - remove from end, return value return 1 on success -1 on failure-------
int vector_pop(int * value, Vector * vect);

//----------delete item at index, shifting all trailing elements left-----
int vector_delete(int index, int * value, Vector * vect);

//-----remove(item) - looks for value and removes index holding it (even if in multiple places)-----
int vector_remove(int value, Vector * vect);

/*
	------resize(new_capacity) when you reach capacity if the size is 1/4 of capacity, resize to half-------
*/
void vector_desize(Vector * vect);

#endif