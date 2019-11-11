#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt, qq = 0;
  cin >> tt;
  while (tt--)
  {
    int n;
    cin >> n;
    vector<int> A(3);
    for (int i = 0; i < 3; i++)
    {
      cin >> A[i];
    }
    string s,
        ans;
    cin >> s;
    vector<int> B(n);
    for (int i = 0; i < n; i++)
    {
      auto c = s[i];
      if (c == 'R')
      {
        B[i] = 0;
      }
      else if (c == 'P')
      {
        B[i] = 1;
      }
      else
      {
        B[i] = 2;
      }
    }
    vector<int> C = {'R', 'P', 'S'};
    int win = 0;
    for (int i = 0; i < n; i++)
    {
      int k = (B[i] + 1) % 3;
      if (A[k] > 0)
      {
        ans.push_back(C[k]);
        win++;
        A[k]--;
      }
      else
      {
        ans.push_back(' ');
      }
    }
    if (win >= n - win)
    {
      cout << "YES\n";
      for (int i = 0; i < n; i++)
      {
        if (ans[i] != ' ')
          continue;
        for (int j = 0; j < 3; j++)
        {
          if (A[j] > 0)
          {
            ans[i] = C[j];
            A[j]--;
            break;
          }
        }
      }
      cout << ans << "\n";
    }
    else
    {
      cout << "NO\n";
    }
  }
  return 0;
}