#include <bits/stdc++.h>

using namespace std;


long long n, m, dp[7][100200], MOD = 1e9 + 7, lowVal, upVal, ans;

int main() {
    cin >> n >> m;
    dp[1][1] = 1;
    dp[2][1] = 0;
    dp[3][1] = 1;
    dp[4][1] = 0;

    dp[5][1] = 2;
    dp[5][0] = 1;
    for (int i = 2; i <= 100020; i++) {
        dp[1][i] = dp[3][i - 1] + dp[4][i - 1];
        dp[2][i] = dp[1][i - 1];
        dp[3][i] = dp[1][i - 1] + dp[2][i - 1];
        dp[4][i] = dp[3][i - 1];
        dp[1][i] %= MOD;
        dp[2][i] %= MOD;
        dp[3][i] %= MOD;
        dp[4][i] %= MOD;
        dp[5][i] = dp[1][i] + dp[2][i] + dp[3][i] + dp[4][i];
        dp[5][i] %= MOD;
    }
    //cout << dp[5][m];
    ans = (dp[5][n] + dp[5][m]) % MOD;
    cout << (ans - 2 + MOD) % MOD << endl;
}
