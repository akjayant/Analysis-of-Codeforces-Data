#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const int maxn=1e6+5;

ll fac[maxn];
ll inv[maxn];
ll C(int m,int n)
{
    if(m>n)
        return -1;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

ll quick_mod(ll a,ll m)
{
    ll tmp=a%mod;
    ll ans=1;
    while(m)
    {
        if(m&1)
            ans=ans*tmp%mod;
        tmp=tmp*tmp%mod;
        m>>=1;
    }
    return ans;
}

void init()
{
    fac[0]=1;
    for(int i=1; i<maxn; i++)
        fac[i]=(fac[i-1]*i)%mod;
    inv[maxn-1]=quick_mod(fac[maxn-1],mod-2);
    for(int i=maxn-2; i>=0; i--)
        inv[i]=(inv[i+1]*(i+1))%mod;
}

int main()
{
    init();
    ll n,m;
    cin>>n>>m;
    ll ans1=0,ans2=0;
    for(int i=0;i<=n;i++,n--){
        ans1=(C(i,n)+ans1)%mod;
    }
    ans1=ans1*2%mod;
    for(int i=0;i<=m;i++,m--){
        ans2=(C(i,m)+ans2)%mod;
    }
    ans2=ans2*2%mod;
    ll ans=(ans1+ans2-2+mod)%mod;
    printf("%lld\n",ans);
    return 0;
}
