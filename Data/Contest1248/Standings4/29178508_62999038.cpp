#include <bits/stdc++.h>

using namespace std;

const long long Mod = 1e9 + 7;
const int maxn = 1e5 + 10;
int n, m;
long long dp[maxn], ans;

int main()
{
    scanf("%d%d", &n, &m);
    dp[0] = dp[1] = 1;
    for(int i=2; i<=max(n, m); i++) dp[i] = (dp[i-1] + dp[i-2])%Mod;
    ans = (ans + dp[m]*2)%Mod;
    ans = (ans + dp[n]*2)%Mod;
    printf("%lld\n", (ans+Mod-2)%Mod);
    return 0;
}
