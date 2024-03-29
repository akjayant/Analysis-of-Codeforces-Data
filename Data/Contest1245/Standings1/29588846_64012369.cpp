#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
using namespace std;
long long MOD = 1e9 + 7;
typedef long long ll;
typedef pair<ll, ll> pll;

struct UnionFind {
	vector< int > data;

	UnionFind(int sz) {
		data.assign(sz, -1);
	}

	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return (false);
		if (data[x] > data[y]) swap(x, y);
		data[x] += data[y];
		data[y] = x;
		return (true);
	}

	int find(int k) {
		if (data[k] < 0) return (k);
		return (data[k] = find(data[k]));
	}

	int size(int k) {
		return (-data[find(k)]);
	}
};

template< typename T >
struct edge {
	int src, to;
	T cost;

	edge(int to, T cost) : src(-1), to(to), cost(cost) {}

	edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

	edge& operator=(const int& x) {
		to = x;
		return *this;
	}

	operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

ll N;
vector<pll> cities;
vector<ll> C, K;
vector<ll> plants;
vector<pll> conns;

template< typename T >
T kruskal(Edges< T >& edges, int V) {
	sort(begin(edges), end(edges), [](const edge< T >& a, const edge< T >& b) {
		return (a.cost < b.cost);
	});
	UnionFind tree(V);
	T ret = 0;
	for (auto& e : edges) {
		if (tree.unite(e.src, e.to)) {
			ret += e.cost;
			if (e.src == 0) {
				plants.push_back(e.to);
			}
			else {
				conns.push_back(pll(e.src, e.to));
			}
		}
	}
	return (ret);
}

int main() {
	cin >> N;
	cities.resize(N + 1);
	for (ll n = 1; n <= N; n++) {
		cin >> cities[n].first >> cities[n].second;
	}
	C.resize(N + 1);
	K.resize(N + 1);
	for (ll n = 1; n <= N; n++)cin >> C[n];
	for (ll n = 1; n <= N; n++)cin >> K[n];
	Edges<ll> G;
	for (int n = 1; n <= N; n++) {
		G.push_back({ 0,n,C[n] });
	}
	for (int s = 1; s <= N; s++) {
		for (int t = s+1; t <= N; t++) {
			ll dis = abs(cities[s].first - cities[t].first) + abs(cities[s].second - cities[t].second);
			G.push_back({ s,t,dis * (K[s] + K[t]) });
		}
	}
	cout << kruskal(G, N + 1) << endl;
	cout << plants.size() << endl;
	for (ll p : plants)cout << p << " ";
	cout << endl;
	cout << conns.size() << endl;
	for (pll c : conns) {
		cout << c.first << " " << c.second << endl;
	}
	return 0;
}