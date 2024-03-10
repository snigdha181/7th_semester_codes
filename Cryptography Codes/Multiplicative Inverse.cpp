#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,r,n;
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
    n=t1%a;
    if(n==0 || n>0)
    {
        cout<<"\nMultiplicative Inverse is ("<<t1<<") mod "<<b<<" = "<<n;
    }
    else
    {
        cout<<"\nMultiplicative Inverse is ("<<t1<<") mod "<<b<<" = "<<n+a;
    }
    //cout<<"\nMultiplicative Inverse is ("<<t1<<") mod "<<b<<" = "<<n;
    return 0;
}
