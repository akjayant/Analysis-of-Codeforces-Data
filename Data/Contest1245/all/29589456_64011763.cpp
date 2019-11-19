#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void print() { cout << '\n'; }
template<class T> void print(const vector<T>& c) {
  for(const T &x : c) cout << x << ' ';
}
template<class T, class... Ts> void print(const T& t, const Ts&... ts) {
  cout << t; if (sizeof...(ts)) cout << ' '; print(ts...);
}

struct pt {
  int x, y;
};
struct edge {
  ll cost;
  int x, y;
  bool operator<(const edge &e) const {
    return cost < e.cost;
  }
};
class disjointset {
  int n;
  vector<int> par;

public:
  disjointset(int n) : n(n) {
    par.resize(n);
    for (int i = 0; i < n; i++)
      par[i] = i;
  }

  int find(int v) {
    if (par[v] == v) return v;
    else return par[v] = find(par[v]);
  }

  bool merge(int x, int y) {
    int px = find(x);
    int py = find(y);

    if (px == py) return false;

    par[px] = py;
    return true;
  }
};


int main () {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<pt> pts(n);
  for(int i=0; i<n; i++) {
    cin >> pts[i].x >> pts[i].y;
  }
  vector<int> c(n), k(n);
  for(int i=0; i<n; i++) cin >> c[i];
  for(int i=0; i<n; i++) cin >> k[i];

  vector<edge> edges;
  for(int i=0; i<n; i++) {
    edges.push_back({c[i], n, i});
    for(int j=i+1; j<n; j++) {
      edges.push_back({
        1LL*(k[i]+k[j])*(abs(pts[i].x-pts[j].x)+abs(pts[i].y-pts[j].y)),
        i, j
        });
    }
  }

  sort(edges.begin(), edges.end());
  ll res = 0;
  vector<int> res_a;
  vector<pair<int, int>> res_b;

  disjointset djs(n+1);

  for(edge e : edges) {
    if(djs.find(e.x) != djs.find(e.y)) {
      if(e.x == n) res_a.push_back(e.y);
      else res_b.push_back({e.x, e.y});
      res += e.cost;
      djs.merge(e.x, e.y);
    }
  }

  cout << res << '\n';
  cout << res_a.size() << '\n';
  for(int x : res_a) cout << x+1 << ' '; cout << '\n';
  cout << res_b.size() << '\n';
  for(pair<int, int> x : res_b) cout << x.first+1 << ' ' << x.second+1 << '\n';

  return 0;
}
