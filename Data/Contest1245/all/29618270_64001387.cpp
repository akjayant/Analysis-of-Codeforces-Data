#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for(; t > 0; t--)
  {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    string s;
    cin >> s;
    vector<char> seq(n, '#');
    for(int i = 0; i < n; i++)
    {
      if(s[i] == 'S' && a)
      {
        seq[i] = 'R';
        a--;
      }
      else if(s[i] == 'R' && b)
      {
        seq[i] = 'P';
        b--;
      }
      else if(s[i] == 'P' && c)
      {
        seq[i] = 'S';
        c--;
      }
    }
    if((n - a - b - c) * 2 >= n)
    {
      cout << "YES" << endl;
      for(int i = 0; i < n; i++)
      {
        if(seq[i] != '#') cout << seq[i];
        else
        {
          if(a != 0)
          {
            cout << 'R';
            a--;
          }
          else if(b != 0)
          {
            cout << 'P';
            b--;
          }
          else if(c != 0)
          {
            cout << 'S';
            c--;
          }
        }
      }
      cout << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
  return 0;
}
