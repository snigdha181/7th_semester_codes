#include<bits/stdc++.h>
using namespace std;
int main()
{
    int pv,cv,kv,key;
    string p,c="",text;
    string dict="abcdefghijklmnopqrstuvwxyz";
    cout<<"\nEnter the plaintext: ";
    cin>>text;
    cout<<"Enter the key: ";
    cin>>key;
    //encryption
    cout<<"Cipher Value: ";
    for(int i=0; i<text.length(); i++)
    {
        int x = dict.find(text[i]);
        kv = x;
        cv = (kv+key)%26;
        cout<<cv;
        cout<<" ";
        c+=dict[cv];
    }
    cout<<"\nCiphertext = ";
    for(int i=0; i<c.length(); i++)
    {
        putchar(toupper(c[i]));
    }
    //decryption
    cout<<"\nPlaintext Value: ";
    for(int i=0; i<c.length(); i++)
    {
        int x = dict.find(c[i]);
        kv = x;
        pv = (kv-key)%26;
        cout<<pv;
        cout<<" ";
        p+=dict[pv];
    }
    cout<<"\nPlaintext = "<<p;
    return 0;
}
