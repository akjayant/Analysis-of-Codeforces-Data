#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;
bool check(pair<ll,ll> p1,pair<ll,ll> p2)
{
    return p2.second>p1.second;
}
ll expo(ll a,ll b)
{
    if(b==0)
    {
        return 1;
    }
    if(b%2)
    {
        return (a*expo((a*a)%mod,b/2)%mod)%mod;
    }
    else
    {
        return expo((a*a)%mod,b/2)%mod;
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll ans=expo(2,m);
    //cout<<ans<<endl;
    ans=(ans-1+mod)%mod;
    //cout<<ans<<endl;;
    ans=expo(ans,n);
    cout<<ans;
	return 0;
}