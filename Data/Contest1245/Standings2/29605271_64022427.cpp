#include <bits/stdc++.h>

#define sz(a) int(a.size())
using namespace std;

typedef long long ll;

struct DSU {
	vector <int> P, R;

	DSU (int n) {
		R = vector <int> (n, 1);
		P.resize(n);
		iota(begin(P), end(P), 0);
	}

	int find (int x) {
		return x == P[x] ? x : P[x] = find(P[x]);
	}

	bool unionS (int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		if (R[y] > R[x]) swap(x, y);
		P[y] = x;
		R[x] += R[y];
		return true;
	}
};


int main() {
	int n;
	cin >> n;
	vector <int> x (n), y(n);
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	vector <int> k (n);
	DSU dsu (n+1);

	vector <tuple<ll,int,int>> edges;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		edges.emplace_back(c, i, n);
	}
	for (int &t : k) cin >> t;

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int dx = abs(x[i]-x[j]), dy = abs(y[i]-y[j]);
			edges.emplace_back(1LL*(k[i]+k[j])*(dx+dy), i, j);
		}
	}

	sort(begin(edges), end(edges));
	ll ans = 0;
	vector <int> d;
	vector <pair<int,int>> e;
	for (auto [w, u, v] : edges) {
		if (dsu.unionS(u, v)) {
			if (v == n) d.push_back(u+1);
			else e.emplace_back(u+1, v+1);
			ans += w;
		}
	}
	cout << ans << endl;
	cout << sz(d) << endl;
	for (int t : d) cout << t << " ";
	cout << endl;
	cout << sz(e) << endl;
	for (auto[u, v] : e) cout << u << " " << v << endl;

}
