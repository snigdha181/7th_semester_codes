#include <bits/stdc++.h>
using namespace std;
int main()
{
    string key, text;
    string dict = "abcdefghijklmnopqrstuvwxyz";
    string p_values, k_values, c_values, ciphertext;
    cout << "Enter the key: ";
    cin >> key;
    cout << "\nEnter plaintext: ";
    cin >> text;

    // Calculate P's value
    for (int i = 0; i < text.length(); i++)
    {
        int x = dict.find(text[i]);
        int pv = x;
        p_values += to_string(pv) + " ";
    }

    // Calculate K's value
    for (int i = 0; i < text.length(); i++)
    {
        int x = dict.find(key[i % key.length()]);
        int kv = x % 26; // Apply modulo 26 to the key value
        k_values += to_string(kv) + " ";
    }

    // Calculate C's value and ciphertext
    for (int i = 0; i < text.length(); i++)
    {
        int x = dict.find(text[i]);
        int y = dict.find(key[i % key.length()]);
        int cv = (x + y) % 26;
        c_values += to_string(cv) + " ";
        ciphertext += dict[cv];
    }
    cout << "\nP's value: " << p_values << endl;
    cout << "\nK's value: " << k_values << endl;
    cout << "\nC's value: " << c_values << endl;
    cout << "\nCiphertext = " << ciphertext << endl;
    return 0;
}
