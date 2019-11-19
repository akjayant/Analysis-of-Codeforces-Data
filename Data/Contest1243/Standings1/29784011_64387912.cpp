#include <bits/stdc++.h>
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define out(s) freopen(s, "w", stdout);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 1e5 + 5;
int n, m;
vector<int> g[N];
struct DSU {
	int p[N], sz[N];
	void init(int n) {
		fw (i, 0, n) p[i] = i, sz[i] = 1;
	}
	int getp(int u) {
		return u == p[u] ? u : p[u] = getp(p[u]);
	}
	void joint(int u, int v) {
		u = getp(u), v = getp(v);
		if (u == v) return;
		if (sz[u] < sz[v]) swap(u, v);
		sz[u] += sz[v];
		p[v] = u;
	}
} dsu;
bool have[N];
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	fw (i, 0, m) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].pb(v), g[v].pb(u);
	}
	//DSU 2 vertexes if their edge doesn't exist.
	int half = (n + 1) / 2 - 1;
	int moreHalf = -1;
	dsu.init(n);
	fw (i, 0, n) {
		if (g[i].size() < half) {
			//Real graph it's connected to more than half. All vertexes with more than half are connected
			//to each other.
			if (moreHalf == -1) moreHalf = i;
			dsu.joint(i, moreHalf);
		} else {
			//Max 2m / n vertexes like this.
			fa (j, g[i]) have[j] = 1;
			fw (j, 0, n) if (!have[j]) dsu.joint(i, j);
			fa (j, g[i]) have[j] = 0;
		}
	}
	int cnt = 0;
	fw (i, 0, n) if (dsu.getp(i) == i) cnt++;
	cout << cnt - 1;
	return 0;
}