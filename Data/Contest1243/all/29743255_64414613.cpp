#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;
const int maxn = 100000 + 5;
unordered_set<int> g[maxn];

unordered_set<int> vv;

int par[maxn];

int Find(int x) {
	if (par[x] == x) return x;
	return par[x] = Find(par[x]);
}


void bfs(int u, int idx) {
	
	queue<int> q;
	q.emplace(u);
	par[u] = idx;
	vv.erase(u);
	while (!q.empty()) {
		int p = q.front(); q.pop();
		for (auto it = vv.begin(); it != vv.end(); ) {
			if (g[p].find(*it) == g[p].end()) {
				par[*it] = idx;
				q.emplace(*it);
				it = vv.erase(it);
			} else {
				it++;
			}
		}
	}

}

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<pair<int, int>> es;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].insert(b);
		g[b].insert(a);
		es.emplace_back(a, b);
	}

	for (int i = 1; i <= n; i++) {
		vv.insert(i);
	}

	while (!vv.empty()) {
		bfs(*vv.begin(), *vv.begin());
	}


	int res = 0;
	for (int i = 0; i < m; i++) {
		int u = es[i].first;
		int v = es[i].second;
		int fu = Find(u);
		int fv = Find(v);
		if (fv != fu) {
			par[fv] = fu;
			res++;
		}
	}
	cout << res << endl;
	
	
	return 0;
}

