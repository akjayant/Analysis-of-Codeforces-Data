#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2047;
ll n, x[N], y[N], c[N], k[N], a[N][N];
int main()
{
	scanf("%lld", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld%lld", &x[i], &y[i]);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &c[i]);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &k[i]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			a[i][j] = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
	vector<ll> d(c, c + n);
	ll ans = 0;
	vector<int> vis(n, -1);
	for (;;)
	{
		int u = -1;
		for (int i = 0; i < n; ++i)
			if (vis[i] < 0 && (u < 0 || d[u] > d[i]))
				u = i;
		if (u < 0)
			break;
		ans += d[u];
		if (d[u] == c[u])
			vis[u] = u;
		else
			for (int i = 0; i < n; ++i)
				if (vis[i] >= 0 && a[i][u] == d[u])
					vis[u] = i;
		for (int i = 0; i < n; ++i)
			if (vis[i] < 0 && d[i] > a[u][i])
				d[i] = a[u][i];
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		if (vis[i] == i)
			++cnt;
	printf("%lld\n%d\n", ans, cnt);
	for (int i = 0; i < n; ++i)
		if (vis[i] == i)
			printf("%d ", i + 1);
	printf("\n%lld\n", n - cnt);
	set<pair<int, int>> se;
	for (int i = 0; i < n; ++i)
		if (i != vis[i])
			se.emplace(min(i + 1, vis[i] + 1), max(i + 1, vis[i] + 1));
	for (auto p : se)
		printf("%d %d\n", p.first, p.second);
}
