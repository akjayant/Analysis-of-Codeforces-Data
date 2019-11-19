#include <bits/stdc++.h>

using namespace std;
const long long mod = 1e9+7;
int main()
{
    long long n, m, ans = 0, ans1, ans2;
    cin >> n >> m;
    vector <long long> dp(max(n,m)+1);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= max(n,m);i++)
    {
        dp[i] = (dp[i-1]+dp[i-2]+1)% mod;
    }
    ans = (((dp[n] + dp[m] + 1)%mod)*2 % mod);
    cout << ans;
    return 0;
}
