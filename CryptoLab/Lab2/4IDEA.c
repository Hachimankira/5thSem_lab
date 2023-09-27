#include <stdio.h>
#include <stdint.h>

void generate_subkeys(const uint16_t key[8], uint16_t subkeys[52]) {
    for (int i = 0; i < 8; i++) {
        subkeys[i] = key[i];
    }

    for (int i = 8; i < 52; i++) {
        int j = i - 8;
        subkeys[i] = (subkeys[j] << 9) | (subkeys[(j + 1) % 8] >> 7);
    }
}

int main() {
    // 128-bit encryption key in hexadecimal format
    uint16_t key[8] = {
        0x2BD6, 0xE4B7, 0xF26D, 0x58A9,
        0xC71D, 0xB85A, 0x6543, 0x1398
    };

    uint16_t subkeys[52];
    generate_subkeys(key, subkeys);

    printf("Generated Subkeys:\n");
    for (int i = 0; i < 52; i++) {
        printf("Subkey %d: %04X\n", i + 1, subkeys[i]);
    }

    return 0;
}
