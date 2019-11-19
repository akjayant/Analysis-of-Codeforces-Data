#include <bits/stdc++.h>
using namespace std;

vector<int> color;
set<int> white;
vector<set<int> > g;

void dfs(int v, int c) {
	// cerr << "in:" << v << endl;
	color[v] = c;
	white.erase(v);
	for (auto it = white.lower_bound(0); it != white.end(); ) {
		int u = *it;
		if (color[u] == -1 && !g[v].count(u)) {
			dfs(u, c);
			it = white.lower_bound(++u);
		} else {
			++it;
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	g.assign(n, set<int>());
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b; a--, b--;
		g[a].insert(b);
		g[b].insert(a);
	}
	white.clear();
	for (int v = 0; v < n; v++) {
		white.insert(v);
	}

	color.assign(n, -1);
	int cnt = 0;
	for (int v = 0; v < n; v++) {
		if (color[v] == -1) {
			dfs(v, cnt++);
		}
	}
	// for (int v = 0; v < n; v++) {
	// 	cerr << color[v] << " ";
	// }
	// cerr << endl;
	cout << cnt - 1 << endl;
    return 0;
}
