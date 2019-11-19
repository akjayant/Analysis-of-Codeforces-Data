#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e4 + 10;
const int MAXM = 5e6 + 10;
const int MOD = 1e9 + 7;
#define pa pair<int, int>
struct edge {
	int u, v;
	int id;
	ll w;
	edge(int u = 0, int v = 0, ll w = 0, int id = 0)
		:u(u), v(v), w(w), id(id) {}
}edges[MAXM];
int tot = 0;
int fa[MAXN];

void init() {
	for (int i = 0; i < MAXN; i++) {
		fa[i] = i;
	}
}

int Find(int x) {
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		fa[x] = y;
	}
}
ll x[MAXN], y[MAXN];
ll c[MAXN], k[MAXN];

int main() {
	ios::sync_with_stdio(0);
	init();
	int n;
	cin >> n;
	// n+1
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		edges[tot++] = edge(0, i, c[i], i);
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			edges[tot++] = edge(i, j, 1ll * (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])), MAXN);
		}
	}
	sort(edges, edges + tot, [](const edge& e1, const edge& e2) {
		return e1.w < e2.w;
	});
	vector<int> di;
	vector<pa> ed;
	int has = 0;
	ll ret = 0;
	for (int i = 0; i < tot; i++) {
		if (has == n) break;
		int u = edges[i].u, v = edges[i].v;
		if (Find(u) != Find(v)) {
			Union(u, v);
			has++;
			ret += edges[i].w;
			if (edges[i].id <= n) {
				di.push_back(edges[i].id);
				// cout << edges[i].id << "----\n";
			}
			else {
				ed.push_back(pa(edges[i].u, edges[i].v));
				// cout << edges[i].u << " " << edges[i].v << "----\n";
			}
		}
	}

	cout << ret << endl;
	cout << di.size() << endl;
	for (auto it : di) cout << it << " ";
	cout << endl;
	cout << ed.size() << endl;
	for (auto it : ed) cout << it.first << " " << it.second << endl;
}

/*
2 5
2 3 0
SSSSS
*/