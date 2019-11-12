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
    std::cin >> T;
    while (T-- > 0)
    {
      std::cin >> N;
      v.resize(N);
      for (int& i : v)
      {
        std::cin >> i;
      }
      std::sort(v.rbegin(), v.rend());
      int ans = 0;
      for (int i = 0; i < N; i += 1)
      {
        ans = std::max(ans, std::min(i + 1, v[i]));
      }
      std::cout << ans << std::endl;
    }
    return 0;
  }

private:
  int T;
  int N;
  std::vector< int > v;
};

int main()
{
  Solution().main();
  return 0;
}