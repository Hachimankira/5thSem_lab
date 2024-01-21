#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
void knapSack(int W, int wt[], int val[], int n, int curWt, int curVal, int *maxVal) {
    if (curWt > W || n == 0) {
        *maxVal = max(*maxVal, curVal);
        return;
    }
    knapSack(W, wt, val, n - 1, curWt, curVal, maxVal);
    knapSack(W, wt, val, n - 1, curWt + wt[n - 1], curVal + val[n - 1], maxVal);
}
int main() {
    int i, n, *val, *wt, W;
    int randNum1, randNum2;
    double time;
    clock_t start, end;
    printf("Enter number of items:");
    scanf("%d", &n);
    printf("Enter size of knapsack:");
    scanf("%d", &W);
    val = (int *)malloc(n * sizeof(int));
    wt = (int *)malloc(n * sizeof(int));
    start = clock();
    for (i = 0; i < n; i++) {
        randNum1 = rand() % 1000;
        wt[i] = randNum1;
        randNum2 = rand() % 1000;
        val[i] = randNum2;
    }
    printf("Items:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d - Weight: %d, Value: %d\n", i + 1, wt[i], val[i]);
    }
    int maxVal = 0;
    knapSack(W, wt, val, n, 0, 0, &maxVal);
    printf("Maximum profit: %d\n", maxVal);
    end = clock();
    time = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("Time taken: %lf milliseconds\n", time);
    free(val);
    free(wt);
    return 0;
}
