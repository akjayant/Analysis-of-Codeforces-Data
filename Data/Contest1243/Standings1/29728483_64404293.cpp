#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define emp emplace
typedef long long ll;
typedef pair<int, int> ii;

const int N = 1123456;

int n, m;
set<int> nvis, g[N];
int who[N], uf[N];
vector<ii> edg;

int find(int x) {
	if (uf[x] < 0) return x;
	else return uf[x] = find(uf[x]);
}

void uni(int x, int y) {
	int xx = find(x);
	int yy = find(y);

	if (uf[xx] > uf[yy]) swap(xx, yy);

	uf[xx] += uf[yy];
	uf[yy] = xx;
}

void dfs(int u, int c) {
	who[u] = c;
	nvis.erase(u);

	for (int v : g[u]) {
		while (true) {
			auto it = nvis.upper_bound(v);

			if (it != nvis.end() and g[u].count(*it) == 0) {
				dfs(*it, c);
			} else break;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		g[a].emp(b); g[b].emp(a);
		edg.eb(a, b);
	}

	for (int i = 1; i <= n; i++) {
		g[i].emp(0);
		nvis.emp(i);
	}

	int comp = 0;
	for (int i = 1; i <= n; i++) {
		if (nvis.count(i)) {
			dfs(i, comp);
			comp++;
		}
	}

	memset(uf, -1, sizeof uf);

	int ans = 0;
	for (auto e : edg) {
		if (who[e.fi] != who[e.se] and find(who[e.fi]) != find(who[e.se])) {
			ans++;
			uni(who[e.fi], who[e.se]);
		}
	}

	cout << ans << endl;

	return 0;
}
