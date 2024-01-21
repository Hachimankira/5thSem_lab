#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the element at index i
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;  // Generating random numbers between 0 and 999
    }
}
int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int arr[size];
    clock_t start, end;
    double timeSelection;
    // Generate a random array for sorting
    generateRandomArray(arr, size);
    // Perform Selection Sort and measure time
    start = clock();
    selectionSort(arr, size);
    end = clock();
    timeSelection = ((double)(end - start) * 1000000) / CLOCKS_PER_SEC;
    // Display the sorted array and the time taken by Selection Sort
    printf("\nSorted array using Selection Sort:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken by Selection Sort: %f microseconds\n", timeSelection);
    return 0;
}
