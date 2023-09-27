#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        
        if (arr[j] <= pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    srand(time(NULL));

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000; 
        printf("%d ", arr[i]);
    }
    printf("\n");

    clock_t start, end;
    double time;

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    time = ((double)(end - start) * 1000000) / CLOCKS_PER_SEC;
    printf("Time taken for Quick Sort = %lf microseconds\n", time);

    return 0;
}

