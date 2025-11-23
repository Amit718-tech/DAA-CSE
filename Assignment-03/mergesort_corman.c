#include <stdio.h>
#include <limits.h> // For INT_MAX (sentinel)

void merge(int A[], int p, int q, int r) {

    // Lengths of subarrays
    int n1 = q - p + 1;
    int n2 = r - q;

    // Temporary arrays +1 space for sentinel
    int L[n1 + 1], R[n2 + 1];

    // Copy elements into L[]
    for(int i = 0; i < n1; i++)
        L[i] = A[p + i];

    // Copy elements into R[]
    for(int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    // Add sentinel values at end
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0;

    // Merge subarrays back into A[p..r]
    for(int k = p; k <= r; k++) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[], int p, int r) {
    if(p < r) {
        int q = (p + r) / 2;   // Middle index
        mergeSort(A, p, q);    // Sort left half
        mergeSort(A, q + 1, r);// Sort right half
        merge(A, p, q, r);     // Merge sorted halves
    }
}

int main() {
     int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    mergeSort(A, 0, n - 1);

    printf("Sorted Array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}

