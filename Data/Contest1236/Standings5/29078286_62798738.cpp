#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define endl '\n'
using namespace std;
/*ll power(ll x,ll y)
{
    ll res=1;
    while(y>0)
    {
        if(y%2==1)
            res=(res*x)%mod;
        x=(x*x)%mod;
        y=y/2;
    }
    return res;
}*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,i,j;
    cin>>n;
    vector<ll>v[n+1];
    for(i=0;i<=n-1;i++)
    {
        if(i%2==0)
        {
            ll c=1;
            for(j=n*i+1;j<=n*i+n;j++)
                v[c].pb(j),c++;
        }
        else
        {
            ll c=n;
            for(j=n*i+1;j<=n*i+n;j++)
                v[c].pb(j),c--;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
}
