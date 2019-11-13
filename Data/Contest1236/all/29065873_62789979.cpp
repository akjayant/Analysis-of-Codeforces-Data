
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn=400005;
ll mod=1e9+7;
ll pow_mod(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
#endif
    ll n,m;
   cin>>n>>m;
    ll tmp=(pow_mod(2,m)-1+mod)%mod; 
    ll ans=pow_mod(tmp,n);
    cout<<ans<<endl;
    
    
    
    
    
    return 0;
}
