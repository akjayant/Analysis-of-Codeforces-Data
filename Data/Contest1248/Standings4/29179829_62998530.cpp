/*
 * Author: apikdech
 * Time: 16:22:18 20-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
ll fact[N], ifact[N];

ll powmod(ll a,ll b, ll m = MOD) {ll res=1; assert(b>=0); for(;b;b>>=1){if(b&1)res=(res*a)%m;a=(a*a)%m;}return res%m;}

ll inv(ll a) {
	return powmod(a, MOD-2);
}

ll ncr(ll x, ll y) {
	if (y > x) return 0;
	ll res = fact[x];
	res = res * ifact[y] % MOD;
	res = res * ifact[x-y] % MOD;
	return res;
}

void pre() {
	fact[0] = fact[1] = 1;
	ifact[0] = ifact[1] = 1;
	for (ll i = 2; i < N; i++) {
		fact[i] = (fact[i-1] * i) % MOD;
		ifact[i] = inv(fact[i]);
	}
}

int main() {
	pre();
	ios::sync_with_stdio(0); cin.tie(0);
	ll n, m, x = 0, y = 0, satu, dua;
	cin >> n >> m;
	if (n > m) swap(n, m);
	if (n == 1 && m == 1) return cout << "2\n", 0;
	for (ll i = 1; i <= n; i++) {
		satu = n-i;
		dua = (n - satu)/2;
		if (satu + 2*dua != n) continue;
		x = (x + ncr(satu + dua, dua)) % MOD;
	}
	for (ll i = 1; i <= m; i++) {
		satu = m-i;
		dua = (m - satu)/2;
		if (satu + 2*dua != m) continue;
		y = (y + ncr(satu + dua, dua)) % MOD;
	}
	// cout << x << " " << y << "\n";
	// if (x == 0) cout << x << "\n";
	// else if (y == 0) cout << y << "\n";
	cout << (((2LL * x % MOD + 2LL * y % MOD) % MOD) + 2LL) % MOD << "\n";
	return 0;
}
