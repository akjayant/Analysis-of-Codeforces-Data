#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=(b);a<=(c);a++)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ep(a) ((a)*10/9)
#define pb push_back
#define mp make_pair
#define inf (0x3f3f3f3f)
using namespace std;
typedef long long ll;
#ifdef DEBUG
#define do(x) x
#define dont(x) 
#else
#define do(x) 
#define dont(x) x 
#endif
namespace IO
{
	template<typename T>inline void putf(T x)
	{
		static char S[20], *end = S + 19;
		static const char lut[201] = 
			"00010203040506070809"
			"10111213141516171819"
			"20212223242526272829"
			"30313233343536373839"
			"40414243444546474849"
			"50515253545556575859"
			"60616263646566676869"
			"70717273747576777879"
			"80818283848586878889"
			"90919293949596979899";
		static const int M = 100000000;
#define output() i = (y % 100) << 1, y /= 100, *--ptr = lut[i + 1], *--ptr = lut[i]
		char *ptr = end;
		bool sign = true;
		unsigned y, i;
		if (x < 0)
			x = -x, sign = false;
		while (x >= M)
		{
			y = (unsigned) (x % M);
			x /= M;
			output(); output();
			output(); output(); 
		}
		y = (unsigned) x;
		while (y >= 100)
			output();
		if (y < 10)
			*--ptr = '0' + y;
		else
			output();
		if (!sign)
			*--ptr = '-';
		puts(ptr);
#undef output
	}
	template<typename T>inline void read(T &x)
	{
		x = 0;
		char c = getchar();
		bool sign = true;
		while (!isdigit(c))
		{
			if (c == '-')
				sign = false;
			c = getchar();
		}
		while (isdigit(c))
			x = x * 10 + (c & 0xf), c = getchar();
		if (!sign)
			x = -x;
	}
	template<typename T>inline void read(T &x, T &y) {read(x), read(y);}
	template<typename T>inline void read(T &x, T &y, T &z) {read(x), read(y), read(z);}
}
using namespace IO;
const int MAXN = 2222;
struct City
{
	int x, y, k;
	int dis(const City & bb)
	{
		return abs(x - bb.x) + abs(y - bb.y);
	}
} city[MAXN];
struct Edge
{
	int u, v;
	ll w;
	const bool operator<(const Edge & bb) const {return w < bb.w;}
} edge[MAXN * MAXN];
vector<int> G[MAXN];
int tot = 0;
namespace Set
{
	int f[MAXN];
	void init(int n)
	{
		for (int i = 1; i <= n; ++i)
			f[i] = i;
	}
	int find(int u)
	{
		if (f[u] == u) return u;
		return f[u] = find(f[u]);
	}
}
void dfs(int u, int fa, int dep)
{
	for (auto i = G[u].begin(); i != G[u].end(); ++i)
	{
		if (*i == fa) continue;
		dfs(*i, u, dep + 1);
		if (dep >= 1)
			printf("%d %d\n", u, *i);
	}
}
int main()
{
	int n;
	read(n);
	int rt = n + 1;
	for (int i = 1; i <= n; ++i)
		read(city[i].x, city[i].y);
	for (int i = 1; i <= n; ++i)
	{
		int c; read(c);
		edge[++tot] = (Edge) {rt, i, c};
	}
	for (int i = 1; i <= n; ++i)
		read(city[i].k);
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
		{
			ll c = (ll) city[i].dis(city[j]) * (ll) (city[i].k + city[j].k);
			edge[++tot] = (Edge) {i, j, c};
		}
	sort(edge + 1, edge + tot + 1);
	Set::init(n);
	ll ans = 0;
	for (int i = 1, k = n; i <= tot && k; ++i)
	{
		int u = edge[i].u, v = edge[i].v;
		if (Set::find(u) == Set::find(v))
			continue;
		G[u].push_back(v);
		G[v].push_back(u);
		ans += edge[i].w;
		Set::f[Set::f[u]] = Set::f[v];
	}
	putf(ans);
	putf(G[rt].size());
	for (auto i = G[rt].begin(); i != G[rt].end(); ++i)
		printf("%d ", *i);
	putchar('\n');
	putf(n - G[rt].size());
	dfs(rt, 0, 0);
	
	return 0;
}