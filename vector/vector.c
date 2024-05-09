/*
	! size() - number of items
	! capacity() - number of items it can hold
	! is_empty()
	! at(index) - returns the item at a given index, blows up if index out of bounds
	! push(item)
	! insert(index, item) - inserts item at index, shifts that index's value and trailing elements to the right
	! prepend(item) - can use insert above at index 0
	! pop() - remove from end, return value
	! delete(index) - delete item at index, shifting all trailing elements left
	! remove(item) - looks for value and removes index holding it (even if in multiple places)
	! find(item) - looks for value and returns first index with that value, -1 if not found
	! resize(new_capacity) // private function
    	when you reach capacity, resize to double the size
    	when popping an item, if the size is 1/4 of capacity, resize to half


*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vector.h"

//-------------Constructor and deconstructor---------------------
Vector * vector_init()
{
	//Create Temp vector
	Vector * temp = malloc(sizeof(Vector));

	//Make Sure Temp vector allocated successfuly
	if(!temp)
	{
		//Handle failed allocation
		fprintf(stderr, "Allocation Error");
		exit(EXIT_FAILURE);
	}

	//Set Vector varibles to default
	temp->capacity = 1;
	temp->size = 0;

	//Create Array within Vector
	temp->arr = malloc(sizeof(int) * temp->capacity);

	//Check To Make Sure array within vector allocated correctly
	if(!temp)
	{
		//Handle failed allocation
		fprintf(stderr, "Allocation Error");
		exit(EXIT_FAILURE);
	}

	//Return Deafult Vector
	return temp;
}

void vector_deinit(Vector * vect)
{
	//FREE EVERYTHING!
	free(vect->arr);
	free(vect);
}

//---------------------size() - Return number of items---------------------
int vector_size(Vector * vect)
{
	return vect->size;
}

//---------------------capacity() - number of items it can hold---------------------
int vector_capacity(Vector * vect)
{
	return vect->capacity;
}

//----------is_empty() - return True if vector is empty false otherwise----------
bool vector_is_empty(Vector * vect)
{
	if(vector_size(vect) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//----------resize() - double capacity and realloc memory for vector----------
void vector_resize(Vector * vect)
{
	//Double capacity
	vect->capacity = vect->capacity * 2;

	//Realloc memory for array using new capacity
	vect->arr = realloc(vect->arr, sizeof(int) * vect->capacity);

	//Check Realloc was success
	if (!vect)
	{
		//Handle allocation Error
		fprintf(stderr, "Allocation Error");
		exit(EXIT_FAILURE);			
	}
}

//----------push() - place element at back of array----------
void vector_push(int element, Vector * vect)
{
	//Check if resize is needed
	if(vect->size == vect->capacity)
	{
		vector_resize(vect);
	}

	//Get index for insertion
	int index = vect->size;

	//Place New element in at insertion point
	vect->arr[index] = element;

	//Update Size
	vect->size += 1;
}

//----------at(index, return val) - returns the item at a given index, returns -1 if index out of bounds----------
int vector_at(int index, int * value, Vector * vect)
{
	//Check for index out of bounds
	if (index < 0 || index >= vect->size)
	{
		//Return -1 if out of bounds
		return -1;
	}

	//Return value to value parameter
	*value = vect->arr[index];

	//Return 1 on success
	return 1;
}

//----------displays content of vector---------
void vector_display(Vector * vect)
{
	//Format and display each index in vector
	printf("arr: [ ");
	for(int i = 0; i < vect->size; i++)
	{
		printf("%d ", vect->arr[i]);
	}
	printf("]\n");
	printf("cap: %d\n", vect->capacity);
	printf("size: %d\n\n", vect->size);
}

//----insert(index, item) - inserts item at index, shifts that index's value and trailing elements to the right----
//return -1 on out of bunds error 1 on success
int vector_insert(int index, int element, Vector * vect)
{
	//Check if out of bounds
	if(index < 0 || index > vect->size)
	{
		//Return -1 on out of bounds
		return -1;
	}

	//Check if Vector is empty
	if(vect->size == 0)
	{
		//If Empty add element to beggining and update array + size
		vect->arr[index] = element;
		vect->size++;
		return 1;		
	}

	//Check if resize is needed (capacity == size)
	if(vect->capacity == vect->size)
	{
		//Resize if needed
		vector_resize(vect);
	}

	//Shift all values starting from the end to index by 1
	for (int i = vect->size; i >= index; i--)
	{
		//Right shift by 1
		vect->arr[i + 1] = vect->arr[i];
	}

	//Place value at index that has been freed by right shifting values
	vect->arr[index] = element;
	//Increase Size
	vect->size++;

	//Return success
	return 1;
}

//-----prepend(item) - can use insert above at index 0------
void vector_prepend(int element, Vector * vect)
{
	vector_insert(0, element, vect);
}

//------pop() - remove from end, return value return 1 on success -1 on failure-------
int vector_pop(int * value, Vector * vect)
{
	//Check if is empty
	if(vector_is_empty(vect))
	{
		//Return -1 if empty
		return -1;
	}

	//Place return value in parameter
	*value = vect->arr[vect->size - 1];

	//Decrease size by 1
	vect->size -= 1;

	//return 1 on success
	return 1;
}

//-----delete item at index, shifting all trailing elements left-----
int vector_delete(int index, int * value, Vector * vect)
{
	//Check for out of bounds error or if vector is empty
	if(index < 0 || index >= vect->size || vector_is_empty(vect))
	{
		//Return -1 at index 
		return -1;
	}

	//If there is one element in the array
	if(vect->size == 1)
	{
		//Store return vallue
		*value = vect->arr[0];

		//Decrease Size
		vect->size--;

		if(vector_size(vect) / 4 )

		//Return 1 on success
		return 1;		
	}

	//If not one element store return value
	*value = vect->arr[index];

	//Left shift elements starting at index until the end of array
	for (int i = index; i < vect->size - 1; i++)
	{
		//Left shift value
		vect->arr[i] = vect->arr[i + 1];
	}

	//Decrease Size
	vect->size--;

	return 1;
}

//-----remove(item) - looks for value and removes index holding it (even if in multiple places)-----
int vector_remove(int value, Vector * vect)
{
	//Check if vector is empty
	if(vector_is_empty(vect))
	{
		return -1;
	}

	//Return Value for parameter
	int ret;

	//Temp Value to hold garbage value coming from delete
	int temp;

	//Iterate over the items in the array looking for matching indexs in reverse order to 
	//Accomadate for left shifting the delete function will do
	for(int i = vect->size; i >= 0; i--)
	{
		//Check to make sure value is at correct index
		if(vector_at(i, &ret, vect) == 1)
		{
			//Check to see if value is what we are looking for
			if(ret == value)
			{
				//If it is then delete it
				vector_delete(i, &temp, vect);				
			}
		}
	}

	//Return 1 on success
	return 1;
}

/*
	------resize(new_capacity) when you reach capacity if the size is 1/4 of capacity, resize to half-------
*/
void vector_desize(Vector * vect)
{
	//Double capacity
	vect->capacity = vect->capacity / 2;

	//Realloc memory for array using new capacity
	vect->arr = realloc(vect->arr, sizeof(int) * vect->capacity);

	//Check Realloc was success
	if (!vect)
	{
		//Handle allocation Error
		fprintf(stderr, "Allocation Error");
		exit(EXIT_FAILURE);			
	}
}


