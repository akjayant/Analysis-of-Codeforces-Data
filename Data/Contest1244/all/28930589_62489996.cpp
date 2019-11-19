#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef double dl;

#ifdef DEBUG
#include "../debug.h"
#else
#define debug(...) 42
#define cerr if(0) cout
#define endl '\n'
#endif

#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()

const int inf = (int) 1.01e9;
const ll infll = (ll) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1.0);
const int mod = (int) 1e9 + 7;
const int N = int(3.1e5);
ll ar[N][3];
vector<int> g[N];
int d[N];
int n;
vector<int> col(3);

ll dfs(int u, int p, int de) {
  ll here = ar[u][col[de % 3]];
  d[u] = de;
  for(int x: g[u]) if(x != p) {
    here += dfs(x, u, de + 1);
  } 
  return here;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < n; ++j) {
      cin >> ar[j][i];
    }
  }
  for(int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v;
    --u, --v;
    g[u].EB(v);
    g[v].EB(u);
  }
  int root = -1;
  for(int i = 0; i < n; ++i) {
    if(SZ(g[i]) >= 3) {
      cout << -1 << '\n';
      return 0;
    }
    if(SZ(g[i]) == 1) {
      root = i;
    } 
  }
  assert(root != -1);
  vector<int> resc(3);
  iota(ALL(col), 0);
  ll res = infll;
  debug(res);
  do {
    // debug(col);
    ll c = dfs(root, -1, 0);
    if(c < res) {
      res = c;
      resc = col;
    }
  } while(next_permutation(ALL(col)));
  assert(res != infll);
  cout << res << '\n';
  for(int i = 0; i < n; ++i) {
    cout << 1 + resc[d[i] % 3] << ' ';
  }
  cout << '\n';
  return 0;
}
