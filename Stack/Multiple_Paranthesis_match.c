
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    char *arr;
};

void createStack(struct stack *s)
{
    s->top = -1;
    s->size = 80;
    s->arr = (char *)malloc(s->size * sizeof(char));
}

char pop(struct stack *s)
{
    if (s->top == -1)
        printf("Stack is empty.\n");
    else
    {
        char y = s->arr[s->top];
        s->top--;
        return y;
    }
}
void push(struct stack *s, char element)
{
    if (s->top == s->size - 1)
        printf("Stack is full.\n");
    else
    {
        s->top++;
        s->arr[s->top] = element;
    }
}

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }

    else if (a == '{' && b == '}')
    {
        return 1;
    }
    else if (a == '[' && b == ']')
    {
        return 1;
    }
    else
        return 0;
}

char stackTop(struct stack *s)
{
    return s->arr[s->top];
}

int paranthesisMatching(struct stack *s, char exp[])
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(s, exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            char popchar = pop(s);
            if (match(stackTop(s), popchar))
            {
                return 0;
            }
        }
    }

    if (isEmpty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void main()
{
    struct stack *s;
    createStack(s);

    char exp[90];

    printf("Enter the expression: ");
    scanf("%s", exp);

    if (paranthesisMatching(s, exp))
    {
        printf("Empression is balanced.\n");
    }
    else
    {
        printf("Empression is unbalanced.\n");
    }
}