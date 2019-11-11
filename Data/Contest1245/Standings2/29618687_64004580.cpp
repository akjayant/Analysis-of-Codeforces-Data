#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.length();

    vector<int> dp(n + 1);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
      dp[i] += dp[i + 1];
      dp[i] %= MOD;

      if (i + 1 < n and s[i + 1] == s[i] and (s[i] == 'u' or s[i] == 'n')) {
	dp[i] += dp[i + 2];
	dp[i] %= MOD;
      }
    }
    int result = dp[0];
    for (char c: s) {
      if (c == 'w' or c == 'm')
	result = 0;
    }
    cout << result << '\n';
}
