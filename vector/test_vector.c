#include "test_vector.h"
#include "vector.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void run_all_tests()
{
	test_is_empty();
	test_push();
	test_at();
	test_resize();
	test_insert();
	test_pop();
	test_delete();
	test_remove();
	test_desize();
}

void test_is_empty()
{
	printf("-----Testing Is Empty-----\n");

	Vector * test_vector = vector_init();

	//Testing Empty Vector
	assert(vector_is_empty(test_vector) == true);

	//Testing Non Empty Vector
	vector_push(12, test_vector);
	assert(vector_is_empty(test_vector) == false);

	vector_deinit(test_vector);
	printf("DONE\n\n");
}

void test_push()
{
	printf("-----Testing Push-----\n");

	Vector * test_vector = vector_init();
	int ret;

	//Test when array is empty before push
	vector_push(1, test_vector);
	assert(vector_at(0, &ret, test_vector) == 1);
	assert(ret == 1);

	//Test More Pushes
	vector_push(2, test_vector);
	assert(vector_at(1, &ret, test_vector) == 1);
	assert(ret == 2);
	vector_push(3, test_vector);
	assert(vector_at(2, &ret, test_vector) == 1);
	assert(ret == 3);
	vector_push(4, test_vector);
	assert(vector_at(3, &ret, test_vector) == 1);
	assert(ret == 4);
	vector_push(5, test_vector);
	assert(vector_at(4, &ret, test_vector) == 1);
	assert(ret == 5);
	vector_deinit(test_vector);
	printf("DONE\n\n");
}

void test_at()
{
	printf("-----Testing At-----\n");	

	Vector * test_vector = vector_init();
	int ret;

	//Test When array is empty return -1
	assert(vector_at(123, &ret, test_vector) == -1);

	//Test When 1 element in array
	vector_push(1, test_vector);
	assert(vector_at(0, &ret, test_vector) == 1);
	assert(ret == 1);

	//Test edge cases after resize
	vector_push(2, test_vector);
	vector_push(3, test_vector);
	vector_push(4, test_vector);
	vector_push(5, test_vector);
	assert(vector_at(5, &ret, test_vector) == -1);
	assert(vector_at(-1, &ret, test_vector) == -1);
	assert(vector_at(2, &ret, test_vector) == 1);
	assert(ret == 3);
	vector_deinit(test_vector);
	printf("DONE\n\n");
}

void test_resize()
{
	printf("-----Testing Resize-----\n");

	Vector * test_vector = vector_init();

	//Test resizes
	assert(vector_capacity(test_vector) == 1);
	vector_resize(test_vector);
	assert(vector_capacity(test_vector) == 2);
	vector_resize(test_vector);
	assert(vector_capacity(test_vector) == 4);
	vector_resize(test_vector);
	assert(vector_capacity(test_vector) == 8);

	vector_deinit(test_vector);
	printf("DONE\n\n");
}

void test_insert()
{
	printf("-----Testing insert-----\n");

	Vector * test_vector = vector_init();
	int ret;

	//Test out of bounds when empty
	assert(vector_insert(-1, 1, test_vector) == -1);
	assert(vector_insert(1, 1, test_vector) == -1);

	//Test inserting at front
	assert(vector_insert(0, 1, test_vector) == 1);
	assert(vector_at(0, &ret, test_vector) == 1);
	assert(ret == 1);
	assert(vector_insert(0, 2, test_vector) == 1);
	assert(vector_at(0, &ret, test_vector) == 1);
	assert(ret == 2);
	assert(vector_insert(0, 3, test_vector) == 1);
	assert(vector_at(0, &ret, test_vector) == 1);
	assert(ret == 3);

	//Test out of bounds when not empty
	assert(vector_insert(-1, 1, test_vector) == -1);
	assert(vector_insert(4, 1, test_vector) == -1);

	Vector * test_vector_2 = vector_init();

	//Test inserting at back
	assert(vector_insert(0, 1, test_vector_2) == 1);
	assert(vector_at(0, &ret, test_vector_2) == 1);
	assert(ret == 1);
	assert(vector_insert(1, 2, test_vector_2) == 1);
	assert(vector_at(1, &ret, test_vector_2) == 1);
	assert(ret == 2);
	assert(vector_insert(2, 3, test_vector_2) == 1);
	assert(vector_at(2, &ret, test_vector_2) == 1);
	assert(ret == 3);

	Vector * test_vector_3 = vector_init();

	//Test inserting middle
	assert(vector_insert(0, 1, test_vector_3) == 1);
	assert(vector_at(0, &ret, test_vector_3) == 1);
	assert(ret == 1);
	assert(vector_insert(1, 2, test_vector_3) == 1);
	assert(vector_at(1, &ret, test_vector_3) == 1);
	assert(ret == 2);
	assert(vector_insert(2, 3, test_vector_3) == 1);
	assert(vector_at(2, &ret, test_vector_3) == 1);
	assert(ret == 3);
	assert(vector_insert(1, 12, test_vector_3) == 1);
	assert(vector_at(1, &ret, test_vector_3) == 1);
	assert(ret == 12);
	assert(vector_insert(1, 420, test_vector_3) == 1);
	assert(vector_at(1, &ret, test_vector_3) == 1);
	assert(ret == 420);
	assert(vector_insert(2, 330, test_vector_3) == 1);
	assert(vector_at(2, &ret, test_vector_3) == 1);
	assert(ret == 330);			

	vector_deinit(test_vector);
	vector_deinit(test_vector_2);
	vector_deinit(test_vector_3);
	printf("DONE\n\n");	
}

