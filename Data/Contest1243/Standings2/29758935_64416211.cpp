#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 3;
int head[N], nxt[N], to[N], ne, n;
void add_edge(int f, int t) {
	nxt[ne] = head[f];
	head[f] = ne;
	to[ne] = t;
	ne++;
}
void addBiEdge(int u, int v) {
	add_edge(u, v);
	add_edge(v, u);
}
void init() {
	memset(head, -1, n * sizeof head[0]);
	ne = 0;
}
bool vis[N];
int tmpVis[N], visID, res[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // cost 	node
set<int> nodes;
void prim(int u, int cost) {
	if (vis[u]++)
		return;
	res[u] = cost;
	++visID;
	for (int e = head[u]; ~e; e = nxt[e]) {
		int v = to[e];
		tmpVis[v] = visID;
	}
	if (nodes.count(u))
		nodes.erase(u);
	vector<int> tmp;
	for (auto it = nodes.begin(); it != nodes.end();) {
		if (tmpVis[*it] != visID) {
			tmp.push_back(*it);
			it = nodes.erase(it);
		} else {
			++it;
		}
	}
	for (auto v: tmp) {
		prim(v, 0);
	}
	for (int e = head[u]; ~e; e = nxt[e]) {
		int v = to[e];
		if (!vis[v])
			q.push({1, v});
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	int m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		nodes.insert(i);
	init();
	while (m--) {
		int u, v;
		scanf("%d %d", &u, &v);
		addBiEdge(--u, --v);
	}
	q.push({0, 0});
	while (true) {
		while (q.size() && vis[q.top().second])
			q.pop();
		if (q.empty())
			break;
		auto p = q.top();
		q.pop();
		prim(p.second, p.first);
	}
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += res[i];
	printf("%d\n", sum);
	return 0;
}