#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 7;
const ll mod = 1e9 + 7;

int n, m;
ll dp[100006];
int main()
{
    dp[1] = 2, dp[2] = 4;
    for (int i = 3; i <= N - 7;i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    
    while (~scanf("%d %d", &n, &m))
    {
        printf("%lld\n", (dp[n] + dp[m] - 2)% mod );
    }
    return 0;
}