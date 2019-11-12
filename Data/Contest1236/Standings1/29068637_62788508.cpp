#include <bits/stdc++.h>
using namespace std;

const long long md = (long long) 1e9 + 7;

long long power(long long a, long long b) {
	long long res = 1;
	while (b > 0) {
		if (b & 1) {
			res = res * a % md;
		}
		a = a * a % md;
		b >>= 1;
	}
	return res;
}

void solve() {
	int n, m;
	cin >> n >> m;
	long long x = (power(2, m) - 1 + md) % md;
	long long ans = power(x, n);
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int notests = 1;
	while (notests--) {
		solve();
	}
	return 0;
}