#include<stdio.h>
#include<stdlib.h>

struct myArray{
    int total_size;
    int used_size;
    int *ptr;
};

void create(struct myArray *a, int t_size, int u_size){

    a->total_size = t_size;
    a->used_size = u_size;
    a->ptr = (int *)malloc(t_size * sizeof(int));

}

void setValue(struct myArray *a){
    int n;

    for(int i=0;i<a->used_size;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&n);
       a->ptr[i] = n;
    }
}

void showValue(struct myArray *a){
   

    for(int i=0;i<a->used_size;i++){
        printf("Element is %d\n",(a->ptr)[i]);
       
    }
}

void main(){
    struct myArray *marks;
    marks=(struct myArray *) malloc (sizeof (struct myArray));
    
    create(marks,10,6);

    printf("Now enter the values : \n");
    setValue(marks);

    printf("Values are : \n");
    showValue(marks);
}

