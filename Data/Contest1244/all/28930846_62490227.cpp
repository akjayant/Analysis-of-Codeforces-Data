#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n;
long long w[maxn][4];
int head[maxn], to[maxn << 1], nxt[maxn << 1], tot;
int du[maxn], col[maxn];
void AddEdge(int u, int v) {
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
bool is_good(int n) {
	for (int i = 1; i <= n; i++) {
		if(du[i] > 2) {
			return false;
		}
	}
	return true;
}
long long ans = LONG_LONG_MAX;
int tcol[maxn];
void dfs(int u, int fath, int dps, long long sum) {
	tcol[u] = dps % 3 + 1;
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v == fath)	continue;
		dfs(v, u, dps + 1, sum + w[u][dps % 3 + 1]);
	}
	if (du[u] == 1 && u != fath) {
		// printf("%lld\n", sum + w[u][dps % 3 + 1]);
		// for (int i = 1; i <= n; i++) {
		// 	printf("%d%c", tcol[i], i < n ? ' ' : '\n');
		// }
		if (sum + w[u][dps % 3 + 1] < ans) {
			for (int i = 1; i <= n; i++) {
				col[i] = tcol[i];
			}
			ans = sum + w[u][dps % 3 + 1];
		}
	}
}
void dfss(int u, int fath, int dps, long long sum) {
	tcol[u] = dps % 3 + 1;
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v == fath)	continue;
		tcol[u] = dps % 3 + 1;
		dfss(v, u, dps + 2, sum + w[u][dps % 3 + 1]);
	}
	if (du[u] == 1 && u != fath) {
		// printf("%lld\n", sum + w[u][dps % 3 + 1]);
		// for (int i = 1; i <= n; i++) {
		// 	printf("%d%c", tcol[i], i < n ? ' ' : '\n');
		// }
		if (sum + w[u][dps % 3 + 1] < ans) {
			for (int i = 1; i <= n; i++) {
				col[i] = tcol[i];
			}
			ans = sum + w[u][dps % 3 + 1];
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int j = 1; j <= 3; j++) {
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &w[i][j]);
		}
	}
	for (int i = 1; i < n; i++) {
		int u, v;	scanf("%d%d", &u, &v);
		du[u]++;
		du[v]++;
		AddEdge(u, v);
		AddEdge(v, u);
	}
	if (is_good(n)) {
		int rt = 0;
		for (int i = 1; i <= n; i++) {
			if (du[i] == 1) {
				rt = i;
				break;
			}
		}
		for (int i = 0; i < 3; i++) {
			dfs(rt, rt, i, 0);
			dfss(rt, rt, i, 0);
		}
		printf("%lld\n", ans);
		for (int i = 1; i <= n; i++) {
			printf("%d%c", col[i], i < n ? ' ' : '\n');
		}
	}
	else {
		printf("-1\n");
	}
	return 0;
}