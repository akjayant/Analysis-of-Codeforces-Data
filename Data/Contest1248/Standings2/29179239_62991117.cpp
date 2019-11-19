#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, m;
    cin >> n >> m;
    long long ans = 0;
    vector<long long> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 0;
    long long sum = 1;
    for (long long i = 2; i <= n; i++) {
        dp[i] = (sum - dp[i - 1] + mod) % mod;
        sum = (sum + dp[i]) % mod;
    }
    for (long long i = 0; i <= n; i++) {
        ans = (ans + dp[i] * 2) % mod;
    }
    vector<long long> dp2(m + 1, 0);
    dp2[0] = 0;
    dp2[1] = 0;
    sum = 1;
    for (long long i = 2; i <= m; i++) {
        dp2[i] = (sum - dp2[i - 1] + mod) % mod;
        sum = (sum + dp2[i]) % mod;
    }
    for (long long i = 0; i <= m; i++) {
        ans = (ans + dp2[i] * 2) % mod;
    }
    ans += 2;
    cout << ans % mod;
    return 0;
}
