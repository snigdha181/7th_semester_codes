#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,r,n=10,m;
    cout<<"Enter the numbers: ";
    cin>>a>>b>>c;
    r=a+b;
    for(int i=0; i<n; i++)
    {
        m=r%c;
        if(m==0 || m>0)
        {
            cout<<"("<<a<<"+"<<b<<") "<<"mod "<<c<<" = "<<m;
            exit(0);
        }
        else
        {
            cout<<"("<<a<<"+"<<b<<") "<<"mod "<<c<<" = "<<m+c;
            exit(0);
        }
    }
    return 0;
}
