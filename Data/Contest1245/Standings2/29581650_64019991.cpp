#include <iostream>
#include <queue>
#include <algorithm>
#include <random>
#include <vector>
#include <assert.h>
#include <set>
#include <unordered_set>
#include <numeric>
#include <map>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <sstream>

#pragma warning(disable : 4996)
using namespace std;

#define ft first
#define sd second
#define all(__array) (__array).begin(), (__array).end()
#define nl '\n'
#define mod(__val, __mod) ((((__val) % (__mod)) + (__mod)) % (__mod))
typedef long long ll;
typedef unsigned long long ull;
typedef double dl;	

const ll LINF = numeric_limits<ll>::max();
const int INF = numeric_limits<int>::max();
const double EPS = 1e-8;
const double PI = acos(-1);
random_device rnd;

const int MOD = (int)1e9 + 7;

struct Point {
	ll x, y;
	ll k, c;
	bool isLight = false;
	bool fantom = false;
};

struct Edge {
	int a, b;
	ll cost;

	bool operator < (const Edge& a) {
		return cost < a.cost;
	}
};

ll dist(const Point& a, const Point& b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

ll cost(const Point& a, const Point& b) {
	if (a.fantom) {
		return b.c;
	}
	if (b.fantom) {
		return a.c;
	}

	return dist(a, b) * 1LL * (a.k + b.k);
}

struct DSU {
	vector<int> par;

	DSU(int n) {
		par.resize(n);
		iota(all(par), 0);
	}

	int find(int a) {
		return par[a] == a ? a : par[a] = find(par[a]);
	}

	void merge(int a, int b) {
		a = find(a);
		b = find(b);
		assert(a != b);
		if (rnd() & 1)
			swap(a, b);
		par[a] = b;
	}
};

inline void solve() {
	int n;
	cin >> n;
	vector<Point> point(n);
	for (auto& i : point) {
		cin >> i.x >> i.y;
	}
	for (auto& i : point) {
		cin >> i.c;
	}
	for (auto& i : point) {
		cin >> i.k;
	}

	point.push_back({ 0, 0, 0, 0, true, true });

	ll ans = 0;
	int v = 0;
	DSU dsu(n + 1);
	vector<Edge> edges;
	for (int i = 0; i < (int)point.size(); i++) {
		for (int j = i + 1; j < (int)point.size(); j++) {
			edges.push_back({ i, j, cost(point[i], point[j]) });
		}
	}

	sort(all(edges));
	vector<pair<int, int>> connections;
	vector<int> stations;
	for (auto& edge : edges) {
		if (dsu.find(edge.a) == dsu.find(edge.b))
			continue;

		if (point[edge.a].fantom) {
			stations.push_back(edge.b);
		}
		else if (point[edge.b].fantom) {
			stations.push_back(edge.a);
		}
		else {
			connections.push_back({ edge.a, edge.b });
		}

		ans += edge.cost;
		dsu.merge(edge.a, edge.b);
	}

	cout << ans << nl;

	cout << stations.size() << nl;
	for (auto& i : stations) {
		cout << i + 1 << " ";
	}

	cout << nl << connections.size() << nl;

	for (auto& i : connections) {
		cout << i.first + 1 << " " << i.second + 1 << nl;
	}


	

}

inline void IO() {
#ifdef _SEVA
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

int main() {
	IO();
	//int t;
	//cin >> t;
	//while (t--)
	solve();
	return 0;
}