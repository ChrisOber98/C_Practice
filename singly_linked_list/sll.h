#ifndef SLL_H_
#define SLL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
	struct Node * next;
	int data;
}Node;

//-------------Constructor and deconstructor---------------------
Node * node_init(int element);
void sll_deinit(Node ** head);

//------size() - returns the number of data elements in the list------
int sll_size(Node * head);

//------empty() - bool returns true if empty-----------
bool sll_empty(Node * head);

//------value_at(index) - returns the value of the nth item (starting at 0 for first)
bool sll_at(int index, int * ret, Node * head);

//-----push_front(value) - adds an item to the front of the list-----
void sll_push_front(int element, Node ** head);

//-----pop_front() - remove the front item and return its value
bool sll_pop_front(int * ret, Node ** head);

//-----push_back(value) - adds an item at the end-----
void sll_push_back(int element, Node ** head);

//-----pop_back() - removes end item and returns its value-----
bool sll_pop_back(int * ret, Node ** head);

//-----front() - get the value of the front item-----
bool sll_front(int * ret, Node * head);

//-----back() - get the value of the end item-----
bool sll_back(int * ret, Node * head);

//-----insert(index, value) - insert value at index, so the current item at that index is pointed to by the new item at the index
bool sll_insert(int index, int element, Node ** head);

//-----erase(index) - removes node at given index-----
bool sll_erase(int index, Node ** head);

//---print() - prints readable versions of linked list
void sll_print(Node * head);

//-----value_n_from_end(n) - returns the value of the node at the nth position from the end of the list
bool sll_value_n_from_end(int val, int * ret, Node * head);

//-----reverse() - reverses the list-----
void sll_reverse(Node ** head);


#endif