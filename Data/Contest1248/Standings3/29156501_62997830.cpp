#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;

LL dp[100005][2][2][2];

LL DP(int n) {
    if(n == 1) return 2;
    if(n == 2) return 4;
    for(int i = 4; i <= n; ++i) {
        dp[i][0][0][1] = (dp[i-1][0][1][0]+dp[i-1][0][1][1]) % mod;
        dp[i][0][1][0] = (dp[i-1][1][0][0]+dp[i-1][1][0][1]) % mod;
        dp[i][0][1][1] = dp[i-1][1][1][0];
        dp[i][1][1][0] = (dp[i-1][1][0][1]+dp[i-1][1][0][0]) % mod;
        dp[i][1][0][1] = (dp[i-1][0][1][1]+dp[i-1][0][1][0]) % mod;
        dp[i][1][0][0] = dp[i-1][0][0][1];
    }
    LL ans = (dp[n][0][0][1]+dp[n][0][1][0]+dp[n][0][1][1]+dp[n][1][1][0]+
              dp[n][1][0][1]+dp[n][1][0][0]) % mod;
    return ans;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    dp[3][0][1][0]=dp[3][1][0][0]=dp[3][1][1][0] = 1;
    dp[3][0][0][1]=dp[3][0][1][1]=dp[3][1][0][1] = 1;
    LL ans = (DP(n) + DP(m) - 2 + mod) % mod;
    printf("%lld\n", ans);
    return 0;
}