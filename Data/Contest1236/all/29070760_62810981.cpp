#include <bits/stdc++.h>

using namespace std;

long long mod = 1000000007;

long long mpow(long long b, long long e) {
	if(e == 0) {
		return 1;
	}
	else if(e == 1) {
		return b;
	}

	long long ans = mpow(b, e/2);
	ans *= ans;
	ans %= mod;

	if(e % 2 == 1) {
		ans *= b;
		ans %= mod;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, m;
	cin >> n >> m;

	long long way = mpow(2, m) - 1;
	way += mod;
	way %= mod;

	long long ans = mpow(way, n);

	cout << ans << endl;

	return 0;
}
