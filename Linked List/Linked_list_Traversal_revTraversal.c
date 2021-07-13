#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void revTraversal(struct node *ptr)
{
    if (ptr != NULL)
    {
        revTraversal(ptr->next);
        printf("%d\n", ptr->data);
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

    printf("Element in reverse order is : \n");

    revTraversal(head);
}