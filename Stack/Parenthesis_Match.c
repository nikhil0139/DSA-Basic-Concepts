
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    char *arr;
};




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
void push(struct stack *s,char element)
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

int paranthesisMatching(char exp[])
{
    struct stack *s;
    s= (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 80;
    s->arr = (char *)malloc(s->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(s,'(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            pop(s);
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
    
    char * exp ;

    printf("Enter the expression: ");
    scanf("%s",exp);

    if (paranthesisMatching(exp))
    {
        printf("Empression is balanced.\n");
    }
    else
    {
        printf("Empression is unbalanced.\n");
    }
}