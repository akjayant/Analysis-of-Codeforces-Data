#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  ll n;
  cin >> n;
  vector<vector<ll> > c(3, vector<ll>(n));
  for (ll i = 0; i < n; i++) cin >> c[0][i];
  for (ll i = 0; i < n; i++) cin >> c[1][i];
  for (ll i = 0; i < n; i++) cin >> c[2][i];
  vector<vector<ll> > adj(n);
  vector<ll> deg(n);
  for (ll i = 0; i < n - 1; i++) {
    ll u, v;
    cin >> u >> v;
    --u; --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    ++deg[u];
    ++deg[v];
  }
  ll root = -1;
  bool possible = true;
  for (ll i = 0; i < n; i++) {
    if (deg[i] > 2) possible = false;
    else if (deg[i] == 1) root = i;
  }
  if (!possible) {
    cout << -1 << endl;
    return 0;
  }
  vector<ll> a;
  function<void(ll, ll)> dfs = [&](ll u, ll p) {
    a.emplace_back(u);
    for (auto v: adj[u]) {
      if (v == p) continue;
      dfs(v, u);
    }
  };
  dfs(root, -1);
  ll min_cost = 1e18;
  vector<ll> min_p;
  vector<ll> p({0, 1, 2});
  do {
    ll cur_cost = 0;
    for (int i = 0; i < n; i++) {
      cur_cost += c[p[i % 3]][a[i]];
    }
    if (cur_cost < min_cost) {
      min_cost = cur_cost;
      min_p = p;
    }
  } while (next_permutation(p.begin(), p.end()));
  cout << min_cost << endl;
  vector<ll> ans(n);
  for (ll i = 0; i < n; i++) {
    ans[a[i]] = min_p[i % 3] + 1;
  }
  for (auto x: ans) cout << x << " ";
  cout << endl;
  return 0;
}

