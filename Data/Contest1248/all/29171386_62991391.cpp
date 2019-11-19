#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e5 + 10, MOD = 1e9 + 7;
int dp[N][2];

int32_t main()
{
    int n, m; cin >> n >> m;
    if (n == 1 && m == 1) return cout << "2\n", 0;
    dp[0][1] = dp[0][0] = dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= max(n, m); i ++) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 2][1]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 2][0]) % MOD;
    }
    cout << (2 * (dp[n][0] + dp[m][0] - 1 + MOD) ) % MOD << "\n";
}
