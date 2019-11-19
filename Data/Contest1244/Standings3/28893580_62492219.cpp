#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define all(v) (v).begin(),v.end()
#define rall(v) (v).rbegin(),v.rend()
#define sz(v) (int)(v).size()
#define ch(c) (c - 'a')

typedef long long ll;
typedef pair<int, int> pi;

const int N = 112345;
int cost[3][N];
int n;
vector<int> adj[N];

int get3(int c1, int c2) {
  for (int i = 0; i < 3; ++i)
    if (i != c1 && i != c2)
      return i;
  return -1;
}

vector<int> ids;

void dfs(int i, int p) {
  ids.push_back(i);
  for (auto j : adj[i]) {
    if (j != p)
      dfs(j, i);
  }
}

int res[N];

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("test.in", "rt", stdin);
#endif
  cin >> n;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < n; ++j)
      cin >> cost[i][j];
  }
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    adj[x].push_back(y), adj[y].push_back(x);
  }
  int src = -1;
  for (int i = 0; i < n; ++i) {
    if (sz(adj[i]) > 2)
      return cout << -1, 0;
    if (sz(adj[i]) == 1) {
      src = i;
    }
  }
  dfs(src, -1);
  ll mn = 1e18;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (i != j) {
        int c1 = i, c2 = j;
        ll tot = cost[c1][ids[0]] + cost[c2][ids[1]];
        for (int k = 2; k < n; ++k) {
          int c3 = get3(c1, c2);
          tot += cost[c3][ids[k]];
          c1 = c2, c2 = c3;
        }
        if (tot < mn) {
          mn = tot;
          res[ids[0]] = i, res[ids[1]] = j;
          c1 = i, c2 = j;
          for (int k = 2; k < n; ++k) {
            int c3 = get3(c1, c2);
            c1 = c2, c2 = c3;
            res[ids[k]] = c3;
          }
        }
      }
    }
  }
  cout << mn << endl;
  for (int i = 0; i < n; ++i) {
    cout << res[i] + 1 << " ";
  }
  return 0;
}
