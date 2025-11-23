#include <stdio.h>

// Function prototypes
void maxHeapify(int A[], int i, int heapSize);
void buildMaxHeap(int A[], int n);
void heapSort(int A[], int n);

// Get left and right child according to CLRS (1-indexing)
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }

void maxHeapify(int A[], int i, int heapSize) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if(l <= heapSize && A[l] > A[largest])
        largest = l;

    if(r <= heapSize && A[r] > A[largest])
        largest = r;

    if(largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        maxHeapify(A, largest, heapSize);
    }
}

void buildMaxHeap(int A[], int n) {
    for(int i = n/2; i >= 1; i--)
        maxHeapify(A, i, n);
}

void heapSort(int A[], int n) {
    buildMaxHeap(A, n);

    int heapSize = n;

    for(int i = n; i >= 2; i--) {
        int temp = A[1];
        A[1] = A[i];
        A[i] = temp;

        heapSize--;
        maxHeapify(A, 1, heapSize);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n+1]; // +1 because we start indexing from 1

    printf("Enter %d numbers:\n", n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &A[i]);

    heapSort(A, n);

    printf("\nSorted array: ");
    for(int i = 1; i <= n; i++)
        printf("%d ", A[i]);

    printf("\n");
    return 0;
}

