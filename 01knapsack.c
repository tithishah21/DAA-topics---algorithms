#include <stdio.h>

// Brute force recursive 0-1 Knapsack
int knapsack(int W, int wt[], int val[], int n) {
    // Base Case: No items or no capacity
    if (n == 0 || W == 0)
        return 0;

    // If weight of current item > capacity, skip it
    if (wt[n - 1] > W)
        return knapsack(W, wt, val, n - 1);

    // Else choose max of including or excluding the item
    else {
        int include = val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1);
        int exclude = knapsack(W, wt, val, n - 1);
        return (include > exclude) ? include : exclude;
    }
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum value: %d\n", knapsack(W, wt, val, n));
    return 0;
}
