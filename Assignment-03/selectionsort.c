#include<stdio.h>

void selectionSort(int arr[], int n);
void printArray(int arr[], int n);

int main()
{
    int arr[20];
    int n, i;

    printf("Enter the number of array elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

void selectionSort(int arr[], int n)
{
    int i, j, min, temp;

    for(i = 0; i < n-1; i++)
    {
        min = i;

        for(j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
