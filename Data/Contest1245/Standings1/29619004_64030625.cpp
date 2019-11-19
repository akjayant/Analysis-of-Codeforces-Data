#include <bits/stdc++.h>
using namespace std;

int64_t dp[32][2][2];
bool vis[32][2][2];

int64_t dfs(int a, int b, int pos, bool a_full, bool b_full) {
	if (pos == -1) return 1;
	if (vis[pos][a_full][b_full]) return dp[pos][a_full][b_full];
	vis[pos][a_full][b_full] = true;
	auto &ans = dp[pos][a_full][b_full];
	ans = 0;
	{ // 00
		ans += dfs(a, b, pos - 1, a_full && !(a & (1 << pos)), b_full && !(b & (1 << pos)));
	}
	{ // 01
		if (!b_full || (b & (1 << pos))) {
			ans += dfs(a, b, pos - 1, a_full && !(a & (1 << pos)), b_full);
		}
	}
	{ // 10
		if (!a_full || (a & (1 << pos))) {
			ans += dfs(a, b, pos - 1, a_full, b_full && !(b & (1 << pos)));
		}
	}
	return ans;
}

int main() {
	cin.tie(nullptr), ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		int l, r; cin >> l >> r;
		if (l) {
			--l;
			memset(vis, false, sizeof(vis));
			auto rr = dfs(r, r, 30, true, true);
			memset(vis, false, sizeof(vis));
			auto rl = dfs(r, l, 30, true, true);
			memset(vis, false, sizeof(vis));
			auto ll = dfs(l, l, 30, true, true);
			cout << rr - rl - rl + ll << '\n';
		} else {
			memset(vis, false, sizeof(vis));
			auto rr = dfs(r, r, 30, true, true);
			cout << rr << '\n';
		}
	}
}
