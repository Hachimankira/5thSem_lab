#include <stdio.h>
#include <limits.h>
#include <time.h>
int MatrixChainOrder(int p[], int n) {
    int m[n][n];
    /* m[i,j] = Minimum number of scalar multiplications needed
       to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where
       dimension of A[i] is p[i-1] x p[i] */
    int i, j, k, L, q;
    /* L is chain length. */
    for (i = 1; i < n; i++)
        m[i][i] = 0;
    /* L is chain length. */
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n - 1];
}
int main() {
    int size;
    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    // Get the input array from the user
    printf("Enter the dimensions of matrices (size %d): ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    // Measure the time to run the MatrixChainOrder function
    clock_t start = clock();
    int minMultiplications = MatrixChainOrder(arr, size);
    clock_t end = clock();
    // Calculate the time taken
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Minimum number of multiplications is %d\n", minMultiplications);
    printf("Time taken to run MatrixChainOrder: %f seconds\n", cpu_time_used);
    return 0;
}
