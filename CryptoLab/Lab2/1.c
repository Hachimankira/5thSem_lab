#include <stdio.h>
#include <stdint.h>

#define LEFT_SHIFT(value, num_bits) (((value) << (num_bits)) | ((value) >> (28 - (num_bits))))

void generate_subkeys(const uint64_t key, uint64_t subkeys[16]) {
    const int pc1[] = {
        57, 49, 41, 33, 25, 17, 9,
        1, 58, 50, 42, 34, 26, 18,
        10, 2, 59, 51, 43, 35, 27,
        19, 11, 3, 60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15,
        7, 62, 54, 46, 38, 30, 22,
        14, 6, 61, 53, 45, 37, 29,
        21, 13, 5, 28, 20, 12, 4
    };

    const int pc2[] = {
        14, 17, 11, 24, 1, 5,
        3, 28, 15, 6, 21, 10,
        23, 19, 12, 4, 26, 8,
        16, 7, 27, 20, 13, 2,
        41, 52, 31, 37, 47, 55,
        30, 40, 51, 45, 33, 48,
        44, 49, 39, 56, 34, 53,
        46, 42, 50, 36, 29, 32
    };

    const int round_shifts[16] = {
        1, 1, 2, 2, 2, 2, 2, 2,
        1, 2, 2, 2, 2, 2, 2, 1
    };

    uint64_t pc1_key = 0;
    for (int i = 0; i < 56; i++) {
        pc1_key |= ((key >> (64 - pc1[i])) & 1) << (55 - i);
    }

    uint32_t c0 = pc1_key >> 28;
    uint32_t d0 = pc1_key & 0xFFFFFFF;

    for (int round_num = 0; round_num < 16; round_num++) {
        c0 = LEFT_SHIFT(c0, round_shifts[round_num]);
        d0 = LEFT_SHIFT(d0, round_shifts[round_num]);

        uint64_t cd_concat = ((uint64_t)c0 << 28) | d0;
        uint64_t subkey = 0;
        for (int i = 0; i < 48; i++) {
            subkey |= ((cd_concat >> (56 - pc2[i])) & 1) << (47 - i);
        }

        subkeys[round_num] = subkey;
    }
}

int main() {
    uint64_t key = 0x0001001100110100010101110111100110011011101111001101111111110001;
    uint64_t subkeys[16];

    generate_subkeys(key, subkeys);

    for (int i = 0; i < 16; i++) {
        printf("Round %d Subkey: %016llX\n", i + 1, subkeys[i]);
    }

    return 0;
}
