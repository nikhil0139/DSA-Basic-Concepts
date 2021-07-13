#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int count(struct node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int Add(struct node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void main()
{

    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 45;
    third->next = fourth;

    fourth->data = 12;
    fourth->next = NULL;

    traversal(head);

    int y = count(head);
    printf("Number of nodes in linked list is : %d\n", y);

    int s = Add(head);
    printf("The sum of elements in linked list is : %d\n", s);
}