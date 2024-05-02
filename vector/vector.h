#ifndef VECTOR_H_
#define VECTOR_H_

typedef struct Vector
{
	int * arr;
	int capacity;
	int size;
}Vector;

void vect_display(Vector * vect);

Vector * vect_init();

void vect_fin(Vector * vect);

void vect_resize(Vector * vect);

void vect_insert_at(int index, int element, Vector * vect);

void vect_update_at(int index, int element, Vector * vect);

int vect_delete_at(int index, Vector * vect);

int vect_at(int index, Vector * vect);

#endif