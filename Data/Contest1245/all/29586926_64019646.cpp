#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  int cm = count(s.begin(), s.end(), 'm');
  int cw = count(s.begin(), s.end(), 'w');
  if (cm || cw) {
    cout << 0;
    return 0;
  }
  vector<int> ans;
  for (int i = 0; i < n; )
  {
    if (s[i] == 'u' || s[i] == 'n') {
      int cnt = 0;
      int j;
      for (j = i; j < n; j++)
      {
        if (s[i] != s[j])
          break;
        cnt++;
      }
      if (cnt > 1) {
        ans.emplace_back(cnt);
      }
      i = j;
    }
    else
    {
      i++;
    }
  }
  int mod = 1e9 + 7;
  vector<int> T(n + 1);
  long long a = 1, b = 0;
  T[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    long long aa = 0, bb = 0;
    bb = a;
    aa = (a + b) % mod;
    swap(a, aa);
    swap(b, bb);
    T[i] = (a + b) % mod;
  }
  long long res = 1;
  for (auto c : ans) {
    
    res = (res * 1LL * T[c - 1]) % mod;
  }
  cout << res << "\n";
  return 0;
}