#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,r,n;
    int pv,cv,kv,key;
    string p,c="",text;
    string dict="abcdefghijklmnopqrstuvwxyz";
    cout<<"Enter the numbers: ";
    cin>>a>>b;
    float q,t;
    int r1=a, r2=b, t1=0, t2=1;
    r=a%b;
    cout<<"\nq\t r1 \tr2 \tr \tt1 \tt2 \tt\n";
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
    cout<<"\n\nGCD ("<<a<<","<<b<<") = "<<r1;
    cout<<"\nValue of t: "<<t1;
    if(r1==1)
    {
        cout<<"\n\nMultiplicative Inverse Possible...";
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
            cv = (kv*key)%26;
            cout<<cv;
            cout<<" ";
            c+=dict[cv];
        }
        cout<<"\nCiphertext = ";
        for(int i=0; i<c.length(); i++)
        {
            putchar(toupper(c[i]));
        }
        n=t1%a;
        if(n==0 || n>0)
        {
            cout<<"\nMultiplicative Inverse is ("<<t1<<") mod "<<b<<" = "<<n;
            //decryption
            cout<<"\nPlaintext Value: ";
            for(int i=0; i<c.length(); i++)
            {
                int x = dict.find(c[i]);
                kv = x;
                pv = (kv*n)%26;
                cout<<pv;
                cout<<" ";
                p+=dict[pv];
            }
            cout<<"\nPlaintext = "<<p;
        }
        else
        {
            cout<<"\nMultiplicative Inverse is ("<<t1<<") mod "<<b<<" = "<<n+a;
            int X=n+a;
            //decryption
            cout<<"\nPlaintext Value: ";
            for(int i=0; i<c.length(); i++)
            {
                int x = dict.find(c[i]);
                kv = x;
                pv = (kv*X)%26;
                cout<<pv;
                cout<<" ";
                p+=dict[pv];
            }
            cout<<"\nPlaintext = "<<p;
        }
    }
    else
    {
        cout<<"\nMultiplicative Inverse Not Possible...";
    }
    return 0;
}

