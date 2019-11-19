#include <bits/stdc++.h>

class Solution
{
public:

  Solution()
  {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
  }

  int main()
  {
    std::cin >> N >> M;
    while (M-- > 0)
    {
      int x, y;
      std::cin >> x >> y;
      x -= 1;
      y -= 1;
      g[x].insert(y);
      g[y].insert(x);
    }
    for (int i = 0; i < N; i += 1)
    {
      remaining.insert(i);
      v.push_back({int(g[i].size()), i});
    }
    std::sort(v.begin(), v.end());
    int components = 0;
    for (const auto& aux : v)
    {
      int i = aux.second;
      if (remaining.count(i) == 0)
      {
        continue;
      }
      components += 1;
      dfs(i);
    }
    std::cout << components - 1 << std::endl;
    return 0;
  }

private:
  int N;
  int M;
  std::unordered_set< int > g[112345];
  std::unordered_set< int > remaining;
  std::vector< std::pair< int, int > > v;

  void dfs(const int& i)
  {
    std::vector< std::pair< int, int > > edges;
    for (const int& j : remaining)
    {
      if (g[i].count(j) == 0)
      {
        edges.push_back({int(g[j].size()), j});
      }
    }
    for (const auto& j : edges)
    {
      remaining.erase(j.second);
    }
    for (const auto& j : edges)
    {
      dfs(j.second);
    }
  }
};

int main()
{
  Solution().main();
  return 0;
}