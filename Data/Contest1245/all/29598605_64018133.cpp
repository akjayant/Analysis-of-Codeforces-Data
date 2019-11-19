#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2000 + 3;

int n, m;
long long x[N], y[N];
long long c[N], k[N];
struct str {
	int x, y;
	long long z;
} e[N * N];
int fa[N];
long long ans;
int vt, v[N];
int ut, ux[N], uy[N];

int getfa(int x);
long long mabs(long long x);

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%I64d%I64d", x + i, y + i);
	for (int i = 1; i <= n; ++i)
		scanf("%I64d", c + i);
	for (int i = 1; i <= n; ++i)
		scanf("%I64d", k + i);
		
	for (int i = 0; i <= n; ++i)
		fa[i] = i;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j)
			e[++m] = (str){ i, j, (k[i] + k[j]) * (mabs(x[i] - x[j]) + mabs(y[i] - y[j])) };
		e[++m] = (str){ i, 0, c[i] };
	}
	sort(e + 1, e + m + 1, [](const str &a, const str &b) {
		return a.z < b.z;
	});
	for (int i = 1; i <= m; ++i) {
		if (getfa(e[i].x) == getfa(e[i].y)) continue;
		ans += e[i].z;
		fa[getfa(e[i].x)] = getfa(e[i].y);
		if (e[i].y == 0) v[++vt] = e[i].x;
		else ux[++ut] = e[i].x, uy[ut] = e[i].y;
	}

	printf("%I64d\n", ans);
	printf("%d\n", vt);
	for (int i = 1; i <= vt; ++i)
		printf("%d ", v[i]);
	printf("\n");
	printf("%d\n", ut);
	for (int i = 1; i <= ut; ++i)
		printf("%d %d\n", ux[i], uy[i]);

	return 0;
}

int getfa(int x) {
	return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}

long long mabs(long long x) {
	return x > 0 ? x : -x;
}
