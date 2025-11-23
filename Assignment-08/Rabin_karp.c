#include <stdio.h>
#include <string.h>

#define d 256   // Alphabet size (ASCII)

// Rabin-Karp function
void rabinKarp(char text[], char pattern[], int q) {
    int n = strlen(text);
    int m = strlen(pattern);

    int p = 0;       // hash value for pattern
    int t = 0;       // hash value for current text window
    int h = 1;

    // Compute h = d^(m-1) % q
    for (int i = 0; i < m-1; i++)
        h = (h * d) % q;

    // Compute initial hash values for pattern and first text window
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over the text
    for (int s = 0; s <= n - m; s++) {

        // If hash values match, check characters one by one
        if (p == t) {
            int match = 1;
            for (int j = 0; j < m; j++) {
                if (text[s + j] != pattern[j]) {
                    match = 0;
                    break;
                }
            }
            if (match)
                printf("Pattern found at shift %d\n", s);
        }

        // Compute hash for next window (rolling hash)
        if (s < n - m) {
            t = (d * (t - text[s] * h) + text[s + m]) % q;

            // Make sure hash value is positive
            if (t < 0)
                t = t + q;
        }
    }
}

int main() {
    char text[100], pattern[100];

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter pattern: ");
    scanf("%s", pattern);

    int q = 101; // a prime number

    rabinKarp(text, pattern, q);

    return 0;
}
