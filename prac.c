#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Randomized QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Randomized Partition function
int randomizedPartition(int arr[], int low, int high) {
    int randomPivot = low + rand() % (high - low + 1);
    swap(&arr[randomPivot], &arr[high]);
    return partition(arr, low, high);
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to find the maximum product subarray
void maxProductSubarray(int arr[], int n, int *maxProduct, int *start, int *end) {
    int maxCurrent = arr[0], minCurrent = arr[0], maxGlobal = arr[0];
    int tempStart = 0;
    *start = 0;
    *end = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] < 0) {
            int temp = maxCurrent;
            maxCurrent = minCurrent;
            minCurrent = temp;
        }
        maxCurrent = arr[i] > arr[i] * maxCurrent ? arr[i] : arr[i] * maxCurrent;
        minCurrent = arr[i] < arr[i] * minCurrent ? arr[i] : arr[i] * minCurrent;

        if (maxGlobal < maxCurrent) {
            maxGlobal = maxCurrent;
            *start = tempStart;
            *end = i;
        }
        if (maxCurrent == arr[i]) {
            tempStart = i;
        }
    }
    *maxProduct = maxGlobal;
}

// Main function
int main() {
    srand(time(0));
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sorting the array using Randomized QuickSort
    quickSort(arr, 0, n - 1);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Finding the maximum product subarray
    int maxProduct, start, end;
    maxProductSubarray(arr, n, &maxProduct, &start, &end);

    printf("Maximum Product Subarray: ");
    for (int i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Maximum Product: %d\n", maxProduct);

    return 0;
}
