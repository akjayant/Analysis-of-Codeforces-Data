
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
long long dp[100010][4];

int main()
{
	int n,m;
	cin >> n >> m;
	if(n < m)
		swap(n,m);

	long long ans = 0;

	if(n >= 2)
	{
		dp[1][0] = 1;
		dp[1][1] = 1;
		dp[1][2] = 1;
		dp[1][3] = 1;

		for(int i=2; i<n; ++i)
		{
			dp[i][0] = dp[i-1][2];
			dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
			dp[i][2] = (dp[i-1][1] + dp[i-1][3]) % MOD;
			dp[i][3] = dp[i-1][1];
		}

		ans += (dp[n-1][0] + dp[n-1][1] + dp[n-1][2] + dp[n-1][3] - 2 + MOD) % MOD;
		ans %= MOD;

		if(m >= 2)
		{
			ans += (dp[m-1][0] + dp[m-1][1] + dp[m-1][2] + dp[m-1][3]) % MOD;
			ans %= MOD;
		}
		else
		{
			ans += 2;
			ans %= MOD;
		}
	}
	else
		ans = 2;

	cout << ans << endl;

	return 0;
}