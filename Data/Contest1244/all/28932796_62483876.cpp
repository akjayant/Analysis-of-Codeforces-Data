#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define N 100005
#define M 200005
int tar[M], nex[M], fir[N], cnt;
int n, mx, cost[N][3], deg[N];
int col[N], ans[N], way[3];
ll sum = 1ll << 60;
void Add(int a, int b)
{
	++cnt;
	tar[cnt] = b;
	nex[cnt] = fir[a];
	fir[a] = cnt;
}
void Dfs(int r, int fa, int x, ll now)
{
	col[r] = way[x % 3];
	now += cost[r][col[r]];
	if (now > sum)
		return;
	if (x == n - 1)
	{
		sum = now;
		for (int i = 1; i <= n; i++)
			ans[i] = col[i];
		return;
	}
	for (int i = fir[r]; i; i = nex[i])
	{
		int v = tar[i];
		if (v != fa)
			Dfs(v, r, x + 1, now);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &cost[i][0]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &cost[i][1]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &cost[i][2]);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		Add(u, v), Add(v, u);
		deg[u]++, deg[v]++;
		mx = max(mx, max(deg[u], deg[v]));
	}
	if (mx > 2)
	{
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		if (deg[i] == 1)
		{
			for (int j = 0; j <= 2; j++)
			{
				for (int k = 0; k <= 2; k++)
				{
					if (k == j)continue;
					for (int l = 0; l <= 2; l++)
					{
						if (l == j || l == k)continue;
						way[0] = j, way[1] = k, way[2] = l;
						Dfs(i, 0, 0, 0);
					}
				}
			}
			break;
		}
	printf("%I64d\n", sum);
	for (int i = 1; i <= n; i++)
		printf("%d%c", ans[i] + 1, i == n ? 10 : 32);
}
