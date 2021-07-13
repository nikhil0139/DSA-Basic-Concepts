#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

int isEmpty()
{
    if (top == NULL)
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
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(int x)
{
    if (isFull())
    {
        printf("Stack Overflow.\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        return n;
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow.\n");
    }
    else
    {
        struct Node *n = top;
        top = top->next;
        int x = n->data;
        free(n);
        return x;
    }
}

void peek(int pos)
{
    struct Node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        printf("Element at position %d is %d\n", pos, ptr->data);
    }
    else
    {
        printf("Invalid position\n");
    }
}

void stackTop()
{
    struct Node *ptr = top;
    if (isEmpty())
    {
        printf("Stack underflow.\n");
    }
    else
    {
        printf("Element at top is %d \n", ptr->data);
    }
}

void stackBottom()
{
    struct Node *ptr = top;
    if (isFull())
    {
        printf("Stack overflow.\n");
    }
    else
    {
        while (ptr->next != NULL)
        {

            ptr = ptr->next;
        }
        printf("Element at bottom is %d \n", ptr->data);
    }
}

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element is %d \n", ptr->data);
        ptr = ptr->next;
    }
}

void main()
{

    top = push(25);
    top = push(78);
    top = push(36);
    top = push(85);

    int ele = pop();
    printf("Popped Element is %d\n", ele);

    traversal(top);

    for (int i = 1; i <= 3; i++)
    {
        peek(i);
    }

    peek(120);

    stackTop();
    stackBottom();
}
