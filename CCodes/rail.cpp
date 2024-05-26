#include<bits/stdc++.h>
using namespace std;
int main()
{
    string plaintext, ciphertext, odd;
    int numR, numC;
    cout<<"Enter the plaintext: ";
    getline(cin, plaintext);

    numC = ceil((plaintext.length()/2));
    numR = plaintext.length()-numC;
    cout<<numR<<numC;
    cout<<endl;
    int n = plaintext.size();
    ciphertext = "";

    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            ciphertext += plaintext[i];
        }
        else
        {
            odd += plaintext[i];
        }
    }
    ciphertext.append(odd);
    cout<<ciphertext;
}
