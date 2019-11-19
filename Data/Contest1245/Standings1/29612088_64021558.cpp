/*
  This C++ Source Is
  Writen By syksykCCC
  (After July, 2019)
*/
#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i < y; i++)
#define REP(i, x, y) for(int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i > y; i--)
#define PER(i, x, y) for(int i = x; i >= y; i--)
#define LLL __int128
#define int128 __int128
#define DEBUG(x) cerr << #x << " : " << x << endl
using namespace std;
typedef unsigned int uint;
typedef long long int64;
typedef long long LL;
typedef unsigned long long uint64;
typedef long long ULL;
typedef long double LLF;
template<typename T> inline void read(T &val)
{
	val = 0; char c = getchar(); int f = 1;
	while(!isdigit(c))
	{
		if(c == '-') f = -1;
		c = getchar();
	}
	while(isdigit(c))
	{
		val = (val << 3) + (val << 1) + (c ^ 48);
		c = getchar();
	}
	val *= f;
}
template<typename T> void write_(T val)
{
	if(!val) return;
	write_(val / 10);
	putchar(val % 10 + 48);
}
template<typename T> inline void write(T val)
{
	if(val == 0) putchar(48);
	else if(val < 0)
	{
		putchar('-');
		write_(-val);
	}
	else write_(val);
}

const int N = 2005;
LL n, c[N], k[N], f[N], x[N], y[N], cnt; 
vector<pair<LL, LL> > edges;
vector<LL> stations;
struct edge
{
	int u, v;
	LL w;
	bool operator < (const edge &oth) const
	{
		return w < oth.w;
	}
} e[N * N];
LL find(LL u)
{
	if(f[u] == u) return u;
	return f[u] = find(f[u]); 
} 

int main()
{
#ifdef LOCAL
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> n;
	REP(i, 1, n) cin >> x[i] >> y[i];
	REP(i, 1, n) cin >> c[i];
	REP(i, 1, n) cin >> k[i];
	REP(i, 1, n) e[++cnt] = (edge){0, i, c[i]};
	REP(i, 1, n) REP(j, i + 1, n)
		e[++cnt] = (edge){i, j, (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]))};
	sort(e + 1, e + cnt + 1);
	REP(i, 0, n) f[i] = i;
	LL ans = 0, st = 0, cn = 0;
	REP(i, 1, cnt)
	{
		int fau = find(e[i].u), fav = find(e[i].v);
		if(fau == fav) continue;
		if(e[i].u == 0)
		{
			st++;
			stations.push_back(e[i].v);
		}
		else
		{
			cn++;
			edges.push_back(make_pair(e[i].u, e[i].v));
		}
		f[fau] = fav;
		ans += e[i].w;
	}
	cout << ans << endl;
	cout << st << endl;
	rep(i, 0, stations.size()) cout << stations[i] << ' ';
	cout << '\n' << cn << endl;
	rep(i, 0, edges.size()) cout << edges[i].first << ' ' << edges[i].second << endl;
	return 0;
}
