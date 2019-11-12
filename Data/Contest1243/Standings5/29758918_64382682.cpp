#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
      string s,t;
      cin >> s;
      cin >> t;
      int a[n],i;
      int k = 0;
      for(i=0;i<n;i++)
      {
          if(s[i]!=t[i])
          {
              a[k] = i;
              k++;
          }
      }
      if(k>2)
      {
          cout << "No\n";
      }
      else if(k==1)
      {
          cout << "No\n";
      }
      else
      {
          if(s[a[0]]==s[a[1]] && t[a[0]]==t[a[1]])
          {
              cout << "Yes\n";
          }
          else
          {
              cout << "No\n";
          }
      }
    }
}
