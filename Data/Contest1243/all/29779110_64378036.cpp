#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define endl '\n'
using namespace std;
const ll inf=1e18;
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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,i,c=-1,a=1,b;
        cin>>n;
        ll v[n];
        for(i=0;i<n;i++)
            cin>>v[i];
            sort(v,v+n,greater<ll>());
        for(i=0;i<n;i++)
        {
            c=max(c,min(a,v[i]));
            a++;
        }
        cout<<c<<endl;
    }
}
