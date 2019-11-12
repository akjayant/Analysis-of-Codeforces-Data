#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define F(i, n) for(int i = 0; i < n; ++ i)

const int MOD = 1e9 + 7;

int binpow(int a, int n) {
	if (n == 0) {
        return 1;
	}
	if (n % 2 == 1) {
		return binpow(a, n - 1) * a % MOD;
	} else {
		int b = binpow(a, n / 2);
		return b * b % MOD;
	}
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    int a = (MOD + binpow(2, m) - 1) % MOD;
    cout << binpow(a, n);
}
