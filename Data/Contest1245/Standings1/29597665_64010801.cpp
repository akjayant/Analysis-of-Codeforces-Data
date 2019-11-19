#include <bits/stdc++.h>

const int N = 2005;
typedef long long LL;

int n, x[N], y[N], c[N], k[N], tot, f[N];
struct edge { int l, r; LL c; } e[N * N];
bool link[N][N];

int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> x[i] >> y[i];
	for (int i = 1; i <= n; ++i) std::cin >> c[i];
	for (int i = 1; i <= n; ++i) std::cin >> k[i];
	for (int i = 0; i <= n; ++i) f[i] = i;
	for (int i = 1; i <= n; ++i) 
		for (int j = i + 1; j <= n; ++j)
			e[++tot] = { i, j, (LL) (k[i] + k[j]) * (std::abs(x[i] - x[j]) + std::abs(y[i] - y[j])) };
	for (int i = 1; i <= n; ++i) e[++tot] = { 0, i, c[i] };
	std::sort(e + 1, e + tot + 1, [] (edge a, edge b) { return a.c < b.c; });
	LL ans = 0;
	for (int i = 1; i <= tot; ++i) {
		int x = e[i].l, y = e[i].r;
		int rx = find(x), ry = find(y);
		if (rx != ry) {
			ans += e[i].c, f[rx] = ry;
			link[y][x] = link[x][y] = 1;
		}
	}
	std::cout << ans << '\n';
	int c = 0;
	for (int i = 1; i <= n; ++i)
		c += link[0][i];
	std::cout << c << '\n';
	for (int i = 1; i <= n; ++i)
		if (link[0][i]) std::cout << i << ' ';
	std::cout << '\n';
	c = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			c += link[i][j];
	std::cout << c << '\n';
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (link[i][j]) std::cout << i << ' ' << j << '\n';
	return 0;
}
