#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int fpow(int a, int b)
{
    a %= MOD;
    int ret = 1;
    for (; b; a = a * a % MOD, b /= 2)
        if (b % 2)
            ret = ret * a % MOD;
    return ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int dp[100001];
    dp[0] = dp[1] = 2;
    for (int i = 2; i <= 100000; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

    int n, m;
    cin >> n >> m;
    cout << (((dp[m] + dp[n]) % MOD) + MOD - 2) % MOD << '\n';

    return 0;
}

//      *   *  *****  *   *  *   *
//     *   *  *      **  *  *   *
//    *****  *****  * * *  *   *
//   *   *      *  *  **  *   *
//  *   *  *****  *   *   ***
//     *****  *****  *****
//    *      *   *  *
//   *      *****  *
//  *      *  *   *
//  ***** *   *   *****
