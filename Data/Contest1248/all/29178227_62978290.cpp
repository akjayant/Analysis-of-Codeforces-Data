#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

signed main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ll cnt_p_even = 0;
		for (int i = 0; i < n; ++i) {
			int pi; cin >> pi;
			if (pi % 2 == 0) ++cnt_p_even;
		}
		int m; cin >> m;
		ll cnt_q_even = 0;
		for (int i = 0; i < m; ++i) {
			int qi; cin >> qi;
			if (qi % 2 == 0) ++cnt_q_even;
		}
		ll ans = cnt_p_even * cnt_q_even;
		ans += (n - cnt_p_even) * (m - cnt_q_even);
		cout << ans << endl;
	}
	return 0;
}