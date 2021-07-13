#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int top;
    int size;
    char *arr;
};

void push(struct stack *s, char ch)
{
    s->top++;
    s->arr[s->top] = ch;
}

char pop(struct stack *s)
{
    char y = s->arr[s->top];
    s->top--;
    return y;
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/' || ch == '%')
    {
        return 2;
    }

    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isOperator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '%' || ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
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

char stackTop(struct stack *s)
{
    return s->arr[s->top];
}

char *infixToPostfix(char *infix)
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 80;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(s)))
            {
                push(s, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(s);
                j++;
            }
        }
    }

    while (!isEmpty(s))
    {
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';

    return postfix;
}

void main()
{
    char *infix;

    printf("Enter the infix expression : ");
    scanf("%s", infix);

    printf("Postfix Expression is %s", infixToPostfix(infix));
}