#include <bits/stdc++.h>
using namespace std;
const int maxn=200050;
typedef long long ll;
const ll MOD=1e9+7;
ll Pow(ll x,ll n) {
	ll ans=1,base=x%MOD;
	while(n) {
		if(n&1) ans=ans*base%MOD;
		base=base*base%MOD;
		n>>=1;
	}
	return ans%MOD;
}
int main() {
	int T=1;
	// scanf("%d", &T);
	while(T--) {
		ll n,m;
		scanf("%lld%lld", &n,&m);
		ll t=Pow(2, m)-1;
		ll ans=Pow(t,n);
		printf("%lld\n", ans);
	}
	return 0;
}
