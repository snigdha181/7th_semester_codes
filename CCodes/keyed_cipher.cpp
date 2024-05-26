#include <bits/stdc++.h>
using namespace std;

int main()
{
    string plaintext, ciphertext, key;
    int numR, numC;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);
    cout << "Enter the key : ";
    getline(cin, key);
    plaintext.erase(remove(plaintext.begin(), plaintext.end(), ' '), plaintext.end());
    numR = ceil((plaintext.length()/5));
    numC = ceil(static_cast<double>(plaintext.length()) / 3);
    cout<<numR<<numC;
    cout<<endl;
    if (key.length() != numC)
    {
        cout << "Key length must match the number of columns (" << numC << ")." << endl;
        return 1;
    }
    int colOrder[100];
    for (int i = 0; i < numC; ++i)
    {
        colOrder[i] = key[i] - '1';
    }
    char matrix[100][100];
    int index = 0;
    for (int i = 0; i < numR; ++i)
    {
        for (int j = 0; j < numC; ++j)
        {
            if (index < plaintext.length())
            {
                matrix[i][j] = plaintext[index++];
            }
            else
            {
                matrix[i][j] = ' ';
            }
        }
    }
    ciphertext = "";
    for (int k = 0; k < numC; ++k)
    {
        int col = colOrder[k];
        for (int i = 0; i < numR; ++i)
        {
            if (matrix[i][col] != ' ')
            {
                ciphertext += matrix[i][col];
            }
        }
    }
    cout << "Encrypted text: ";
    for (char &c : ciphertext)
    {
        cout << static_cast<char>(toupper(c));
    }
}
