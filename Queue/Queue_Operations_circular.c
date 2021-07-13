#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct circularQueue *q)
{
    if (q->rear == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct circularQueue *q)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct circularQueue *q, int value)
{
    if (isFull(q))
    {
        printf("Circular Queue is full . Cannot insert more elements in the queue\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = value;
        printf("Successfully inserted.\n");
    }
}

void dequeue(struct circularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Circular Queue is empty . Cannot remove more elements in the queue\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        int y = q->arr[q->front];
        printf("Dequeued element is %d\n", y);
    }
}

void display(struct circularQueue *q)
{
    int i = (q->front + 1) % q->size;
    while (i <= q->rear)
    {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
}

void main()
{
    struct circularQueue *q;
    q->size = 6;
    q->front = 0;
    q->rear = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 45);
    enqueue(q, 56);
    enqueue(q, 84);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    enqueue(q, 54);
    enqueue(q, 56);
    enqueue(q, 52);
    enqueue(q, 52);
    enqueue(q, 52);

    printf("The Empty queue is %d\n", isEmpty(q));
    printf("The Full queue is %d\n", isFull(q));

    display(q);
}