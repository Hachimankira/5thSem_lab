/* Program to find the nth Fibonacci number */
#include <stdio.h>
#include <time.h>
int main()
{
    int n, i;
    double first = 0, second = 1, temp, time;
    clock_t start, end;
    printf("Enter the position of fibonacci number:");
    scanf("%d", &n);
    start = clock();
    printf("%f,%f", first, second);
    i = 3;
    while (i <= n)
    {
        temp = first + second;
        first = second;
        second = temp;
        printf("%f \n", temp);
        i++;
    }
    printf("\n\n\n");
    end = clock();
    printf("The nth fibonacci number is: %lf \n", temp);
    time = ((double)(end - start) * 1000000) / CLOCKS_PER_SEC;
    printf("Time=%lf micro seconds", time);
}