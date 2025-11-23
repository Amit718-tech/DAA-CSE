#include <stdio.h>

typedef struct {
    int weight;
    int value;
    float ratio;
} Item;

void sortDescending(Item items[], int n) {
    Item temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

float fractionalKnapsack(Item items[], float x[], int n, int U) {

    // Step 1: Sort items by ratio
    sortDescending(items, n);

    // Step 2: Initialize solution vector
    for(int i = 0; i < n; i++)
        x[i] = 0.0;

    int C = U;
    float totalValue = 0;
    int i;

    // Step 3: Fill items greedily
    for(i = 0; i < n; i++) {
        if(items[i].weight > C)
            break;
        else {
            x[i] = 1.0;
            totalValue += items[i].value;
            C -= items[i].weight;
        }
    }

    // Step 4: Take fractional item if space remains
    if(i < n) {
        x[i] = (float)C / items[i].weight;
        totalValue += x[i] * items[i].value;
    }

    return totalValue;
}

int main() {

    int n, U;

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item items[n];
    float x[n];

    printf("Enter weights:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &items[i].weight);

    printf("Enter values:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &items[i].value);

    printf("Enter knapsack capacity: ");
    scanf("%d", &U);

    // Compute ratios
    for(int i = 0; i < n; i++)
        items[i].ratio = (float)items[i].value / items[i].weight;

    // Call Knapsack function
    float result = fractionalKnapsack(items, x, n, U);

    // Print output
    printf("\nOptimal solution vector (x[i]):\n");
    for(int i = 0; i < n; i++)
        printf("%.2f ", x[i]);

    printf("\n\nMaximum Profit = %.2f\n", result);

    return 0;
}
