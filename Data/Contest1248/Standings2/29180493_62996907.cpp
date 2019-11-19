#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 100033;
ll dp[MAXN][2][2];
const int MOD = 1e9 + 7;
int main()
{
    int n, m;
    cin >> n >> m;
    if (n < m)
        swap(n, m);
    dp[1][0][1] = 1;
    dp[1][1][0] = 1;
    for (int i = 2; i <= max(n, m); i++)
    {
        dp[i][1][1] = dp[i - 1][1][0];
        dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1]) % MOD;
        dp[i][0][1] = (dp[i - 1][1][0] + dp[i - 1][1][1]) % MOD;
        dp[i][0][0] = dp[i - 1][0][1];
    }
    ll ans = dp[n][0][0] + dp[n][0][1] + dp[n][1][0] + dp[n][1][1];
    ans += dp[m][0][0] + dp[m][0][1] + dp[m][1][0] + dp[m][1][1] - 2;
    ans %= MOD;
    ans %= MOD;
    cout << ans;
    cout.flush();
    // system("pause");
    return 0;
}