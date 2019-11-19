#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main(int argc, char **argv) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<ll> c[3];
  vector<vector<int>> adj(n);
  c[0].resize(n);
  c[1].resize(n);
  c[2].resize(n);
  for(int i=0; i<n; i++) cin >> c[0][i];
  for(int i=0; i<n; i++) cin >> c[1][i];
  for(int i=0; i<n; i++) cin >> c[2][i];
  for(int i=0; i<n-1; i++) {
    int x, y; cin >> x >> y;
    x--; y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int u = -1;
  for(int i=0; i<n; i++) {
    if(adj[i].size() >= 3) {
      cout << -1 << endl;
      return 0;
    }
    if(adj[i].size() == 1) u = i;
  }

  vector<int> p{u};
  int v = adj[u][0];
  for(int i=0; i<n-1; i++) {
    p.push_back(v);

    int t1 = adj[v][0];
    int t2 = adj[v][1];
    if(t1 != u) {
      u = v;
      v = t1;
    }
    else {
      u = v;
      v = t2;
    }
  }

  auto f = [&](int col[3]) {
    ll res = 0;
    for(int i=0; i<n; i++) {
      res += c[col[i%3]][p[i]];
    }
    return res;
  };

  ll mn = 1e18;
  int col[3] = {0, 1, 2};
  int res_col[3];
  do {
    ll t = f(col);
    if(t < mn) {
      mn = t;
      memcpy(res_col, col, sizeof(col));
    }
  } while(next_permutation(col, col+3));

  cout << mn << endl;
  vector<int> res(n);
  for(int i=0; i<n; i++) {
    res[p[i]] = res_col[i%3];
  }

  for(int i=0; i<n; i++) cout << res[i]+1 << ' ';

  return 0;
}