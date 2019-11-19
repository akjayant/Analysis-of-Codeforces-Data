#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first 
#define ss second
int const INF = 2e8 + 7;
int mod = 1e9 + 7;



signed main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int> > dp(max(n,m), vector<int> (4));
	if (m == 1 && n == 1) {
		cout << 2;
		return 0;
	}

	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;
	dp[1][3] = 1;
	for (int i = 2; i < max(n, m); i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3])%mod;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1])%mod;
		dp[i][3] = dp[i - 1][2];
	}
	if (m == 1) {
		cout << (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2] + dp[n - 1][3]) % mod;
		return 0;
	}
	if (n == 1) {
		cout << (dp[m - 1][0] + dp[m - 1][1] + dp[m - 1][2] + dp[m - 1][3]) % mod;
		return 0;
	}
	cout << (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2] + dp[n - 1][3] + dp[m - 1][0] + dp[m - 1][1] + dp[m - 1][2] + dp[m - 1][3]+mod-2)%mod;
}
