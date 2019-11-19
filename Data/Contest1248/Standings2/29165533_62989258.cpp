#include <iostream>

using namespace std;

const int mod = 1e9 + 7;
long long ans;

long long dp[3][100005];

int main()
{
    int n, m; cin >> n >> m;

    dp[1][0] = dp[1][1] = 1LL;
    dp[2][0] = dp[2][1] = 1LL;

    for(int l = 2; l <= max(n, m); l++)
    {
        dp[1][l] = (dp[2][l - 1] + dp[2][l - 2]) % mod;
        dp[2][l] = (dp[1][l - 1] + dp[1][l - 2]) % mod;
    }

    if(n == 1)
    {
        ans = (dp[1][m] + dp[2][m]);
        ans %= mod;

        cout << ans << '\n';
        return 0;
    }

    ans = (dp[1][m] + dp[2][m]) + (dp[1][n] + dp[2][n] - 2 + mod);
    ans %= mod;

    cout << ans << '\n';

    return 0;
}
