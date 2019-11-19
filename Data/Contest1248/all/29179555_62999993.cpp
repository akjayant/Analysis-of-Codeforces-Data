#include<bits/stdc++.h>
using namespace std;

const long long md = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cout.precision(15);

  int n, m;
  cin >> n >> m;
  int mx = max(n, m) + 5;
  long long dp[mx][2][2];
  cout << "";
  memset(dp, 0, sizeof(dp));
  dp[1][0][0] = 2; // dp[1][1][0] = dp[1][1][1] = 
  dp[2][0][1] = dp[2][1][0] = 1;
  dp[2][1][1] = dp[2][0][0] = 1;

  for(int i = 3; i <= mx; ++i) {
    dp[i][0][0] = dp[i - 1][1][0];
    dp[i][1][1] = dp[i - 1][0][1];
    dp[i][1][0] = (dp[i - 1][1][1] + dp[i - 1][0][1]) % md;
    dp[i][0][1] = (dp[i - 1][0][0] + dp[i - 1][1][0]) % md;
  }

  long long sum = 0, zi = 0;
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < 2; ++j) {
      sum += dp[n][i][j];
      sum %= md;
      zi += dp[m][i][j];
      zi %= md;
    }
  }
  while(zi < 0) zi += md;
  while(sum < 0) sum += md;
  cout << ((sum - 2 + zi) + md) % md;

  return 0;
}
