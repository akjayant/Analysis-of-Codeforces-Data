#include <bits/stdc++.h>

using namespace std;
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);
typedef pair<int, int> ii;

const int MOD = 1e9 + 7;

int main(){
	fast_io();
	long long dp[100004];
	dp[1] = dp[2] = 2;
	long long sum[100002];
	sum[0] = 0;
	sum[1] = 2, sum[2] = 4;
	for(int i = 3; i < 100002; ++i) {
		dp[i] = dp[i-1] + dp[i-2];
		dp[i] %= MOD;
		sum[i] = sum[i-1] + dp[i];
		sum[i] %= MOD;
	}
	int n, m; cin >> n >> m;

	long long ans = dp[n + 1];
	ans += sum[m - 1];
	ans %= MOD;
	cout << ans << "\n";

}