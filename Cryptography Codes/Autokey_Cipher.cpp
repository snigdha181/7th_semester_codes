#include <iostream>
#include <string>
using namespace std;

string find_P_value(const string &text, const string &dict)
{
    string p_values;
    for(int i = 0; i < text.length(); i++)
    {
        int x = dict.find(text[i]);
        int pv = x;
        p_values += to_string(pv) + " ";
    }
    return p_values;
}

string find_K_value(const string &text, const string &dict, int key)
{
    string k_values;
    k_values += to_string(key) + " "; // First key value taken from the user
    char prev_char = text[0]; // Initial character of the key is the first character of the plaintext
    for(int i = 1; i < text.length(); i++)
    {
        int x = dict.find(text[i]);
        int kv = dict.find(prev_char); // Use previous character as the key
        k_values += to_string(kv) + " ";
        prev_char = text[i]; // Update previous character for the next iteration
    }
    return k_values;
}

string find_C_value(const string &text, const string &dict, int key)
{
    string c_values, ciphertext;
    char prev_char = dict[key]; // Initial character of the key is the key itself
    for(int i = 0; i < text.length(); i++)
    {
        int x = dict.find(text[i]);
        int kv = dict.find(prev_char); // Use previous character as the key
        int cv = (x + kv) % 26;
        c_values += to_string(cv) + " ";
        ciphertext += dict[cv];
        prev_char = text[i]; // Update previous character for the next iteration
    }
    return c_values;
    //cout << "\nCiphertext: " << ciphertext << endl;
}

int main()
{
    int key;
    string text;
    string dict = "abcdefghijklmnopqrstuvwxyz";

    cout << "Enter the first key value: ";
    cin >> key;
    cout << "\nEnter plaintext: ";
    cin >> text;

    cout << "\nP's value: " << find_P_value(text, dict) << endl;
    cout << "\nK's value: " << find_K_value(text, dict, key) << endl;
    cout << "\nC's value: " << find_C_value(text, dict, key) << endl;


    return 0;
}
