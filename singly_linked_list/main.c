#include "sll.h"

#include <stdlib.h>

int main(int argc, char ** argv)
{
	Node * head = NULL;

	sll_insert_start(12, &head);
	sll_insert_start(101, &head);

	sll_delete_at(1, &head);

	sll_insert_start(1, &head);
	sll_insert_start(3, &head);
	sll_insert_start(4, &head);	
	sll_insert_start(5, &head);

	sll_delete_at(2, &head);
	sll_delete_at(3, &head);
	sll_delete_at(123123, &head);
	sll_delete_at(0, &head);
	sll_delete_at(0, &head);
	sll_delete_at(0, &head);

	sll_delete_at(0, &head);

	sll_free(&head);

	return 0;
}