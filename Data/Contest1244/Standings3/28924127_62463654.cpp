#include <bits/stdc++.h>
#define int int64_t
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define double long double
#define fo(i, n)    for(int i = 0; i < n; i ++)
#define foe(i, n)   for(int i = 0; i <= n; i ++)
#define fo1(i, n)   for(int i = 1; i < n; i ++)
#define fo1e(i, n)  for(int i = 1; i <= n; i ++)
using namespace std;

int32_t main(){
  int t; cin >> t;
  while(t --){
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int f = a / c + (a % c != 0) + b / d + (b % d != 0);
    if(f <= k)
      cout << a / c + (a % c != 0) << " " << b / d + (b % d != 0);
    else
      cout << -1;
    cout << endl;
  }
}
