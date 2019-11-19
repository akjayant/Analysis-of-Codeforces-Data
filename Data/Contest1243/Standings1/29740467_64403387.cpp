#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <assert.h>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <random>
#include <cmath>

//#define ll long long
#define ld long double
//#define mp make_pair
#define pb push_back
#define eb emplace_back
#define int long long
using namespace std;

const int INF = 2e9;
const int MOD = 1e9 + 7;
const int MB = 30;
vector<vector<int>> g;

bool cmp(const int& a, const int& b) {
	return g[a].size() < g[b].size();
}

struct DSU {
	vector<int> p, s;
	DSU(int n) {
		p.resize(n);
		s.resize(n);
		for (int i = 0; i < n; i++) {
			p[i] = i;
			s[i] = 1;
		}
	}

	int find(int x) {
		if (x == p[x]) return x;
		return p[x] = find(p[x]);
	}

	void unite(int a, int b) {
		a = find(a);
		b = find(b);

		if (a == b) return;
		if (s[a] < s[b]) swap(a, b);

		p[b] = a;
		s[a] += s[b];
	}

	bool equal(int a, int b) {
		return find(a) == find(b);
	}

	int getSize(int x) {
		return s[find(x)];
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
	
	sort(a.begin(), a.end(), cmp);
	set<int> st;
	DSU dsu(n);
	for (int v : a) {
		map<int, int> mp;
		for (int u : g[v]) {
			if (st.count(dsu.find(u))) {
				mp[dsu.find(u)]++;
			}
		}

		vector<int> del;
		for (int u : st) {
			if (mp[u] < dsu.getSize(u)) {
				dsu.unite(v, u);
				del.pb(u);
			}
		}

		for (int u : del) {
			st.erase(u);
		}

		st.insert(dsu.find(v));
	}

	cout << (st.size() - 1);
}

signed main() {
	/*
	freopen("cyclic.in", "r", stdin);
	freopen("cyclic.out", "w", stdout);
	*/
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout.precision(12);
	solve();
}
