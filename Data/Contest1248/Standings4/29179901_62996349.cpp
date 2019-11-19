#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n; cin >> m >> n;
    if (n < m) swap(m, n);

    if (n == 1) {
        cout << "2\n";
        return 0;
    }

    vector<vector<int64_t>> dp(n + 1, vector<int64_t>(4));
    dp[2][0] = dp[2][1] = dp[2][2] = dp[2][3] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i][0] = dp[i - 1][2];
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % MOD;
        dp[i][3] = dp[i - 1][1];
    }

    dp[1][0] = dp[1][3] = 1;
    int64_t dp1 = (dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3]) % MOD;
    int64_t dp2 = (dp[m][0] + dp[m][1] + dp[m][2] + dp[m][3]) % MOD;
    int64_t sol = (dp1 - 2 + dp2) % MOD; if (sol < 0) sol += MOD;
    cout << sol << '\n';
    return 0;
}
