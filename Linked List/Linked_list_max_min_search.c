#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void max(struct node *p)
{
    int max = p->data;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }

    printf("Maximum value in linked list is : %d\n", max);
}

void min(struct node *p)
{
    int min = p->data;
    while (p != NULL)
    {
        if (p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }

    printf("Minimum value in linked list is : %d\n", min);
}

void search(struct node *p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
        {
            printf("Element found in the list\n");
        }
        p = p->next;
    }
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
    int key;

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

    max(head);

    min(head);

    printf("Enter the value you want to search : ");
    scanf("%d", &key);

    search(head, key);

    // int y = count(head);
    // printf("Number of nodes in linked list is : %d\n", y);

    // int s = Add(head);
    // printf("The sum of elements in linked list is : %d\n", s);
}