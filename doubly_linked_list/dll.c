#include "dll.h"

#include <stdio.h>
#include <stdlib.h>

Node * node_init(int element)
{
	Node * temp = (Node*)malloc(sizeof(Node));

	if (!temp)
	{
		fprintf(stderr, "Allocation Error.\n");
		exit(EXIT_FAILURE);
	}

	temp->next = NULL;
	temp->prev = NULL;
	temp->data = element;

	return temp;
}

DoublyLinkedList * dll_init()
{
	DoublyLinkedList * dll = (struct DoublyLinkedList *)malloc(sizeof(struct DoublyLinkedList));

	if (!dll)
	{
		fprintf(stderr, "Allocation Error.\n");
		exit(EXIT_FAILURE);
	}

	Node * temp_head = node_init(-999);
	Node * temp_tail = node_init(-999);


	dll->head = temp_head;
	dll->tail = temp_tail;
	dll->head->next = dll->tail;
	dll->tail->prev = dll->head;

	return dll;
}

void dll_print(DoublyLinkedList * dll)
{
	Node * cur = dll->head->next;

	printf("[ NULL <-> ");
	while(cur != dll->tail)
	{
		printf("%d <-> ", cur->data);
		cur = cur->next;
	}
	printf("NULL ]\n\n");
}

void dll_free(DoublyLinkedList ** dll)
{
	printf("---Freeing DLL---\n");

	Node * cur = (*dll)->head;

	while(cur != NULL)
	{
		Node * temp = cur;
		cur = cur->next;
		free(temp);
	}

	free(*dll);
}

void dll_insert_front(int element, DoublyLinkedList ** dll)
{
	printf("---INSERTING %d TO FRONT OF DLL---\n", element);

	Node * new_node = node_init(element);

	Node * next_element = (*dll)->head->next;
	Node * head = (*dll)->head;

	new_node->next = next_element;
	new_node->prev = head;

	head->next = new_node;
	next_element->prev = new_node;

	dll_print(*dll);
}

void dll_insert_back(int element, DoublyLinkedList ** dll)
{
	printf("---INSERTING %d TO BACK OF DLL---\n", element);

	Node * new_node = node_init(element);

	Node * prev_element = (*dll)->tail->prev;
	Node * tail = (*dll)->tail;

	new_node->next = tail;
	new_node->prev = prev_element;

	tail->prev = new_node;
	prev_element->next = new_node;

	dll_print(*dll);
}

void dll_insert_at(int element, int index, DoublyLinkedList ** dll)
{
	printf("---INSERTING %d TO INDEX %d OF DLL---\n", element, index);

	if (index < 0)
	{
		printf("OUT OF BOUNDS ERROR!\n\n");
		return;
	}

	Node * new_node = node_init(element);

	Node * cur = (*dll)->head->next;
	Node * prev = (*dll)->head;
	
	int counter = 0;

	while (cur != (*dll)->tail && counter < index)
	{
		prev = cur;
		cur = cur->next;
		counter += 1;
	}

	if(counter == index)
	{
		new_node->prev = prev;
		new_node->next = cur;

		prev->next = new_node;
		cur->prev = new_node;
	}
	else
	{
		printf("OUT OF BOUNDS ERROR\n\n");
		free(new_node);
		return;
	}

	dll_print(*dll);
}

void dll_delete_front(DoublyLinkedList ** dll)
{
	printf("---DELETING FROM FRONT OF DLL---\n");

	if ((*dll)->head->next == (*dll)->tail)
	{
		printf("DLL IS EMPTY!\n\n");
		return;
	}

	Node * prev = (*dll)->head;
	Node * cur = (*dll)->head->next;
	Node * next = (*dll)->head->next->next;

	prev->next = next;
	next->prev = prev;

	free(cur);

	dll_print(*dll);
}

void dll_delete_back(DoublyLinkedList ** dll)
{
	printf("---DELETING FROM BACK OF DLL---\n");

	if ((*dll)->head->next == (*dll)->tail)
	{
		printf("DLL IS EMPTY!\n\n");
		return;
	}

	Node * prev = (*dll)->tail->prev->prev;
	Node * cur = (*dll)->tail->prev;
	Node * next = (*dll)->tail;

	next->prev = prev;
	prev->next = next;

	free(cur);

	dll_print(*dll);
}

void dll_delete_at(int index, DoublyLinkedList ** dll)
{
	printf("---DELETING INDEX %d OF DLL---\n", index);

	if (index < 0)
	{
		printf("OUT OF BOUNDS ERROR!\n\n");
		return;
	}

	Node * cur = (*dll)->head->next;
	Node * prev = (*dll)->head;
	
	int counter = 0;

	while (cur != (*dll)->tail && counter < index)
	{
		prev = cur;
		cur = cur->next;
		counter += 1;
	}

	if(counter == index && cur != (*dll)->tail)
	{
		prev->next = cur->next;
		cur->next->prev = prev;
		free(cur);
	}
	else
	{
		printf("OUT OF BOUNDS ERROR!\n\n");
		return;
	}

	dll_print(*dll);
}