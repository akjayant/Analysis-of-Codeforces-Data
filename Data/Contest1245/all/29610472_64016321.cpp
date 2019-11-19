#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#define int long long

const int N = 2e3 + 32, P = 1e9 + 7;
struct edge {
	int x, y, z, op;
	bool operator<(const edge& r) const { return z < r.z; }
} e[N * N];

int p[N];
int f(int x) { return x[p] ? x[p] = f(x[p]) : x; }
void m(int x, int y) { (x = f(x)) != (y = f(y)) && (x[p] = y); }

int n, x[N], y[N], c[N], k[N], cnt, ans;
std::queue<int> vec, xx, yy;
signed main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) scanf("%lld%lld", x + i, y + i);
	for (int i = 1; i <= n; i++) scanf("%lld", c + i);
	for (int i = 1; i <= n; i++) scanf("%lld", k + i);
	for (int i = 1; i <= n; i++) {
		e[++cnt] = {n + 1, i, c[i], 1};
		for (int j = i + 1; j <= n; j++)
			e[++cnt] = {i, j, (llabs(x[i] - x[j]) + llabs(y[i] - y[j])) * (k[i] + k[j]),
						0};
	}
	std::sort(e + 1, e + cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		int u = e[i].x, v = e[i].y, w = e[i].z;
		if (f(u) != f(v)) {
			if (e[i].op)
				vec.push(v);
			else
				xx.push(u), yy.push(v);
			m(u, v), ans += w;
		}
	}
	printf("%lld\n%lld\n", ans, (int)vec.size());
	for (; !vec.empty(); vec.pop()) printf("%lld%c", vec.front(), " \n"[vec.size() == 1]);
	printf("%lld\n", (int)xx.size());
	for (; !xx.empty(); xx.pop(), yy.pop()) printf("%lld %lld\n", xx.front(), yy.front());
}