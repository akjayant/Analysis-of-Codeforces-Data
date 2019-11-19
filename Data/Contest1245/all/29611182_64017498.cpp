#include <cstdio>
#include <algorithm>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define abs(x) ((x) > 0 ? (x) : -(x))

typedef long long ll;
ll read()
{
	ll ret = 0, t = 1; char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}
const int MAXN = 2005;

struct edge { int u, v; ll k; } E[MAXN * MAXN]; int Elen;
bool cmp(edge e1, edge e2) { return e1.k < e2.k; }
int N, X[MAXN], Y[MAXN], C[MAXN], K[MAXN], fa[MAXN]; ll ans;
int ans1, a1[MAXN], ans2, a2u[MAXN], a2v[MAXN], count;
int get(int x)
{
	if (fa[x] != x) fa[x] = get(fa[x]);
	return fa[x];
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin), freopen("test.out", "w", stdout);
	#endif
	N = read(); int i, j;
	for (i = 1; i <= N; ++i) X[i] = read(), Y[i] = read();
	for (i = 1; i <= N; ++i) C[i] = read();
	for (i = 1; i <= N; ++i) K[i] = read();
	for (i = 1; i <= N; ++i) for (j = i + 1; j <= N; ++j) E[++Elen].u = i, E[Elen].v = j, E[Elen].k = (ll)(abs(X[i] - X[j]) + abs(Y[i] - Y[j])) * (K[i] + K[j]);
	for (i = 1; i <= N; ++i) E[++Elen].u = i, E[Elen].v = N + 1, E[Elen].k = C[i];
	for (i = 1; i <= N + 1; ++i) fa[i] = i;
	std::sort(E + 1, E + Elen + 1, cmp);
	for (i = 1; i <= Elen; ++i)
	{
		int gu = get(E[i].u), gv = get(E[i].v);
		if (gu != gv)
		{
			fa[gu] = gv, ans += E[i].k;
			if (E[i].v == N + 1) a1[++ans1] = E[i].u;
			else a2u[++ans2] = E[i].u, a2v[ans2] = E[i].v;
			++count;
			if (count == N) break;
		}
	}
	printf("%lld\n", ans);
	printf("%d\n", ans1);
	for (i = 1; i <= ans1; ++i) printf("%d ", a1[i]); putchar('\n');
	printf("%d\n", ans2);
	for (i = 1; i <= ans2; ++i) printf("%d %d\n", a2u[i], a2v[i]);
	return 0;
}