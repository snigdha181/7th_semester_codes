#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int SIZE = 5;

string prepareKey(string key) {
    string preparedKey;
    bool visited[26] = {false};

    for (char &c : key) {
        if (isalpha(c)) {
            c = toupper(c);
            if (!visited[c - 'A'] && c != 'J') {
                preparedKey += c;
                visited[c - 'A'] = true;
            }
        }
    }

    for (char c = 'A'; c <= 'Z'; ++c) {
        if (c != 'J' && !visited[c - 'A']) {
            preparedKey += c;
        }
    }

    return preparedKey;
}

void generatePlayfairMatrix(string key, char playfairMatrix[SIZE][SIZE]) {
    key = prepareKey(key);
    int index = 0;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            playfairMatrix[i][j] = key[index++];
        }
    }
}

void encryptPair(char playfairMatrix[SIZE][SIZE], char a, char b) {
    int r1, c1, r2, c2;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (playfairMatrix[i][j] == a) {
                r1 = i;
                c1 = j;
            }
            if (playfairMatrix[i][j] == b) {
                r2 = i;
                c2 = j;
            }
        }
    }

    if (r1 == r2) {
        cout << playfairMatrix[r1][(c1 + 1) % SIZE] << playfairMatrix[r2][(c2 + 1) % SIZE];
    } else if (c1 == c2) {
        cout << playfairMatrix[(r1 + 1) % SIZE][c1] << playfairMatrix[(r2 + 1) % SIZE][c2];
    } else {
        cout << playfairMatrix[r1][c2] << playfairMatrix[r2][c1];
    }
}

void decryptPair(char playfairMatrix[SIZE][SIZE], char a, char b) {
    int r1, c1, r2, c2;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (playfairMatrix[i][j] == a) {
                r1 = i;
                c1 = j;
            }
            if (playfairMatrix[i][j] == b) {
                r2 = i;
                c2 = j;
            }
        }
    }

    if (r1 == r2) {
        cout << playfairMatrix[r1][(c1 + SIZE - 1) % SIZE] << playfairMatrix[r2][(c2 + SIZE - 1) % SIZE];
    } else if (c1 == c2) {
        cout << playfairMatrix[(r1 + SIZE - 1) % SIZE][c1] << playfairMatrix[(r2 + SIZE - 1) % SIZE][c2];
    } else {
        cout << playfairMatrix[r1][c2] << playfairMatrix[r2][c1];
    }
}

int main() {
    string key = "LGDBAQMHECURNIFXVSOKZYWTP";
    char playfairMatrix[SIZE][SIZE];
    generatePlayfairMatrix(key, playfairMatrix);

    string plaintext;
    cout << "Enter the plaintext: ";
    cin >> plaintext;

    for (char &c : plaintext) {
        c = toupper(c);
        if (c == 'J') c = 'I';
    }

    cout << "Encrypted text: ";
    for (int i = 0; i < plaintext.length(); i += 2) {
        if (i == plaintext.length() - 1) {
            encryptPair(playfairMatrix, plaintext[i], 'X');
        } else if (plaintext[i] == plaintext[i + 1]) {
            encryptPair(playfairMatrix, plaintext[i], 'X');
            --i;
        } else {
            encryptPair(playfairMatrix, plaintext[i], plaintext[i + 1]);
        }
    }

    cout << endl;

    string ciphertext;
    cout << "Enter the ciphertext: ";
    cin >> ciphertext;

    cout << "Decrypted text: ";
    for (int i = 0; i < ciphertext.length(); i += 2) {
        decryptPair(playfairMatrix, ciphertext[i], ciphertext[i + 1]);
    }

    return 0;
}
