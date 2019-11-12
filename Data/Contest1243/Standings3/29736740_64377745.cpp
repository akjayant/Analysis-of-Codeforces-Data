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
    int pl = 0, c1 = -1, c2 = -1;
    for(int i = 0; i < n; i++)
    {
      if(s[i] != t[i])
      {
        pl++;
        if(c1 == -1)
        {
          c1 = i;
        }
        else if(c2 == -1)
        {
          c2 = i;
        }
      }
    }
    if(pl == 0)
    {
      cout << "Yes" << endl;
    }
    else if(pl == 2)
    {
      if(s[c1] == s[c2] && t[c1] == t[c2])
      {
        cout << "Yes" << endl;
      }
      else cout << "No" << endl;
    }
    else cout << "No" << endl;
  }
  return 0;
}
