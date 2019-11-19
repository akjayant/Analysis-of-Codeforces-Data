#include <bits/stdc++.h>
#define mp make_pair
#define debug(x) cout << #x << ": " << x << endl
#define pb push_back
typedef long long LL;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const LL mod = 1e9 + 7;
using namespace std;
struct node {
	LL x, y;
}s[maxn];
vector<node> l;
struct edge {
	LL u, v, w;
	edge(LL _u=0,LL _v=0,LL _w=0):u(_u),v(_v),w(_w){}
	bool operator <(const edge& a) {
		return w < a.w;
	}
}e[2010 * 2010];
int f[maxn],vis[maxn];
vector<int> g[maxn], r;
int find(int x) {
	return f[x] == -1 ? x : f[x] = find(f[x]);
}
LL c[maxn], k[maxn], n, ans = 0, tot = 0;
void dfs(int x) {
	vis[x] = true;
	for (int i = 0; i < g[x].size(); ++i) {
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
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> s[i].x >> s[i].y;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		e[tot++] = edge(0, i, c[i]);
	}
	for (int i = 1; i <= n; ++i)
		cin >> k[i];
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			LL cost = (k[i] + k[j]) * (labs(s[i].x - s[j].x) + labs(s[i].y - s[j].y));
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
	cout << ans << endl;
	vis[0] = true;
	for (int i = 0; i < g[0].size(); ++i) {
		r.push_back(g[0][i]);
	}
	cout << r.size() << endl;
	for (int i = 0; i < r.size(); ++i)
		cout << r[i] << " ";
	cout << "\n";
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	cout << l.size() << "\n";
	for (int i = 0; i < l.size(); ++i)
		cout << l[i].x << " " << l[i].y << "\n";
}