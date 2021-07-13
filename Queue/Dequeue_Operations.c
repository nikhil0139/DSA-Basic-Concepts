#include <stdio.h>
#include <stdlib.h>

struct DEqueue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct DEqueue *q)
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

int isFull(struct DEqueue *q)
{
    if (q->front == -1 && q->rear == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue_rear(struct DEqueue *q, int value)
{
    if (q->rear == q->size - 1)
    {
        printf("Cannot insert more element at the rear side.\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = value;
        printf("Successfully inserted at the rear end.\n");
    }
}

void enqueue_front(struct DEqueue *q, int value)
{
    if (q->front == -1)
    {
        printf("Cannot insert more element at the front end.\n");
    }
    else
    {
        q->arr[q->front] = value;
        q->front--;
        printf("Successfully inserted at the front end.\n");
    }
}

void dequeue_front(struct DEqueue *q)
{
    if (q->rear == q->front)
    {
        printf("Cannot delete elements as there are no more elements in the DEqueue.\n");
    }
    else
    {
        q->front++;
        int y = q->arr[q->front];
        printf("Deleted element at the front end is %d.\n", y);
    }
}

void dequeue_rear(struct DEqueue *q)
{
    if (q->rear == q->front)
    {
        printf("Cannot delete elements as there are no more elements in the DEqueue.\n");
    }
    else
    {
        int y = q->arr[q->rear];
        q->rear--;
        printf("Deleted element at the front end is %d.\n", y);
    }
}

void display(struct DEqueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        for (int i = (q->front + 1); i <= q->rear; i++)
        {
            printf("%d ", q->arr[i]);
        }
    }
}

void main(){
    struct DEqueue *q;
    q->size = 50;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue_rear(q,45);
    enqueue_rear(q,85);
    enqueue_rear(q,22);
    enqueue_rear(q,14);
    enqueue_rear(q,44);
    enqueue_rear(q,21);
    enqueue_rear(q,78);
    enqueue_rear(q,96);
    enqueue_rear(q,85);
    enqueue_rear(q,21);
    enqueue_rear(q,54);
    enqueue_rear(q,91);
    enqueue_rear(q,21);

    enqueue_front(q,65);

    dequeue_front(q);
    dequeue_front(q);
    dequeue_front(q);
    dequeue_front(q);
    dequeue_front(q);


    dequeue_rear(q);
    dequeue_rear(q);
    dequeue_rear(q);
    dequeue_rear(q);

    enqueue_front(q,65);


    display(q);
}