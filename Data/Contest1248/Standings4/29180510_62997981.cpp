#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
int a[maxn];
signed main() {
	int n, m;
	cin >> n >> m;
	a[0] = 1, a[1] = 1;
	for (int i = 2; i < maxn; i++) {
		a[i] = a[i - 1] + a[i - 2];
		a[i] %= mod;
	}
	int ans = a[n];
	for (int i = 1; i < m; i++) {
		ans += a[i - 1];
		ans %= mod;
	}
	cout << (2*ans%mod+mod)%mod << endl;
	return 0;
}