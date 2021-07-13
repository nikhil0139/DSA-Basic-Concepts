#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};


void createStack(struct stack *s)
{
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
}

void isEmpty(struct stack *s)
{
    if (s->top == -1)
        printf("Stack is empty.\n");
    else
        printf("Stack is not empty.\n");
}

void isFull(struct stack *s)
{
    if (s->top == s->size - 1)
        printf("Stack is full.\n");
    else
        printf("Stack is not full.\n");
}

void push(struct stack *s,int element)
{
    if (s->top == s->size - 1)
        printf("Stack is full.\n");
    else
    {
        s->top++;
        s->arr[s->top] = element;
    }
}

void pop(struct stack *s)
{
    if (s->top == -1)
        printf("Stack is empty.\n");
    else
    {
        printf("Popped element is %d\n", s->arr[s->top]);
        s->top--;
    }
}

void peek(struct stack *s,int position)
{
    if (s->top == -1)
        printf("Stack is empty.\n");
    else
    {
        int y = s->top - position + 1;
        printf("Elememt at position %d is %d.\n", position, s->arr[y]);
    }
}

void top(struct stack *s)
{
    if (s->top == -1)
        printf("Stack is empty.\n");
    else
        printf("Element at top of the stack is %d.\n", s->arr[s->top]);
}

void bottom(struct stack *s)
{
    if (s->top == -1)
        printf("Stack is empty.\n");
    else
        printf("Element at top of the stack is %d.\n", s->arr[0]);
}

void display(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = s->top; i >= 0; i--)
        {
            printf("%d ", s->arr[i]);
        }
    }
}
void main()
{
    struct stack *s;
    createStack(s);

    isEmpty(s);

    isFull(s);

    push(s,76);
    push(s,56);
    push(s,55);
    push(s,58);
    push(s,97);
    push(s,46);

    pop(s);

    peek(s,3);

    top(s);

    bottom(s);

    display(s);
}