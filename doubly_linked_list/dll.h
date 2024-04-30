typedef struct Node
{
	struct Node * next;
	struct Node * prev;
	int data;
}Node;

typedef struct DoublyLinkedList
{
	struct Node * head;
	struct Node * tail;
}DoublyLinkedList;

Node * node_init(int element);

DoublyLinkedList * dll_init();

void dll_print(DoublyLinkedList * dll);

void dll_free(DoublyLinkedList ** dll);

void dll_insert_front(int element, DoublyLinkedList ** dll);

void dll_insert_back(int element, DoublyLinkedList ** dll);

void dll_insert_at(int element, int index, DoublyLinkedList ** dll);

void dll_delete_front(DoublyLinkedList ** dll);

void dll_delete_back(DoublyLinkedList ** dll);

void dll_delete_at(int index, DoublyLinkedList ** dll);

