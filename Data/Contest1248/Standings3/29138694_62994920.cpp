#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

long long n, m, dp[100009][2];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	dp[0][0] = 0; dp[0][1] = 1;
	for (int i = 1; i < max(n, m); i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][0] %= MOD;
		dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] %= MOD;
	}
	long long ans = 2 * (dp[m - 1][0] + dp[m - 1][1]);
	ans %= MOD;
	ans += 2 * ((dp[n - 1][0] + dp[n - 1][1] - 1 + MOD) % MOD);
	ans %= MOD;
	cout << ans << E;
	//system("pause");
	return 0;
}