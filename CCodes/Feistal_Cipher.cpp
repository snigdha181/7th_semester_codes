#include <iostream>
#include <bitset>
#include <cstdint>

using namespace std;

// Function F for the Feistel cipher
uint8_t F(uint8_t halfBlock, uint8_t key) {
    // Simple example: XOR operation
    return halfBlock ^ key;
}

// Encrypt function for Feistel cipher
uint16_t feistelEncrypt(uint16_t plaintext, uint8_t K0, uint8_t K1) {
    // Split plaintext into left and right halves
    uint8_t left = (plaintext >> 8) & 0xFF;
    uint8_t right = plaintext & 0xFF;

    // Number of rounds
    const int rounds = 2;

    // Feistel rounds
    for (int i = 0; i < rounds; ++i) {
        uint8_t temp = right;
        if (i == 0) {
            right = left ^ F(right, K0);
        } else {
            right = left ^ F(right, K1);
        }
        left = temp;
    }

    // Combine left and right halves to form the ciphertext
    return (left << 8) | right;
}

// Decrypt function for Feistel cipher
uint16_t feistelDecrypt(uint16_t ciphertext, uint8_t K0, uint8_t K1) {
    // Split ciphertext into left and right halves
    uint8_t left = (ciphertext >> 8) & 0xFF;
    uint8_t right = ciphertext & 0xFF;

    // Number of rounds (same as encryption)
    const int rounds = 2;

    // Feistel rounds (in reverse order for decryption)
    for (int i = rounds - 1; i >= 0; --i) {
        uint8_t temp = left;
        if (i == 0) {
            left = right ^ F(left, K0);
        } else {
            left = right ^ F(left, K1);
        }
        right = temp;
    }

    // Combine left and right halves to form the plaintext
    return (left << 8) | right;
}

int main() {
    // Example plaintext (4F4B in hexadecimal)
    uint16_t plaintext = 0x4F4B;

    // Keys for the Feistel cipher (K0 and K1)
    uint8_t K0 = 0b10101101;
    uint8_t K1 = 0b10110110;

    // Encrypt the plaintext
    uint16_t ciphertext = feistelEncrypt(plaintext, K0, K1);

    // Decrypt the ciphertext
    uint16_t decryptedText = feistelDecrypt(ciphertext, K0, K1);

    // Print results
    cout << "Plaintext: " << hex << plaintext << endl;
    cout << "Ciphertext: " << hex << ciphertext << endl;
    cout << "Decrypted Text: " << hex << decryptedText << endl;

    return 0;
}
