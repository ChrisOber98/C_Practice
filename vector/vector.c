/*
	*Accessing an element at index = O(1)

	*Inserting at index = O(N)

	*Deleting from index = O(N)

	*Updating at index = O(1)

	*Traversing Array = O(N)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Vector
{
	int * arr;
	int capacity;
	int size;
}Vector;

void vect_display(Vector * vect)
{
	printf("arr: [ ");
	for(int i = 0; i < vect->size; i++)
	{
		printf("%d ", vect->arr[i]);
	}
	printf("]\n");
	printf("cap: %d\n", vect->capacity);
	printf("size: %d\n\n", vect->size);
}

Vector * vect_init()
{
	printf("---Init Vector---\n");

	Vector * temp;

	temp->capacity = 1;
	temp->size = 0;

	temp->arr = malloc(sizeof(int) * temp->capacity);

	if(!temp)
	{
		fprintf(stderr, "Allocation Error");
		exit(EXIT_FAILURE);
	}

	vect_display(temp);

	return temp;
}

void vect_fin(Vector * vect)
{
	printf("---Deconstructing Vector---\nFreeing Array\n\n");
	free(vect->arr);
}

void vect_resize(Vector * vect)
{
	printf("---Resizing Vector---\n");
	vect->capacity = vect->capacity * 2;
	vect->arr = realloc(vect->arr, sizeof(int) * vect->capacity);
	if (!vect)
	{
		fprintf(stderr, "Allocation Error");
		exit(EXIT_FAILURE);			
	}
	vect_display(vect);
}

void vect_insert_at(int index, int element, Vector * vect)
{
	printf("---inserting at vector---\n");

	if(index < 0 || index > vect->size)
	{
		printf("Trying to access out of bound index\n\n");
		return;
	}

	if(vect->size == 0)
	{
		vect->arr[index] = element;
		vect->size++;
		vect_display(vect);
		return;		
	}

	if(vect->capacity == vect->size)
	{
		vect_resize(vect);
	}

	for (int i = vect->size; i >= index; i--)
	{
		vect->arr[i + 1] = vect->arr[i];
	}

	vect->arr[index] = element;
	vect->size++;

	vect_display(vect);
}

void vect_update_at(int index, int element, Vector * vect)
{
	printf("---updating at vector---\n");

	if(index < 0 || index > vect->size)
	{
		printf("Trying to access out of bound index\n\n");
		return;
	}

	vect->arr[index] = element;
	vect_display(vect);
}

void vect_delete_at(int index, Vector * vect)
{
	printf("---deleting at vector---\n");

	if(index < 0 || index > vect->size)
	{
		printf("Trying to access out of bound index\n\n");
		return;
	}

	if(vect->size == 0)
	{
		vect_display(vect);
		return;		
	}

	if(vect->size == 1)
	{
		vect->size--;
		vect_display(vect);
		return;		
	}

	for (int i = index; i < vect->size - 1; i++)
	{
		vect->arr[i] = vect->arr[i + 1];
	}

	vect->size--;

	vect_display(vect);

}

int vect_at(int index, Vector * vect)
{
	printf("---finding at---\n");
	if (index < 0 || index >= vect->size)
	{
		printf("Trying to access out of bound index\n\n");
		return -999;
	}

	printf("returning: %d\n\n", vect->arr[index]);

	return vect->arr[index];
}

int main(int argc, char ** argv)
{

	Vector * my_vect = vect_init();

	vect_delete_at(0, my_vect);

	vect_insert_at(12, 12, my_vect);

	vect_insert_at(0, 3, my_vect);

	vect_insert_at(0, 69, my_vect);

	vect_insert_at(2, 420, my_vect);

	vect_insert_at(4, 6969, my_vect);

	vect_update_at(123, 123, my_vect);

	vect_update_at(2, 765, my_vect);

	vect_at(123123, my_vect);

	vect_at(3, my_vect);

	vect_at(2, my_vect);

	vect_delete_at(1, my_vect);

	vect_delete_at(1, my_vect);

	vect_delete_at(0, my_vect);

	vect_insert_at(0, 3, my_vect);

	vect_fin(my_vect);

	return 0;
}