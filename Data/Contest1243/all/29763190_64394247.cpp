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
      std::unordered_map< char, int > have;
      for (const char& c : a)
      {
        have[c] += 1;
      }
      for (const char& c : b)
      {
        have[c] += 1;
      }
      bool valid = true;
      for (const auto& i : have)
      {
        if (i.second & 1)
        {
          valid = false;
        }
      }
      if (valid == false)
      {
        std::cout << "No" << std::endl;
        continue;
      }
      solve();
    }
    return 0;
  }

private:
  int T;
  int N;
  std::string a;
  std::string b;

  void solve()
  {
    std::unordered_map< char, int > haveA;
    for (const char& c : a)
    {
      haveA[c] += 1;
    }
    std::unordered_map< char, int > haveB;
    for (const char& c : b)
    {
      haveB[c] += 1;
    }
    std::vector< std::pair< int, int > > ans;
    for (int i = 0; i < N; i += 1)
    {
      if (a[i] == b[i])
      {
        continue;
      }
      if (haveB[a[i]] < haveA[a[i]])
      {
        const char& c = a[i];
        for (int j = N - 1; j >= 0; j -= 1)
        {
          if (a[j] == c)
          {
            ans.push_back({j + 1, i + 1});
            haveA[a[j]] -= 1;
            haveA[b[i]] += 1;
            haveB[b[i]] -= 1;
            haveB[a[j]] += 1;
            std::swap(b[i], a[j]);
            break;
          }
        }
      }
      else if (haveA[b[i]] < haveB[b[i]])
      {
        const char& c = b[i];
        for (int j = N - 1; j >= 0; j -= 1)
        {
          if (b[j] == c)
          {
            ans.push_back({i + 1, j + 1});
            haveB[b[j]] -= 1;
            haveB[a[i]] += 1;
            haveA[a[i]] -= 1;
            haveA[b[j]] += 1;
            std::swap(a[i], b[j]);
            break;
          }
        }
      }
      else
      {
        const char& c = a[i];
        for (int j = N - 1; j >= 0; j -= 1)
        {
          if (b[j] == c)
          {
            ans.push_back({N, j + 1});
            ans.push_back({N, i + 1});
            haveB[b[i]] -= 1;
            haveB[a[N - 1]] += 1;
            haveA[a[N - 1]] -= 1;
            haveA[b[i]] += 1;
            std::swap(b[i], b[j]);
            std::swap(a[N - 1], b[j]);
            break;
          }
        }
      }
    }
    if (int(ans.size()) > N + N)
    {
      std::cout << "No" << std::endl;
    }
    else
    {
      std::cout << "Yes" << std::endl;
      std::cout << int(ans.size()) << std::endl;
      for (const auto& i : ans)
      {
        std::cout << i.first << ' ' << i.second << std::endl;
      }
    }
  }
};

int main()
{
  Solution().main();
  return 0;
}