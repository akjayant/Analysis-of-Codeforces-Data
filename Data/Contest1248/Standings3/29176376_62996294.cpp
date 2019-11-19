#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	
	ll n, m, i;

	cin >> n >> m;
	vector<ll> dp(100000 + 5);
	dp[0] = 1;
	// dp[2] = 2;

	for(i = 0; i < dp.size() - 3; i++) {
		dp[i] %= mod;
		dp[i + 1] += dp[i] % mod;
		dp[i + 2] += dp[i] % mod;
		dp[i + 1] %= mod;
		dp[i + 2] %= mod;
	}

	// cout << dp[2] << " " << dp[4000];
	cout << (dp[n] + dp[m] - 1) * 2 % mod;
}


