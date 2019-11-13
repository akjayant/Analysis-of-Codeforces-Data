#include <bits/stdc++.h>
#define maxn 300010
#define mod 1000000007
using namespace std;
typedef long long ll;
int a[maxn];

ll quick_mod(ll a,ll b)
{
    ll ans = 1;
    ll tmp = a;
    while(b)
    {
        if(b&1) ans = (ans*tmp)%mod;
        tmp = (tmp*tmp)%mod;
        b>>=1;
    }
    return ans;

}

int main()
{
    ll n,m;
    scanf("%lld%lld",&n,&m);
    ll ans = (quick_mod(2,m)+mod-1)%mod;
    ans = quick_mod(ans,n);
    printf("%lld\n",ans);
}

