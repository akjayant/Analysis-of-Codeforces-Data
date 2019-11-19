#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int SIZE = (int)1e5+5;

long long dp[SIZE][3][3], cost[SIZE][3], ans = 0x3f3f3f3f3f3f3f3f;
int n, choice[SIZE], father[SIZE];
std::vector<int> edge[SIZE];

void dfs(const int x, const int f)
{
  father[x] = f;
  if (f == 0) {
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        if (i != j)
          dp[x][i][j] = cost[x][i];
  }
  else
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        if (i != j)
          dp[x][i][j] = std::min(dp[x][i][j], dp[f][j][i ^ j ^ 3] + cost[x][i]);
  bool mark = false;
  for (auto y: edge[x]) {
    if (y == f)
      continue;
    mark = true;
    dfs(y, x);
  }
  if (!mark) {
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        if (i != j && dp[x][i][j] < ans) {
          ans = std::min(ans, dp[x][i][j]);
          choice[x] = i;
          if (f != 0)
            choice[f] = j;
          if (father[f] != 0)
            choice[father[f]] = i ^ j ^ 3;
        }
  } else {
    if (father[f] != 0)
      choice[father[f]] = choice[f] ^ choice[x] ^ 3;
  }
  return;
}

int main(void)
{
  memset(dp, 0x3f, sizeof dp);
  scanf("%d", &n);
  for (int j = 0; j < 3; ++j)
    for (int i = 1; i <= n; ++i)
      scanf("%I64d", &cost[i][j]);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i)
    if (edge[i].size() > 2) {
      printf("-1\n");
      return 0;
    }
  for (int i = 1; i <= n; ++i)
    if (edge[i].size() == 1) {
      dfs(i, 0);
      printf("%I64d\n", ans);
      for (int j = 1; j <= n; ++j)
        printf("%d%c", choice[j] + 1, " \n"[j == n]);
      break;
    }
  return 0;
}
