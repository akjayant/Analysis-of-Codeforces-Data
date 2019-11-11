#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7, mod = 1e9 + 7;
string str;
int dp[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> str;
  int n = str.size();
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    if (str[i - 1] == 'w' || str[i - 1] == 'm') {
      cout << 0 << "\n";
      return 0;
    }
    dp[i] = dp[i - 1];
    if (i > 1 && ((str[i - 1] == 'u' && str[i - 2] == 'u') || (str[i - 1] == 'n' && str[i - 2] == 'n'))) {
      dp[i] += dp[i - 2];
    }
    if (dp[i] >= mod) {
      dp[i] -= mod;
    }
  }
  cout << dp[n] << "\n";

  return 0;
}
