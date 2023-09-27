#include <stdio.h>
#include <stdint.h>

// AES S-box substitution table
uint8_t s_box[256] = {
    0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
    // ...
};

// AES ShiftRows permutation offsets for each row
int shift_offsets[4][4] = {
    {0, 1, 2, 3},
    {1, 2, 3, 0},
    {2, 3, 0, 1},
    {3, 0, 1, 2}
};

void sub_bytes(uint8_t state[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[i][j] = s_box[state[i][j]];
        }
    }
}

void shift_rows(uint8_t state[4][4]) {
    for (int i = 0; i < 4; i++) {
        uint8_t temp[4];
        for (int j = 0; j < 4; j++) {
            temp[j] = state[i][(j + shift_offsets[i][j]) % 4];
        }
        for (int j = 0; j < 4; j++) {
            state[i][j] = temp[j];
        }
    }
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
        {0x32, 0x88, 0x31, 0xE0},
        {0x43, 0x5A, 0x31, 0x37},
        {0xF6, 0x30, 0x98, 0x07},
        {0xA8, 0x8D, 0xA2, 0x34}
    };

    printf("Original State:\n");
    print_state(state);

    sub_bytes(state);
    printf("\nAfter SubBytes:\n");
    print_state(state);

    shift_rows(state);
    printf("\nAfter ShiftRows:\n");
    print_state(state);

    return 0;
}
