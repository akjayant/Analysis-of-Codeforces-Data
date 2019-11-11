#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second

#define pb push_back

int main() {
	string s;
	cin >> s;
	int n = s.length();

	const int mod = 1000000000 + 7;

	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (s[i - 1] == 'w' || s[i - 1] == 'm') {
			cout << 0 << endl;
			return 0;
		}

		if (s[i - 1] != 'n' && s[i - 1] != 'u') {
			dp[i] = dp[i - 1];
			continue;
		}

		if (i > 1 && s[i - 1] == s[i - 2]) dp[i] = dp[i - 2];
		dp[i] = (dp[i] + dp[i - 1]) % mod;
	}

	cout << dp[n] << endl;

	return 0;
}
