#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vii = vector<ii>;
const ll MOD = 998244353;
const ll INF = 1e18+9;
const int MAXN = 1000006;


int n, c[MAXN][3], coloring[MAXN];
int col[] = {0, 1, 2};
bool feasible = true; int st = -1;
vi gr[MAXN];

ll dfs(int u, int id = 0, int p = -1) {
  ll s = c[u][col[id]];
  for (int v : gr[u]) {
    if (v == p) continue;
    s += dfs(v, (id+1)%3, u);
  }
  return s;
}

ll dfs2(int u, int id = 0, int p = -1) {
  ll s = c[u][col[id]];
  coloring[u] = col[id];
  for (int v : gr[u]) {
    if (v == p) continue;
    s += dfs2(v, (id+1)%3, u);
  }
  return s;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c[i][0];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i][1];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i][2];
  }
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v; u--, v--;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    if (gr[i].size() > 2) feasible = false;
    else if (gr[i].size() == 1) st = i;
  }
  ll ans = INF;
  do {
    if (dfs(st) < ans) {
      ans = dfs2(st);
    }
  } while (next_permutation(col, col+3));
  if (feasible) {
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
      cout << coloring[i]+1 << " ";
    }
    cout << endl;
  } else
    cout << -1 << endl;
}
