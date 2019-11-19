#include<bits/stdc++.h>


using namespace std;

const int N = 1e6 + 2, MOD = 1e9 + 7;

#define ss second
#define ff first
//#define int long long
#define ll long long

using vi = vector <int>;
using vp = vector <pair <int, int>>;

using pii = pair<int, int>;

#define x first
#define y second

#define pb push_back
#define mp make_pair

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

template<typename T = int>
inline T read() {
	T res = 0, sig = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') {
		c = getchar();
	}
	if (c == '-') {
		sig = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * sig;
}

void fastio() {
	ios::sync_with_stdio(false);
	cin.tie(0);
}

struct Edge {
	int v, u;
	ll w;

	Edge() {}

	Edge(int v, int u, ll w) : v(v), u(u), w(w) {}

	bool operator < (const Edge &r) {
		return w < r.w;
	}
};

struct DSU {
	vector<int> p, sz;

	void init(int n) {
		p.resize(n);
		iota(all(p), 0);
		sz.assign(n, 1);
	}
	int get(int i) {
		return i == p[i] ? i : p[i] = get(p[i]);
	}

	bool unite(int i, int j) {
		i = get(i);
		j = get(j);
		if (i != j) {
			if (sz[i] > sz[j]) {
				swap(i, j);
			}
			p[i] = j;
			sz[j] += sz[i];
			return true;
		}
		return false;
	}

	DSU() {}
};

int main() {
	fastio();
	int n;
	cin >> n;
	vector<ll> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	vector<ll> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	vector<ll> k(n);
	for (int i = 0; i < n; i++) {
		cin >> k[i];
	}
	vector<Edge> edges;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			edges.emplace_back(i, j, (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]));
		}
		edges.emplace_back(i, n, c[i]);
	}
	sort(all(edges));
	DSU dsu;
	dsu.init(n + 1);
	vector<pair<int, int>> who;
	ll ans = 0;
	for (auto [i, j, w] : edges) {
		if (dsu.unite(i, j)) {
			who.emplace_back(i, j);
			ans += w;
		}
	}
	vector<int> ans0;
	vector<pair<int, int>> ans1;
	for (auto [i, j] : who) {
		if (j == n) {
			ans0.emplace_back(i + 1);
		} else {
			ans1.emplace_back(i + 1, j + 1);
		}
	}
	cout << ans << '\n' << sz(ans0) << '\n';
	for (auto i : ans0) {
		cout << i << " ";
	}
	cout << '\n' << sz(ans1) << '\n';
	for (auto [i, j] : ans1) {
		cout << i << " " << j << '\n';
	}
	cout << '\n';
	return 0;
}
