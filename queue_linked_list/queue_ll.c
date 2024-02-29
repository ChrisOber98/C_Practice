#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node * next;
}Node;

typedef struct Queue
{
    Node* head;
    Node* tail;
}Queue;

Node* initNode(int num);

Queue* initQueue();
void enqueue(Queue** que, int num);
int dequeue(Queue** que);
void display(Queue* que);
int head(Queue* que);
int tail(Queue* que);

int main()
{
    Queue* que = initQueue();
    enqueue(&que, 1212);
    enqueue(&que, 1);
    enqueue(&que, 2);
    display(que);

    printf("dequeued: %d\n", dequeue(&que));
    display(que);

    printf("dequeued: %d\n", dequeue(&que));
    display(que);

    printf("dequeued: %d\n", dequeue(&que));
    display(que);

    return 0;
}

Queue* initQueue()
{
    Queue* que = (Queue*)malloc(sizeof(Queue));
    que->head = NULL;
    que->tail = NULL;
    return que;
}

Node* initNode(int num)
{
    Node* temp = (Node*)malloc(sizeof(Node)); 
    temp->val = num;
    temp->next = NULL;
    return temp;  
}

void enqueue(Queue** que, int num)
{
    Node* new_node = initNode(num);

    if((*que)->head == NULL && (*que)->tail == NULL)
    {
        (*que)->head = new_node;
        (*que)->tail = new_node;
        return;
    }

    (*que)->tail->next = new_node;
    (*que)->tail = new_node;
}

int dequeue(Queue** que)
{
    int val = (*que)->head->val;

    if((*que)->head == NULL)
    {   
        printf("QUEUE IS EMPTY!\n");
        return -999;
    }

    if((*que)->head == (*que)->tail)
    {
        Node* temp = (*que)->head;
        (*que)->head = NULL;
        (*que)->tail = NULL;
        free(temp);
        return val;
    }

    Node* temp = (*que)->head;
    (*que)->head = (*que)->head->next;
    free(temp);
    return val;

}

int head(Queue* que)
{
    if (que->head == NULL)
    {
        printf("HEAD IS NULL\n");
        return -999;
    }
    else
    {
        return que->head->val;
    }
}

int tail(Queue* que)
{
    if (que->tail == NULL)
    {
        printf("TAIL IS NULL\n");
        return -999;
    }
    else
    {
        return que->tail->val;
    }
}

void display(Queue* que)
{
    Node* cur = que->head;

    if (cur == NULL)
    {
        printf("NULL\n");
        printf("Head: %d\n", head(que));
        printf("Tail: %d\n\n", tail(que));
        return;
    }

    while(cur != NULL)
    {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }

    printf("NULL\n");
    printf("Head: %d\n", head(que));
    printf("Tail: %d\n\n", tail(que));
}
