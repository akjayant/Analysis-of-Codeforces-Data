#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
long long dp[200000][2];

const int MOD = 1e9 + 7;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    dp[0][1] = 1;
    dp[0][0] = 1;
    for (int i = 1; i <= max(n, m); i++)
    {
        dp[i][0] = (dp[i][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
        if (i > 1)
        {
            dp[i][0] = (dp[i][0] + dp[i - 2][1]) % MOD;
            dp[i][1] = (dp[i][1] + dp[i - 2][0]) % MOD;
        }
    }
    cout << (dp[n][0] + dp[n][1] + dp[m][0] + dp[m][1] - 2 + MOD) % MOD;
    return 0;
}
