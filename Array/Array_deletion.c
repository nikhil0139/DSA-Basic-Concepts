#include<stdio.h>
void main(){
    int a[100],n,i,index;

    printf("Enter number of elements in array : ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter %d element : ",i+1);
        scanf("%d",&a[i]);
    }

    printf("Enter index you want to delete : ");
    scanf("%d",&index);

    for(i=index;i<n;i++){
        a[i]=a[i+1];
    }

    n=n-1;

    for(i=0;i<n;i++){
        printf("Element %d : %d\n",i+1,a[i]);
    }
}