#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Item {
    int value;
    int weight;
};
int compare(const void *a, const void *b) {
    double ratioA = ((double) ((struct Item *)a)->value) / ((struct Item *)a)->weight;
    double ratioB = ((double) ((struct Item *)b)->value) / ((struct Item *)b)->weight;
    return (ratioB > ratioA) ? 1 : -1;
}
double fractionalKnapsack(struct Item items[], int n, int capacity) {
    
    qsort(items, n, sizeof(struct Item), compare);
    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {     
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += (double) (remainingWeight * items[i].value) / items[i].weight;
            break;  
        }
    }
    return totalValue;
}
int main() {
    
    srand(time(NULL));
    for (int n = 100; n <= 1000; n += 100) {
        struct Item items[n];      
        for (int i = 0; i < n; i++) {
            items[i].value = rand() % 100 + 1;  
            items[i].weight = rand() % 50 + 1;  
        }
        clock_t start = clock();  
        int capacity = 2 * n;      
        double result = fractionalKnapsack(items, n, capacity);
        clock_t end = clock();  
        double timeTaken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
        printf("Input Size: %d, Time Taken: %.6f ms, Result: %.2f\n", n, timeTaken, result);
    }

    return 0;
}
