#include <bits/stdc++.h>
#define MAXN 100000
#define MOD 1000000007
#define int long long
using namespace std;

string s;
char c;
int ans, cnt;
int dp[MAXN+5];
bool tf = 1;

signed main() {
  dp[0] = dp[1] = 1;
  for (int i = 2; i <= MAXN; i++) {
    dp[i] = (dp[i-1] + dp[i-2]) % MOD;
  }
  cin >> s;
  c = ' ';
  ans = 1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'm' || s[i] == 'w') tf = 0;
    if (c == 'n' && s[i] == 'n') cnt++;
    else if (c == 'u' && s[i] == 'u') cnt++;
    else {
      ans = (ans * dp[cnt]) % MOD;
      cnt = 0;
      if (s[i] == 'n' || s[i] == 'u') cnt = 1;
    }
    c = s[i];
  }
  if (cnt) ans = (ans * dp[cnt]) % MOD;
  if (tf) cout << ans << '\n';
  else cout << 0 << '\n';
  return 0;
}