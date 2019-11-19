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
    int n; cin >> n;
    string s; cin >> s;
    int ans = n;
    fo(i, s.size())
      ans += (s[i] - '0');
    fo(i, s.size()){
      if(s[i] == '1'){
        ans = max(ans, i + 1 + max(i+1, s.size()-i));
      }
    }
    reverse(s.begin(), s.end());
    fo(i, s.size()){
      if(s[i] == '1'){
        ans = max(ans, i + 1 + max(i+1, s.size()-i));
      }
    }
    cout << ans << endl;
  }
}