void test_pop()
{
	printf("-----Testing pop-----\n");	

	Vector * test_vector = vector_init();
	int ret;

	//Push random values to test
	vector_push(2, test_vector);
	vector_push(3, test_vector);
	vector_push(4, test_vector);
	vector_push(5, test_vector);

	//Pop some values
	assert(vector_pop(&ret, test_vector) == 1);
	assert(ret == 5);
	assert(vector_pop(&ret, test_vector) == 1);
	assert(ret == 4);
	assert(vector_pop(&ret, test_vector) == 1);
	assert(ret == 3);
	assert(vector_pop(&ret, test_vector) == 1);
	assert(ret == 2);

	//Pop when empty
	assert(vector_pop(&ret, test_vector) == -1);

	vector_deinit(test_vector);
	printf("DONE\n\n");
}

void test_delete()
{
	printf("-----Testing delete-----\n");

	Vector * test_vector = vector_init();
	int ret;

	//Test out of bounds when empty
	assert(vector_delete(-1, &ret, test_vector) == -1);
	assert(vector_delete(1, &ret, test_vector) == -1);

	//Push Random data
	vector_push(2, test_vector);
	vector_push(3, test_vector);
	vector_push(4, test_vector);
	vector_push(5, test_vector);

	//Test deleting at front
	assert(vector_delete(0, &ret, test_vector) == 1);
	assert(ret == 2);
	assert(vector_delete(0, &ret, test_vector) == 1);
	assert(ret == 3);
	assert(vector_delete(0, &ret, test_vector) == 1);
	assert(ret == 4);

	//Test out of bounds when not empty
	assert(vector_delete(-1, &ret, test_vector) == -1);
	assert(vector_delete(1, &ret, test_vector) == -1);

	Vector * test_vector_2 = vector_init();

	//Push Random data
	vector_push(2, test_vector_2);
	vector_push(3, test_vector_2);
	vector_push(4, test_vector_2);
	vector_push(5, test_vector_2);

	//Test deleting at back
	assert(vector_delete(3, &ret, test_vector_2) == 1);
	assert(ret == 5);
	assert(vector_delete(2, &ret, test_vector_2) == 1);
	assert(ret == 4);
	assert(vector_delete(1, &ret, test_vector_2) == 1);
	assert(ret == 3);

	Vector * test_vector_3 = vector_init();

	//Push Random data
	vector_push(2, test_vector_3);
	vector_push(3, test_vector_3);
	vector_push(4, test_vector_3);
	vector_push(5, test_vector_3);

	//Test inserting middle	
	assert(vector_delete(1, &ret, test_vector_3) == 1);
	assert(ret == 3);
	assert(vector_delete(1, &ret, test_vector_3) == 1);
	assert(ret == 4);
	assert(vector_delete(1, &ret, test_vector_3) == 1);
	assert(ret == 5);	

	vector_deinit(test_vector);
	vector_deinit(test_vector_2);
	vector_deinit(test_vector_3);
	printf("DONE\n\n");	
}

void test_remove()
{
	printf("-----Testing Remove-----\n");

	Vector * test_vector = vector_init();
	int ret;

	//Push Random data
	vector_push(2, test_vector);
	vector_push(2, test_vector);
	vector_push(23, test_vector);
	vector_push(34, test_vector);
	vector_push(45, test_vector);
	vector_push(11, test_vector);	
	vector_push(2, test_vector);
	vector_push(10, test_vector);	

	//Test Removal
	assert(vector_remove(2, test_vector) == 1);
	assert(vector_at(0, &ret, test_vector) == 1);
	assert(ret == 23);
	assert(vector_at(1, &ret, test_vector) == 1);
	assert(ret == 34);
	assert(vector_at(2, &ret, test_vector) == 1);
	assert(ret == 45);
	assert(vector_at(3, &ret, test_vector) == 1);
	assert(ret == 11);
	assert(vector_at(4, &ret, test_vector) == 1);
	assert(ret == 10);

	vector_deinit(test_vector);
	printf("DONE\n\n");	
}

void test_desize()
{
	printf("-----Testing Resize-----\n");

	Vector * test_vector = vector_init();

	//Test resizes
	assert(vector_capacity(test_vector) == 1);
	vector_resize(test_vector);
	assert(vector_capacity(test_vector) == 2);
	vector_resize(test_vector);
	assert(vector_capacity(test_vector) == 4);
	vector_resize(test_vector);
	assert(vector_capacity(test_vector) == 8);

	//Test desize
	assert(vector_capacity(test_vector) == 8);
	vector_desize(test_vector);
	assert(vector_capacity(test_vector) == 4);
	vector_desize(test_vector);
	assert(vector_capacity(test_vector) == 2);
	vector_desize(test_vector);
	assert(vector_capacity(test_vector) == 1);

	

	vector_deinit(test_vector);
	printf("DONE\n\n");	
}