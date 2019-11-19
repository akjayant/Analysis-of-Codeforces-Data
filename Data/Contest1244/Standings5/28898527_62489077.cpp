#include <bits/stdc++.h>
#define X first
#define Y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define ini(x, y) memset(x, y, sizeof(x))
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int n, c[3][100000];
vector<int> adj[100000];
ll dp[3][3][100000];
int cdd[100000];

ll go(int now, int prv, int c1, int c2) {
	ll &ret = dp[c1][c2][now];
	if (ret != -1) return ret;

	ret = 0;
	for (int nxt : adj[now]) if (nxt != prv)
		ret = max(ret, go(nxt, now, 3 - c1 - c2, c1) + c[3 - c1 - c2][nxt]);

	return ret;
}
void construct(int now, int prv, int c1, int c2) {
	for (int nxt : adj[now]) if (nxt != prv) {
		if (go(now, prv, c1, c2) == go(nxt, now, 3 - c1 - c2, c1) + c[3 - c1 - c2][nxt]) {
			cdd[nxt] = 3 - c1 - c2;
			construct(nxt, now, 3 - c1 - c2, c1);
		}
	}
}
int main() {
	fastio; ini(dp, -1);
	cin >> n;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < n; ++j)
			cin >> c[i][j];

	for (int a, b, i = 1; i < n; ++i) {
		cin >> a >> b;
		adj[--a].push_back(--b);
		adj[b].push_back(a);

		if (sz(adj[a]) >= 3 || sz(adj[b]) >= 3) return cout << -1, 0;
	}

	int root = -1;
	for (int i = 0; i < n; ++i)
		if (sz(adj[i]) == 1) root = i;

	ll ans = 0x3f3f3f3f3f3f3f3fll, p1, p2;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) if (i != j) {
			if (ans > go(root, -1, i, j) + c[i][root]) {
				ans = go(root, -1, i, j) + c[i][root];
				p1 = i;
				p2 = j;
			}
		}

	cout << ans << endl;
	if (ans == -1) return 0;

	cdd[root] = p1;
	construct(root, -1, p1, p2);

	for (int i = 0; i < n; ++i)
		cout << cdd[i] + 1 << ' ';

	return 0;
}