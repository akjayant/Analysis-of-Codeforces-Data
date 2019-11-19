#include <cstdio>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>

#pragma GCC optimize(2)

using namespace std;

const int maxn = 2005;

struct edge
{
	int u, v;
	long long w;
}c[maxn*maxn];

int tot;

inline bool operator < (edge p, edge q)
{
	return p.w < q.w;
}

struct point
{
	int x, y;
	int cost, k;
}a[maxn];

int f[maxn];

bool vis[maxn];

struct node
{
	int a, b;
};

queue <node> Q;

int find (int x)
{
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

int ans1;

int main (void)
{
	int n;
	scanf("%d", &n);
	for(register int i=1; i<=n; ++i)
		scanf("%d %d", &a[i].x, &a[i].y);
	for(register int i=1; i<=n; ++i)
	{
		scanf("%d", &a[i].cost);
		c[++tot]=(edge){0,i,a[i].cost};
	}
	for(register int i=1; i<=n; ++i)
		scanf("%d", &a[i].k);
	for(register int i=1; i<=n; ++i)
		for(register int j=i+1; j<=n; ++j)
		{
			long long s = a[i].k + a[j].k;
			s *= abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
			c[++tot]=(edge){i,j,s};
		}
	sort(c+1, c+tot+1);
	int cnt = n+1;
	long long ans = 0;
	for(register int i=1; i<=n; ++i) f[i] = i;
	register int tp = 1;
	while(cnt>1)
	{
		edge cur = c[tp++];
		if(find(cur.u) != find(cur.v))
		{
			f[find(cur.u)] = find(cur.v);
			ans += cur.w;
			if(cur.u == 0) vis[cur.v] = 1;
			else Q.push((node){cur.u,cur.v});
			-- cnt;
		}
	}
	cout << ans << endl;
	cnt = 0;
	for(register int i=1; i<=n; ++i)
		if(vis[i] == 1) ++ cnt;
	printf("%d\n", cnt);
	for(register int i=1; i<=n; ++i)
		if(vis[i] == 1) printf("%d ", i);
	printf("\n");
	printf("%d\n", n-cnt);
	while(!Q.empty())
	{
		node cur = Q.front(); Q.pop();
		printf("%d %d\n", cur.a, cur.b);
	}
	return 0;
}
