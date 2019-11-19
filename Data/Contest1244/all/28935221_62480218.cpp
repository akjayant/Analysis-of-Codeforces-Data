#include <cstdio>
#include <cctype>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
#define R register
#define ll long long
using namespace std;
const ll inf = 1e18;
const int N = 110000, M = N << 1;

int n, hd[N], to[M], nxt[M], noedg = 1, dgr[N], c[N][3], lst[N][3][3], col[N];
ll f[N][3][3];

template <class T> inline void read(T &x) {
	x = 0;
	char ch = getchar(), w = 0;
	while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	x = w ? -x : x;
	return;
}

inline void addEdg(int x, int y) {
	nxt[++noedg] = hd[x], hd[x] = noedg, to[noedg] = y, ++dgr[x];
	nxt[++noedg] = hd[y], hd[y] = noedg, to[noedg] = x, ++dgr[y];
	return;
}

void dfs1(int now, int fa) {
	for (R int i = hd[now], v; i; i = nxt[i]) {
		if ((v = to[i]) == fa) continue;
		dfs1(v, now);
		for (R int j = 0; j <= 2; ++j) {
			for (R int k = 0; k <= 2; ++k) {
				if (k == j) continue;
				for (R int u = 0; u <= 2; ++u) {
					if (u == k || u == j) continue;
					if (f[v][k][u] + c[now][j] < f[now][j][k])
						f[now][j][k] = f[v][k][u] + c[now][j], lst[now][j][k] = u;
				}
			}
		}
	}
	return;
}

void dfs2(int now, int fa, int pa, int pb) {
	col[now] = pa;
	for (R int i = hd[now], v; i; i = nxt[i]) {
		if ((v = to[i]) == fa) continue;
		dfs2(v, now, pb, lst[now][pa][pb]);
	}
	return;
}

int main() {
	int x, y;
	read(n);
	for (R int i = 1; i <= n; ++i)
		read(c[i][0]);
	for (R int i = 1; i <= n; ++i)
		read(c[i][1]);
	for (R int i = 1; i <= n; ++i)
		read(c[i][2]);
	for (R int i = 1; i < n; ++i)
		read(x), read(y), addEdg(x, y);
	int root1 = 0, root2 = 0;
	for (R int i = 1; i <= n; ++i) {
		if (dgr[i] == 1) {
			if (root1) root2 = i;
			else root1 = i;
		}
		if (dgr[i] > 2) return printf("-1\n"), 0;
	}
	memset(f, 0x3f, sizeof (f));
	for (R int i = 0; i <= 2; ++i) {
		for (R int j = 0; j <= 2; ++j)
			f[root2][i][j] = c[root2][i];
		f[root2][i][i] = inf;
	}
	dfs1(root1, 0);
	int pa = 0, pb = 1;
	for (R int i = 0; i <= 2; ++i)
		for (R int j = 0; j <= 2; ++j)
			if (f[root1][i][j] < f[root1][pa][pb])
				pa = i, pb = j;
	dfs2(root1, 0, pa, pb);
	cout << f[root1][pa][pb] << endl;
	for (R int i = 1; i <= n; ++i)
		printf("%d ", col[i] + 1);
	return 0;
}