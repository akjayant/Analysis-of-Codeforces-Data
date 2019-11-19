#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define int long long
#define sz(a) (int)(a.size())
#define pb emplace_back

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

const int MAXN = 1e5 + 228;

int power[MAXN];
int c[3][MAXN];
vector<int> graph[MAXN];
int paint[MAXN];

int dfs(int v, int p, vector<int>& colors, int cur_color, bool out) {
  if (out) {
    paint[v] = colors[cur_color];
  }
  int ans = c[colors[cur_color]][v];
  for (auto u : graph[v]) {
    if (u != p) {
      ans += dfs(u, v, colors, (cur_color + 1) % 3, out);
    }
  }
  return ans;
}

signed main() {
  fast_io();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c[0][i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[1][i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[2][i];
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    cin >> v >> u;
    v--;
    u--;
    graph[v].pb(u);
    graph[u].pb(v);
    power[v]++;
    power[u]++;
  }
  int start = 0;
  for (int i = 0; i < n; i++) {
    if (power[i] > 2) {
      cout << -1;
      return 0;
    } else if (power[i] == 1) {
        start = i;
    }
  }
  int ans = 1e18;
  vector<int> colors = {0, 1, 2};
  int ind = 0;
  for (int i = 0; i < 6; i++) {
    int cur_ans = dfs(start, start, colors, 0, 0);
    if (cur_ans < ans) {
      ans = cur_ans;
      ind = i;
    }
    next_permutation(colors.begin(), colors.end());
  }
  cout << ans << '\n';
  for (int i = 0; i < ind; i++) {
    next_permutation(colors.begin(), colors.end());
  }
  dfs(start, start, colors, 0, 1);
  for (int i = 0; i < n; i++) {
    cout << paint[i] + 1 << ' ';
  }
  return 0;
}