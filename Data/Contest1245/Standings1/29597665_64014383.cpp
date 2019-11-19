#include <bits/stdc++.h>

typedef long long LL;

const int N = 35;
LL dp[N][2][2];

int R1, R2, l, r;
LL dfs(int dep, bool lim1, bool lim2) {
	if (dep == -1) return 1;
	if (~dp[dep][lim1][lim2]) return dp[dep][lim1][lim2];
	int up1 = lim1 ? R1 >> dep & 1 : 1;
	int up2 = lim2 ? R2 >> dep & 1 : 1;
	LL ret = 0;
	for (int i = 0; i <= up1; ++i)
		for (int j = 0; j <= up2; ++j) if (!(i && j))
			ret += dfs(dep - 1, lim1 && i == up1, lim2 && j == up2);
	return dp[dep][lim1][lim2] = ret;
}
LL solve(int r1, int r2) {
	R1 = r1, R2 = r2;
	std::memset(dp, -1, sizeof dp);
	if (r1 < 0 || r2 < 0) return 0;
	return dfs(31, 1, 1);
}

void solve() {
	std::cin >> l >> r;
	std::cout << solve(r, r) - 2 * solve(l - 1, r) + solve(l - 1, l - 1) << '\n';
}
int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	int tc; std::cin >> tc;
	while (tc--) solve();
	return 0;
}
