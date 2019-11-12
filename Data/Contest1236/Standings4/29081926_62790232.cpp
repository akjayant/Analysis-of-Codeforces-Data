#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fastInOut();

const ll MOD = 1000000007;

ll fastPow(ll b, ll p) {
	ll ret = 1;
	while (p) {
		if (p % 2)
			ret = (ret * b) % MOD;
		b = (b * b) % MOD, p >>= 1;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	fastInOut();
	ll n, m;
	cin >> n >> m;
	ll cur = (fastPow(2, m) - 1 + MOD) % MOD;
	cout << fastPow(cur, n);
	return 0;
}

void fastInOut() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
