#ifndef SLL_H_
#define SLL_H_

typedef struct Node
{
	struct Node * next;
	int data;
}Node;

Node * node_init(int element);

void sll_print(Node * head);

void sll_free(Node ** head);

void sll_insert_start(int element, Node ** head);

void sll_insert_end(int element, Node ** head);

void sll_insert_at(int index, int element, Node ** head);

void sll_delete_start(Node ** head);

void sll_delete_end(Node ** head);

void sll_delete_at_end(Node ** head);

void sll_delete_at(int index, Node ** head);


#endif