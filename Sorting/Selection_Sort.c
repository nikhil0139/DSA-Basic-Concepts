#include <stdio.h>

void print(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int A[], int n)
{
    int min, temp;

    for (int i = 0; i < n - 1; i++)
    {
        min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }

        temp = A[min];
        A[min] = A[i];
        A[i] = temp;
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

    selectionSort(A, n);
    printf("After sorting the elements of the array are : ");
    print(A, n);
}