#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,r,n=10;
    cout<<"Enter the numbers: ";
    cin>>a>>b;
    float q;
    int r1=a, r2=b;
    r=a%b;
    cout<<"\nq\t r1 \tr2 \tr\n";
    while(r>0)
    {
        q=r1/r2;
        r=r1-q*r2;
        cout<<"\n"<<q<<"\t"<<r1<<"\t"<<r2<<"\t"<<r;
        r1=r2;
        r2=r;
    }
    cout<<"\n\nGCD ("<<a<<","<<b<<") = "<<r1;
    return 0;
}
