#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, mod = 1e9 + 7;
long long dp[N];
int main() {
	string s;
	cin >> s;
	dp[0] = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'm' || s[i] == 'w') {
			cout << 0;
			return 0;
		}
	}
	if (s.size() > 1) {
		if (s[1] == s[0]) {
		 	if (s[1] == 'u')
				dp[1] = 1;
			if (s[1] == 'n')
				dp[1] = 1;
		}
	}
	dp[1] += dp[0];
	for (int i = 2; i < s.size(); i++) {
		dp[i] = dp[i - 1];
		if (s[i] == 'u' && s[i - 1] == 'u' || s[i] == 'n' && s[i - 1] == 'n') {
			dp[i] = (dp[i] + dp[i - 2]) % mod;
		}
	}
	cout << dp[(int) s.size() - 1] % mod;
	return 0;
}
