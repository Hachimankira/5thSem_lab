#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long mod_inverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) {
        x1 += m0;
    }

    return x1;
}

int is_prime(long long n) {
    if (n <= 1) {
        return 0;
    }
    if (n <= 3) {
        return 1;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }

    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }

    return 1;
}

long long generate_prime() {
    long long candidate;
    do {
        candidate = rand() % 9000 + 1000; // 4-digit numbers
    } while (!is_prime(candidate));
    return candidate;
}

long long generate_key(long long *pub_key, long long *priv_key, long long *modulus) {
    long long p = generate_prime();
    long long q = generate_prime();

    *modulus = p * q;
    long long phi = (p - 1) * (q - 1);

    long long e;
    do {
        e = rand() % (phi - 2) + 2;
    } while (gcd(e, phi) != 1);

    *pub_key = e;
    *priv_key = mod_inverse(e, phi);

    return *modulus;
}

long long mod_pow(long long base, long long exponent, long long modulus) {
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

int main() {
    long long pub_key, priv_key, modulus;
    modulus = generate_key(&pub_key, &priv_key, &modulus);

    char message[] = "CAB College";
    printf("Original Message: %s\n", message);

    long long encrypted[strlen(message)];
    for (int i = 0; i < strlen(message); ++i) {
        encrypted[i] = mod_pow(message[i], pub_key, modulus);
    }

    printf("Encrypted Message: ");
    for (int i = 0; i < strlen(message); ++i) {
        printf("%lld ", encrypted[i]);
    }
    printf("\n");

    char decrypted[strlen(message)];
    for (int i = 0; i < strlen(message); ++i) {
        decrypted[i] = mod_pow(encrypted[i], priv_key, modulus);
    }
    decrypted[strlen(message)] = '\0';

    printf("Decrypted Message: %s\n", decrypted);

    return 0;
}
