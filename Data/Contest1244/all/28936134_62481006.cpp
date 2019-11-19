#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100005;

vector<int> g[N];
int p[N], c[N], val[4][N], root, chi0, chi1, n;

void dfs(int u, int v) {
	for (auto t : g[u]) {
		if (t == v) continue;
		p[t] = u;
		if (!c[t]) {
			c[t] = 6 - c[p[t]] - c[p[p[t]]];
		}
		dfs(t, u);
	}
}

int check(int c1, int c2, int c3) {
	int res = 0;
	memset(c, 0, sizeof(c));
	c[root] = c1;
	c[chi0] = c2;
	c[chi1] = c3;
	dfs(root, 0);
	for (int i = 1; i <= n; i++) {
		res += val[c[i]][i];
	}
	return res;
}

main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int j = 1; j <= 3; j++)
	for (int i = 1; i <= n; i++) {
		cin >> val[j][i];
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v); g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (g[i].size() > 2) {
			return cout << -1, 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (g[i].size() == 2) {
			root = i;
			chi0 = g[i][0];
			chi1 = g[i][1];
			p[chi0] = root;
			p[chi1] = root;
			break;
		}
	}
	int mn = 2e18;
	mn = min(mn, check(1 ,2, 3));
	mn = min(mn, check(1 ,3, 2));
	mn = min(mn, check(2 ,1, 3));
	mn = min(mn, check(2 ,3, 1));
	mn = min(mn, check(3 ,1, 2));
	mn = min(mn, check(3 ,2, 1));
	cout << mn << endl;
	if (mn == check(1, 2, 3)) {
		for (int i = 1; i <= n; i++) {
			cout << c[i] << ' ';
		}
		return 0;
	}
	if (mn == check(1, 3, 2)) {
		for (int i = 1; i <= n; i++) {
			cout << c[i] << ' ';
		}
		return 0;
	}
	if (mn == check(2, 1, 3)) {
		for (int i = 1; i <= n; i++) {
			cout << c[i] << ' ';
		}
		return 0;
	}
	if (mn == check(2, 3, 1)) {
		for (int i = 1; i <= n; i++) {
			cout << c[i] << ' ';
		}
		return 0;
	}
	if (mn == check(3, 1, 2)) {
		for (int i = 1; i <= n; i++) {
			cout << c[i] << ' ';
		}
		return 0;
	}
	if (mn == check(3, 2, 1)) {
		for (int i = 1; i <= n; i++) {
			cout << c[i] << ' ';
		}
		return 0;
	}
	return 0;
 }
