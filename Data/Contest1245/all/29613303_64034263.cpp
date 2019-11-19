#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2010;

int n;
ll x[N], y[N];
ll c[N], k[N], d[N][N];

struct data{
	ll u, v, c;
	bool operator<(data o) const {
		return c < o.c;
	}
}E[N * N];

int p[N]; ll mn[N];
int find(int u) {
	if(p[u] == u) return u;
	return p[u] = find(p[u]);
}

void join(int u, int v) {
	int U = find(u);
	int V = find(v);
	if(U == V) return;

	mn[U] = min(mn[U], mn[V]);
	p[V] = U;
}

ll compCost(int u) {
	return mn[find(u)];
}

vector<pair<int,int>> ans;
vector<int> g[N], node;

int vis[N]; int now, sc;
void dfs(int u) {
	vis[u] = 1;
	if(c[u] < now) {
		now = c[u];
		sc = u;
	}
	for(int v : g[u]) if(!vis[v])
		dfs(v);
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%I64d %I64d", &x[i], &y[i]);
	for(int i = 0; i < n; i++) scanf("%I64d", &c[i]);
	for(int i = 0; i < n; i++) scanf("%I64d", &k[i]);

	int ptr = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			d[i][j] = (ll)(abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]);
			E[ptr++] = {i, j, d[i][j]};
		}
	sort(E, E + ptr);
	for(int i = 0; i < n; i++) p[i] = i, mn[i] = c[i];

	ll tot = 0;
	for(int i = 0; i < ptr; i++) {
		if(find(E[i].u) != find(E[i].v) && E[i].c <= max(compCost(E[i].u), compCost(E[i].v))) {
			join(E[i].u, E[i].v);
			ans.push_back({E[i].u, E[i].v});
			g[E[i].u].push_back(E[i].v);
			g[E[i].v].push_back(E[i].u);
			tot += E[i].c;
		}
	}

	for(int i = 0; i < n; i++) if(!vis[i]) {
		now = INT_MAX;
		dfs(i);

		tot += now;
		node.push_back(sc);		
	}
	
	printf("%I64d\n", tot);
	printf("%d\n", (int)node.size());
	for(int x : node) printf("%d ", x + 1);
	puts("");
	printf("%d\n", (int)ans.size());
	for(auto it : ans) printf("%d %d\n", it.first + 1, it.second + 1);
	return 0;
}