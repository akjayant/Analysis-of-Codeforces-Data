#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
const ll MOD=1e9+7;
ll fpow(ll a,ll b)
{
    if(a==0) return 0;
    if(b==0) return 1;
    if(b==1) return a;
    ll tem=fpow(a,b/2);
    ll t=(tem*tem)%MOD;
    if(b%2) t=(t*a)%MOD;
    return t;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;

    ll ans=fpow(2,m);
    ans--;
    ans=fpow(ans,n);
    cout<<ans<<'\n';
}
