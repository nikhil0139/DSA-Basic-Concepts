#include <stdio.h>
#include <stdlib.h>

struct priorityQueue
{
    int data;
    int priority;
    struct priorityQueue *next;
};

struct priorityQueue *pq= NULL;

int isEmpty()
{
    if (pq == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    struct priorityQueue *n = (struct priorityQueue *)malloc(sizeof(struct priorityQueue));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void delete ()
{
    if (isEmpty())
    {
        printf("Queue is Empty.Cannot delete elements.\n");
    }
    else
    {
        int max = pq->priority;
        struct priorityQueue *n = pq->next;
        while (n != NULL)
        {
            if (n->priority > max)
            {
                max = n->priority;
            }
        }
        struct priorityQueue *p = pq;
        struct priorityQueue *q = pq->next;

        while(q->priority == max){
            p=p->next;
            q=q->next;
        }
        p->next = q->next;
        free(q);
    }
}


void Insert(int p, int element)
{
    struct priorityQueue * head = pq;
    if (isFull(pq))
    {
        printf("Queue is full. Cannot insert more elements.\n");
    }
    else
    {
        struct priorityQueue *temp = (struct priorityQueue *)malloc(sizeof(struct priorityQueue));
        temp->data = element;
        temp->priority = p;
        if (pq == NULL)
        {
            temp->next = NULL;
            pq = temp;
        }
        else if (pq->priority > temp->priority)
        {
            temp->next = pq;
            pq = temp;
        }
        else
        {
            while (head->next != NULL && head->priority < temp->priority)
            {
                head = head->next;
            }
            temp->next = head->next;
            head->next = temp;
        }
    }
}


void display(){
    struct priorityQueue * head = pq;

    if(isEmpty()){
        printf("Queue is Empty.\n");
    }
    else{
        while(head!=NULL){
            printf("%d ",pq->data);
        }
    }
}

void main(){
    


    Insert(1,98);
    Insert(3,85);
    Insert(5,12);
    Insert(7,63);
    Insert(9,75);
    Insert(2,25);
    Insert(4,13);
    Insert(6,36);
    Insert(8,72);
    

    display();
}