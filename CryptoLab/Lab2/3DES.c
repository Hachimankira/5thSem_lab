#include <stdio.h>
#include <stdint.h>

// Expansion (E) table for DES
int expansion_table[48] = {
    32, 1,  2,  3,  4,  5,
    4,  5,  6,  7,  8,  9,
    8,  9,  10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32, 1
};

// P-box permutation for DES
int p_box_permutation[32] = {
    16, 7, 20, 21, 29, 12, 28, 17,
    1,  15, 23, 26, 5,  18, 31, 10,
    2,  8, 24, 14, 32, 27, 3,  9,
    19, 13, 30, 6,  22, 11, 4,  25
};

// Apply the expansion E-box to a 32-bit input
uint64_t apply_expansion(uint32_t input) {
    uint64_t result = 0;
    for (int i = 0; i < 48; i++) {
        int bit_position = expansion_table[i] - 1;
        int bit_value = (input >> (32 - bit_position)) & 1;
        result |= (uint64_t)bit_value << (47 - i);
    }
    return result;
}

// Apply the P-box permutation to a 32-bit input
uint32_t apply_p_box(uint32_t input) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        int bit_position = p_box_permutation[i] - 1;
        int bit_value = (input >> (32 - bit_position)) & 1;
        result |= (uint32_t)bit_value << (31 - i);
    }
    return result;
}

void print_binary(uint64_t num, int num_bits) {
    for (int i = num_bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    uint32_t data = 0x12345678;
    uint32_t subkey = 0xAABBCCDD;

    printf("Original Data:\n");
    print_binary(data, 32);

    uint64_t expanded_data = apply_expansion(data);
    printf("\nAfter Expansion:\n");
    print_binary(expanded_data, 48);

    uint64_t xor_result = expanded_data ^ subkey;
    printf("\nAfter XOR with Subkey:\n");
    print_binary(xor_result, 48);

    uint32_t p_box_result = apply_p_box(xor_result);
    printf("\nAfter P-box Permutation:\n");
    print_binary(p_box_result, 32);

    return 0;
}
