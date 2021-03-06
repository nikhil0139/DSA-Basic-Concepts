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

struct node *insertAtFirst(struct node *head , int data){
    struct node *ptr;
    ptr = (struct node *) malloc (sizeof(struct node));
    ptr->data = data;

    struct node *p = head;
    while(p->next!=head){
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;

}

void traversal(struct node *head){
    struct node *ptr = head;
    do{
    printf("Element is %d\n",ptr->data);
    ptr=ptr->next;
    }while(ptr!=head);
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
    fourth->next = head;

    traversal(head);

    head=insertAtFirst(head,60);

    printf("After insertion elements are : \n");
    traversal(head);
}