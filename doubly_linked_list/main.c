/*
	* Insertion at start = O(1)
	* Insertion at end = O(1)
	* Insertion in middle = O(1)
	* Deletion from start = O(1)
	* Deletion at end = O(1)
	* Deletion from middle = O(1)
	* Traversing = O(N)
	- Accessing an element = O(N)
*/

#include "dll.h"

int main(int argc, char ** argv)
{
	DoublyLinkedList * dll = dll_init();

	dll_print(dll);

	dll_insert_front(1, &dll);
	dll_insert_front(2, &dll);
	dll_insert_front(3, &dll);

	dll_insert_back(5, &dll);
	dll_insert_back(6, &dll);
	dll_insert_back(7, &dll);

	dll_insert_at(123, 2, &dll);
	dll_insert_at(456, 0, &dll);
	dll_insert_at(456, 9, &dll);
	dll_insert_at(345, 8, &dll);

	dll_delete_front(&dll);
	dll_delete_front(&dll);

	dll_delete_back(&dll);
	dll_delete_back(&dll);

	dll_delete_at(1, &dll);
	dll_delete_at(3, &dll);
	dll_delete_at(0, &dll);
	dll_delete_at(-123, &dll);
	dll_delete_at(2, &dll);

	dll_free(&dll);

	return 0;
}