#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
#include <algorithm>
#define try1(edge,idx) \
std::memset(chs + 1,0,n);\
for (Q.push(1),chs[1] = 1;Q.size();)\
{\
	int cur = Q.front(); Q.pop();\
	for (int i = idx[cur];i;i = edge[i].second)\
		if (int to = edge[i].first;! chs[to])\
			Q.push(to),chs[to] = 1;\
}
const int N = 1E7;
std::pair <int,int> edgea[N + 1]; int idxa[N + 1];
std::pair <int,int> edgeb[N + 1]; int idxb[N + 1];
std::queue <int> Q; bool chs[N + 1];
void solve()
{
	int n,m; std::cin >> n >> m;
	std::memset(idxa + 1,0,n << 2),std::memset(idxb + 1,0,n << 2);
	for (int cnt = 0;m --;)
	{
		int ai,bi; std::cin >> ai >> bi;
		edgea[++ cnt] = {bi,idxa[ai]},idxa[ai] = cnt;
		edgeb[++ cnt] = {ai,idxb[bi]},idxb[bi] = cnt;
	}
	try1(edgea,idxa);
	if (int j = std::count(chs + 1,chs + n + 1,1);j < n)
	{
		std::cout << "Yes\n" << j << ' ' << n - j << '\n';
		for (int i = 1;i <= n;++ i)
			if (chs[i]) std::cout << i << ' ';
		std::cout << '\n';
		for (int i = 1;i <= n;++ i)
			if (! chs[i]) std::cout << i << ' ';
		std::cout << '\n';
		return;
	}
	try1(edgeb,idxb);
	if (int j = std::count(chs + 1,chs + n + 1,0);j)
	{
		std::cout << "Yes\n" << j << ' ' << n - j << '\n';
		for (int i = 1;i <= n;++ i)
			if (! chs[i]) std::cout << i << ' ';
		std::cout << '\n';
		for (int i = 1;i <= n;++ i)
			if (chs[i]) std::cout << i << ' ';
		std::cout << '\n';
		return;
	}
	std::cout << "No\n";
}
main()
{
	std::ios_base::sync_with_stdio(0),std::cin.tie(0);
	int t; for (std::cin >> t;t --;) solve();
}