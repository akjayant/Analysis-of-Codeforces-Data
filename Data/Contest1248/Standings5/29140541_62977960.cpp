#include<bits/stdc++.h>
 using namespace std;

#define  int  long long
#define  endl  '\n'
const int mod = 1e9 + 7;


int32_t main()
{ 
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif 
  
  int t, n, m, x;
  cin >> t;

  while(t--)
  {
    int o1 = 0, o2 = 0;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
      cin >> x;
      if(x & 1)
        o1++;
    }

    cin >> m;

    for(int i = 0; i < m; i++)
    {
      cin >> x;
      if(x & 1)
        o2++;
    }

    int ans = o1 * o2 + (n - o1) * (m - o2);
    cout << ans << endl;
    
  }

  return 0;
}