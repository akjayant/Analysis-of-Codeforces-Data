#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
const ll mod=1e9+7;
ll n,m;
ll Pow(ll a,ll b, ll mod)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    //freopen("ce.in","r",stdin);
    cin>>n>>m;
    m=Pow(2,m,mod)-1;
    ll ans=Pow(m,n,mod);
    if(ans<0) ans+=mod;
    cout<<ans;
    return 0;
}
