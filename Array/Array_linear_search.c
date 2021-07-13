#include<stdio.h>
void main(){
    int a[100],n,i,index=0,element;

    printf("Enter number of elements in array : ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter %d element : ",i+1);
        scanf("%d",&a[i]);
    }

    printf("Enter element you want to search : ");
    scanf("%d",&element);

    for(i=0;i<n;i++){
        if(a[i]==element){
            index=1;
            break;
        }
    }

    if(index==1)
    printf("Element %d found at %d position\n",a[i],i+1);
    else
    printf("Element %d is not in the given list\n");
} 