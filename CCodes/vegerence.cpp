#include<bits/stdc++.h>
using namespace std;
int main()
{
    string dict="abcdefghijklmnopqrstuvwxyz";
    string key,pt,ct;
    cout<<"Enter the key: ";
    cin>>key;
    cout<<"\nKey's value: ";
    for(int i=0; i<key.length(); i++)
    {
        int x=dict.find(key[i]);
        cout<<x<<" ";
    }
    cout<<"\nEnter the plaintext: ";
    cin>>pt;
    cout<<"\nP's value: ";
    for(int i=0; i<pt.length(); i++)
    {
        int p=dict.find(pt[i]);
        cout<<p<<" ";
    }
    cout<<"\nC's value: ";
    for(int i=0; i<pt.length(); i++)
    {
        int p=dict.find(pt[i]);
        int x=dict.find(key[i%key.length()]);
        int s=p+x;
        if(s>26)
        {
            int T=s%26;
            cout<<T<<" ";
            ct+=dict[T];
        }
        else
        {
            cout<<s<<" ";
            ct+=dict[s];
        }

    }
    cout<<"\nCiphertext: ";
    for(int i=0; i<ct.length(); i++)
    {
        putchar(toupper(ct[i]));
    }
    return 0;
}
