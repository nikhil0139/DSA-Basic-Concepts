#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *deleteAtEnd(struct node *head){
    struct node *p = head;
    struct node *q = p->next;

    while(q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    
    p->next=NULL;
    free(q);

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

    head=deleteAtEnd(head);

    printf("After deletion elements are : \n");
    traversal(head);
}