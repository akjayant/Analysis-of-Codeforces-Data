#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long dp[110000][2] = {};

void init() {
    dp[1][0] = 2;
    dp[1][1] = 0;
    for(int i=2; i<110000; ++i) {
        dp[i][1] = dp[i - 1][0];
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    init();

    int n, m; cin >> n >> m;
    long long res = (dp[n][0] + dp[n][1]) % MOD;
    res = (res + dp[m][0] + dp[m][1] - 2) % MOD;
    cout << res << '\n';
}