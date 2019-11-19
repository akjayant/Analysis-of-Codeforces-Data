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
  
  int n;
  cin >> n;
  vector<int> a(n);

  for(int i = 0; i < n; i++)
    cin >> a[i];

  sort(a.begin(), a.end());
  
  int x = 0, y = 0;

  for(int i = 0; i < n; i++)
  {
     if(i < n / 2)
       y += a[i];
     else
       x += a[i];
  }
  
  int ans = x * x + y * y;
  
  cout << ans;

  return 0;
}