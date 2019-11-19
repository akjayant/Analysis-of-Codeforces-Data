#include <bits/stdc++.h>
using namespace std;

namespace TYC
{
	typedef long long ll;
	typedef pair<ll, int> pa;
	typedef pair<int, int> pii;
	const int N = 2010;

	int n, X[N], Y[N], K[N], vis[N], pre[N];
	ll dis[N];
	struct Edge { int v; ll w; };
	vector<Edge> E[N];
	vector<int> li;
	vector<pii> edge;

	inline int read()
	{
		int x = 0, f = 0, ch = getchar();
		while (!isdigit(ch))
			f |= (ch == '-'), ch = getchar();
		while (isdigit(ch))
			x = x * 10 + ch - '0', ch = getchar();
		return f ? -x : x;
	}

	void add(const int u, const int v, const ll w)
	{
		E[u].push_back({v, w});
		E[v].push_back({u, w});
	}

	ll Prim()
	{
		memset(dis, 0x3f, sizeof(dis));
		dis[n] = 0;
		ll ans = 0;
		for (int k = 1; k <= n; k++)
		{
			int u = 0;
			for (int i = 1; i <= n; i++)
				if (!vis[i] && (!u || dis[i] < dis[u]))
					u = i;
			vis[u] = 1;
			ans += dis[u];
			if (u != n)
			{
				if (pre[u] == n)
					li.push_back(u);
				else
					edge.push_back(pii(pre[u], u));
			}
			for (auto p : E[u])
				if (!vis[p.v] && dis[p.v] > p.w)
					dis[p.v] = p.w, pre[p.v] = u;
		}
		return ans;
	}

	void work()
	{
		n = read();
		for (int i = 1; i <= n; i++)
			X[i] = read(), Y[i] = read();
		for (int i = 1; i <= n; i++)
			add(n + 1, i, read());
		for (int i = 1; i <= n; i++)
			K[i] = read();
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				add(i, j, (ll)(K[i] + K[j]) * (abs(X[i] - X[j]) + abs(Y[i] - Y[j])));
		++n;
		printf("%lld\n", Prim());
		printf("%d\n", int(li.size()));
		for (int i : li)
			printf("%d ", i);
		puts("");
		printf("%d\n", int(edge.size()));
		for (pii p : edge)
			printf("%d %d\n", p.first, p.second);
	}
}

int main()
{
	TYC::work();
	return 0;
}