#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100010;
struct edge {
	int to, next;
} e[N * 2];
int head[N], ecnt, ind[N];
inline void adde(int from, int to) {
	e[++ecnt] = (edge){to, head[from]}, head[from] = ecnt;
	e[++ecnt] = (edge){from, head[to]}, head[to] = ecnt;
	ind[from]++, ind[to]++;
}
LL res; int col[N], c[3][N];
void dfs(int u, int f, int ls1, int ls2) {
	int t = 3 - ls1 - ls2;
	res += c[t][u], col[u] = t;
	for (int i = head[u]; i; i = e[i].next)
		if (e[i].to != f) dfs(e[i].to, u, ls2, t);
}
int main() {
	int n; scanf("%d", &n);
	for (int k = 0; k < 3; k++)
		for (int i = 1; i <= n; i++) scanf("%d", &c[k][i]);
	for (int i = 1, a, b; i < n; i++) {
		scanf("%d%d", &a, &b), adde(a, b);
	}
	for (int i = 1; i <= n; i++) if (ind[i] > 2) {
		puts("-1"); return 0;
	}
	int rt = -1;
	for (int i = 1; i <= n; i++) if (ind[i] == 1) {
		rt = i; break;
	}
	int fuck = e[head[rt]].to, fuck2 = 0; LL tmp = 1e18;
	for (int i = head[fuck]; i; i = e[i].next)
		if (e[i].to != rt) fuck2 = e[i].to; 
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) if (i != j) {
			res = 0, dfs(fuck2, fuck, i, j);
			tmp = min(tmp, res + c[i][rt] + c[j][fuck]);
		}
	cout << tmp << endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) if (i != j) {
			res = 0, dfs(fuck2, fuck, i, j);
			if (res + c[i][rt] + c[j][fuck] == tmp) {
				col[rt] = i, col[fuck] = j;
				for (int k = 1; k <= n; k++) printf("%d ", col[k] + 1);
				return 0;
			}
		}
}