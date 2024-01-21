#include <stdio.h>
#include <time.h>
int min(int a, int b);
void floyds(int p[10][10], int n) {
    int i, j, k;
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (i == j) {
                    p[i][j] = 0;
                } else {
                    p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
                }
            }
        }
    }
}
int min(int a, int b) {
    return (a < b) ? a : b;
}
int main() {
    double time;
    clock_t start, end;
    int p[10][10], w, n, e, u, v, i, j;
    printf("\n Enter the number of vertices:");
    scanf("%d", &n);
    printf("\n Enter the number of edges: \n");
    scanf("%d", &e);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            p[i][j] = 999;
        }
    }
    for (i = 1; i <= e; i++) {
        printf("\n Enter the end vertices of edge %d with its weight \n", i);
        scanf("%d%d%d", &u, &v, &w);
        p[u][v] = w;
    }
    printf("\n Matrix of input data:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d \t", p[i][j]);
        }
        printf("\n");
    }
    start = clock();
    floyds(p, n);
    printf("\n Transitive closure:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d \t", p[i][j]);
        }
        printf("\n");
    }
    printf("\n The shortest paths are:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i != j) {
                printf("\n <%d,%d> = %d", i, j, p[i][j]);
            }
        }
    }
    end = clock();
    time = ((double) (end - start) * 1000) / CLOCKS_PER_SEC;  // Corrected time calculation
    printf("\n Time = %lf milliseconds", time);
    return 0;
}
