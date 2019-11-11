#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

typedef long long i64;

i64 MOD = (i64)(1e9+7);

#define MAXN (int)1e5

i64 dp[MAXN + 1];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::string str;
  std::cin >> str;
  int n = str.length();
  dp[0] = 1, dp[1] = 1;
  for (int i = 2; i <= MAXN; i++)
    dp[i] = (dp[i-1] + dp[i-2]) % MOD;
  int i = 0;
  i64 ans = 1;
  while (i < n) {
    if (str[i] == 'm' || str[i] == 'w') {
      ans = 0;
      break;
    }
    if (str[i] != 'n' && str[i] != 'u') {
      i++;
      continue;
    }
    int len = 0;
    while (str[i + len] == str[i])
      len++;
    i += len;
    ans = (ans * dp[len]) % MOD;
  }
  std::cout << ans << std::endl;

  return 0;
}
