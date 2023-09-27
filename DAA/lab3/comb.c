#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array using the last element as the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to generate a random pivot and partition the array
int randomizedPartition(int arr[], int low, int high) {
    // Generate a random index between low and high
    int randomIndex = low + rand() % (high - low + 1);

    // Swap the element at randomIndex with the element at high
    swap(&arr[randomIndex], &arr[high]);

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

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find pivot element such that
        // elements smaller than pivot are on the left
        // elements greater than pivot are on the right
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to perform Randomized Quick Sort
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = randomizedPartition(arr, low, high);

        randomizedQuickSort(arr, low, pivotIndex - 1);
        randomizedQuickSort(arr, pivotIndex + 1, high);
    }
}

// Function to merge two subarrays of arr[]
void merge(int arr[], int l, int m, int r) {
    // Merge code here
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
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

// Function to perform Merge Sort
void mergeSort(int arr[], int l, int r) {
    // Merge Sort code here
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

// Function to build a max heap
void heapify(int arr[], int n, int i) {
    // Heapify code here
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest element is not the root
    if (largest != i) {
        // Swap the largest element with the root
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int n) {
    // Heap Sort code here
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to the end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Seed the random number generator
    srand(time(NULL));

//    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000; // Generate random numbers between 0 and 99
//        printf("%d ", arr[i]);
    }
    printf("\n");

    clock_t start, end;
    double time;


    // Quick Sort
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
//    printf("Sorted array (Quick Sort): ");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
    time = ((double)(end - start) * 1000000) / CLOCKS_PER_SEC;
    printf("Time taken for Quick Sort = %lf microseconds\n", time);

    // Heap Sort
    start = clock();
    heapSort(arr, n);
    end = clock();
//    printf("Sorted array (Heap Sort): ");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
    time = ((double)(end - start) * 1000000) / CLOCKS_PER_SEC;
    printf("Time taken for Heap Sort = %lf microseconds\n", time);

    // Randomized Quick Sort
    start = clock();
    randomizedQuickSort(arr, 0, n - 1);
    end = clock();
//    printf("Sorted array (Randomized Quick Sort): ");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
    time = ((double)(end - start) * 1000000) / CLOCKS_PER_SEC;
    printf("Time taken for Randomized Quick Sort = %lf microseconds\n", time);
    
     // Merge Sort
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
//    printf("Sorted array (Merge Sort): ");

//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
    time = ((double)(end - start) * 1000000) / CLOCKS_PER_SEC;
    printf("Time taken for Merge Sort = %lf microseconds\n", time);

    return 0;
}

