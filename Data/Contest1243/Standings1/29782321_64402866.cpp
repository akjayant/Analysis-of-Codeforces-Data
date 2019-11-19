#include <bits/stdc++.h>
 
using namespace std;
#define mkp make_pair
const int MAXN = 5 * 100100;
int n, m, uf[MAXN], sz[MAXN], comp;
vector<int> g[MAXN];
set<pair<int, int>> s[MAXN];
 
inline int find(int x) { return uf[x] ? uf[x] = find(uf[x]) : x; }
void join(int x, int y)
{
	if((x = find(x)) == (y = find(y)) || !x || !y)
		return;
	comp--;
	if(sz[x] < sz[y])
		swap(x, y);
	uf[y] = x;
	g[x].push_back(y);
	sz[x] += sz[y] + 1;
}
 
struct no
{
	int beg, end, mid;
	int q;
	no *l, *r;
	no(int beg, int end) : beg(beg), end(end), mid((beg + end) >> 1), q(0)
	{
		if(beg != end)
			l = new no(beg, mid), r = new no(mid + 1, end);
	}
	void upd(int a, int b, int v)
	{
		if(b < beg || end < a)
			return;
		if(a <= beg && end <= b)
			return join(v, q), swap(q, v);
		l->upd(a, b, v), r->upd(a, b, v);
	}
	void dfs()
	{
		if(beg == end)
			return;
		join(q, l->q), join(q, r->q);
		l->dfs(), r->dfs();
	}
};
 
void f(int u, int v)
{
	auto it = prev(s[u].lower_bound(mkp(v + 1, -1)));
	pair<int, int> p = *it;
	s[u].erase(it);
	if(p.first <= v - 1)
		s[u].emplace(p.first, v - 1);
	if(v + 1 <= p.second)
		s[u].emplace(v + 1, p.second);
 
}

void printAns(int v)
{
	printf("%d ", v);
	for(const int& x : g[v])
		printAns(x);
}

int main()
{
	scanf("%d %d", &n, &m), comp = n;
	no seg(1, n);
	for(int i = 1; i <= n; ++i)
		s[i].emplace(1, n);
	for(int i = 1, u, v; i <= m; ++i)
		scanf("%d %d", &u, &v), f(u, v), f(v, u);
	for(int i = 1; i <= n; ++i)
		for(const auto&[beg, end] : s[i])
			seg.upd(beg, end, i);
	seg.dfs();
	printf("%d\n", comp - 1);
}