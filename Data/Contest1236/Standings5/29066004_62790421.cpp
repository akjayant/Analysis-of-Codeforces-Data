#include<bits/stdc++.h>
using namespace std;
#define maxn 300005
typedef long long ll;
ll mod=1e9+7;
ll qsm(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
int main()
{
	ll n,m;
	scanf("%lld%lld",&n,&m);
	ll ans=qsm((qsm(2,m)-1+mod)%mod,n);
	printf("%lld\n",ans);
    return 0;
}