#include <stdio.h>
int is_Sorted = 1;

void print(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubbleSort(int A[], int n)
{
    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                is_Sorted = 0;
            }
        }
        if (is_Sorted)
        {
            printf("Array is Already Sorted.\n");
            return;
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

    bubbleSort(A, n);

    if (is_Sorted != 1)
    {
        printf("After Sorting ,the array elements are : ");
        print(A, n);
    }
}