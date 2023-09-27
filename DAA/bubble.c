#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Bubble Sort on an array
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Generate random integers and populate the array
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Generate random integers between 0 and 999
    }

    clock_t start, end;
    double time;
    
    start = clock();
    
    bubbleSort(arr, n);
    
    
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    end = clock();
    
    time = ((double)(end - start) * 1000000) / CLOCKS_PER_SEC;
    printf("\nTime taken for Bubble Sort = %lf microseconds\n", time);
    
    return 0;
}
