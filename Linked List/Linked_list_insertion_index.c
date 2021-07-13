#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *insertAtBetween(struct node *head , int data , int index){
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    int i=0;
    struct node *p = head;

    while(i!=index-1){
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;

    return head;
}

void traversal(struct node *ptr){
    while(ptr!=NULL){
    printf("Element is %d\n",ptr->data);
    ptr=ptr->next;
    }
}

void main(){

    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 45;
    third->next = fourth;

    fourth->data = 12;
    fourth->next = NULL;

    traversal(head);

    head=insertAtBetween(head,89,3);

    printf("After insertion elements are : \n");
    traversal(head);
}