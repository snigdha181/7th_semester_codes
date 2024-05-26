#include <bits/stdc++.h>
using namespace std;
int main()
{
    string plaintext, ciphertext;
    int numRows, numCols;
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);
    // Calculate the number of rows and columns for the grid
    numRows = ceil(sqrt(plaintext.length()));
    numCols = ceil(static_cast<double>(plaintext.length()) / numRows);
    // Create a 2D matrix to hold the plaintext
    char matrix[100][100];  // Assuming the plaintext is not longer than 10000 characters
    // Fill the matrix with the plaintext characters row by row
    int index = 0;
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            if (index < plaintext.length())
            {
                matrix[i][j] = plaintext[index++];
            }
            else
            {
                matrix[i][j] = ' '; // Pad with spaces
            }
        }
    }
    // Read characters column by column to generate ciphertext
    ciphertext = "";
    for (int j = 0; j < numCols; ++j)
    {
        for (int i = 0; i < numRows; ++i)
        {
            ciphertext += matrix[i][j];
        }
    }
    cout << "Encrypted text: ";
    for (char &c : ciphertext)
    {
        cout << static_cast<char>(toupper(c));
    }
    cout << endl;
    // Decrypting the text
    string decryptedText = "";
    index = 0;
    for (int j = 0; j < numCols; ++j)
    {
        for (int i = 0; i < numRows; ++i)
        {
            if (index < ciphertext.length())
            {
                matrix[i][j] = ciphertext[index++];
            }
        }
    }
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            decryptedText += matrix[i][j];
        }
    }
    cout << "Decrypted text: " << decryptedText << endl;
    return 0;
}
