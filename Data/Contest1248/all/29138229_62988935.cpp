#include <bits/stdc++.h>
using namespace std;
using Int = long long;
const Int MOD = 1000000007;
Int dp[100000][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    dp[0][0] = 1;
    for (int i = 1; i < max(N, M); i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = dp[i - 1][0];
    }
    Int ans = 2 * (dp[N - 1][0] + dp[N - 1][1]) - 2;
    ans += 2 * (dp[M - 1][0] + dp[M - 1][1]);
    ans %= MOD;
    cout << ans << '\n';
    return 0;
}