#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1e5 + 10;
const ll mod = 1e9 + 7;

ll dp[MAXN][5];
ll dp2[MAXN][5];

int main()
{
    int n,m;
    cin>>n>>m;
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[2][3] = 1;
    for (int i = 3;i<=m;i++)
    {
        dp[i][0] = dp[i-1][2];
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % mod;
        dp[i][2] = (dp[i-1][3] + dp[i-1][1]) % mod;
        dp[i][3] = dp[i-1][1];
    }
    ll sum = 0;
    for (int i = 0;i<=3;i++) sum = (sum + dp[m][i]) % mod;
    // cout<<sum<<'\n';
    dp2[1][0] = 1;
    dp2[1][1] = 1;
    dp2[2][0] = 1;
    dp2[2][1] = 1;
    dp2[2][2] = 1;
    dp2[2][3] = 1;
    for (int i = 3;i<=n;i++)
    {
        dp2[i][0] = dp2[i-1][2];
        dp2[i][1] = (dp2[i-1][0] + dp2[i-1][2]) % mod;
        dp2[i][2] = (dp2[i-1][3] + dp2[i-1][1]) % mod;
        dp2[i][3] = dp2[i-1][1];
    }
    ll sum2 = 0;
    for (int i = 0;i<=3;i++) sum2 = (sum2 + dp2[n][i]) % mod;
    // cout<<sum2<<'\n';
    sum =(sum - 2 + sum2 + mod) % mod;
    cout<<sum;
    return 0;
}