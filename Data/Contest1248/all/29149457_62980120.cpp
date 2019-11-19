#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll i,x,e=0,o=0;
        for(i=0;i<n;i++)
        {
            cin>>x;
            if(x%2==0)
                e++;
            else
                o++;
        }
        ll j,y,ee=0,oo=0;
        ll m;
        cin>>m;
        for(j=0;j<m;j++)
        {
            cin>>y;
            if(y%2==0)
                ee++;
            else
                oo++;
        }
        ll ans=ee*e+oo*o;
        cout<<ans<<endl;
    }
    return 0;
}