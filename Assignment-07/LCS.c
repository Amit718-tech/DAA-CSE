#include <stdio.h>
#include <string.h>

#define MAX 100

char b[MAX][MAX];   // Stores direction arrows
int c[MAX][MAX];    // Stores LCS lengths

void printLCS(char X[], int i, int j) {
    if (i == 0 || j == 0)
        return;

    if (b[i][j] == 'D') {  // Diagonal (↖) match
        printLCS(X, i - 1, j - 1);
        printf("%c", X[i - 1]);
    }
    else if (b[i][j] == 'U') {  // Up (↑)
        printLCS(X, i - 1, j);
    }
    else {  // Left (←)
        printLCS(X, i, j - 1);
    }
}

void lcsLength(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);

    // Initialize first row and column to 0
    for (int i = 0; i <= m; i++)
        c[i][0] = 0;
    for (int j = 0; j <= n; j++)
        c[0][j] = 0;

    // Fill the DP tables (CLRS logic)
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'D'; // Diagonal ↖
            }
            else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'U'; // Up ↑
            }
            else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'L'; // Left ←
            }
        }
    }
}

int main() {
    char X[MAX], Y[MAX];

    printf("Enter first string: ");
    scanf("%s", X);

    printf("Enter second string: ");
    scanf("%s", Y);

    lcsLength(X, Y);

    int m = strlen(X);
    int n = strlen(Y);

    printf("\nLCS Length: %d\n", c[m][n]);
    printf("LCS: ");
    printLCS(X, m, n);

    printf("\n");
    return 0;
}

