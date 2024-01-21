#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_CHAR 256
struct Node {
    char data;
    unsigned frequency;
};
int compareNodes(const void* a, const void* b) {
    return ((struct Node*)a)->frequency - ((struct Node*)b)->frequency;
}
void generateRandomFrequencies(struct Node* data, int size) {
    for (int i = 0; i < size; i++) {
        data[i].data = 'a' + i;
        data[i].frequency = rand() % 100 + 1;
    }
}
void printFrequencies(struct Node* data, int size) {
    printf("Initial Frequencies:\n");
    for (int i = 0; i < size; i++) {
        printf("(%c, %u) ", data[i].data, data[i].frequency);
    }
    printf("\n");
}
void analyzeHuffmanAlgorithm(struct Node* data, int size) {
    clock_t start, end;
    double cpu_time_used;
    // Measure time to generate Huffman codes
    start = clock();
    // Sorting nodes based on frequency (Greedy Algorithm)
    qsort(data, size, sizeof(data[0]), compareNodes);
    // Huffman code generation (Greedy Algorithm)
    printf("Huffman Codes:\n");
    for (int i = 0; i < size; i++) {
        printf("'%c': %d\n", data[i].data, i);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to generate Huffman codes: %f seconds\n", cpu_time_used);
}
int main() {
    int numInputs;
    printf("Enter the number of inputs: ");
    scanf("%d", &numInputs);
    struct Node* input = malloc(numInputs * sizeof(struct Node));
    generateRandomFrequencies(input, numInputs);
    printFrequencies(input, numInputs);
    analyzeHuffmanAlgorithm(input, numInputs);
    free(input);
    return 0;
}
