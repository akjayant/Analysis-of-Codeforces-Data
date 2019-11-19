#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<assert.h>
#include<functional>
using namespace std;

#define INF 1234567890
#define ll long long

struct Node {
	int x, y, c, k;
};

struct Edge {
	ll c;
	int a, b;
	bool operator<(Edge &n)
	{
		return c < n.c;
	}
};

int N;
vector<Node> v;
vector<Edge> e;
ll g[2020][2020];
int p[2020], fin[2020];

int Find(int n)
{
	if (n == p[n]) return n;
	return p[n] = Find(p[n]);
}

void Union(int a, int b)
{
	p[Find(a)] = Find(b);
}

int main()
{
	for (int i = 0; i < 2020; i++)
		p[i] = i;
	scanf("%d", &N);
	v.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &v[i].x, &v[i].y);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &v[i].c);
		e.push_back({ v[i].c, i, -1 });
	}
	for (int i = 0; i < N; i++)
		scanf("%d", &v[i].k);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (i == j) continue;
			g[i][j] = (ll)(v[i].k + v[j].k) * (abs(v[i].x - v[j].x) + abs(v[i].y - v[j].y));
			e.push_back({ g[i][j], i, j });
		}
	sort(e.begin(), e.end());

	ll res = 0;
	vector<int> rv;
	vector<pair<int, int> > re;
	for (int i = 0; i < e.size(); i++)
	{
		if (e[i].b == -1)
		{
			int a = Find(e[i].a);
			if (fin[a]) continue;
			fin[a] = 1;
			res += e[i].c;
			rv.push_back(e[i].a);
		}
		else
		{
			int a = Find(e[i].a), b = Find(e[i].b);
			if (a == b) continue;
			if (fin[a] && fin[b]) continue;

			if (fin[a] || fin[b]) fin[a] = fin[b] = 1; //
			Union(a, b);
			res += e[i].c;
			re.push_back({ e[i].a, e[i].b });
		}
	}
	
	printf("%lld\n", res);
	printf("%d\n", rv.size());
	for (int i = 0; i < rv.size(); i++)
		printf("%d ", rv[i] + 1);
	printf("\n");
	printf("%d\n", re.size());
	for (int i = 0; i < re.size(); i++)
		printf("%d %d\n", re[i].first + 1, re[i].second + 1);
	return 0;
}