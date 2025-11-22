#include<stdio.h>

// Function to partition the array
int partition(int A[], int low, int high) {
    int pivot = A[low]; // Choosing the first element as pivot
    int i = low;
    int j = high;

    while (i < j) {
        // Find element greater than pivot from left
        while (A[i] <= pivot && i < high) {
            i++;
        }
        // Find element smaller than or equal to pivot from right
        while (A[j] > pivot) {
            j--;
        }
        // Swap elements if i is still less than j
        if (i < j) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    // Swap pivot with A[j] to place pivot in its correct sorted position
    int temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j; // Return the partitioning index
}

// Function to perform QuickSort
void Quicksort(int A[], int low, int high) {
    if (low < high) {
        int j = partition(A, low, high); // Get the partitioning index
        Quicksort(A, low, j - 1);       // Sort the left sub-array
        Quicksort(A, j + 1, high);      // Sort the right sub-array
    }
}

int main() {
    int n;
    printf("Enter the size of the array:");
    scanf("%d", &n);

    int A[n]; // Declaring a variable-length array (VLA)
    printf("Enter the array element:");

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    Quicksort(A, 0, n - 1); // Call QuickSort

    printf("Sorted array:");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n"); // Add a newline for better output formatting

    return 0;
}
