#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxN = 1e6+10;
LL dp[maxN][2][2];
LL sum[maxN];
LL pow2[maxN];
int mod = 1000*1000*1000+7;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    //pow2[1] = 2;
    //for(int i = 2; i <= max(m,n); i++) {
    //    pow2[i] = pow2[i-1]*2%mod;
    //}
    dp[2][0][1] = 1;
    dp[2][1][0] = 1;
    dp[2][0][0] = 1;
    dp[2][1][1] = 1;
    for(int i = 3; i <= max(n,m); i++) {
        dp[i][0][0] = dp[i-1][1][0];
        dp[i][1][0] = (dp[i-1][1][1] + dp[i-1][0][1]) % mod;
        dp[i][0][1] = (dp[i-1][1][0] + dp[i-1][1][1]) % mod;
        dp[i][1][1] = dp[i-1][1][0];
        sum[i] = (dp[i][0][0] + dp[i][1][0] + dp[i][0][1] + dp[i][1][1]) % mod;
    }
    sum[1] = 2;
    sum[2] = 4;
    cout << (sum[n] - 2 + sum[m])%mod << endl;

    return 0;
}
