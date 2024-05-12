#include <bits/stdc++.h>
using namespace std;
const int SIZE = 5;
string Key(string key)
{
    string KEY;
    bool visited[26] = {false};
    for (char &c : key)
    {
        if (isalpha(c))
        {
            c = toupper(c);
            if (!visited[c - 'A'] && c != 'J')
            {
                KEY += c;
                visited[c - 'A'] = true;
            }
        }
    }
    for (char c = 'A'; c <= 'Z'; ++c)
    {
        if (c != 'J' && !visited[c - 'A'])
        {
            KEY += c;
        }
    }
    return KEY;
}
void PMatrix(string key, char matrix[SIZE][SIZE])
{
    key = Key(key);
    int index = 0;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            matrix[i][j] = key[index++];
        }
    }
}
void ent(char matrix[SIZE][SIZE], char a, char b)
{
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
void det(char matrix[SIZE][SIZE], char a, char b)
{
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
int main()
{
    string key = "LGDBAQMHECURNIFXVSOKZYWTP";
    char matrix[SIZE][SIZE];
    PMatrix(key, matrix);
    string pt;
    cout << "Enter the plaintext: ";
    cin >> pt;
    for (char &c : pt)
    {
        c = toupper(c);
        if (c == 'J') c = 'I';
    }
    cout << "Encrypted text: ";
    for (int i = 0; i < pt.length(); i += 2)
    {
        if (i == pt.length() - 1)
        {
            ent(matrix, pt[i], 'X');
        }
        else if (pt[i] == pt[i + 1])
        {
            ent(matrix, pt[i], 'X');
            --i;
        }
        else
        {
            ent(matrix, pt[i], pt[i + 1]);
        }
    }
    cout << endl;
    string ct;
    cout << "Enter the ciphertext: ";
    cin >> ct;
    cout << "Decrypted text: ";
    for (int i = 0; i < ct.length(); i += 2)
    {
        det(matrix, ct[i], ct[i + 1]);
    }
    return 0;
}
