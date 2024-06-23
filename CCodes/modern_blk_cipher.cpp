#include <iostream>
#include <array>

using namespace std;

// Simple S-box for demonstration
const uint8_t SBox[16] = {
    0x6, 0x4, 0xC, 0x5, 0x0, 0x7, 0x2, 0xE,
    0x1, 0xF, 0x3, 0xA, 0xD, 0x9, 0xB, 0x8
};

// Simple P-box for demonstration
const uint8_t PBox[16] = {
    0x0, 0x4, 0x8, 0xC, 0x1, 0x5, 0x9, 0xD,
    0x2, 0x6, 0xA, 0xE, 0x3, 0x7, 0xB, 0xF
};

// Key for demonstration
const uint8_t key[16] = {
    0x3, 0xF, 0xE, 0x2, 0x4, 0xC, 0x8, 0x1,
    0x7, 0xB, 0x5, 0x0, 0x9, 0x6, 0xD, 0xA
};

int main() {
    // Example plaintext block (16 numbers)
    uint8_t plaintext[16] = {
        1, 2, 3, 4, 5, 6, 7, 8,
        9, 10, 11, 12, 13, 14, 15, 16
    };
    uint8_t state[16];

    // Initial AddRoundKey step
    for (int i = 0; i < 16; ++i) {
        state[i] = plaintext[i] ^ key[i];
    }

    // Number of rounds
    const int rounds = 4;

    for (int round = 0; round < rounds; ++round) {
        // SubBytes step
        for (int i = 0; i < 16; ++i) {
            state[i] = SBox[state[i]];
        }

        // ShiftRows step
        uint8_t temp[16];
        for (int i = 0; i < 16; ++i) {
            temp[i] = state[PBox[i]];
        }
        for (int i = 0; i < 16; ++i) {
            state[i] = temp[i];
        }

        // AddRoundKey step
        for (int i = 0; i < 16; ++i) {
            state[i] ^= key[i];
        }
    }

    // Print the ciphertext
    cout << "Ciphertext: ";
    for (int i = 0; i < 16; ++i) {
        cout << (int)state[i] << " ";
    }
    cout << endl;

    return 0;
}

