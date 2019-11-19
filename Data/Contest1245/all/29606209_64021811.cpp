#include "bits/stdc++.h"

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define ll long long
#define DBG 1
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define loop(n) rep(loop, (0), (n))
#define all(c) begin(c), end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
template <typename T, typename S>istream &operator>>(istream &is, pair<T, S> &p) { is >> p.first >> p.second; return is; }
//template <typename T, typename S>ostream &operator<<(ostream &os, pair<T, S> &p) {os << p.first << " " << p.second;return os;}

template <typename T> void printvv(const vector<vector<T>> &v) {
	cerr << endl;
	rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
		if (typeid(v[i][j]).name() == typeid(INF).name() and v[i][j] == INF) {
			cerr << "INF";
		}
		else
			cerr << v[i][j];
		cerr << (j == v[i].size() - 1 ? '\n' : ' ');
	}
	cerr << endl;
}

#ifndef _DEBUG
#define printvv(...)
#endif
void YES(bool f) { cout << (f ? "YES" : "NO") << endl; }
void Yes(bool f) { cout << (f ? "Yes" : "No") << endl; }
template <class T, class U>bool chmin(T& a, U b) { if (a > b) { a = b; return true; }return false; }
template <class T, class U>bool chmax(T& a, U b) { if (a < b) { a = b; return true; }return false; }
using Weight = int;
using Flow = int;
struct Edge {
	int s, d; Weight w; Flow c; int id;
	Edge() {};
	Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w), c(w) {};
};
bool operator<(const Edge &e1, const Edge &e2) { return e1.w < e2.w; }
bool operator>(const Edge &e1, const Edge &e2) { return e2 < e1; }
inline ostream &operator<<(ostream &os, const Edge &e) { return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')'); }

using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

void addArc(Graph &g, int s, int d, Weight w = 1) {
	g[s].emplace_back(s, d, w);
}
void addEdge(Graph &g, int a, int b, Weight w = 1) {
	addArc(g, a, b, w);
	addArc(g, b, a, w);
}
struct UnionFind {
	vector<int> parent;
	int size;
	UnionFind(int n) :parent(n, -1), size(n) {}
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y)return false;
		if (size_of(x) < size_of(y))swap(x, y);
		parent[x] += parent[y]; parent[y] = x; size--;
		return true;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
	int size_of(int x) { return -parent[root(x)]; }
};

vector<Edge> kruskal(int N, vector<Edge> &edges) {
	int totalCost = 0;
	sort(all(edges));
	UnionFind dset(N);
	vector<Edge>mst;
	rep(i, 0, edges.size()) {
		Edge e = edges[i];
		if (!dset.same(e.s, e.d)) {
			mst.push_back(e);
			totalCost += e.w;
			dset.unite(e.s, e.d);
		}
	}
	return mst;
}

signed main(signed argc, char *argv[]) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(12);

	int N; cin >> N;
	vector<int>x(N), y(N); rep(i, 0, N) { cin >> x[i] >> y[i]; }
	vector<int>c(N); rep(i, 0, N) { cin >> c[i]; }
	vector<int>k(N); rep(i, 0, N) { cin >> k[i]; }

	Edges es;
	rep(i, 0, N) {
		es.eb(i, N, c[i]);
	}
	rep(i, 0, N) {
		rep(j, i + 1, N) {
			int d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
			int cost = d * (k[i] + k[j]);
			es.eb(i, j, cost);
		}
	}
	auto mst = kruskal(N + 1, es);
	int yen = 0;
	vector<int>station;
	Edges connections;
	for (auto e : mst) {
		yen += e.w;
		if (e.d == N) {
			station.eb(e.s);
		}
		else {
			connections.eb(e);
		}
	}
	cout << yen << endl;
	cout << station.size() << endl;
	rep(i, 0, station.size()) {
		cout << 1 + station[i] << (i == station.size() - 1 ? '\n' : ' ');
	}
	cout << connections.size() << endl;
	for (auto e : connections) {
		cout << e.s + 1 << " " << e.d + 1 << endl;
	}



	return 0;
}
