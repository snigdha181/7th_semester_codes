#include <bits/stdc++.h>
using namespace std;

// Function to convert a character to its numeric equivalent in the alphabet
int charToInt(char c) {
    return c - 'a';
}

// Function to convert a numeric value to its corresponding character in the alphabet
char intToChar(int x) {
    return 'a' + x;
}

// Function to encrypt the plaintext using the Hill Cipher
string encrypt(string plaintext, vector<vector<int>>& key) {
    string ciphertext = "";
    int n = key.size();

    // Padding the plaintext if necessary
    if (plaintext.length() % n != 0) {
        int padding = n - (plaintext.length() % n);
        for (int i = 0; i < padding; ++i)
            plaintext += 'x'; // Adding 'x' as padding character
    }

    // Encrypting the plaintext
    for (int i = 0; i < plaintext.length(); i += n) {
        vector<int> block(n, 0);
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                block[j] += charToInt(plaintext[i + k]) * key[j][k];
                block[j] %= 26; // Modulo 26 to keep the result within the alphabet range
            }
            ciphertext += intToChar(block[j]);
        }
    }

    return ciphertext;
}

int main() {
    int n;
    string text;
    cout << "Enter the dimension of the key matrix: ";
    cin >> n;

    vector<vector<int>> key(n, vector<int>(n));
    cout << "Enter the key matrix elements row-wise: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> key[i][j];
        }
    }

    cout << "\nEnter plaintext: ";
    cin >> text;

    string ciphertext = encrypt(text, key);

    cout << "\nCiphertext: " << ciphertext << endl;

    return 0;
}
