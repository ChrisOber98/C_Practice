#include "test_sll.h"
#include "sll.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


void run_all_tests()
{
	test_push_front();
	test_pop_front();
	test_push_back();
	test_pop_back();
	test_insert();
	test_erase();
}

void test_push_front()
{
	printf("-----Testing Push Front-----\n");

	Node * head = NULL;

	int ret;

	sll_push_front(5, &head);
	assert(sll_size(head) == 1);
	assert(sll_front(&ret, head) == 1);
	assert(ret == 5);

	sll_push_front(4, &head);
	assert(sll_size(head) == 2);
	assert(sll_front(&ret, head) == 1);
	assert(ret == 4);

	sll_deinit(&head);
}

void test_pop_front()
{
	printf("-----Testing Pop Front-----\n");

	Node * head = NULL;

	int ret;

	sll_push_front(5, &head);
	assert(sll_size(head) == 1);
	assert(sll_front(&ret, head) == 1);
	assert(ret == 5);

	sll_push_front(4, &head);
	assert(sll_size(head) == 2);
	assert(sll_front(&ret, head) == 1);
	assert(ret == 4);

	assert(sll_pop_front(&ret, &head) == true);
	assert(sll_size(head) == 1);
	assert(ret == 4);
	assert(sll_front(&ret, head) == 1);
	assert(ret == 5);

	assert(sll_pop_front(&ret, &head) == true);
	assert(sll_size(head) == 0);
	assert(ret == 5);

	assert(sll_pop_front(&ret, &head) == false);

	sll_deinit(&head);
}

void test_push_back()
{
	printf("-----Testing Push Back-----\n");

	Node * head = NULL;

	int ret;

	sll_push_back(5, &head);
	assert(sll_size(head) == 1);
	assert(sll_back(&ret, head) == 1);
	assert(ret == 5);

	sll_push_back(4, &head);
	assert(sll_size(head) == 2);
	assert(sll_back(&ret, head) == 1);
	assert(ret == 4);

	sll_deinit(&head);
}

void test_pop_back()
{
	printf("-----Testing Pop Back-----\n");

	Node * head = NULL;

	int ret;

	sll_push_back(5, &head);
	assert(sll_size(head) == 1);
	assert(sll_back(&ret, head) == 1);
	assert(ret == 5);

	sll_push_back(4, &head);
	assert(sll_size(head) == 2);
	assert(sll_back(&ret, head) == 1);
	assert(ret == 4);

	assert(sll_pop_back(&ret, &head) == true);
	assert(sll_size(head) == 1);
	assert(ret == 4);
	assert(sll_front(&ret, head) == 1);
	assert(ret == 5);

	assert(sll_pop_back(&ret, &head) == true);
	assert(sll_size(head) == 0);
	assert(ret == 5);

	assert(sll_pop_back(&ret, &head) == false);

	sll_deinit(&head);
}

void test_insert()
{
	printf("-----Testing Insert-----\n");

	Node * head = NULL;

	int ret;

	assert(sll_insert(0, 5, &head) == true);
	assert(sll_size(head) == 1);
	assert(sll_at(0, &ret, head) == true);
	assert(ret == 5);

	assert(sll_insert(0, 1, &head) == true);
	assert(sll_size(head) == 2);
	assert(sll_at(0, &ret, head) == true);
	assert(ret == 1);

	assert(sll_insert(2, 9, &head) == true);
	assert(sll_size(head) == 3);
	assert(sll_at(2, &ret, head) == true);
	assert(ret == 9);

	assert(sll_insert(3, 12, &head) == true);
	assert(sll_size(head) == 4);
	assert(sll_at(3, &ret, head) == true);
	assert(ret == 12);

	assert(sll_insert(123, 12, &head) == false);
	assert(sll_insert(-1, 12, &head) == false);

	sll_deinit(&head);	
}

void test_erase()
{
	printf("-----Testing Erase----\n");

	Node * head = NULL;

	int ret;

	assert(sll_insert(0, 5, &head) == true);
	assert(sll_size(head) == 1);
	assert(sll_at(0, &ret, head) == true);
	assert(ret == 5);

	assert(sll_insert(0, 1, &head) == true);
	assert(sll_size(head) == 2);
	assert(sll_at(0, &ret, head) == true);
	assert(ret == 1);

	assert(sll_insert(2, 9, &head) == true);
	assert(sll_size(head) == 3);
	assert(sll_at(2, &ret, head) == true);
	assert(ret == 9);

	assert(sll_insert(3, 12, &head) == true);
	assert(sll_size(head) == 4);
	assert(sll_at(3, &ret, head) == true);
	assert(ret == 12);

	assert(sll_erase(0, &head) == true);
	assert(sll_size(head) == 3);
	assert(sll_at(0, &ret, head) == true);
	assert(ret == 5);

	assert(sll_erase(2, &head) == true);
	assert(sll_size(head) == 2);
	assert(sll_at(1, &ret, head) == true);
	assert(ret == 9);

	assert(sll_erase(-1, &head) == false);
	assert(sll_erase(100, &head) == false);

	assert(sll_erase(1, &head) == true);
	assert(sll_size(head) == 1);
	assert(sll_at(0, &ret, head) == true);
	assert(ret == 5);

	assert(sll_erase(0, &head) == true);
	assert(sll_size(head) == 0);
	assert(ret == 5);

	sll_deinit(&head);	
}