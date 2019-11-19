// in the name of holy satan
#include <bits/stdc++.h>
using namespace std;
const int mMain = 1e5 + 100;
typedef long long lint;
const lint mode = 1e9 + 7;

int n, m;
lint dp[mMain];

int main()
{
    iostream::sync_with_stdio(false);
    cin >> n >> m;
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < mMain; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= mode;
    }

    lint ans = dp[m - 1] * 2 + 2 * dp[n - 1] - 2;
    ans %= mode;
    cout << ans;
    // cout << power(2, 5);
}