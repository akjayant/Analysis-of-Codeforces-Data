#include <bits/stdc++.h>
#define X first
#define Y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define ini(x, y) memset(x, y, sizeof(x))
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
const int MOD = 1e9 + 7;

ll f(ll n, ll r) {
	ll ret = 1;
	while (r) {
		if (r & 1) ret = ret * n % MOD;
		n = n * n % MOD;
		r >>= 1;
	}
	return ret;
}
int main() {
	fastio;
	ll n, m;
	cin >> n >> m;

	ll a = f(2, m) - 1;
	a %= MOD;
	if (a < 0) a += MOD;

	cout << f(a, n);

	return 0;
}