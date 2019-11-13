#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int k;
  cin >> k;
  for(; k > 0; k--)
  {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> alp(26, 0);
    for(int i = 0; i < n; i++)
    {
      alp[s[i] - 'a']++;
      alp[t[i] - 'a']++;
    }
    int ver = 1;
    for(int i = 0; i < 26; i++)
    {
      if(alp[i] & 1) ver = 0;
    }
    if(ver == 1)
    {
      vector<pair<int, int>> ans;
      for(int i = 0; i < n; i++)
      {
        if(s[i] != t[i])
        {
          int found = 0;
          for(int j = i + 1; j < n; j++)
          {
            if(t[j] == t[i])
            {
              found = 1;
              ans.push_back({i + 1, j + 1});
              char mc = s[i];
              s[i] = t[j];
              t[j] = mc;
              break;
            }
          }
          if(found == 0)
          {
            for(int j = i + 1; j < n; j++)
            {
              if(s[j] == t[i])
              {
                found = 1;
                ans.push_back({j + 1, j + 1});
                ans.push_back({i + 1, j + 1});
                char mc = s[i];
                s[i] = s[j];
                s[j] = t[j];
                t[j] = mc;
                break;
              }
            }
          }
        }
      }
      cout << "Yes" << endl;
      int sz = ans.size();
      cout << sz << endl;
      for(int i = 0; i < sz; i++)
      {
        cout << ans[i].first << " " << ans[i].second << endl;
      }
    }
    else
    {
      cout << "No" << endl;
    }
  }
  return 0;
}
