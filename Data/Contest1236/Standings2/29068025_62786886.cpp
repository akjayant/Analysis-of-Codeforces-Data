#include<bits/stdc++.h>
#define bi (1<<i)
#define bk (1<<k)
#define bj (1<<j)
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef long long ll;
const ll N=3e5+10,mod=1e9+7;
ll qp(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)res=res*a%mod;
        b/=2;
        a=a*a%mod;
    }
    return res;
}
int main()
{
   // freopen("i.txt","r",stdin);
    ll n,m;
    scanf("%lld %lld",&n,&m);
    ll ans=(qp(2,m)-1+mod)%mod;
    printf("%lld\n",qp(ans,n));
}
