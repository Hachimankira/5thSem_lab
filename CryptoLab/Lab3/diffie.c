#include <stdio.h>
#include <math.h>

// Function to calculate (base^exponent) % modulus efficiently
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
    // Publicly shared prime number and base (generator)
    long long prime = 23;  // Example prime number
    long long base = 5;    // Example base

    // Alice's private key
    long long alice_private_key = 6; // Example private key for Alice
    long long alice_public_key = mod_pow(base, alice_private_key, prime);

    // Bob's private key
    long long bob_private_key = 15; // Example private key for Bob
    long long bob_public_key = mod_pow(base, bob_private_key, prime);

    // Shared secret key calculation
    long long shared_secret_alice = mod_pow(bob_public_key, alice_private_key, prime);
    long long shared_secret_bob = mod_pow(alice_public_key, bob_private_key, prime);

    printf("Publicly Shared Prime: %lld\n", prime);
    printf("Publicly Shared Base: %lld\n", base);
    printf("Alice's Private Key: %lld\n", alice_private_key);
    printf("Alice's Public Key: %lld\n", alice_public_key);
    printf("Bob's Private Key: %lld\n", bob_private_key);
    printf("Bob's Public Key: %lld\n", bob_public_key);
    printf("Shared Secret Key (Alice's side): %lld\n", shared_secret_alice);
    printf("Shared Secret Key (Bob's side): %lld\n", shared_secret_bob);

    return 0;
}
