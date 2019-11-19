#include <bits/stdc++.h>

using namespace std;
using lint = long long;

const int MAX = 2009;

struct DSU {
    int par[MAX];
    void init(int n) {
    	for (int i = 0; i <= n; ++i) par[i] = i;
    }
    int find(int u) {
    	if (u == par[u]) return u;
    	return par[u] = find(par[u]);
    }
    bool merge(int u, int v) {
    	u = find(u); v = find(v);
    	if (u == v) return false;
    	par[u] = v;
    	return true;
    }
} dsu;

vector<pair<int, int>> cities;

lint dist[MAX][MAX];
lint c[MAX], k[MAX];

vector<pair<lint, pair<int, int>>> edges;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
	int x, y;
	cin >> x >> y;
	cities.push_back(pair<int, int>(x, y));
    }
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < n; ++i) cin >> k[i];
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n; ++j) {
    	    dist[i][j] = 1LL * (k[i - 1] + k[j - 1]) * (abs(cities[i - 1].first - cities[j - 1].first) + abs(cities[i - 1].second - cities[j - 1].second));
	}
    }
    for (int i = 1; i <= n; ++i) {
    	dist[0][i] = dist[i][0] = 1LL * c[i - 1];
    }
    for (int i = 0; i <= n; ++i) {
    	for (int j = i + 1; j <= n; ++j) {
    	    edges.push_back(make_pair(1LL * dist[i][j], make_pair(i, j)));
	}
    }
    sort(edges.begin(), edges.end());
    dsu.init(n);
    lint cost = 0LL;
    vector<int> gen;
    vector<pair<int, int>> con;
    for (int i = 0; i < edges.size(); ++i) {
    	if (dsu.merge(edges[i].second.first, edges[i].second.second)) {
    	    cost += 1LL * edges[i].first;
    	    if (edges[i].second.first == 0) {
    	    	gen.push_back(edges[i].second.second);
	    }
	    else if (edges[i].second.second == 0) {
	    	gen.push_back(edges[i].second.first);
	    }
	    else {
		con.push_back(edges[i].second);
	    }
	}
    }
    sort(gen.begin(), gen.end());
    sort(con.begin(), con.end());
    cout << cost << '\n';
    cout << gen.size() << '\n';
    for (auto g : gen) {
    	cout << g << ' ';
    }
    cout << '\n';
    cout << con.size() << '\n';
    for (auto c : con) {
    	cout << c.first << ' ' << c.second << '\n';
    }
}
