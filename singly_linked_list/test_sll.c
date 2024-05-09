#include "test_sll.h"
#include "sll.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


void run_all_tests()
{
	test_push_front();
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
}