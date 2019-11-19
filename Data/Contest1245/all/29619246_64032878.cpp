#include <vector>
#include <numeric>
#include <utility>
#include <iostream>
#include <algorithm>
using LL = long long;
const int N = 2E3,M = N * N;
int x[N + 1],y[N + 1],k[N + 1];
int m,u[M],v[M]; LL w[M]; int ID[M];
inline void link(int u,int v,LL w)
{
	::u[m] = u,::v[m] = v,::w[m] = w;
	ID[m] = m,++ m;
}
int fa[N + 2];
int find(int x) { return x != fa[x] ? fa[x] = find(fa[x]) : x; }
std::vector <int> v_;
std::vector <std::pair <int,int>> e;
main()
{
	std::ios_base::sync_with_stdio(0),std::cin.tie(0);
	int n; std::cin >> n;
	for (int i = 1;i <= n;++ i) std::cin >> x[i] >> y[i];
	int V = n + 1;
	for (int i = 1;i <= n;++ i) { int ci; std::cin >> ci,link(V,i,ci); }
	for (int i = 1;i <= n;++ i) std::cin >> k[i];
	for (int i = 1;i <= n;++ i)
		for (int j = 1;j < i;++ j)
			link(j,i,static_cast <LL>(k[i] + k[j]) * (std::abs(x[i] - x[j]) + std::abs(y[i] - y[j])));
	std::sort(ID,ID + m,[](int LHS,int RHS){ return w[LHS] < w[RHS]; });
	std::iota(fa + 1,fa + n + 2,1); LL ans = 0;
	for (int i = 0;i < m;++ i)
	{
		int u = ::u[ID[i]],v = ::v[ID[i]];
		int Fu = find(u),Fv = find(v);
		if (Fu != Fv)
		{
			fa[Fu] = Fv,ans += w[ID[i]];
			if (u == V) v_.push_back(v);
			else e.emplace_back(u,v);
		}
	}
	std::cout << ans << '\n' << v_.size() << '\n';
	for (int i : v_) std::cout << i << ' '; std::cout << '\n';
	std::cout << e.size() << '\n';
	for (auto i : e) std::cout << i.first << ' ' << i.second << '\n'; std::cout << '\n';
}