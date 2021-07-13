#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *insertAtEnd(struct node *head , int data){
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    
    struct node *p = head;

    while(p->next!=NULL){
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;

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

    head=insertAtEnd(head,96);

    printf("After insertion elements are : \n");
    traversal(head);
}