#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

signed main() {
	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	ll sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; ++i) {
		if (i < n / 2)
			sum1 += a[i];
		else
			sum2 += a[i];
	}
	cout << (sum1 * sum1 + sum2 * sum2) << endl;
	return 0;
}