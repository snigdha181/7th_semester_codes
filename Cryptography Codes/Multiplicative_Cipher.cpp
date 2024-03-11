#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,r,t1=0,t2=1,t,r1,r2,q,n;
    cout<<"Enter the numbers: ";
    cin>>a>>b;
    r=a%b;
    r1=a;
    r2=b;
    cout<<"\nq \tr1 \tr2 \tr \tt1 \tt2 \tt\n";
    while(r>0)
    {
        q=r1/r2;
        r=r1-q*r2;
        t=t1-q*t2;
        cout<<"\n"<<q<<"\t"<<r1<<"\t"<<r2<<"\t"<<r<<"\t"<<t1<<"\t"<<t2<<"\t"<<t;
        r1=r2;
        r2=r;
        t1=t2;
        t2=t;
    }
    n=t1%a;
    cout<<"\n\nGCD("<<a<<","<<b<<") = "<<r1;
    cout<<"\nValue of t: "<<t1;
    if(n==0 || n>0)
    {
         cout<<"\n\nMultiplicative Inverse("<<t1<<") mod "<<a<<" = "<<n;
    }
    else
    {
         cout<<"\n\nMultiplicative Inverse("<<t1<<") mod "<<a<<" = "<<n+a;
    }
    int key_value,p_value,key,c_value;
    string dict="abcdefghijklmnopqrstuvwxyz";
    string text;
    cout<<"\n\nEnter the text: ";
    cin>>text;
    cout<<"Enter the key: ";
    cin>>key;
    char ch;

    string ciphertext = "";
    cout<<"Ciphervalue = ";

    //encryption
    for(int i=0; i<text.length(); i++)
    {
        int x = dict.find(text[i]);
        // cout<<x ;
        key_value = x;
        p_value=(key_value*key)%26;
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
    string s = ciphertext;
    //decryption
    for(int i=0; i<s.length(); i++)
    {
        int x = dict.find(s[i]);
        // cout<<x ;
        key_value = x;
        p_value=(key_value*n)%26;
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


