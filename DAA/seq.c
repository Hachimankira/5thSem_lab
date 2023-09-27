#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sequentialSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int n, x;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; 
    }

    x = rand() % 1000;

    clock_t start, end;
    double time;
    
    start = clock();
    
    int result = sequentialSearch(arr, n, x);
    
    
    
    if (result != -1) {
        printf("Element %d found at index %d\n", x, result);
    } else {
        printf("Element %d not found in the array\n", x);
    }
    end = clock();
    
    time = ((double)(end - start) * 1000000) / CLOCKS_PER_SEC;
    printf("Time taken for Sequential Search = %lf milliseconds\n", time);
    
    return 0;
}
