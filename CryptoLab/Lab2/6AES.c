#include <stdio.h>
#include <stdint.h>

// AES MixColumns matrix
uint8_t mix_columns_matrix[4][4] = {
    {0x02, 0x03, 0x01, 0x01},
    {0x01, 0x02, 0x03, 0x01},
    {0x01, 0x01, 0x02, 0x03},
    {0x03, 0x01, 0x01, 0x02}
};

void mix_columns(uint8_t state[4][4]) {
    uint8_t result[4][4];

    for (int c = 0; c < 4; c++) {
        for (int r = 0; r < 4; r++) {
            result[r][c] = 
                gmul(mix_columns_matrix[r][0], state[0][c]) ^
                gmul(mix_columns_matrix[r][1], state[1][c]) ^
                gmul(mix_columns_matrix[r][2], state[2][c]) ^
                gmul(mix_columns_matrix[r][3], state[3][c]);
        }
    }

    for (int c = 0; c < 4; c++) {
        for (int r = 0; r < 4; r++) {
            state[r][c] = result[r][c];
        }
    }
}

uint8_t gmul(uint8_t a, uint8_t b) {
    uint8_t p = 0;
    uint8_t counter;
    uint8_t hi_bit_set;
    for (counter = 0; counter < 8; counter++) {
        if (b & 1) {
            p ^= a;
        }
        hi_bit_set = (a & 0x80);
        a <<= 1;
        if (hi_bit_set) {
            a ^= 0x1B; // AES polynomial
        }
        b >>= 1;
    }
    return p;
}

void print_state(uint8_t state[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%02X ", state[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example state matrix (4x4) for illustration purposes
    uint8_t state[4][4] = {
        {0xDB, 0x13, 0x53, 0x45},
        {0xF2, 0x0A, 0x22, 0x5C},
        {0x01, 0x01, 0x01, 0x01},
        {0xC6, 0xC6, 0xC6, 0xC6}
    };

    printf("Original State:\n");
    print_state(state);

    mix_columns(state);
    printf("\nAfter MixColumns:\n");
    print_state(state);

    return 0;
}
