// youngjinp20
// 2019 10

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod = 1000000007;

ll mod_exp(ll base, ll exp) {
	if (exp == 0) return 1;
	if (exp == 1) return base;
	ll j = mod_exp(base, exp/2);
	ll res = j * j % mod;
	res *= (exp&1 ? base : 1);
	res %= mod;
	return res;
}

int main() {
	ll n, m;
	cin >> n >> m;
	ll k = mod_exp(2, m) - 1;
	k = (k+mod) % mod;
	printf("%lld", mod_exp(k, n));
	return 0;
}
