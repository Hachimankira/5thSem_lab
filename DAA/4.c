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
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    // Create temporary arrays
    int L[n1], R[n2];
    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    // Merge the temporary arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;  // Generating random numbers between 0 and 999
    }
}
int main() {
    int size;
    printf("Enter the number of inputs: ");
    scanf("%d", &size);
    int arrSelection[size], arrMerge[size];
    clock_t start, end;
    double timeSelection, timeMerge;
    // Generate a random array for both algorithms to sort
    generateRandomArray(arrSelection, size);
    for (int i = 0; i < size; i++) {
        arrMerge[i] = arrSelection[i];
    }
    // Perform Selection Sort and measure time
    start = clock();
    selectionSort(arrSelection, size);
    end = clock();
    timeSelection = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    // Perform Merge Sort and measure time
    start = clock();
    mergeSort(arrMerge, 0, size - 1);
    end = clock();
    timeMerge = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    // Display the sorted arrays and the time taken by each algorithm
    printf("\nSelection Sort:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arrSelection[i]);
    }
    printf("\nTime taken by Selection Sort: %f milliseconds\n\n", timeSelection);
    printf("Merge Sort:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arrMerge[i]);
    }
    printf("\nTime taken by Merge Sort: %f milliseconds\n", timeMerge);
    return 0;
}
