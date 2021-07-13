#include<stdio.h>
void main(){
    int a[100],n,i,index,element;

    printf("Enter number of elements in array : ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter %d element : ",i+1);
        scanf("%d",&a[i]);
    }

    printf("Enter index at which you want to insert element : ");
    scanf("%d",&index);

    printf("Enter element which you want to insert : ");
    scanf("%d",&element);

    for(i=n+1;i>index;i--){
        a[i]=a[i-1];
    }

    a[i]=element;

    n=n+1;

    for(i=0;i<n;i++){
        printf("Element %d : %d\n",i+1,a[i]);
    }
}