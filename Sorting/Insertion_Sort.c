#include <stdio.h>

void print(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int A[], int n)
{

    int j, key;

    for (int i = 1; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;

        while (A[j] > key && j >= 0)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void main()
{
    int A[100], n;

    printf("Enter the number of elements  : ");
    scanf("%d", &n);

    printf("Enter the elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Before sorting the elements of the array are : ");
    print(A, n);

    insertionSort(A, n);
    printf("After sorting the elements of the array are : ");
    print(A, n);
}