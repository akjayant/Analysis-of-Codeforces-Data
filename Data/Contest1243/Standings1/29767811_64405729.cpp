#include<bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 15;

int n, m;
set<int> g[N];
set<int> unused;

void dfs(int v) {
	unused.erase(v);
	int cur = -1;
	while (unused.upper_bound(cur) != unused.end()) {
		auto it = unused.upper_bound(cur);
		cur = *it;
		if (g[v].find(cur) == g[v].end()) {
			dfs(cur);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (m--) {
		int v, u;
		cin >> v >> u;
		v--;
		u--;
		g[v].insert(u);
		g[u].insert(v);
	}
	for (int i = 0; i < n; i++) {
		unused.insert(i);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (unused.find(i) != unused.end()) {
			ans++;
			dfs(i);
		}
	}
	cout << ans - 1 << '\n';
	return 0;
}