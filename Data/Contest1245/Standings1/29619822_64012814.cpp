#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <ctime>

using namespace std;

#define repeat(n) for(register LL ______________ = (n); ______________ > 0; --______________)
#define loop(i, l, r) for(register LL i = (l), ________r = (r); i <= ________r; ++i)
#define iloop(i, l, r) for(register LL i = (l), ________r = (r); i < ________r; ++i)
#define rloop(i, r, l) for(register LL i = (r), ________l = (l); i >= ________l; --i)

typedef long long LL;

#ifdef CAI_WEI_HAN
#include "LOG.h"
#else
#define LOG(...) 1
#endif

struct Edge
{
	int i, j;
	LL w;
};

struct Disjoint_Set_Union
{
	int father[2005];
	int *W;
	
	Disjoint_Set_Union(int n, int W[]): W(W)
	{ iota(&father[1], &father[n]+1, 1); }
	
	int get_root(int i)
	{
		if(father[i] == i)
			return i;
		else
			return father[i] = get_root(father[i]);
	}
	
	bool in_same_set(int i, int j)
	{ return get_root(i) == get_root(j); }
	
	void merge(int i, int j)
	{
		i = get_root(i);
		j = get_root(j);
		if(W[i] > W[j])
			swap(i, j);
		
		father[j] = i;
	}
	
	int _min(int i)
	{ return W[get_root(i)]; }
	
	int min_(int i)
	{ return get_root(i); }
};

signed main()
{
#ifdef CAI_WEI_HAN
	freopen("test.in", "r", stdin);
	#define cout cerr
#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	constexpr char endl = '\n';
	
	int n;
	cin >> n;
	
	int X[2005], Y[2005];
	loop(i, 1, n)
		cin >> X[i] >> Y[i];
	
	int W[2005];
	loop(i, 1, n)
		cin >> W[i];
	
	int EW[2005];
	loop(i, 1, n)
		cin >> EW[i];
	
	vector<Edge> E;
	loop(i, 1, n)
	loop(j, 1, n)
	if(i != j)
		E.push_back({ i, j, (LL)(EW[i] + EW[j]) * (abs(X[i] - X[j]) + abs(Y[i] - Y[j])) });
	sort(E.begin(), E.end(), [](Edge a, Edge b) { return a.w < b.w; });
	
	Disjoint_Set_Union dsu(n, W);
	vector<Edge> ans_edge;
	LL ans = 0;
	for(auto e : E)
	if(! dsu.in_same_set(e.i, e.j) && dsu._min(e.i) + dsu._min(e.j) > min(dsu._min(e.i), dsu._min(e.j)) + e.w) {
		dsu.merge(e.i, e.j);
		ans_edge.push_back(e);
		ans += e.w;
	}
	
	vector<int> ans_point;
	bool vis[2005]{};
	loop(i, 1, n)
	if(! vis[dsu.get_root(i)]) {
		vis[dsu.get_root(i)] = true;
		ans += dsu._min(i);
		ans_point.push_back(dsu.min_(i));
	}
	
	cout << ans << endl << ans_point.size() << endl;
	for(auto i : ans_point)
		cout << i << ' ';
	cout << endl << ans_edge.size() << endl;
	for(auto e : ans_edge)
		cout << e.i << ' ' << e.j << endl;
}