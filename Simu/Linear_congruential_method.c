//Implement Linear Congruential Method for random number generation.

#include<stdio.h>
#define MAX 50
int main()
{
    int i, n, a, seed, c, m, r[MAX];
    printf("How many random number you want to generate: ");
    scanf("%d", &n);
    printf("Enter value of a,c and m: ");
    scanf("%d %d %d", &a,&c, &m);
    // printf("Enter value of c: ");
    // scanf("%d", &c);
    // printf("Enter value of m: ");
    // scanf("%d", &m);
    printf("Enter the seed value: ");
    scanf("%d", &r[0]);
    for(i=1; i<=n; i++)
    {
        r[i] = (a*r[i-1] + c) % m;
    }
    printf("Generated random numbers are: \n");
    for(i=1; i<=n; i++)
    {
        printf("%f\n", (float)r[i]/m);

    }
}