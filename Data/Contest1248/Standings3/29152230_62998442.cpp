#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int n, m, mod = 1e9 + 7;
long long dp[200000][2];


void solve() {
    cin >> n >> m;
    dp[1][1] = 2;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][0] %= mod;
        dp[i][1] %= mod;
        if (dp[i][0] < 0) {
            dp[i][0] += mod;
        }
        if (dp[i][1] < 0) {
            dp[i][1] += mod;
        }
    }
    long long ans = dp[n][1] + dp[n][0] - 2;
    ans %= mod;
    if (ans < 0) {
        ans += mod;
    }
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 2;
    for (int i = 2; i <= m; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][0] %= mod;
        dp[i][1] %= mod;
        if (dp[i][0] < 0) {
            dp[i][0] += mod;
        }
        if (dp[i][1] < 0) {
            dp[i][1] += mod;
        }
    }
    ans += dp[m][1] + dp[m][0];
    ans %= mod;
    if (ans < 0) {
        ans += mod;
    }
    cout << ans;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}