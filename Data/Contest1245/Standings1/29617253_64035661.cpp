#include<bits/stdc++.h>
#define N 2005
#define ll long long
#define int long long
using namespace std;
int n, w, h, x[N], y[N], fa[N], vis[N], ans0[N], C[N], K[N], sz;
int dis[N];
int get(int x) {
	return x == fa[x]? x : (fa[x] = get(fa[x]));
}
void merge(int x, int y) {
	x = get(x), y = get(y);
	fa[x] = y;
}
int dist(int i, int j) {
	if(i == j) return 0;
	if(i == 0) return (int)C[j];
	if(j == 0) return (int)C[i];
	return (labs(x[i] - x[j]) + labs(y[i] - y[j])) * (K[i] + K[j]);
}
struct edge {
	int u, v, val;
}e[N * N], anss[N];
int cmp(edge x, edge y) {
	return x.val < y.val;
}
signed main() {
	scanf("%I64d", &n);
	for(int i = 1; i <= n; i ++) scanf("%I64d%I64d", &x[i], &y[i]);
	for(int i = 1; i <= n; i ++) scanf("%I64d", &C[i]);
	for(int i = 1; i <= n; i ++) scanf("%I64d", &K[i]);
	for(int i = 0; i <= n; i ++) {
		for(int j = i + 1; j <= n; j ++) {
			int dis = dist(i, j);
			e[++ sz].u = i, e[sz].v = j, e[sz].val = dis;
		//	printf("  %I64d %I64d %I64d\n", i, j, dis);
		}
	}
	sort(e + 1, e + 1 + sz, cmp);
	for(int i = 0; i <= n; i ++) fa[i] = i;
	int ans = 0, bs = 0, gs1 = 0, gs0 = 0;
	for(int i = 1; i <= sz; i ++) {
		int u = e[i].u, v = e[i].v, c = e[i].val;
		int x = get(u), y = get(v);
		if(x == y) continue;
		fa[x] = y;
		bs ++; ans += c;
		if(u == 0) ans0[++ gs0] = v;
		else anss[++ gs1].u = u, anss[gs1].v = v;
		if(bs == n) break;
	}
	printf("%I64d\n", ans);
	printf("%I64d\n", gs0);
	for(int i = 1; i <= gs0; i ++) printf("%I64d ", ans0[i]); printf("\n");
	printf("%I64d\n", gs1);
	for(int i = 1; i <= gs1; i ++) printf("%I64d %I64d\n", anss[i].u, anss[i].v);
	return 0; 
}

