#include <bits/stdc++.h>
using namespace std;

int main()
{
    string plain, cipher, cipher_odd;
    cin>>plain;
    int n = plain.size();
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0) cipher += plain[i];
        else cipher_odd += plain[i];
    }
    cipher.append(cipher_odd);
    cout<<cipher;

    return 0;
}
