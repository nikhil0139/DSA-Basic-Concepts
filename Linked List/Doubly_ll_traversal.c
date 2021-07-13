#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *previous;
    struct node *next;
};

void traversal(struct node *head)
{
    struct node *p = head;
    printf("Forward order : \n");
    while (p != NULL)
    {
        printf("Element is %d\n", p->data);
        p = p->next;
    } 

    struct node *q = head;

    while (q->next != NULL)
    {
        q = q->next;
    }
    printf("Backward order : \n");
     while (q != NULL)
    {
        printf("Element is %d\n", q->data);
        q = q->previous;
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
    head->previous = NULL;

    second->data = 10;
    second->next = third;
    second->previous = head;

    third->data = 45;
    third->next = fourth;
    third->previous = second;

    fourth->data = 12;
    fourth->next = NULL;
    fourth->previous = third;

    traversal(head);
}