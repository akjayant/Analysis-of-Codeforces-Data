#include <bits/stdc++.h>

const int MAX_SIZE = 1000000 + 5;

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
    std::cin >> N;
    long long int ans = N;
    for (int i = 2; 1LL * i * i <= N; i += 1)
    {
      if (N % i)
      {
        continue;
      }
      ans = std::gcd(ans, i);
      ans = std::gcd(ans, N / i);
    }
    std::cout << ans << std::endl;
    return 0;
  }

private:
  long long int N;
};

int main()
{
  Solution().main();
  return 0;
}