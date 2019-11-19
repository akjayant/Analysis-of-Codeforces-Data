#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const ll mod = 1000000007LL;

ll solve(int k) {
	ll c[4] = { 1LL,1LL,1LL,1LL };
	for (int i = 3; i <= k; ++i) {
		ll c_[4];
		c_[0] = (c[1] + c[2]) % mod;
		c_[1] = (c[0] + c[3]) % mod;
		c_[2] = c[1]; c_[3] = c[0];
		for (int j = 0; j < 4; ++j) c[j] = c_[j];
	}
	return (c[0] + c[1] + c[2] + c[3]) % mod;
}

signed main() {
	int n, m;
	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << 2 << endl;
	}
	else if (n == 1 || m == 1) {
		int k = n == 1 ? m : n;
		cout << solve(k) << endl;
	}
	else {
		cout << ((solve(n) + solve(m)) % mod - 2 + mod) % mod << endl;
	}
	return 0;
}