#include<stdio.h>
void main(){
    int a[100],n,i;

    printf("Enter number of elements in array : ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter %d element : ",i+1);
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++){
        printf("Element %d : %d\n",i+1,a[i]);
    }
}