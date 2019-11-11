#include <bits/stdc++.h>
using namespace std;

constexpr int kMod = 1E9 + 7;

int dp[100010];

int main() {
	cin.tie(nullptr), ios_base::sync_with_stdio(false);
	string str; cin >> str;
	if (str.find('m') != string::npos || str.find('w') != string::npos) {
		cout << "0\n";
		return 0;
	}
	int n = int(str.size());
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (i > 1 && str[i - 2] == 'u' && str[i - 1] == 'u') {
			dp[i] = (dp[i] + dp[i - 2]) % kMod;
		}
		if (i > 1 && str[i - 2] == 'n' && str[i - 1] == 'n') {
			dp[i] = (dp[i] + dp[i - 2]) % kMod;
		}
	}
	cout << dp[n] << '\n';
}
