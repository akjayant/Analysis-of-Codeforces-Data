#include <bits/stdc++.h>
using namespace std;

using edgeT = long long;
struct edge
{
    int i, j;
    edgeT d;
    bool operator < (const edge &o) const {return d < o.d;}
};

struct disjointSetUnion
{
    int sz;
    vector <int> par;

    disjointSetUnion(int s)
    {
        sz = s;
        par.resize(sz);
        for (int i = 0; i < sz; i++) par[i] = i;
    }

    int findRoot(int i)
    {
        return par[i] == i ? i : (par[i] = findRoot(par[i]));
    }

    void unionElements(int i, int j)
    {
        par[findRoot(i)] = findRoot(j);
    }

    bool sameComponent(int i, int j) {return findRoot(i) == findRoot(j);}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
      cin >> points[i].first >> points[i].second;
    }

    vector<int> c(n), k(n);
    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> k[i];
    }

    auto dist = [](auto p1, auto p2) {
		  auto dx = abs(p1.first - p2.first);
		  auto dy = abs(p1.second - p2.second);
		  return dx + dy;
		};

    vector<edge> edges;
    for (int i = 0; i < n; i++) {
      edges.push_back({i, n, c[i]});
      for (int j = i + 1; j < n; j++) {
	auto d = dist(points[i], points[j]);
	auto w = (long long) d * (long long)(k[i] + k[j]);
	edges.push_back({i, j, w});
      }
    }
    sort(edges.begin(), edges.end());
    
    disjointSetUnion dsu(n + 1);
    edgeT cost = 0;
    vector<int> stations;
    vector<pair<int, int>> connections;
    for (const edge &e: edges) if (!dsu.sameComponent(e.i, e.j))
    {
      if (e.j == n) {
	stations.push_back(e.i + 1);
      }
      else {
	connections.push_back({e.i + 1, e.j + 1});
      }
      dsu.unionElements(e.i, e.j);
      cost += e.d;
    }

    cout << cost << '\n';
    cout << stations.size() << '\n';
    for (auto elem: stations) cout << elem << " ";
    cout << '\n';
    cout << connections.size() << '\n';
    for (auto [ind1, ind2]: connections) {
      cout << ind1 << " " << ind2 << '\n';
    }
}
