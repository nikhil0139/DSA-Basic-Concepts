#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

int isEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display()
{
    struct Node *ptr = front;
    while (ptr <= rear)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void enqueue(int val)
{
    if (isFull())
    {
        printf("Queue is full. Cannot insert more elements.\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = val;
        n->next = NULL;
        if (isEmpty())
        {
            front = rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
    }

    printf("Successfully inserted.\n");
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty. Cannot delete more elements.\n");
        return 0;
    }
    else
    {
        struct Node *ptr = front;
        front = front->next;
        int y = ptr->data;
        free(ptr);
        return y;
    }
}

void main()
{

    enqueue(5);
    enqueue(8);
    enqueue(9);
    enqueue(1);

    int x = dequeue();
    printf("Dequeued element is %d\n", x);

    display();
}
