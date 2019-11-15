#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int add(int x,int y) {
  x += y;
  if( x >= mod) x -= mod;
  return x;
}
int mult(int x,int y) {
  long long int ans = (long long)x*(long long)y;
  ans%=mod;
  return ans;
}
int dp[100005];
int main() {
  int t = 1;
  string s;
  while(t--) {
    cin >> s;
    if(s[0] == 'm' || s[0] == 'w') dp[0] = 0;
    else dp[0] = 1;
    for(int i = 1; i < s.size(); i++) {
      if(s[i] == 'm' || s[0] == 'w') {
	dp[i] = 0;
	continue;
      }
      dp[i] = dp[i-1];
      if(s[i] != 'u' && s[i] != 'n') {
	continue;
      }
      if(s[i] == s[i-1]) {
	if( i == 1)
	  dp[i] = add(dp[i], 1);
	else
	  dp[i] = add(dp[i], dp[i - 2]);
      }
    }
  }
  cout << dp[s.size() - 1] << endl;
  return 0 ;
}
