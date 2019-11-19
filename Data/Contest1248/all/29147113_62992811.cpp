#include <bits/stdc++.h>

using namespace std;

long long dp[111111];

const long long MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    dp[1] = 2;
    dp[2] = 4;
    for (int i = 3; i <= max(n, m); i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    cout << (dp[n] + dp[m] - 2 + MOD) % MOD << endl;
}
