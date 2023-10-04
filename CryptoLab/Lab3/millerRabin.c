#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long modular_pow(long long base, long long exponent, long long modulus) {
    long long result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

bool is_composite(long long a, long long d, long long n, int s) {
    long long x = modular_pow(a, d, n);
    if (x == 1 || x == n - 1) {
        return false;
    }

    for (int i = 0; i < s - 1; i++) {
        x = (x * x) % n;
        if (x == n - 1) {
            return false;
        }
    }
    return true;
}

bool miller_rabin(long long n, int k) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }

    int s = 0;
    long long d = n - 1;
    while (d % 2 == 0) {
        s++;
        d /= 2;
    }

    for (int i = 0; i < k; i++) {
        long long a = rand() % (n - 2) + 2;
        if (is_composite(a, d, n, s)) {
            return false;
        }
    }
    return true;
}

int main() {
    long long test_values[] = {2, 17, 19, 23, 7919, 104729, 9999991};
    int k = 5;
    int num_values = sizeof(test_values) / sizeof(test_values[0]);

    for (int i = 0; i < num_values; i++) {
        if (miller_rabin(test_values[i], k)) {
            printf("%lld is prime\n", test_values[i]);
        } else {
            printf("%lld is composite\n", test_values[i]);
        }
    }

    return 0;
}
