#include<bits/stdc++.h>
using namespace std;
int main()
{
    int key;
    string text;
    string dict = "abcdefghijklmnopqrstuvwxyz";
    string p_values, k_values, c_values, ciphertext;
    cout << "Enter the first key value: ";
    cin >> key;
    cout << "\nEnter plaintext: ";
    cin >> text;
    // Calculate P's value
    for(int i = 0; i < text.length(); i++)
    {
        int x = dict.find(text[i]);
        int pv = x;
        p_values += to_string(pv) + " ";
    }
    // Calculate K's value
    k_values += to_string(key) + " "; // First key value taken from the user
    char prev_char = text[0]; // Initial character of the key is the first character of the plaintext
    for(int i = 1; i < text.length(); i++)
    {
        int x = dict.find(text[i]);
        int kv = dict.find(prev_char); // Use previous character as the key
        k_values += to_string(kv) + " ";
        prev_char = text[i]; // Update previous character for the next iteration
    }
    // Calculate C's value and ciphertext
    prev_char = dict[key]; // Initial character of the key is the key itself
    for(int i = 0; i < text.length(); i++)
    {
        int x = dict.find(text[i]);
        int kv = dict.find(prev_char); // Use previous character as the key
        int cv = (x + kv) % 26;
        c_values += to_string(cv) + " ";
        ciphertext += dict[cv];
        prev_char = text[i]; // Update previous character for the next iteration
    }
    cout << "\nP's value: " << p_values << endl;
    cout << "\nK's value: " << k_values << endl;
    cout << "\nC's value: " << c_values << endl;
    cout<<"\nCiphertext = ";
    for(int i=0; i<ciphertext.length(); i++)
    {
        putchar(toupper(ciphertext[i]));
    }
    return 0;
}
