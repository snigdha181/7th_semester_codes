#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,r,n;
    cout<<"Enter the numbers: ";
    cin>>a>>b;
    float q,s,t;
    int r1=a, r2=b, s1=1, s2=0, t1=0, t2=1;
    r=a%b;
    cout<<"\nq\t r1 \tr2 \tr \ts1 \ts2 \ts \tt1 \tt2 \tt\n";
    while(r>0)
    {
        q=r1/r2;
        r=r1-q*r2;
        s=s1-q*s2;
        t=t1-q*t2;
        cout<<"\n"<<q<<"\t"<<r1<<"\t"<<r2<<"\t"<<r<<"\t"<<s1<<"\t"<<s2<<"\t"<<s<<"\t"<<t1<<"\t"<<t2<<"\t"<<t;
        r1=r2;
        r2=r;
        s1=s2;
        s2=s;
        t1=t2;
        t2=t;
    }
    cout<<"\n\nGCD ("<<a<<","<<b<<") = "<<r1;
    cout<<"\nValue of s: "<<s1;
    cout<<"\nValue of t: "<<t1;
    n=s1*a+t1*b;
    cout<<"\n\nValue of n: "<<n;
    return 0;
}
