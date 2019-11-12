//g++  5.4.0

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,an=0;
        cin>>a>>b>>c;
        ll d=min(b,c/2);
        an+=d+2*d;
        b-=d;
        d=min(a,b/2);
        an+=d+2*d;
        cout<<an<<"\n";
    }
}