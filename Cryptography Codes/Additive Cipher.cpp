#include<bits/stdc++.h>
using namespace std;
int main()
{
    int key_value,p_value,key,c_value;
    string dict="abcdefghijklmnopqrstuvwxyz";
    string text;
    cout<<"Enter the text: ";
    cin>>text;
    cout<<"Enter the key: ";
    cin>>key;
    char ch;

    string ciphertext = "";
    cout<<"Ciphervalue = ";
    for(int i=0; i<text.length(); i++)
    {
        int x = dict.find(text[i]);
        // cout<<x ;
        key_value = x;
        p_value=(key_value+key)%26;
        cout<<p_value;
        cout<<" ";
        ciphertext += dict[p_value];
    }
    cout<<"\nCiphertext = "<<ciphertext;
    cout<<"\nUppercase = ";
    for(int i=0; i<ciphertext.length(); i++)
    {
        putchar(toupper(ciphertext[i]));
    }
    return 0;
}
