#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Job {
    int id;
    int deadline;
    int profit;
};
int compareProfit(const void *a, const void *b) {
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}
void jobSequencingNaive(struct Job jobs[], int n) {
    int result[n]; 
    int slots[n];  
    for (int i = 0; i < n; i++) {
        slots[i] = -1;
    }
    qsort(jobs, n, sizeof(struct Job), compareProfit);
    for (int i = 0; i < n; i++) {
        for (int j = (jobs[i].deadline - 1); j >= 0; j--) {
            if (slots[j] == -1) {
                result[j] = i;  
                slots[j] = 1;   
                break;
            }
        }
    }
    int totalProfit = 0;
    printf("Job Sequence (Naïve Algorithm): ");
    for (int i = 0; i < n; i++) {
        if (slots[i] != -1) {
            printf("%d ", jobs[result[i]].id);
            totalProfit += jobs[result[i]].profit;
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}
void jobSequencingGreedy(struct Job jobs[], int n) {
    int result[n]; 
    int slots[n];  
    for (int i = 0; i < n; i++) {
        slots[i] = -1;
    }
    qsort(jobs, n, sizeof(struct Job), compareProfit);
    for (int i = 0; i < n; i++) {
        for (int j = (jobs[i].deadline - 1); j >= 0; j--) {
            if (slots[j] == -1) {
                result[j] = i;  
                slots[j] = 1;   
                break;
            }
        }
    }
    int totalProfit = 0;
    printf("Job Sequence (Greedy Algorithm): ");
    for (int i = 0; i < n; i++) {
        if (slots[i] != -1) {
            printf("%d ", jobs[result[i]].id);
            totalProfit += jobs[result[i]].profit;
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}
int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    struct Job jobs[n];
    srand(time(NULL)); 
    for (int i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        jobs[i].deadline = rand() % n + 1;  
        jobs[i].profit = rand() % 100 + 1;  
    }
    clock_t naiveStart = clock();
    jobSequencingNaive(jobs, n);
    clock_t naiveEnd = clock();
    double naiveTime = ((double) (naiveEnd - naiveStart))*1000 / CLOCKS_PER_SEC;
    clock_t greedyStart = clock();
    jobSequencingGreedy(jobs, n);
    clock_t greedyEnd = clock();
    double greedyTime = ((double) (greedyEnd - greedyStart))*1000 / CLOCKS_PER_SEC;
    printf("\nTime taken for Naïve Algorithm: %f miliseconds\n", naiveTime);
    printf("Time taken for Greedy Algorithm: %f miliseconds\n", greedyTime);
    return 0;
}
