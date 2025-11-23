#include <stdio.h>
#include <string.h>

void naiveStringMatcher(char T[], char P[]) {
    int n = strlen(T);
    int m = strlen(P);

    for(int s = 0; s <= n - m; s++) {  // shift s
        int j;
        for(j = 0; j < m; j++) {
            if(T[s + j] != P[j])
                break;
        }

        if(j == m) {
            printf("Pattern found at shift %d\n", s);
        }
    }
}

int main() {
    char T[100], P[100];

    printf("Enter text: ");
    scanf("%s", T);

    printf("Enter pattern: ");
    scanf("%s", P);

    naiveStringMatcher(T, P);

    return 0;
}
