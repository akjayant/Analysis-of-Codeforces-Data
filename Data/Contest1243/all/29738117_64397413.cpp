#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<iostream>
#include<iterator>
#include<math.h>
#include<cmath>
#include<sstream>
#include<vector>
#include<iomanip>
#include<string>
#include<fstream>
#include<algorithm>
#include<map>
#include<thread>
#include<stack>
#include<numeric>
#include<functional>
#include<queue>
#include<set>
#include<list>
#include<bitset>
#include<unordered_map>
#include<cassert>


typedef long long ll;

using namespace std;

const ll inf = 1e15;
const ll MOD = 1e9 + 7;
// 9223372036854775807 2^63 - 1

struct th
{
  ll x, y, ind;
  ll c, k;
};

int n;
string s, t;

bool check()
{
  vector<int> alp(30, 0);

  for (auto &i : s)
  {
    ++alp[i - 'a'];
  }
  for (auto &i : t)
  {
    ++alp[i - 'a'];
  }

  bool ok = true;
  for (auto &i : alp)
  {
    if (i % 2 != 0) ok = false;
  }

  return ok;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << setprecision(30);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif // _DEBUG
#ifndef _DEBUG
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif // !_DEBUG

  int KK;
  cin >> KK;

  while (KK--)
  {
    cin >> n;
    cin >> s >> t;
    
    if (!check())
    {
      cout << "NO" << endl;
      continue;
    }

    cout << "YES" << endl;

    list<int> dif;
    for (int i = 0; i < n; ++i)
    {
      if (s[i] != t[i]) dif.push_back(i);
    }

    vector<pair<int, int>> ans;

    bool ok = true;
    while (ok)
    {
      ok = false;
      for (auto it = dif.begin(); it != dif.end(); ++it)
      {
        auto it2 = it;
        it2++;

        auto it3 = dif.end();
        for (; it2 != dif.end(); ++it2)
        {
          if (s[*it] == s[*it2])
          {
            ok = true;
            it3 = it2;
            break;
          }
        }

        if (it3 != dif.end())
        {
          ans.emplace_back(*it3, *it);
          swap(s[*it3], t[*it]);
          dif.erase(it);
          if (s[*it3] == t[*it3]) dif.erase(it3);
          break;
        }
      }
    }
   
    while (!dif.empty())
    {
      swap(s[*dif.begin()], t[*dif.begin()]);
      ans.emplace_back(*dif.begin(), *dif.begin());

      ok = true;
      while (ok)
      {
        ok = false;
        for (auto it = dif.begin(); it != dif.end(); ++it)
        {
          auto it2 = it;
          it2++;

          auto it3 = dif.end();
          for (; it2 != dif.end(); ++it2)
          {
            if (s[*it] == s[*it2])
            {
              ok = true;
              it3 = it2;
              break;
            }
          }

          if (it3 != dif.end())
          {
            ans.emplace_back(*it3, *it);
            swap(s[*it3], t[*it]);
            dif.erase(it);
            if (s[*it3] == t[*it3]) dif.erase(it3);
            break;
          }
        }
      }
    }

    cout << ans.size() << endl;
    for (auto &i : ans)
    {
      cout << i.first + 1 << ' ' << i.second + 1 << endl;
    }
  }

  return 0;

}