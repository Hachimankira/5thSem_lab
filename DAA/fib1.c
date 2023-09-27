#include <stdio.h>
#include <time.h>

// Function to calculate the nth Fibonacci number iteratively
long long iterativeFibonacci(int n)
{
    if (n <= 1)
        return n;

    long long first = 0, second = 1, temp;

    for (int i = 2; i <= n; i++)
    {
        temp = first + second;
        first = second;
        second = temp;
    }

    return second;
}

int main()
{
    int n;
    double time_taken;
    clock_t start, end;

    printf("Enter the value of n for Fibonacci calculation: ");
    scanf("%d", &n);

    start = clock();
    long long result = iterativeFibonacci(n);
    end = clock();

    printf("The %dth Fibonacci number is: %lld\n", n, result);

    // Calculate and print the time taken for the calculation
    time_taken = ((double)(end - start) * 1000000) / CLOCKS_PER_SEC;
    printf("Time taken for Fibonacci calculation: %lf seconds\n", time_taken);

    return 0;
}
