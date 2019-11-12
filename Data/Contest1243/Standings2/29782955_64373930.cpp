#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> v(n);
		for (int& i : v) cin >> i;

		sort(v.begin(), v.end(), greater<int>{});

		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, (ll)min(i+1, v[i]));
		}

		cout << ans << "\n";
	}
}