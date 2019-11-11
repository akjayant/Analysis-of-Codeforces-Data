#include <bits/stdc++.h>
using namespace std;

const int md = (int) 1e9 + 7;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'm' || s[i] == 'w') {
			cout << "0\n";
			return;
		}
	}
	vector<int> dp(n + 1);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1];
		if (i > 1 && s[i - 2] == 'u' && s[i - 1] == 'u') {
			dp[i] += dp[i - 2];
			dp[i] %= md;
			continue;
		}
		if (i > 1 && s[i - 2] == 'n' && s[i - 1] == 'n') {
			dp[i] += dp[i - 2];
			dp[i] %= md;
		}
	}
	cout << dp[n] << "\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}