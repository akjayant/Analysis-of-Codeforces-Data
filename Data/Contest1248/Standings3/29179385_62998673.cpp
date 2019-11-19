#include <bits/stdc++.h>

using namespace std;

int f[100010];
const int mod = 1000000007;

int main() {
	int n, m; cin >> n >> m;
	f[1] = 2;
	f[0] = 2;
	for(int i = 1; i <= max(n, m); i++) {
		f[i] = f[i - 1] + f[i - 2];
		f[i] %= mod;
	}
	cout << ((f[n] + f[m]) % mod - 2 + mod) % mod;
	return 0;
}