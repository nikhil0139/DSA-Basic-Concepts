#include<stdio.h>

void print(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void countSort(int A[] , int n){
    int max = A[0] , i;
    
    for(i=1;i<n;i++){
        if(A[i]>max){
            max = A[i];
        }
    }
    
    int count[max+1];
    
    for(i = 0;i<max+1;i++){
        count[i] = 0;
    }
    
    for(i=0;i<n;i++){
        count[A[i]]++;
    }
    i=0;
    int j=0;
    
    while(i<max+1){
        if(count[i]>0){
            A[j] = i;
            count[i]--;
            j++;
        }
        else{
            i++;
        }
    }
}

void main()
{
    int A[100], n;

    printf("Enter the number of elements : ");
    scanf("%d", &n);

    printf("Enter the elements : ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Before Sorting ,the array elements are : ");
    print(A, n);

    countSort(A, n);

    printf("After Sorting ,the array elements are : ");
    print(A, n);
    
}