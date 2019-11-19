#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
vector<int> g[N];
int degree[N];
int color[N], color_print[N];
int cost[N][3];
vector<int> pat = {0, 1, 2};
long long ans = 4e18;

int dfs(int u, int p, int idx) {
  color[u] = pat[idx];
  for (int v : g[u])
    if (v != p)
      dfs(v, u, (idx + 1) % 3);
}

long long solve(int root) {
  do {
    dfs(root, -1, 0);
    long long cur = 0;
    for (int i = 0; i < n; ++i)
      cur += cost[i][color[i]];
    if (cur < ans) {
      ans = cur;
      for (int i = 0; i < n; ++i)
        color_print[i] = color[i];
    }
  } while (next_permutation(pat.begin(), pat.end()));
}

int main() {
  scanf("%d", &n);
  for (int j = 0; j < 3; ++j)
    for (int i = 0; i < n; ++i)
      scanf("%d", &cost[i][j]);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    ++degree[u], ++degree[v];
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; ++i)
    if (degree[i] >= 3)
      return 0 * puts("-1");
  for (int i = 0; i < n; ++i) {
    if (degree[i] == 1) {
      solve(i);
      printf("%lld\n", ans);
      for (int i = 0; i < n; ++i) {
        if (i > 0)
          printf(" ");
        printf("%d", color_print[i] + 1);
      }
      puts("");
      break;
    }
  }
  return 0;
}