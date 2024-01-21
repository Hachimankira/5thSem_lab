#include <stdio.h>
#include <limits.h>
#define N 4 // Number of cities
// Function to find the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}
// Function to solve the Travelling Salesman Problem using dynamic programming
int tsp(int graph[N][N], int mask, int pos, int dp[N][1 << N], int path[N][1 << N]) {
    // If all cities have been visited
    if (mask == (1 << N) - 1) {
        return graph[pos][0]; // Return to the starting city
    }
    // If the solution has already been calculated
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }
    int ans = INT_MAX;
    int nextCity = -1;
    // Try to visit each city that has not been visited yet
    for (int city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) { // If the city has not been visited
            int newMask = mask | (1 << city);
            int cost = graph[pos][city] + tsp(graph, newMask, city, dp, path);
            if (cost < ans) {
                ans = cost;
                nextCity = city;
            }
        }
    }
    path[pos][mask] = nextCity; // Store the next city in the path
    return dp[pos][mask] = ans;
}
// Function to initialize and call the tsp function
int travellingSalesman(int graph[N][N], int path[N][1 << N]) {
    int dp[N][1 << N]; // Dynamic programming table to store solutions
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (1 << N); j++) {
            dp[i][j] = -1; // Initialize with -1
            path[i][j] = -1; // Initialize with -1
        }
    }
    int mask = 1; // Start from the first city
    int minCost = tsp(graph, mask, 0, dp, path);
    return minCost;
}
// Function to print the path
void printPath(int path[N][1 << N], int start) {
    int mask = 1; // Start from the first city
    int pos = start;
    printf("Path: %d", pos + 1);
    for (int i = 0; i < N - 1; i++) {
        int nextCity = path[pos][mask];
        printf(" -> %d", nextCity + 1);
        mask |= (1 << nextCity);
        pos = nextCity;
    }
    printf(" -> 1\n");
}
int main() {
    int graph[N][N];
    int path[N][1 << N];
    // Get input for the adjacency matrix
    printf("Enter the adjacency matrix (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int minCost = travellingSalesman(graph, path);
    printf("Minimum cost for the Travelling Salesman Problem: %d\n", minCost);
    // Print the path
    printf("Optimal Path:\n");
    printPath(path, 0); // Assuming starting from city 1
    return 0;
}
