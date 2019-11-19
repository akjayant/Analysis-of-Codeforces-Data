#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <cstdlib>
#include <bitset>
//#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
//char buf[(1 << 21) + 1], * p1 = buf, * p2 = buf;
//#define int long long
#define lowbit(x) (x&(-x))
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
#define pb push_back
typedef unsigned long long ull;
typedef long long ll;
typedef std::pair<int, int> pii;
#define bug puts("BUG")
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
template<class T>inline void read(T& x) {
	int sign = 1; char c = getchar(); x = 0;
	while (c > '9' || c < '0') { if (c == '-')sign = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	x *= sign;
}
using namespace std;
const int maxn = 2e3 + 10;
struct node {
	ll x, y;
}s[maxn];
vector<node> l;
struct edge {
	ll u, v, w;
	edge(ll _u = 0, ll _v = 0, ll _w = 0) :u(_u), v(_v), w(_w) {}
	bool operator <(const edge& a) {
		return w < a.w;
	}
}e[maxn * maxn];
int f[maxn], vis[maxn];
vector<int> g[maxn], r;
int find(int x) {
	return f[x] == -1 ? x : f[x] = find(f[x]);
}
ll c[maxn], k[maxn], n, ans = 0, tot = 0;
void dfs(int x) {
	vis[x] = true;
	for (int i = 0; i < g[x].size();++i) {
		int to = g[x][i];
		if (!vis[to]) {
			l.push_back(node({ x,to }));
			dfs(to);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	read(n);
	for (int i = 1; i <= n; ++i)
		read(s[i].x), read(s[i].y);
	for (int i = 1; i <= n; ++i) {
		read(c[i]);
		e[tot++] = edge(0, i, c[i]);
	}
	for (int i = 1; i <= n; ++i)
		read(k[i]);
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			ll cost = (k[i] + k[j]) * (abs(s[i].x - s[j].x) + abs(s[i].y - s[j].y));
			e[tot++] = edge(i, j, cost);
		}
	}
	memset(f, -1, sizeof f);
	memset(vis, 0, sizeof vis);
	sort(e, e + tot);
	for (int i = 0; i < tot; ++i) {
		int fu = find(e[i].u), fv = find(e[i].v);
		if (fu != fv) {
			ans += e[i].w;
			f[fu] = fv;
			g[e[i].u].push_back(e[i].v);
			g[e[i].v].push_back(e[i].u);
		}
	}
	cout << ans << "\n";
	vis[0] = true;
	for (int i = 0; i < g[0].size(); ++i) {
		r.push_back(g[0][i]);
	}
	cout << r.size() << "\n";
	for (int i = 0; i < r.size(); ++i)
		cout << r[i] << " ";
	puts("");
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	cout << l.size() << "\n";
	for (int i = 0; i < l.size(); ++i)
		cout << l[i].x << " " << l[i].y << "\n";
}