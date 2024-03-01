#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

typedef struct Queue{
    int * arr;
    int tail;
    int head;
}Queue;

Queue* initQueue();
void display(Queue* que);
void enqueue(Queue** que, int num);
int dequeue(Queue** que);

int main()
{
    Queue* que = initQueue();

    enqueue(&que, 1);
    enqueue(&que, 2);
    enqueue(&que, 3);
    enqueue(&que, 4);
    enqueue(&que, 5);
    enqueue(&que, 6);
    enqueue(&que, 7);
    enqueue(&que, 8);
    enqueue(&que, 9);
    enqueue(&que, 10);
    enqueue(&que, 11);
    display(que);

    printf("dequeued: %d\n", dequeue(&que));
    display(que);

    printf("dequeued: %d\n", dequeue(&que));
    display(que);

    printf("dequeued: %d\n", dequeue(&que));
    display(que);

    printf("dequeued: %d\n", dequeue(&que));
    display(que);

    printf("dequeued: %d\n", dequeue(&que));
    display(que);

    printf("dequeued: %d\n", dequeue(&que));
    display(que);

    printf("dequeued: %d\n", dequeue(&que));
    display(que);

    printf("dequeued: %d\n", dequeue(&que));
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
    que->arr = (int*)malloc(sizeof(int) * QUEUE_SIZE);
    que->head = -1;
    que->tail = -1;
    return que;
}

void display(Queue* que)
{
    for(int i = 0; i <= que->tail; i++)
    {
        printf("%d ", que->arr[i]);
    }
    printf("\n");
}

int dequeue(Queue** que)
{
    if ((*que)->head == -1 || (*que)->tail == -1)
    {
        printf("QUEUE IS EMPTY CAN NOT DEQUEUE\n");
        return -999;
    }

    if ((*que)->head == 0 && (*que)->tail == 0)
    {
        int val = (*que)->arr[(*que)->head];
        (*que)->head--;
        (*que)->tail--;
        return val;        
    }
    else
    {
        int val = (*que)->arr[(*que)->head];
        for (int i = 1; i <= (*que)->tail; i++)
        {
            (*que)->arr[i - 1] = (*que)->arr[i];
        }
        (*que)->tail--;
        return val;        
    }
}

void enqueue(Queue** que, int num)
{
    if ((*que)->tail + 1 >= QUEUE_SIZE)
    {
        printf("NOT ABLE TO ENQUEUE QUEUE IS FULL\n");
        return;
    }

    if ((*que)->head == -1 || (*que)->tail == -1)
    {
        (*que)->head = 0;
        (*que)->tail = 0;       
        (*que)->arr[0] = num;
    }
    else
    {
        (*que)->arr[(*que)->tail + 1] = num;
        (*que)->tail++;
    }   
}

