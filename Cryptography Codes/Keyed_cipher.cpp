#include <bits/stdc++.h>
using namespace std;

int main() {
    string plaintext, ciphertext, key;
    int numRows, numCols;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the key (as a permutation of column indices starting from 1): ";
    getline(cin, key);

    // Remove spaces from plaintext for simplicity
    plaintext.erase(remove(plaintext.begin(), plaintext.end(), ' '), plaintext.end());

    // Calculate the number of rows and columns for the grid
    numRows = ceil(sqrt(plaintext.length()));
    numCols = ceil(static_cast<double>(plaintext.length()) / numRows);

    // Ensure the key length matches the number of columns
    if (key.length() != numCols) {
        cout << "Key length must match the number of columns (" << numCols << ")." << endl;
        return 1;
    }

    // Convert key characters to column indices
    int colOrder[100]; // Assuming the number of columns will not exceed 100
    for (int i = 0; i < numCols; ++i) {
        colOrder[i] = key[i] - '1'; // Convert 1-based index to 0-based index
    }

    // Create a 2D matrix to hold the plaintext
    char matrix[100][100]; // Assuming the plaintext is not longer than 10000 characters

    // Fill the matrix with the plaintext characters row by row
    int index = 0;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (index < plaintext.length()) {
                matrix[i][j] = plaintext[index++];
            } else {
                matrix[i][j] = ' '; // Pad with spaces
            }
        }
    }

    // Read characters column by column based on the key order to generate ciphertext
    ciphertext = "";
    for (int k = 0; k < numCols; ++k) {
        int col = colOrder[k];
        for (int i = 0; i < numRows; ++i) {
            if (matrix[i][col] != ' ') {
                ciphertext += matrix[i][col];
            }
        }
    }

    cout << "Encrypted text: ";
    for (char &c : ciphertext) {
        cout << static_cast<char>(toupper(c));
    }
    cout << endl;

    // Decrypting the text
    string decryptedText = "";
    index = 0;
    for (int k = 0; k < numCols; ++k) {
        int col = colOrder[k];
        for (int i = 0; i < numRows; ++i) {
            if (index < ciphertext.length()) {
                matrix[i][col] = ciphertext[index++];
            } else {
                matrix[i][col] = ' '; // Pad with spaces
            }
        }
    }

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (matrix[i][j] != ' ') {
                decryptedText += matrix[i][j];
            }
        }
    }

    cout << "Decrypted text: " << decryptedText << endl;
    return 0;
}
