#include <stdio.h>

void print(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{

    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{

    int partIndex;
    if (low < high)
    {
        partIndex = partition(A, low, high);
        quickSort(A, low, partIndex - 1);
        quickSort(A, partIndex + 1, high);
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

    quickSort(A, 0, n - 1);

    printf("After Sorting the elements of the array are : ");
    print(A, n);
}