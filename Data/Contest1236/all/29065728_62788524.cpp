#include <stdio.h>
const int mod = 1e9+7;
#define ll long long
ll Power(ll a, ll x) {
	ll ans = 1;
	while (x) {
		if (x&1) ans = ans*a%mod;
		a=a*a%mod;
		x>>=1;
	}
	return ans;
}
int main() {
	ll n, m;
	scanf("%lld%lld", &n, &m);
	printf("%lld\n", Power((Power(2ll, m)-1+mod)%mod, n));
	return 0;
}