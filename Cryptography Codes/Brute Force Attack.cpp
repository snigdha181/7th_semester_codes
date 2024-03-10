#include<iostream>
using namespace std;

int main()
{
    int key;
    string text;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter key: ";
    cin >> key;

    string cipher = "";

    // Encrypt the plain text
    for(int i = 0; i < text.length(); i++)
    {
        if(isupper(text[i]))
            cipher += (text[i] + key - 65) % 26 + 65;
        else if(islower(text[i]))
            cipher += (text[i] + key - 97) % 26 + 97;
        else
            cipher += text[i];
    }

    cout << "Cipher text: " << cipher << endl << endl;

    // Decrypt the cipher text using brute force attack
    for(int n = 0; n < 26; n++)
    {
        string decryptedText = "";
        for(int i = 0; i < cipher.length(); i++)
        {
            if(isupper(cipher[i]))
            {
                if((cipher[i] - n - 65) < 0)
                    decryptedText += 91 + (cipher[i] - n - 65);
                else
                    decryptedText += (cipher[i] - n - 65) % 26 + 65;
            }
            else if(islower(cipher[i]))
            {
                if((cipher[i] - n - 97) < 0)
                    decryptedText += 123 + (cipher[i] - n - 97);
                else
                    decryptedText += (cipher[i] - n - 97) % 26 + 97;
            }
            else
                decryptedText += cipher[i];
        }
        cout << "Plain text for key " << n << ": " << decryptedText << endl;
    }

    return 0;
}
