#include<bits/stdc++.h>
#define MAXN 2005
#define MAXM 4000001
#define ll long long

using namespace std;

int N, M;

struct Edge
{
	int u, v;
	ll w;
};

int p[MAXN], l[MAXN];
vector<Edge> e;

bool cmp(Edge a, Edge b)
{
	return a.w < b.w;
}

int id(int x)
{
	return (x != p[x] ? p[x] = id(p[x]) : p[x]);
}

vector<int> geradores;
vector< pair<int, int> > ligacoes;

ll kruskal()
{
	int i, j, u, v;
	ll w, cost = 0;
	M = e.size();
	for(int i = 0; i <= N; i++)
	{
		p[i] = i;
		l[i] = 1;
	}
	sort(e.begin(), e.end(), cmp);
	for(i = 0, j = 1; i < M && j <= N; i++)
	{
		u = id(e[i].u);
		v = id(e[i].v);
		w = e[i].w;
		if(u != v)
		{
			if(l[u] > l[v])
				swap(u, v);
			p[v] = u;
			l[u] += l[v];
			u = e[i].u;
			v = e[i].v;
			if(u > v)
				swap(u, v);
			if(u == 0)
				geradores.push_back(v);
			else
				ligacoes.push_back({u, v});
			j++;
			cost += w;
		}
	}
	return cost;
}

int X[MAXN], Y[MAXN];
ll K[MAXN];

int main()
{
	ll x;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d %d", &X[i], &Y[i]);
	}
	//printf("qq\n");
	for(int i = 1; i <= N; i++)
	{
		scanf("%lld", &x);
		e.push_back({0, i, x});
	}
	//printf(":(\n");
	for(int i = 1; i <= N; i++)
	{
		scanf("%lld", &K[i]);
	}
	//printf("q\n");
	for(int i = 2; i <= N; i++)
	{
		for(int j = 1; j < i; j++)
			e.push_back({i, j, (K[i]+K[j])*(abs(X[i]-X[j])+abs(Y[i]-Y[j]))});
	}
	//printf("oi\n");
	printf("%lld\n", kruskal());
	printf("%d\n", geradores.size());
	for(int i = 0; i < geradores.size(); i++)
		printf("%d ", geradores[i]);
	printf("\n%d\n", ligacoes.size());
	for(auto p:ligacoes)
		printf("%d %d\n", p.first, p.second);
	return 0;
}
