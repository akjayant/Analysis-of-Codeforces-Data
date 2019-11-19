#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define debug(n1) cout << n1 << endl;
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

using namespace std;

const string __sep = "\n";
vector<int> p;
vector<ll> min_v;

int dsu_get (int v) {
  return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}


ll min_x(int v) {
  if (v == p[v]) return min_v[v];
  else {
    min_v[v] = min_x(p[v]);
    return min_v[v];
  }
}

void dsu_unite (int a, int b) {
  a = dsu_get (a);
  b = dsu_get (b);
  if (min_x(b) > min_x(a)) swap (a, b);
  if (a != b) {
    p[a] = b;
    min_v[a] = min_v[b];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<ll, pair<int, int>>> g;

  ll x[n];
  ll y[n];
  ll c[n];
  ll k[n];
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> k[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      g.push_back(make_pair((k[i] + k[j]) * 1ll * (abs(x[i] - x[j]) + abs(y[i] - y[j])), make_pair(i, j)));
    }
  }
  ll cost = 0ll;
  vector <pair<int,int>> res;
  sort (g.begin(), g.end());

  for (int i = 0; i < n; ++i) {
    p.push_back (i);
    min_v.push_back(c[i]);
  }
  for (int i=0; i<g.size(); ++i) {
    int a = g[i].second.first,  b = g[i].second.second;
    ll l = g[i].first;
    if (dsu_get(a) != dsu_get(b)) {
      if (min_x(a) > min_x(b)) swap(a, b);
      if (min_v[b] > l) {
        cost += l;
        res.push_back (g[i].second);
        //cout << " adding the edge from " << a << " "<< b << endl;
        dsu_unite (a, b);
      } else {
        //cout << " not adding the edge from " << a << " "<< b << endl;
      }
    }
  }
  //cout << " cur_cost " << cost << endl;

  set<int> electr;
  for (int i = 0; i < n; ++i) {
    int minimal = dsu_get(i);
    //cout << " representative " << minimal << endl;
    if (electr.find(minimal) == electr.end()) {
      cost += min_x(minimal);
      electr.insert(dsu_get(i));
    }
  }
  cout << cost << "\n";
  cout << electr.size() << "\n";
  for (auto vv : electr) cout << (1 +vv) << " ";
  cout << "\n";
  cout << res.size() << "\n";
  for (auto it : res) {
    cout << (1 + it.first) << " " << (1+it.second) << "\n";
  }
  cout << endl;


  return 0;
}
