#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define s second
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>

const int maxn = 1e5 + 50;

vi r[maxn];
ll dp[maxn][3][3];
int back[maxn][3][3];
int c[3][maxn];
int ans[maxn];

ll dfs(int v, int c1, int c2, int p = -1) {
	// cout << v << ' ' << p << ' ' << c1 << ' ' << c2 << endl;
	if (r[v].size() > 2) {
		cout << -1 << endl;
		exit(0);
	}
	ans[v] = c1 + 1;
	ll ans = c[c1][v];
	for (auto &u : r[v]) {
		if (u == p)
			continue;
		ans += dfs(u, c2, 3 - c1 - c2, v);
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				dp[i][j][k] = 1e18;
			}
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		r[a].pb(b);
		r[b].pb(a);
	}
	//scout << 1 << endl;
	ll ans = 1e18;
	int col[n];
	int v = 0;
	for (int i = 0; i < n; ++i) {
		if (r[i].size() == 1)
			v = i;
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == j)
				continue;
			ll lel = 0;
			if ((lel = dfs(v, i, j)) < ans) {
				ans = lel;
				for (int i = 0; i < n; ++i) {
					col[i] = ::ans[i];
				}
			}
		}
	}
	cout << ans << endl;
	for (int i = 0; i < n; ++i) {
		cout << col[i] << ' ';
	}
	cout << endl;
}

signed main() {
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}	
}