#include <stdio.h>
#include <stdint.h>

// Initial Permutation (IP) table for DES
int initial_permutation_table[64] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
};

void apply_initial_permutation(uint64_t *block) {
    uint64_t result = 0;
    for (int i = 0; i < 64; i++) {
        int bit_position = initial_permutation_table[i] - 1;
        int bit_value = (*block >> (63 - bit_position)) & 1;
        result |= (uint64_t)bit_value << (63 - i);
    }
    *block = result;
}

void print_binary(uint64_t num) {
    for (int i = 63; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    uint64_t plaintext = 0x0123456789ABCDEF;

    printf("Original Plaintext:\n");
    print_binary(plaintext);

    apply_initial_permutation(&plaintext);
    printf("\nAfter Initial Permutation:\n");
    print_binary(plaintext);

    return 0;
}
