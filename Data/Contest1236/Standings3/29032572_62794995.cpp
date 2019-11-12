#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod=1e9+7;
ll n,m;
ll qpow(ll a,ll b)
{
	ll ans=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1)
			ans=ans*a%mod;
	return ans;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	printf("%lld\n",qpow((qpow(2,m)+mod-1)%mod,n));
	return 0;
}