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
      std::cin >> a >> b;
      std::cout << (valid() ? "Yes" : "No") << std::endl;
    }
    return 0;
  }

private:
  int T;
  int N;
  std::string a;
  std::string b;

  bool valid()
  {
    if (a == b)
    {
      return true;
    }
    std::unordered_map< char, int > have;
    std::unordered_map< char, int > haveA;
    std::unordered_map< char, int > haveB;
    for (const char& c : a)
    {
      have[c] += 1;
      haveA[c] += 1;
    }
    for (const char& c : b)
    {
      have[c] += 1;
      haveB[c] += 1;
    }
    bool valid = true;
    for (const auto& i : have)
    {
      if (i.second & 1)
      {
        return false;
      }
    }
    std::vector< int > v;
    for (int i = 0; i < N; i += 1)
    {
      if (a[i] != b[i])
      {
        v.push_back(i);
      }
    }
    if (int(v.size()) != 2)
    {
      return false;
    }
    std::swap(a[v[0]], b[v[1]]);
    return a == b;
  }
};

int main()
{
  Solution().main();
  return 0;
}