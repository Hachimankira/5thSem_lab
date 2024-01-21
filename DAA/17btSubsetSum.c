#include <stdio.h>
// Function to print the subset with the selected elements
void printSubset(int subset[], int size) {
    printf("Subset: { ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}
// Function to check if a subset with the given sum exists
int isSubsetSum(int set[], int n, int sum, int subset[], int subsetSize, int index) {
    if (sum == 0) {
        printSubset(subset, subsetSize);
        return 1;
    }
    if (index == n) {
        return 0;
    }
    // Include the current element in the subset
    subset[subsetSize] = set[index];
    if (isSubsetSum(set, n, sum - set[index], subset, subsetSize + 1, index + 1)) {
        return 1;
    }
    // Exclude the current element from the subset
    return isSubsetSum(set, n, sum, subset, subsetSize, index + 1);
}
// Function to solve the Subset Sum problem
void subsetSum(int set[], int n, int sum) {
    int subset[100]; // Assuming a maximum of 100 elements in the set
    if (!isSubsetSum(set, n, sum, subset, 0, 0)) {
        printf("No subset with the given sum exists.\n");
    }
}
int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(set) / sizeof(set[0]);
    int sum = 9;
    printf("Given set: { ");
    for (int i = 0; i < n; i++) {
        printf("%d ", set[i]);
    }
    printf("}\n");
    printf("Target sum: %d\n", sum);
    subsetSum(set, n, sum);
    return 0;
}
