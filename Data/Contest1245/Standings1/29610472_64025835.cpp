#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#define int long long

const int N = 33;

int dp[N + 1][2][2];
int calc(int n, int m) {
	if (n < 0 || m < 0) return 0;
	memset(dp, 0, sizeof dp);
	dp[N][0][0] = 1;
	for (int i = N - 1; i >= 0; i--)
		for (int x = 0; x < 2; x++)
			for (int y = 0; y < 2; y++) {
				int nx = x | ((n >> i) & 1);
				int ny = y | ((m >> i) & 1);
				dp[i][nx][ny] += dp[i + 1][x][y];
				if (nx) dp[i][x][ny] += dp[i + 1][x][y];
				if (ny) dp[i][nx][y] += dp[i + 1][x][y];
			}
	return dp[0][0][0] + dp[0][0][1] + dp[0][1][0] + dp[0][1][1];
}

int l, r;
signed main() {
	for (scanf("%*d"); ~scanf("%lld%lld", &l, &r);)
		printf("%lld\n", calc(r, r) + calc(l - 1, l - 1) - calc(l - 1, r) * 2);
}