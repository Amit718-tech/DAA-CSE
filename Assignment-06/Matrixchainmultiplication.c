
#include <stdio.h>
#include <limits.h>

void printOptimalParens(int s[20][20], int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}

void matrixChainOrder(int p[], int n) {
    int m[20][20], s[20][20];
    int i, j, k, L, q;

    // Step 1: Initialization of diagonal values
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    // Step 2: Calculating cost for chains of increasing length
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;

            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    // Printing optimal cost matrix
    printf("\nMinimum number of multiplications: %d\n", m[1][n - 1]);

    printf("\nOptimal Parenthesization: ");
    printOptimalParens(s, 1, n - 1);
    printf("\n");
}

int main() {
    int p[20], n, i;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions array (size %d): ", n + 1);
    for (i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    matrixChainOrder(p, n + 1);

    return 0;
}
