//Implementation of Poker Test.

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define N 100 // Random numbers to be generated
int main() 
{
    // Initialize the frequency table
    int freq[10] = {0};
    srand(time(0));
    printf("The 50 random numbers generated are:\n");
    // Generate random 3-digit numbers and count the frequency of each digit
    for (int i = 0; i < N; i++) 
    {
        int num = rand() % 700 + 100; // Generate a random 3-digit number
        printf("%d\t",num);
        int d1 = num / 100; // Extract the first digit
        int d2 = (num / 10) % 10; // Extract the second digit
        int d3 = num % 10; // Extract the third digit
        freq[d1]++;
        freq[d2]++;
        freq[d3]++;
    }
    printf("\n");
    // Compute the chi-square statistic
    double chi_square = 0;
    for (int i = 0; i < 10; i++)
    {
        double expected = N/10.0; // Expected frequency of each digit
        double observed = freq[i];
        chi_square += (observed - expected)*(observed - expected) / expected;
    }
    // Print the results
 
    printf("Chi-square statistic: %f\n", chi_square);
    if (chi_square < 16.92) 
    {
        printf("The test passed (i.e., the numbers appear to be independent).\n");
    } 
    else 
    {
        printf("The test failed (i.e., the numbers do not appear to be independent).\n");
    }
    return 0;
}
