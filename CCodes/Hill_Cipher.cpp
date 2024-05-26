#include <iostream>
#include <string>
using namespace std;

int main() {
    string message = "ACT";
    string key = "GYBNQKURP";
    int keyMatrix[3][3];
    int messageVector[3][1];
    int cipherMatrix[3][1];
    string CipherText;

    // Generate key matrix
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            keyMatrix[i][j] = (key[k]) % 65;
            k++;
        }
    }

    // Generate vector for the message
    for (int i = 0; i < 3; i++)
        messageVector[i][0] = (message[i]) % 65;

    // Encrypt the message
    int x;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 1; j++) {
            cipherMatrix[i][j] = 0;
            for (x = 0; x < 3; x++) {
                cipherMatrix[i][j] += keyMatrix[i][x] * messageVector[x][j];
            }
            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }

    // Generate the encrypted text
    for (int i = 0; i < 3; i++)
        CipherText += cipherMatrix[i][0] + 65;

    // Print the ciphertext
    cout << "Ciphertext: " << CipherText << endl;

    // Find position of each character in the ciphertext
    cout << "Positions:" << endl;
    for (int i = 0; i < CipherText.length(); i++) {
        cout << CipherText[i] << ": " << (CipherText[i] - 'A' + 1) << endl;
    }

    return 0;
}
