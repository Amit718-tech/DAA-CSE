#include <stdio.h>
#include <math.h>

int x[20];   // Stores positions: x[k] = column of queen in row k
int n;       // Board size
int solutionCount = 0;

int PLACE(int k, int i) {
    for (int j = 1; j <= k - 1; j++) {
        // Check same column or diagonal conflict
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0; // Not safe
    }
    return 1; // Safe position
}

void printSolution() {
    solutionCount++;
    printf("\nSolution %d:\n", solutionCount);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j)
                printf(" Q%d",i);
            else
                printf(" . ");
        }
        printf("\n");
    }
}

void QUEENS(int k) {
    if (k > n) {
        printSolution();
    } else {
        for (int i = 1; i <= n; i++) {
            if (PLACE(k, i)) {
                x[k] = i;
                QUEENS(k + 1);
            }
        }
    }
}

int main() {
    printf("Enter value of n (number of queens): ");
    scanf("%d", &n);

    QUEENS(1);

    if (solutionCount == 0)
        printf("\nNo solution exists for n = %d.\n", n);

    return 0;
}
