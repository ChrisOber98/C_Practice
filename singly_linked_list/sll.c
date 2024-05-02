#include "sll.h"

#include <stdio.h>
#include <stdlib.h>

/*
	* Insertion at start = O(1)
	* Insertion at end = O(1)
	* Insertion in middle = O(1)
	* Deletion from start = O(1)
	* Deletion at end = O(1)
	* Deletion from middle = O(1)
	* Traversing = O(N)
	* Accessing an element = O(N)
*/

Node * node_init(int element)
{
	Node * temp = (Node*)malloc(sizeof(Node));

	temp->next = NULL;
	temp->data = element;

	return temp;
}

void sll_print(Node * head)
{
	Node * temp = head;

	while(temp != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n\n");
}

void sll_free(Node ** head)
{
	printf("---Freeing SLL---\n");


	Node * cur = *head;

	while(cur != NULL)
	{
		Node * temp = cur;
		cur = cur->next;
		free(temp);
	}

	*head = NULL;
}

void sll_insert_start(int element, Node ** head)
{
	printf("---Inserting at start---\n");

	Node * temp = node_init(element);

	if (*head == NULL)
	{
		*head = temp;
		sll_print(*head);
		return;
	}

	temp->next = *head;
	*head = temp;

	sll_print(*head);
}

void sll_insert_end(int element, Node ** head)
{
	printf("---Inserting at end--\n");

	Node * temp = node_init(element);

	if (*head == NULL)
	{
		*head = temp;
		sll_print(*head);
		return;
	}

	Node * cur = *head;
	Node * prev = NULL;

	while (cur != NULL)
	{
		prev = cur;
		cur = cur->next;
	}

	prev->next = temp;

	sll_print(*head);
}

void sll_insert_at(int index, int element, Node ** head)
{
	printf("---Inserting at--\n");

	int counter = 0;

	Node * temp = node_init(element);

	if (index < 0)
	{
		printf("Out of bound error.\n\n");
		return;
	}

	if (*head == NULL && index == 0)
	{
		*head = temp;
		sll_print(*head);
		return;
	}

	Node * cur = *head;
	Node * prev = NULL;

	while (cur != NULL && counter < index)
	{
		prev = cur;
		cur = cur->next;
		counter += 1;
	}

	if (counter == index)
	{
		prev->next = temp;
		temp->next = cur;
		sll_print(*head);
	}
	else
	{
		printf("Out of bound error.\n\n");
		return;		
	}
}

void sll_delete_start(Node ** head)
{
	printf("---Deleting at start---\n");

	if (*head == NULL)
	{
		printf("SLL is Empty.\n\n");
		return;
	}

	Node * temp = *head;

	Node * cur = *head;

	*head = cur->next;

	free(temp);

	sll_print(*head);
}

void sll_delete_end(Node ** head)
{
	printf("---Deleting at end---\n");

	if (*head == NULL)
	{
		printf("SLL is Empty.\n\n");
		return;
	}

	Node * cur = *head;
	Node * prev = NULL;

	if (cur->next == NULL)
	{
		Node * temp = *head;
		*head = NULL;
		free(head);
		sll_print(*head);
		return;
	}

	while (cur->next != NULL)
	{
		prev = cur;
		cur = cur->next;
	}

	prev->next = NULL;
	free(cur);

	sll_print(*head);
}

void sll_delete_at_end(Node ** head)
{
	printf("---Deleting at_end---\n");

	if (*head == NULL)
	{
		printf("SLL is Empty.\n\n");
		return;
	}

	Node * cur = *head;
	Node * prev = NULL;

	if (cur->next == NULL)
	{
		Node * temp = *head;
		*head = NULL;
		free(temp);
		sll_print(*head);
		return;
	}

	while (cur->next != NULL)
	{
		prev = cur;
		cur = cur->next;
	}

	prev->next = NULL;
	free(cur);
	sll_print(*head);
}

void sll_delete_at(int index, Node ** head)
{
	printf("---Deleting at---\n");

	int counter = 0;

	Node * cur = *head;
	Node * prev = NULL;

	if (index < 0)
	{
		printf("Out of bound error.\n\n");
		return;
	}

	if (*head == NULL)
	{
		printf("SLL is Empty.\n\n");
		return;
	}

	if (index == 0)
	{
		sll_delete_start(&(*head));
		return;
	}

	while (cur != NULL && counter < index)
	{
		prev = cur;
		cur = cur->next;
		counter += 1;
	}

	if (counter == index)
	{
		Node* temp = cur;
		prev->next = cur->next;
		free(cur);
		sll_print(*head);
	}
	else
	{
		printf("Out of bound error.\n\n");
		return;		
	}

}