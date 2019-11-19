#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <set>
#include <stack>
using namespace std;

const int N = 1000005;
struct Edge {
	int to, nxt;
	Edge() {
		nxt = -1;
	}
};
int n, m, pnt, hd[N], dfn[N], low[N], _time, sccId[N], sccCnt;
int outDgr[N];
Edge e[N];
set <int> scc[N];
stack <int> stk;

void AddEdge(int u, int v) {
	e[++pnt].to = v;
	e[pnt].nxt = hd[u];
	hd[u] = pnt;
}

void Read() {
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= m;i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		if (u == v) continue;
		AddEdge(u, v);
		//AddEdge(v, u);
	}
}

void Dfs(int u) {
	dfn[u] = low[u] = ++_time;
	stk.push(u);
	for (int i = hd[u];i != -1;i = e[i].nxt) {
		int v = e[i].to;
		if (!dfn[v]) {
			Dfs(v);
			low[u] = min(low[u], low[v]);
		} else if (!sccId[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		sccCnt++;
		while (1) {
			int cur = stk.top();
			stk.pop();
			scc[sccCnt].insert(cur);
			sccId[cur] = sccCnt;
			if (cur == u) {
				break;
			}
		}
	}
}

void Solve() {
	for (int i = 1;i <= n;i++) {
		if (!dfn[i]) {
			Dfs(i);
		}
	}
	if (sccCnt == 1) {
		puts("No");
		return;
	}
//	for (int i = 1;i <= n;i++) {
//		printf("%d ", sccId[i]);
//	}
//	printf("\n");
	for (int i = 1;i <= n;i++) {
		for (int j = hd[i];j != -1;j = e[j].nxt) {
			if (sccId[i] != sccId[e[j].to]) {
				outDgr[sccId[i]]++;
			}
		}
	}
	int ans = 0;
	for (int i = 1;i <= sccCnt;i++) {
		if (outDgr[i] == 0 && !scc[i].empty() && scc[i].size() != n) {
			ans = i;
			break;
		}
	}
	if (ans == 0) {
		printf("No\n");
		return;
	} else {
		printf("Yes\n");
		printf("%d %d\n", scc[ans].size(), n - scc[ans].size());
		for (int i = 1;i <= n;i++) {
			if (sccId[i] == ans) printf("%d ", i);
		}
		putchar('\n');
		for (int i = 1;i <= n;i++) {
			if (sccId[i] != ans) printf("%d ", i);
		}
		putchar('\n');
	}
}

void Init() {
	while (!stk.empty()) stk.pop();
	for (int i = 1;i <= n;i++) {
		hd[i] = -1;
		scc[i].clear();
		dfn[i] = low[i] = sccId[i] = outDgr[i] = 0;
	}
	sccCnt = pnt = _time = 0;
}

int main() {
	memset(hd, -1, sizeof(hd));
	int t;
	scanf("%d", &t);
	while (t--) {
		Read();
		Solve();
		Init();
	}
	return 0;
}