#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
typedef long long lint;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef unsigned long long ulint;
#define endl '\n'
#define fst first
#define sed second
#define pb push_back
#define mp make_pair
#define rint register int
#define SZ(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define reveal(x) cerr << #x << " = " << (x) << endl
#define rep(it, f, e) for (rint it = (f); it <= (e); ++it)
#define per(it, f, e) for (rint it = (f); it >= (e); --it)
#define repe(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)
const int MAXN = 1e5 + 20;
const int BASE = 1 ^ 2 ^ 3;
vector<int> edge[MAXN];
int B[MAXN][3], opt[MAXN], rec[MAXN];
inline lint dfs(int u, int p, int col, int pcol) {
	lint res = B[u][col];
	rec[u] = col;
	for (auto v : edge[u]) {
		if (v != p) {
			res += dfs(v, u, BASE ^ col ^ pcol, col);
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	rep (j, 1, 3)
	rep (i, 1, n) {
		cin >> B[i][j];
	}
	rep (i, 2, n) {
		int u, v;
		cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	int root = 0;
	rep (i, 1, n) {
		if (SZ(edge[i]) > SZ(edge[root])) {
			root = i;
		}
	}
	if (SZ(edge[root]) >= 3) {
		cout << -1 << endl;
		return 0;
	}
	lint ans = 1e18;
	if (SZ(edge[root]) == 2) {
		rep (a, 1, 3) rep (b, 1, 3) rep (c, 1, 3) {
			if (a == b || a == c || b == c) continue;
			lint now = B[root][a];
			now += dfs(edge[root][0], root, b, a);
			now += dfs(edge[root][1], root, c, a);
			rec[root] = a;
			if (now < ans) memcpy(opt, rec, sizeof(opt)), ans = now;
		}
	} else {
		rep (a, 1, 3) rep (b, 1, 3) {
			if (a == b) continue;
			lint now = B[root][a];
			now += dfs(edge[root][0], root, b, a);
			rec[root] = a;
			if (now < ans) memcpy(opt, rec, sizeof(opt)), ans = now;
		}
	}
	cout << ans << endl;
	rep (i, 1, n) {
		cout << opt[i] << ' ';
	}	cout << endl;
	return 0;
}