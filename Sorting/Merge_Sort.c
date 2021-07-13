#include <stdio.h>


void print(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void Merge(int A[], int mid, int low, int high)
{

    int i = low, j = mid + 1, k = low , B[200];
    

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void mergeSort(int A[] , int low , int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergeSort(A , low , mid);
        mergeSort(A , mid+1 , high);
        Merge(A , mid , low , high);
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

    printf("Before Sorting the elements of the array are : ");
    print(A, n);

    mergeSort(A, 0, n - 1);

    printf("After Sorting the elements of the array are : ");
    print(A, n);
}