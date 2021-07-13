#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct Queue *q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue Overflow.\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = value;
    }
}

void dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow.\n");
    }
    else
    {
        q->front++;
    }
}

void display(struct Queue *q)
{
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int queueTop(struct Queue *q)
{
    return q->arr[q->rear];
}

int queueBottom(struct Queue *q)
{
    return q->arr[q->front + 1];
}

int peek(struct Queue *q, int pos)
{
    int i = q->front + 1;
    while (i != (q->front + pos))
    {
        i++;
    }
    return q->arr[i];
}

void main()
{

    struct Queue *q;

    q->size = 80;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->size * (sizeof(int)));

    enqueue(q, 56);
    enqueue(q, 78);
    enqueue(q, 87);
    enqueue(q, 32);
    enqueue(q, 65);
    enqueue(q, 98);
    enqueue(q, 25);
    enqueue(q, 45);
    enqueue(q, 95);
    enqueue(q, 36);
    enqueue(q, 71);
    enqueue(q, 05);
    enqueue(q, 85);

    dequeue(q);
    dequeue(q);
    dequeue(q);

    display(q);

    if (isEmpty(q))
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        printf("Queue is not empty\n");
    }

    if (isFull(q))
    {
        printf("Queue is Full.\n");
    }
    else
    {
        printf("Queue is not Full\n");
    }

    printf("Element at top of the queue is : %d\n", queueTop(q));

    printf("Element at bottom of the queue is : %d\n", queueBottom(q));

    printf("Element at position %d is %d\n", 3, peek(q, 3));
}
