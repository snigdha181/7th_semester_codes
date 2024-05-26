#include <bits/stdc++.h>
using namespace std;
int main()
{
    string ciphertext = "lipps";
    string plaintext;
    for (int key = 1; key <= 26; ++key)
    {
        plaintext = "";
        for (char& c : ciphertext)
        {
            if (isalpha(c))
            {
                char shifted = c - key;
                if (isalpha(shifted))
                {
                    plaintext += shifted;
                }
                else
                {
                    plaintext += 'z' - ('a' - shifted) + 1;
                }
            }
            else
            {
                plaintext += c;
            }
        }
        cout << "Key " << key << ": " << plaintext << endl;
        // Perform validation
        if (plaintext == "hello")
        {
            cout << "Found plaintext: " << plaintext << endl;
            break; // Exit loop if plaintext is found
        }
    }
    return 0;
}
