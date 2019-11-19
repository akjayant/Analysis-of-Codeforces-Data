#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

using ll = long long;
using ii = pair<ll, int>;

int const maxn = 2020;

struct Point {
	int x, y;
	ll c, k;

	ll dist(Point const& rhs) const {
		return (k + rhs.k)*(abs(x-rhs.x) + abs(y-rhs.y));
	}
};

struct Edge {
	int x, y;
	ll cost;

	bool operator<(Edge const& rhs) const {
		return cost < rhs.cost;
	}
};

struct DSU {
	vector<int> pai, w;
	vector<pair<ll, int>> c;
	ll ans;

	DSU(int n) : pai(n+1), w(n+1, 1), c(n+1), ans(0) {
		iota(pai.begin(), pai.end(), 0);
	}

	int find(int x) {
		if (pai[x] == x) return x;
		return pai[x] = find(pai[x]);
	}

	bool con(int x, int y) {
		return find(x) == find(y);
	}

	ll cost(int x) {
		return c[find(x)].ff;
	}

	void join(int x, int y, ll cost) {
		x = find(x), y = find(y);

		if (w[x] < w[y]) swap(x, y);
		pai[y] = x;
		w[x] += w[y];

		ans += cost;
		ans -= max(c[x], c[y]).ff;
		c[x] = min(c[x], c[y]);
	}
};

Point v[maxn];

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> v[i].x >> v[i].y;
	for (int i = 0; i < n; i++) cin >> v[i].c;
	for (int i = 0; i < n; i++) cin >> v[i].k;

	vector<Edge> ed;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			ed.push_back(Edge{i, j, v[i].dist(v[j])});
		}
	}

	sort(ed.begin(), ed.end());

	DSU dsu(n);

	for (int i = 0; i < n; i++) dsu.c[i] = ii{v[i].c, i}, dsu.ans += v[i].c;

	vector<Edge> res;
	for (auto e : ed) {
		if (!dsu.con(e.x, e.y)) {
			if (e.cost < max(dsu.cost(e.x), dsu.cost(e.y))) {
				dsu.join(e.x, e.y, e.cost);
				res.push_back(Edge{e.x, e.y, 0});
			}
		}
	}

	cout << dsu.ans << "\n";
	cout << n-(int)res.size() << "\n";

	vector<int> mrk(n);
	for (int i = 0; i < n; i++) {
		mrk[dsu.c[dsu.find(i)].ss] = 1;
	}

	for (int i = 0; i < n; i++) {
		if (mrk[i]) cout << i+1 << " ";
	}
	cout << "\n";

	cout << res.size() << "\n";
	for (auto p : res) cout << p.x+1 <<" " << p.y+1 << "\n";
}