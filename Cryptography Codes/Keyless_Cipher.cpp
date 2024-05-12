#include <bits/stdc++.h>
using namespace std;
// Function to encrypt plaintext
string encrypt(const string& plaintext, int numRows, int numCols) {
    // Create a 2D matrix to hold the plaintext
    char matrix[numRows][numCols];
    // Fill the matrix with the plaintext characters row by row
    int index = 0;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (index < plaintext.length()) {
                matrix[i][j] = plaintext[index++];
            } else {
                matrix[i][j] = ' '; // If plaintext is shorter than the matrix, pad with spaces
            }
        }
    }
    // Read characters column by column to generate ciphertext
    string ciphertext = "";
    for (int j = 0; j < numCols; ++j) {
        for (int i = 0; i < numRows; ++i) {
            ciphertext += matrix[i][j];
        }
    }
    return ciphertext;
}
// Function to decrypt ciphertext
string decrypt(const string& ciphertext, int numRows, int numCols) {
    // Calculate the number of characters in the ciphertext
    int totalChars = ciphertext.length();
    // Calculate the number of characters that can fit in the last row
    int charsInLastRow = totalChars % numRows;
    // Calculate the number of padding characters in the last column
    int paddingInLastColumn = (charsInLastRow == 0) ? 0 : (numRows - charsInLastRow);
    // Calculate the number of full columns
    int fullCols = (totalChars - paddingInLastColumn) / numRows;
    // Calculate the number of columns in the last row
    int colsInLastRow = fullCols + ((charsInLastRow == 0) ? 0 : 1);
    // Create a 2D matrix to hold the ciphertext
    char matrix[numRows][numCols];
    // Fill the matrix with the ciphertext characters column by column
    int index = 0;
    for (int j = 0; j < colsInLastRow; ++j) {
        for (int i = 0; i < numRows; ++i) {
            if (i < numRows - paddingInLastColumn || j < colsInLastRow - 1) {
                matrix[i][j] = ciphertext[index++];
            } else {
                matrix[i][j] = ' '; // Pad remaining cells with spaces
            }
        }
    }
    // Read characters row by row to generate plaintext
    string plaintext = "";
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < colsInLastRow; ++j) {
            plaintext += matrix[i][j];
        }
    }
    return plaintext;
}
int main() {
    string plaintext, ciphertext;
    int numRows, numCols;
    // Input plaintext
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);
    // Calculate the number of rows and columns for the grid
    numRows = ceil(sqrt(plaintext.length()));
    numCols = ceil(static_cast<double>(plaintext.length()) / numRows);
    // Encrypt plaintext
    ciphertext = encrypt(plaintext, numRows, numCols);
    cout << "Encrypted text: " ;
    for (char& c : ciphertext) {
        cout << static_cast<char>(toupper(c));
    }
    cout << endl;
    // Decrypt ciphertext
    string decryptedText = decrypt(ciphertext, numRows, numCols);
    cout << "Decrypted text: " << decryptedText << endl;
    return 0;
}
