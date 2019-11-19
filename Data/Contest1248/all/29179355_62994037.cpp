// youngjinp20
// 2019 10

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<vi> vvi;

int main() {
	ll n, m;
	ll mod = 1e9+7;
	ll dp[100005][2][2] = {0};
	ll dk[100005] = {0};
	ll sum = 0;

	cin >> n >> m;

	dp[0][1][1] = 0;
	dp[0][1][0] = 1;
	dp[0][0][1] = 1;
	dp[0][0][0] = 0;

	for (int i=1; i<m; i++) {
		dp[i][1][1] = dp[i-1][1][0] % mod;
		dp[i][0][0] = dp[i-1][0][1] % mod;
		dp[i][1][0] = (dp[i-1][0][1] + dp[i-1][0][0]) % mod;
		dp[i][0][1] = (dp[i-1][1][0] + dp[i-1][1][1]) % mod;
	}


	dk[0] = 1;
	dk[1] = 1;
	for (int i=2; i<=n; i++) {
		dk[i] = (dk[i-1] + dk[i-2]) % mod;
	}

	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			sum += dp[m-1][i][j];
		}
	}

	sum %= mod;
	ll res = (2L*dk[n] + sum - 2L) % mod;
	printf("%lld", res);
	return 0;
}
