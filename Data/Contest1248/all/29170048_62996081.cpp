#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 100010;
const ll mod = int(1e9) + 7;

ll dp[N][2], n, m;
ll f[N];

int main()
{
	scanf("%lld%lld", &n, &m);
	dp[1][0] = 2, dp[1][1] = 0;
	for (int i = 2; i <= m; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
		dp[i][1] = dp[i - 1][0] % mod;
	}
	f[1] = 1, f[2] = 2;
	for (int i = 3; i <= n; i++) f[i] = (f[i - 1] + f[i - 2]) % mod;
	ll res = (dp[m][1] + dp[m][0]) % mod;
	ll ans = ((f[n] * 2) % mod + (res - 2) % mod) % mod;
	printf("%lld\n", ans);
	return 0;
}
