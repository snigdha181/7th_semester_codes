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
    return 0;
}

