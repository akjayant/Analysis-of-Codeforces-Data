#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
const ll inf = 1e18;
int n, d[N], head[N], tot;
struct Edge
{
	int u, v, nex;
}e[N];
ll ans = inf;
ll c[4][N];
int col[N], ANS[N];
void add(int u, int v) 
{
	e[++tot] = Edge{ u,v,head[u] };
	head[u] = tot;
}
void dfs(int pos, int fa, int up1, int up2, ll cost) 
{
	for (int i = 1; i <= 3; ++i) 
	{
		if (up1 == -1 && up2 == -1) 
		{
			col[pos] = i;
			ll t = cost + c[i][pos];
			bool f = false;
			for (int k = head[pos]; k; k =e[k].nex)
			{
				if (e[k].v == fa)
					continue;
				f = true;
				dfs(e[k].v, pos, -1, i, t);
			}
			if (!f) 
			{
				if (t < ans) 
				{
					for (int j = 1; j <= n; ++j) 
						ANS[j] = col[j];
					ans = t;
				}
			}
		}
		else if (up1 == -1) 
		{
			if (i != up2) 
			{
				col[pos] = i;
				ll t = cost + c[i][pos];
				bool f = false;
				for (int k = head[pos]; k; k = e[k].nex) 
				{
					if (e[k].v == fa)
						continue;
					f = true;
					dfs(e[k].v, pos, up2, i, t);
				}
				if (!f) 
				{
					if (t < ans) 
					{
						for (int j = 1; j <= n; ++j)
							ANS[j] = col[j];
						ans = t;
					}
				}
			}
		}
		else 
		{
			if (i != up1 && i != up2) 
			{
				col[pos] = i;
				ll t = cost + c[i][pos];
				bool f = false;
				for (int k = head[pos]; k; k = e[k].nex) 
				{
					if (e[k].v == fa) 
						continue;
					f = true;
					dfs(e[k].v, pos, up2, i, t);
				}
				if (!f) 
				{
					if (t < ans) 
					{
						for (int j = 1; j <= n; ++j) 
							ANS[j] = col[j];
						ans = t;
					}
				}
			}
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &c[1][i]);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &c[2][i]);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &c[3][i]);
	tot = 0;
	for (int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
		++d[x], ++d[y];
	}
	for (int i = 1; i <= n; ++i)
	{
		if (d[i] >= 3)
		{
			printf("-1\n");
			return 0;
		}
	}
	int root;
	for (int i = 1; i <= n; ++i)
		if (d[i] == 1)
		{
			root = i;
			break;
		}
	dfs(root, 0, -1, -1, 0);
	printf("%lld\n", ans);
	for (int i = 1; i <= n; ++i)
		printf(i == n ? "%d" : "%d ", ANS[i]);
}


