#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rnd(time(0));
#define f first
#define s second
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
// #define int ll

const int mod = 1e9 + 7;

void solve() {
	string s;
	cin >> s;
	for (auto &i : s) {
		if (i == 'm' || i == 'w') {
			cout << 0 << endl;
			exit(0);
		}
	}
	int n = s.size();
	ll ans = 1;
	ll dp[n + 1];
	dp[1] = 1;
	dp[0] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}
	char last = '\0';
	int cnt = 1;
	for (int i = 0; i < n; ++i) {
		if (last != s[i]) {
			if (last == 'u' || last == 'n') {
				ans = ans * dp[cnt] % mod;
			}
			last = s[i];
			cnt = 1;
		} else {
			cnt++;
		}
	}
	if (last == 'u' || last == 'n') {
		ans = ans * dp[cnt] % mod;
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
}