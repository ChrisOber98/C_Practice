/*
	*Accessing an element at index = O(1)

	*Inserting at index = O(N)

	*Deleting from index = O(N)

	*Updating at index = O(1)

	*Traversing Array = O(N)
*/

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

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

	Vector * temp = malloc(sizeof(Vector));;

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
	free(vect);
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

int vect_delete_at(int index, Vector * vect)
{
	printf("---deleting at vector---\n");

	if(index < 0 || index > vect->size)
	{
		printf("Trying to access out of bound index\n\n");
		return -999;
	}

	if(vect->size == 0)
	{
		printf("returning nothing array is empty\n");
		vect_display(vect);
		return -999;		
	}

	if(vect->size == 1)
	{
		int ret = vect->arr[0];
		printf("returning %d\n", ret);
		vect->size--;
		vect_display(vect);
		return ret;		
	}

	int ret = vect->arr[index];
	for (int i = index; i < vect->size - 1; i++)
	{
		vect->arr[i] = vect->arr[i + 1];
	}

	vect->size--;

	printf("returning %d\n", ret);
	vect_display(vect);
	return ret;

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