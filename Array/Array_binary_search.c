#include<stdio.h>
void main(){
    int a[100],n,i,index=0,element,mid,high,low;

    printf("Enter number of elements in array : ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter %d element : ",i+1);
        scanf("%d",&a[i]);
    }

    printf("Enter element you want to search : ");
    scanf("%d",&element);

    low=0;
    high=n-1;

    while(low<=high){
        mid=(low+high)/2;

        if(a[mid]==element){
            index=1;
            break;
        }

        if(a[mid]<element){
            low=mid+1;
        }
        
        else
        {
            high=mid-1;
        }
        
    }

    if(index==1)
    printf("Element %d found at %d position\n",element,mid+1);
    else
    printf("Element %d is not in the given list\n",element);

}
