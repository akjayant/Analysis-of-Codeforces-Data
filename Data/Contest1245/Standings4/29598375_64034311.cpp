#include <bits/stdc++.h>

using namespace std;
const int N = 2e3 + 3;

struct Edge {
	int u, v;
	long long cost;
	bool operator<(Edge other) const {
		return cost < other.cost;
	}
} edges[N * N];

vector<pair<int, long long>> adj[N]; // first node,	second cost
int parent[N], sz[N], rnk[N], n;
void init() {
	memset(rnk, 0, sizeof rnk);
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
		sz[i] = 1;
	}
}
int root(int node) {
	while (node != parent[node]) {
		parent[node] = parent[parent[node]];
		node = parent[node];
	}
	return node;
}
bool join(int u, int v) {
	u = root(u);
	v = root(v);
	if (u == v)
		return false;
	if (rnk[u] < rnk[v])
		swap(u, v);
	rnk[u] += rnk[u] == rnk[v];
	sz[u] += sz[v];
	parent[v] = u;
	return true;
}
bool find(int u, int v) {
	return root(u) == root(v);
}
bool forbid[N][N], deleted[N * N];
void kruskal() {
	sort(edges, edges + n * n);
	init();
	for (int i = 0; i < n * n; ++i) {
		if (!find(edges[i].u, edges[i].v)) {
			join(edges[i].u, edges[i].v);
			adj[edges[i].u].emplace_back(edges[i].v, edges[i].cost);
			adj[edges[i].v].emplace_back(edges[i].u, edges[i].cost);
		} else {
			deleted[i] = true;
		}
	}
}
int x[N], y[N], c[N], k[N];
long long cost, mini = 1e9;
bool on[N];
pair<long long, int> dfs(int u, int par) {
	pair<long long, int> ret = {c[u], u};
	for (auto v: adj[u])
		if (v.first != par && !forbid[u][v.first])
			ret = min(ret, dfs(v.first, u));
	return ret;
}
bool check(int i) {
	// get minLeft get minRight, weight
	auto left = dfs(edges[i].u, edges[i].v);
	auto right = dfs(edges[i].v, edges[i].u);
	long long weight = edges[i].cost;
	if (min(left.first, right.first) + weight <= left.first + right.first)
		return false;
	on[left.second] = on[right.second] = true;
	cost -= weight;
	cost += max(left.first, right.first);
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d %d", x + i, y + i);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", c + i);
		mini = min(mini, 1LL * c[i]);
	}
	for (int i = 1; i <= n; ++i)
		scanf("%d", k + i);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			edges[(i - 1) * n + (j - 1)] = {i, j, 1LL * (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]))};
	kruskal();
	cost += mini;
	for (int i = 1; i <= n; ++i) {
		if (c[i] == mini) {
			on[i] = true;
			mini = 2e9;
		}
		for (auto v: adj[i])
			if (i < v.first)
				cost += v.second;
	}
	int comps = 1;
	for (int i = n * n - 1; i >= 0; --i) {
		if (!deleted[i] && check(i)) {
			forbid[edges[i].u][edges[i].v] = forbid[edges[i].v][edges[i].u] = true;
			++comps;
		}
	}
	printf("%lld\n%d\n", cost, comps);
	int c = 0;
	for (int i = 1; i <= n; ++i)
		if (on[i]) {
			printf("%d%c", i, " \n"[++c == comps]);
		}
	printf("%d\n", n - comps);
	for (int i = 1; i <= n; ++i) {
		for (auto v: adj[i]) {
			if (i < v.first && !forbid[i][v.first]) {
				printf("%d %d\n", i, v.first);
			}
		}
	}
	return 0;
}