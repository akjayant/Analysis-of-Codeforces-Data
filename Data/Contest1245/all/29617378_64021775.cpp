#include <bits/stdc++.h>
using namespace std;

int main() {
	auto cal = [] (int l, int r) -> long long {
		if (l == -1) return 0;
		if (l == 0) return r + 1;
		long long dp[31][2][2] = { 0 };
		dp[30][1][1] = 1;
#define loop(i) for (int i : { 0, 1 })
		for (int i = 29; ~i; --i) loop(j) loop(k) loop(p) loop(q) {
			if (p & q) continue;
			if (j && (l >> i & 1) < p) continue;
			if (k && (r >> i & 1) < q) continue;
			dp[i][j & (l >> i & 1 ^ p ^ 1)][k & (r >> i & 1 ^ q ^ 1)] += dp[i + 1][j][k];
		}
		return dp[0][0][0] + dp[0][0][1] + dp[0][1][0] + dp[0][1][1];
	};
	int T;
	cin >> T;
	while (T--) {
		int l, r;
		cin >> l >> r;
		--l;
		cout << cal(r, r) + cal(l, l) - cal(l, r) * 2 << endl;
	}
}
