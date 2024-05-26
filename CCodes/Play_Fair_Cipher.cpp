#include <bits/stdc++.h>
using namespace std;
const int SIZE = 5;
int main()
{
    string key = "LGDBAQMHECURNIFXVSOKZYWTP";
    char matrix[SIZE][SIZE];
    // Generate the key matrix
    string KEY;
    bool visited[26] = {false};
    int index = 0;
    for (char &c : key)
    {
        if (isalpha(c))
        {
            c = toupper(c);
            if (!visited[c - 'A'] && c != 'J')
            {
                KEY += c;
                visited[c - 'A'] = true;
                matrix[index / SIZE][index % SIZE] = c;
                index++;
            }
        }
    }
    for (char c = 'A'; c <= 'Z'; ++c)
    {
        if (c != 'J' && !visited[c - 'A'])
        {
            KEY += c;
            matrix[index / SIZE][index % SIZE] = c;
            index++;
        }
    }
    // Input plaintext
    string pt;
    cout << "Enter the plaintext: ";
    cin >> pt;
    for (char &c : pt)
    {
        c = toupper(c);
        if (c == 'J') c = 'I';
    }
    // Encryption
    cout << "Encrypted text: ";
    string encrypted_text;
    for (int k = 0; k < pt.length(); k += 2)
    {
        char a = pt[k];
        char b = (k + 1 < pt.length()) ? pt[k + 1] : 'X'; // Ensure a pair by appending 'X' if necessary
        // If both letters in a pair are the same, append 'X' to the second letter
        if (a == b)
        {
            b = 'X';
            k--; // Adjust the index to process the same letter in the next iteration
        }
        int r1, c1, r2, c2;
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                if (matrix[i][j] == a)
                {
                    r1 = i;
                    c1 = j;
                }
                if (matrix[i][j] == b)
                {
                    r2 = i;
                    c2 = j;
                }
            }
        }
        // Apply the encryption rules
        if (r1 == r2)
        {
            cout << matrix[r1][(c1 + 1) % SIZE] << matrix[r2][(c2 + 1) % SIZE];
        }
        else if (c1 == c2)
        {
            cout << matrix[(r1 + 1) % SIZE][c1] << matrix[(r2 + 1) % SIZE][c2];
        }
        else
        {
            cout << matrix[r1][c2] << matrix[r2][c1];
        }
    }
    cout << endl;
    // Decryption
    string ct;
    cout << "Enter the ciphertext: ";
    cin >> ct;
    cout << "Decrypted text: ";
    for (int i = 0; i < ct.length(); i += 2)
    {
        char a = ct[i];
        char b = ct[i + 1];

        int r1, c1, r2, c2;
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < SIZE; ++k)
            {
                if (matrix[j][k] == a)
                {
                    r1 = j;
                    c1 = k;
                }
                if (matrix[j][k] == b)
                {
                    r2 = j;
                    c2 = k;
                }
            }
        }
        if (r1 == r2)
        {
            cout << char(tolower(matrix[r1][(c1 + SIZE - 1) % SIZE])) << char(tolower(matrix[r2][(c2 + SIZE - 1) % SIZE]));
        }
        else if (c1 == c2)
        {
            cout << char(tolower(matrix[(r1 + SIZE - 1) % SIZE][c1])) << char(tolower(matrix[(r2 + SIZE - 1) % SIZE][c2]));
        }
        else
        {
            cout << char(tolower(matrix[r1][c2])) << char(tolower(matrix[r2][c1]));
        }
    }
    cout << endl;
    return 0;
}
