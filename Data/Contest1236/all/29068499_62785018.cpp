#include <bits/stdc++.h>
using namespace std;
int x,y,z,a,b,q;
int main()
{
    cin>>q;
    while(q--)
    {
        cin>>x>>y>>z;
        b=min(z/2,y);
        a=max(0,min((y-b)/2,x));
        cout<<3*(a+b)<<"\n";
    }
}
