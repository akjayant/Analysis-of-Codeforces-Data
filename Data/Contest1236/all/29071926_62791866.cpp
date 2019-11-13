#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll Pow(ll a, ll x) {
	ll ret = 1;
	for(; x; x >>= 1, (a *= a) %= mod)
		if(x & 1)
			(ret *= a) %= mod;
	return ret;
}
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	printf("%lld\n", Pow(Pow(2, m) - 1, n));
	return 0;
}

