#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,d,k,x,y,i,j;
        cin>>a>>b>>c>>d>>k;
        i=ceil(a*1.0/c);
        j=ceil(b*1.0/d);
        if(i+j<=k)
            cout<<i<<" "<<j<<"\n";
        else
            cout<<"-1\n";
    }
}
