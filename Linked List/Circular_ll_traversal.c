#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void traversal(struct node *head){
    struct node *p = head;
    do{
        printf("Element is %d\n",p->data);
        p = p->next;
    } while(p!=head);
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

}