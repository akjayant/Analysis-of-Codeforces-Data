#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define endl '\n'
using namespace std;
ll power(ll x,ll y)
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
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   ll n,m;
   cin>>n>>m;
   ll r=power(2,m);
   r=(r-1+mod)%mod;
   r=power(r,n);
   cout<<r<<endl;
}
