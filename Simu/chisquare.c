//Implementation of Chi Square Test.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_BINS 10 // number of bins for chi-square test
int main()
{
    printf("Biraj Pudasaini\n");
    int num_random, i;
    double rand_num, expected_frequency, chi_square, chi_critical;
    int observed_frequency[NUM_BINS] = {0};

    // ask user for total number of random numbers
    printf("How many random numbers do you want to generate: ");
    scanf("%d", &num_random);

    // generate random numbers and count their frequencies in bins
    printf("\nRandom numbers generated are:\n");
    for (i = 0; i < num_random; i++) 
    {
        rand_num = (double) rand() / RAND_MAX;
        observed_frequency[(int)(rand_num * NUM_BINS)]++;
        printf("%f \n", rand_num);
    }

    // calculate expected frequency and chi-square value
    expected_frequency = (double) num_random / NUM_BINS;
    chi_square = 0.0;
    for (i = 0; i < NUM_BINS; i++) 
    {
        chi_square += pow(observed_frequency[i] - expected_frequency, 2) / 
        expected_frequency;
    }
    // calculate critical value of chi-square at 5% significance level
    chi_critical = 16.92; // from chi-square table with 9 degrees of freedom
    // print results
    printf("\n\nChi-square value: %f\n", chi_square);
    if (chi_square > chi_critical) 
    {
        printf("The random numbers do not pass the chi-square test at 5%% significance level.\n");
    } else {
        printf("The random numbers pass the chi-square test at 5%% significance level.\n");
    }
    return 0;
}