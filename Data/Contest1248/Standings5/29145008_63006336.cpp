#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9 + 7;

signed main()
{
    int n, m;
    cin >> n >> m;
    int max1 = max(n, m);
    int dp[max1 + 1];
    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= max1; i++) dp[i] = dp[i - 1] % M + dp[i - 2] % M;
    int ans = (((dp[m] + dp[n] - 1) % M + M) * 2) % M;
    cout << ans;
    return 0;
}