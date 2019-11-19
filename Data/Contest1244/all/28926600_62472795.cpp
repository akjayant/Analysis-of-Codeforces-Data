#include <algorithm>
// #include <cstring>
#include <cstdio>
using std::min;

const long long INF = 0xFFFFFFFFFFFFFF;
const int MAXN = 100010;

struct EDGE { int v; EDGE *n; } edge[MAXN*2], *head[MAXN];
int n, ce, c[4][MAXN], d[MAXN], final[2], x[MAXN];
long long f[MAXN][4][4], ans;

void AddEdge(const int u, const int v) {
	edge[++ce] = (EDGE){ v, head[u] };
	head[u] = edge + ce;
}

void dfs(const int u, const int fa) {
	int v = 0;

	for (const EDGE *e = head[u]; e; e = e->n)
		if (e->v != fa)
			v = e->v;

	if (v != 0) {
		dfs(v, u);
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++) {
				if (i == j) continue;
				int k = 6 - i - j;
				f[u][i][j] = f[v][j][k] + c[i][u];
			}
	}
	else {
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++)
				f[u][i][j] = c[i][u];
	}

	// printf("u = %d\n", u);
	// for (int i = 1; i <= 3; i++) {
	// 	for (int j = 1; j <= 3; j++)
	// 		printf("%d ", f[u][i][j]);
	// 	puts("");
	// }
}

void find_solution(const int u, const int fa, const int a, const int b) {
	x[u] = a;
	for (const EDGE *e = head[u]; e; e = e->n)
		if (e->v != fa)
			find_solution(e->v, u, b, 6 - a - b);
}

int main() {
	// freopen("Temp.in", "r", stdin);
	// freopen("Temp.out", "w", stdout);

	// memset(f, 0x3F, sizeof(f));

	scanf("%d", &n);
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &c[i][j]);

	for (int i = 1, u, v; i <= n - 1; i++) {
		scanf("%d %d", &u, &v);
		AddEdge(u, v);
		AddEdge(v, u);
		d[u] ++;
		d[v] ++;
		if (d[u] > 2 || d[v] > 2) {
			puts("-1");
			return 0;
		}
	}

	for (int i = 1; i <= n; i++)
		if (d[i] == 1) {
			dfs(i, i);
			ans = INF;
			for (int j = 1; j <= 3; j++)
				for (int k = 1; k <= 3; k++)
					if (j != k && f[i][j][k] < ans) {
						ans = f[i][j][k];
						final[0] = j;
						final[1] = k;
					}
			printf("%lld\n", ans);
			find_solution(i, i, final[0], final[1]);
			for (int j = 1; j <= n; j++)
				printf("%d ", x[j]);
			puts("");
			break;
		}

	return 0;
}
