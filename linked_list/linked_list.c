/*
    *size() - returns the number of data elements in the list
    *empty() - bool returns true if empty
    *value_at(index) - returns the value of the nth item (starting at 0 for first)
    *push_front(value) - adds an item to the front of the list
    *pop_front() - remove the front item and return its value
    *push_back(value) - adds an item at the end
    *pop_back() - removes end item and returns its value
    *front() - get the value of the front item
    *back() - get the value of the end item
    *insert(index, value) - insert value at index, so the current item at that index is pointed to by the new item at the index
    *erase(index) - removes node at given index
    *value_n_from_end(n) - returns the value of the node at the nth position from the end of the list
    *reverse() - reverses the list
    *remove_value(value) - removes the first item in the list with this value
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int val;
    struct Node * next;
} Node;

Node* initNode(int num)
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->val = num;
    head->next = NULL;
    return head;
}

int size(Node* head)
{
    int size = 0;

    while(head != NULL)
    {
        size++;
        head = head->next;
    } 

    return size;
}

int empty(Node* head)
{
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void display(Node* head)
{
    Node* cur = head;

    if (cur == NULL)
    {
        printf("NULL\n");
        printf("Size: %d\n", size(head));
        return;
    }

    while(cur != NULL)
    {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }

    printf("NULL\n");
    printf("Size: %d\n", size(head));

}

int value_at(Node* head, int index)
{
    int count = 0;

    Node* cur = head;

    while(cur != NULL && count != index)
    {
        cur = cur->next;
        count++;
    }

    if (cur == NULL)
    {
        return -1;
    }
    else
    {
        return cur->val;
    }
}

void push_front(Node** head, int num)
{
    Node* new_node = initNode(num);

    new_node->next = *head;
    *head = new_node; 
}

int pop_front(Node** head)
{
    if(*head == NULL)
    {
        printf("CANT POP FRONT LINKED LIST IS EMPTY!\n");
        return -999;
    }
    Node* temp = *head;
    int temp_val = temp->val;
    *head = (*head)->next;
    free(temp);
    return temp_val;
}

void push_back(Node** head, int num)
{
    Node* new_node = initNode(num);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    Node* cur = *head;
    Node* prev = NULL;

    while (cur != NULL)
    {
        prev = cur;
        cur = cur->next;
    }

    if (prev == NULL)
    {
        (*head)->next = new_node;
    }
    else
    {
        prev->next = new_node;
    }
}

int pop_back(Node** head)
{
    //Check if List is Empty
    if (*head == NULL)
    {
        printf("CAN NOT POP_BACK LINKED LIST IS EMPTY\n");
        return -999;
    }

    //Check if only one item in list
    //if true return value and set head to NULL
    if ((*head)->next == NULL)
    {
        int val = (*head)->val;
        Node* temp = *head;
        *head = NULL;
        free(temp);
        return val;
    }

    Node* cur = *head;
    Node* prev = NULL;

    //Find last and 2nd to last nodes
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    } 

    //Return val of last node and set 2nd to last node
    //as new last node by making next = NULL
    int val = cur->val;
    Node* temp = cur;
    cur = NULL;
    free(temp);
    prev->next = NULL;
    return val;
}

int front(Node* head)
{
    return head->val;
}

int back(Node* head)
{
    Node* prev = NULL;

    //Find last and 2nd to last nodes
    while (head != NULL)
    {
        prev = head;
        head = head->next;
    } 

    return prev->val;
}

void insert(Node** head, int index, int num)
{
    Node* new_node = initNode(num);

    int count = 0;

    Node* cur = *head;
    Node* prev = NULL;

    while(cur != NULL && count != index)
    {
        prev = cur;
        cur = cur->next;
        count++;
    }

    if (prev == NULL)
    {
        new_node->next = *head;
        *head = new_node;
        return;        
    }
    else if (count == index)
    {
        prev->next = new_node;
        new_node->next = cur;
        return;
    }
    else
    {
        printf("Out of bounds error on insert\n");
        return;
    }
}

void erase(Node** head, int index)
{
    if (*head == NULL)
    {
        printf("LIST IS EMPTY CANT ERASE\n");
        return;
    }

    int count = 0;

    Node* cur = *head;
    Node* prev = NULL;

    while(cur != NULL && count != index)
    {
        prev = cur;
        cur = cur->next;
        count++;
    }

    if (prev == NULL)
    {
        Node* temp = *head;
        *head = cur->next;
        free(temp);
        return;        
    }
    else if (count == index)
    {
        Node* temp = cur;
        prev->next = cur->next;
        free(temp);
        return;
    }
    else
    {
        printf("Out of bounds error on erase\n");
        return;
    }  
}

int value_n_from_end(Node* head, int n)
{
    int length_of_list = size(head);
    int pos = length_of_list - n;
    if (n > length_of_list || pos <= 0 || n < 0)
    {
        printf("OUT OF BOUNDS value_n_from_end\n");
        return -999;
    }

    for(int i = 0; i < pos - 1;i++)
    {
        head = head->next;
    }
    return head->val;
}

void reverse(Node** head)
{
    Node* cur = *head;
    Node* prev = NULL;

    while (cur != NULL)
    {
        Node* temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }

    *head = prev;
}

void remove_value(Node** head, int num)
{
    if (*head == NULL)
    {
        printf("List is empty cant remove_value\n");
    }

    Node* cur = *head;
    Node* prev = NULL;

    while(cur != NULL && cur->val != num)
    {
        prev = cur;
        cur = cur->next;
    }

    if (prev == NULL)
    {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);  
        return;     
    }
    else if (cur->val == num)
    {
        Node* temp = cur;
        prev->next = cur->next;
        free(temp);
        return;
    }
    else
    {
        printf("did not find number\n");
        return;
    } 
}

int main()
{
    Node* head = initNode(7);

    display(head);

    printf("val at 1: %d\n", value_at(head, 0));

    push_front(&head, 12);
    display(head);

    push_front(&head, 222);
    display(head); 

    printf("POPED FROM FRONT: %d\n", pop_front(&head));
    display(head);

    printf("POPED FROM FRONT: %d\n", pop_front(&head));
    display(head);

    printf("POPED FROM FRONT: %d\n", pop_front(&head));
    display(head);

    printf("POPED FROM FRONT: %d\n", pop_front(&head));
    display(head);

    push_back(&head, 444);
    display(head);

    push_back(&head, 1212);
    display(head);

    printf("POPED FROM BACK: %d\n", pop_back(&head));
    display(head);

    printf("POPED FROM BACK: %d\n", pop_back(&head));
    display(head);

    printf("POPED FROM BACK: %d\n", pop_back(&head));
    display(head);

    push_back(&head, 444);
    display(head);

    push_back(&head, 1212);
    display(head);

    printf("FRONT: %d\n", front(head));
    printf("BACK: %d\n", back(head));
    display(head);

    printf("POPED FROM BACK: %d\n", pop_back(&head));
    display(head);

    insert(&head, 0, 12);
    display(head);

    insert(&head, 1, 987);
    display(head);

    insert(&head, 2, 345);
    display(head);

    insert(&head, 22, 345);
    display(head);

    printf("POPED FROM BACK: %d\n", pop_back(&head));
    display(head);

    printf("POPED FROM BACK: %d\n", pop_back(&head));
    display(head);

    printf("POPED FROM BACK: %d\n", pop_back(&head));
    display(head);

    erase(&head, 0);
    display(head);

    push_back(&head, 444);
    display(head);

    push_back(&head, 1212);
    display(head);

    push_back(&head, 69);
    display(head);

    push_back(&head, 420);
    display(head);

    erase(&head, 2);
    display(head);

    erase(&head, 2);
    display(head);

    erase(&head, 0);
    display(head);

    erase(&head, 0);
    display(head);

    erase(&head, 0);
    display(head);

    push_back(&head, 1212);
    display(head);

    erase(&head, 110);
    display(head);  

    push_back(&head, 444);
    display(head);

    push_back(&head, 1212);
    display(head);

    push_back(&head, 69);
    display(head);

    push_back(&head, 420);
    display(head);  

    printf("value from 1 from end: %d\n", value_n_from_end(head, 1));
    printf("value from 2 from end: %d\n", value_n_from_end(head, 2));
    printf("value from 3 from end: %d\n", value_n_from_end(head, 3));
    printf("value from 4 from end: %d\n", value_n_from_end(head, 4));
    printf("value from 5 from end: %d\n", value_n_from_end(head, 5));
    printf("value from 5 from end: %d\n", value_n_from_end(head, 6));
    printf("value from 5 from end: %d\n", value_n_from_end(head, -2));

    reverse(&head);
    display(head);

    remove_value(&head, 420);
    display(head);

    remove_value(&head, 444);
    display(head);

    remove_value(&head, 69);
    display(head);

    remove_value(&head, 1212);
    display(head);

    return 0;
}