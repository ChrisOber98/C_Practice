/*
	*size() - number of items
    *capacity() - number of items it can hold
    *is_empty()
    *at(index) - returns the item at a given index, blows up if index out of bounds
    *push(item)
    *insert(index, item) - inserts item at index, shifts that index's value and trailing elements to the right
    *prepend(item) - can use insert above at index 0
    *pop() - remove from end, return value
    *delete(index) - delete item at index, shifting all trailing elements left
    *remove(item) - looks for value and removes index holding it (even if in multiple places)
    *find(item) - looks for value and returns first index with that value, -1 if not found
    *resize(new_capacity) // private function
        when you reach capacity, resize to double the size
        when popping an item, if the size is 1/4 of capacity, resize to half

Time

    O(1) to add/remove at end (amortized for allocations for more space), index, or update
    O(n) to insert/remove elsewhere

Space

    contiguous in memory, so proximity helps performance
    space needed = (array capacity, which is >= n) * size of item, but even if 2n, still O(n)


*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Vector
{
	int size;
	int capacity;
	int *arr;
}Vector;

Vector* initVector()
{
	Vector* vector_t = (Vector*)malloc(sizeof(Vector));
	vector_t->size = 0;
	vector_t->capacity = 1;
	vector_t->arr = (int*)malloc(sizeof(int)*vector_t->capacity);
	return vector_t;
}

int size(Vector* vect)
{
	return vect->size;
}

int capacity(Vector* vect)
{
	return vect->capacity;
}

int isEmpty(Vector* vect)
{
	if(vect->size == 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int at(Vector* vect, int target)
{
	if (target > size(vect))
	{
		printf("Exiting tried to access out of bound index");
		return -999;
	}

	return vect->arr[target];
}

void display(Vector* vect)
{
	if(isEmpty(vect) == 1)
	{
		printf("EMPTY\n");
		printf("size: %d\n", size(vect));
		printf("capacity: %d\n\n", capacity(vect));
		return;
	}

	printf("size: %d\n", size(vect));
	printf("capacity: %d\n", capacity(vect));

	printf("[");
	for(int i = 0; i < size(vect); i++)
	{
		if(i == size(vect) - 1)
		{
			printf("%d", at(vect, i));
		}
		else
		{
			printf("%d, ", at(vect, i));
		}
	}
	printf("]\n\n");
}

void resize(Vector* vect)
{
	int new_capacity = vect->capacity * 2;
	int* temp = (int*)realloc(vect->arr, sizeof(int)* new_capacity);

	vect->arr = temp;
	vect->capacity = new_capacity;
}

void push(Vector* vect, int num)
{
	int cur_size = size(vect);
	int cur_capacity = capacity(vect);

	if(cur_size + 1 == cur_capacity)
	{
		resize(vect);
		cur_capacity = cur_capacity * 2;

		vect->arr[cur_size] = num;
		vect->size = cur_size + 1;
		vect->capacity = cur_capacity;
	}
	else
	{
		vect->arr[cur_size] = num;
		vect->size++;
	}
}

void insert(Vector* vect, int num, int index)
{
	int cur_size = size(vect);
	int cur_capacity = capacity(vect);

	if(index > cur_size)
	{
		printf("tried to insert out of bounds\n");
		return;
	}

	if(cur_size + 1 == cur_capacity)
	{
		resize(vect);
		vect->capacity = cur_capacity * 2;

		for(int i = cur_size; i > index; i--)
		{
			vect->arr[i] = vect->arr[i - 1]; 
		}

		vect->size++;
		vect->arr[index] = num;
	}
	else
	{
		for(int i = cur_size; i > index; i--)
		{
			vect->arr[i] = vect->arr[i - 1]; 
		}

		vect->size++;
		vect->arr[index] = num;
	}
}

void prepend(Vector* vect, int num)
{
	insert(vect, num, 0);
}

int pop(Vector* vect)
{
	int cur_size = size(vect);

	if (cur_size == 0)
	{
		printf("Cant POP vector is empty.\n");
		return -999;
	}


	vect->size = cur_size - 1;
	return at(vect, cur_size - 1);


}

void delete(Vector* vect, int index)
{
	int cur_size = size(vect);
	int cur_capacity = capacity(vect);

	if(index > cur_size)
	{
		printf("tried to delete out of bounds\n");
		return;
	}

	for(int i = index; i < cur_size; i++)
	{
		vect->arr[i - 1] = vect->arr[i];
	}

	vect->size--;
}

void removeVec(Vector* vect, int num)
{
	int cur = 0;
	int new_size = 0;

	for(int i = 0; i < vect->size; i++)
	{
		int cur_element = at(vect, i);

		if (cur_element != num)
		{
			vect->arr[cur] = cur_element;
			new_size++;
			cur++;
		}
	}
	vect->size = new_size;
}

int find(Vector* vect, int num)
{
	for(int i = 0; i < vect->size; i++)
	{
		if (at(vect, i) == num)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	//init vector
	Vector* vect = initVector();

	push(vect, 1);
	push(vect, 2);
	push(vect, 3);
	push(vect, 4);
	push(vect, 1);
	push(vect, 2);
	push(vect, 3);
	push(vect, 4);
	display(vect);

	printf("found at: %d\n",find(vect, 123));


	return 0;
}