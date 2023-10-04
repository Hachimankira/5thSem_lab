#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long power(long long base, long long exponent, long long modulus) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

bool is_probable_prime(long long n, int k) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }

    // Apply Fermat's Little Theorem k times
    for (int i = 0; i < k; i++) {
        // Choose a random number between 2 and n-2
        long long a = rand() % (n - 2) + 2;
        if (power(a, n - 1, n) != 1) {
            return false; // n is composite
        }
    }

    return true; // n is probably prime
}

int main() {
    long long test_values[] = {2, 17, 19, 23, 7919, 104729, 9999991};
    int k = 5;
    int num_values = sizeof(test_values) / sizeof(test_values[0]);

    for (int i = 0; i < num_values; i++) {
        if (is_probable_prime(test_values[i], k)) {
            printf("%lld is probably prime\n", test_values[i]);
        } else {
            printf("%lld is composite\n", test_values[i]);
        }
    }

    return 0;
}
