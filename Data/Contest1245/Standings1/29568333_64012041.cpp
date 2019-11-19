#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
using namespace std;
const int maxn = 2e3 + 10;
LL ans;
vector<int> G[maxn];
int n, cnt, root, x[maxn], y[maxn], c[maxn], k[maxn], fa[maxn];

struct Edge{
	int u, v;
	LL w;
	bool operator < (const Edge &A) const {
		return w < A.w;
	}
}edges[maxn * maxn];

int find(int a) { return fa[a] == a ? a : fa[a] = find(fa[a]); }

int main()
{
	#ifdef DEBUG
	freopen("text.in", "r", stdin);
	#endif
	scanf("%d", &n); root = n + 1;
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &x[i], &y[i]);
	for (int i = 1; i <= n + 1; ++i)
		fa[i] = i;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &c[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &k[i]);
	for (int i = 1; i <= n; ++i) {
		edges[++cnt] = (Edge) { i, root, c[i] };
		for (int j = i + 1; j <= n; ++j)
			edges[++cnt] = (Edge) { i, j, 1ll * (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]))};
	}
	sort(edges + 1, edges + cnt + 1);
	int tot = 0;
	for (int i = 1, u, v; i <= cnt; ++i) {
		u = edges[i].u; v = edges[i].v;
		if (find(u) != find(v)) {
			ans += edges[i].w;
			fa[find(u)] = find(v);
			G[u].pb(v);
			G[v].pb(u);
			if (++tot == n) break;
		}
	}
	cout << ans << endl;
	printf("%d\n", (int) G[root].size());
	for (int x : G[root])
		printf("%d ", x);
	printf("\n");
	printf("%d\n", n - (int) G[root].size());
	for (int i = 1; i <= n; ++i) {
		for (int v : G[i])
			if (v != root && v > i)
				printf("%d %d\n", i, v);
				
	}
	return 0;
}