#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
int solve () {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = n;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') continue;
    ans = max({ans, 2 * (i + 1), 2 * (n - i)});
  }
  return ans;
}
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  //b
  int t;
  cin >> t;
  while (t--) cout << solve() << '\n';
  return 0;
}