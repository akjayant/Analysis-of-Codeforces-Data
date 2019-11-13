#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MAXN=100005;
const int MOD=1000000007;
const int MAMOD=998244353;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
ll qpow(ll a,ll b)
{
    ll ret=1;
    while(b)
    {
        if(b&1)
            ret=ret*a%MOD;
        a=a*a%MOD;
        b/=2;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    ll ans=qpow(2,m)-1;
    cout<<qpow(ans,n)<<endl;
    return 0;
}