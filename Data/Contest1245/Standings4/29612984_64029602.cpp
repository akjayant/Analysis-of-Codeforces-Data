#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

typedef long long i64;

i64 MOD = (i64)(1e9 + 7);

#define MAXN (int)1e5
#define x first
#define y second

std::vector<std::vector<std::pair<int, i64>>> graph;

int main(int argc, char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> coord(n);
  std::vector<i64> c(n, 0), k(n, 0);

  for (int i = 0; i < n; i++)
    std::cin >> coord[i].x >> coord[i].y;
  for (int i = 0; i < n; i++)
    std::cin >> c[i];
  for (int i = 0; i < n; i++)
    std::cin >> k[i];
  graph.resize(n + 1);
  for (int i = 1; i <= n; i++)
    graph[0].push_back({i, c[i - 1]});
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      graph[i].push_back({j, ((i64)std::abs(coord[i - 1].x - coord[j - 1].x) +
                              (i64)std::abs(coord[i - 1].y - coord[j - 1].y)) *
                                 (i64)(k[i - 1] + k[j - 1])});
  n++;

  std::vector<std::pair<i64, std::pair<int, int>>> g; // вес - вершина 1 - вершина 2
  for (int i = 0; i < n; i++)
    for (auto p : graph[i])
      g.push_back({p.second, {i, p.first}});
  int m = g.size();
  i64 cost = 0;
  std::vector<std::pair<int, int>> res;

  std::sort(g.begin(), g.end());
  std::vector<int> tree_id(n);
  for (int i = 0; i < n; ++i)
    tree_id[i] = i;
  for (int i = 0; i < m; ++i) {
    i64 a = g[i].second.first, b = g[i].second.second, l = g[i].first;
    if (tree_id[a] != tree_id[b]) {
      cost += l;
      res.push_back(std::make_pair(a, b));
      int old_id = tree_id[b], new_id = tree_id[a];
      for (int j = 0; j < n; ++j)
        if (tree_id[j] == old_id)
          tree_id[j] = new_id;
    }
  }
  std::cout << cost << "\n";

  std::sort(res.begin(), res.end());

  int cit = 0;
  for (; cit < res.size(); cit++)
    if (res[cit].first != 0)
      break;
  assert(cit > 0);
  std::cout << cit << '\n';
  for (int i = 0; i < cit; i++)
    std::cout << res[i].y << ' ';
  std::cout << '\n';

  std::cout << (res.size() - cit) << '\n';
  for (int i = cit; i < res.size(); i++)
    std::cout << res[i].x << ' ' << res[i].y << '\n';

  return 0;
}
