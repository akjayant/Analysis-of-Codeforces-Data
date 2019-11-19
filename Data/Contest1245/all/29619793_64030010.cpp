#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using pii = pair<int, int>;
ll n, station[2020], k[2020];
int dist[2020][2020];
pii town[2020];
inline int df(pii &a, pii &b)
{
	return (abs(a.first - b.first) + abs(a.second - b.second));
}

struct edge
{
	int s, e;
	ll w;
	bool operator<(const edge & other)
	{
		if (w == other.w) return (s+e) < (other.s + other.e);
		return w < other.w;
	}
};
vector <edge> edgelist;

struct Disjoint_Set_Union
{
#define V 2020
	int parent[V], size[V];
	Disjoint_Set_Union(int N = V-1)
	{
		init(N);
	}
	void init(int N)
	{
		for(int i=0;i<=N;i++)
		{
			parent[i]=i;
			size[i]=1;
		}
	}
	int Find(int K)
	{
		while(K!=parent[K])
		{
			parent[K]=parent[parent[K]];
			K=parent[K];
		}
		return K;
	}
	void unite(int x, int y)
	{
		int u=Find(x), v=Find(y);
		if(u==v)
			return;
		if(size[u]>size[v])
			swap(u, v);
		size[v]+=size[u];
		size[u] = 0;
		parent[u] = parent[v];
	}
} dsu;

vector <pii> pp;
ll Kruskal()
{
	ll mstlen = 0;
	sort(edgelist.begin(),edgelist.end());
	for (auto it:edgelist)
	{
		if (dsu.Find(it.s)==dsu.Find(it.e)) // Cycle Detection
			continue;
		else
		{
			dsu.unite(it.s,it.e);
			pp.push_back({it.s, it.e});
			mstlen += it.w;
		}
	}
	return mstlen;
}



int build[2020];
int32_t main()
{
	usecppio
	cin >> n;
	for (int i = 1; i<=n; i++)
		cin >> town[i].first >> town[i].second;
	for (int i = 1; i<=n; i++)
		cin >> station[i];
	for (int i = 1; i<=n; i++) cin >> k[i];
	for (int i = 1; i<=n; i++)
		for (int j = 1; j<=n; j++)
			dist[i][j] = df(town[i], town[j]);
	for (int i = 1; i<=n; i++)
	{
		edgelist.push_back({i, 0, station[i]});
		edgelist.push_back({0,i,station[i]});
	}
	for (int i = 1; i<=n; i++)
	{
		for (int j = 1; j<=n; j++)
		{
			if (i == j) continue;
			edgelist.push_back({i, j, (ll)dist[i][j]*(k[i]+k[j])});
			edgelist.push_back({j, i, (ll)dist[i][j]*(k[i]+k[j])});
		}
	}
	ll Len = Kruskal();
	cout << Len << '\n';
	int bc = 0;
	int uu = 0;
	for (auto it:pp)
	{
		if (it.first == 0)
		{
			build[it.second] = 1;
			bc++;
		}
		else if (it.second == 0)
		{
			build[it.first] = 1;
			bc++;
		}
		else uu++;
	}
	cout << bc << '\n';
	for (int i = 1; i<=n; i++)
		if (build[i])
			cout << i << ' ';
	cout << '\n';
	cout << uu << '\n';
	for (auto it:pp)
	{
		if (it.first != 0 && it.second!=0)
			cout << it.first <<' ' << it.second << '\n';
	}
}