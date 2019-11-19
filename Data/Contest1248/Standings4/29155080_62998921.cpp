#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll maxn=1e5 + 20, mod=1e9 + 7;
ll dp[maxn][2];

int main ()
{
    ios_base::sync_with_stdio(false);
    ll n, m; cin >> n >> m;
    dp[1][0]=dp[1][1]=1;
    dp[2][0]=dp[2][1]=2;
    for(ll i=3;i<=max(n,m);i++) {
        dp[i][0]=(dp[i-1][1] + dp[i-2][1])%mod;
        dp[i][1]=(dp[i-1][0] + dp[i-2][0])%mod;
    }
    cout << (dp[m][0] + dp[m][1] - 2 + dp[n][0] + dp[n][1])%mod << endl;
    return 0;
}
