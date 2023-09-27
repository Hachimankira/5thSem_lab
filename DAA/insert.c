#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; 
    }

    clock_t start, end;
    double time;
    
    start = clock();
    
    insertionSort(arr, n);
    
    
    
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    end = clock();
    
    time = ((double)(end - start) * 1000000) / CLOCKS_PER_SEC;
    printf("\nTime taken for Insertion Sort = %lf milliseconds\n", time);
    
    return 0;
}
