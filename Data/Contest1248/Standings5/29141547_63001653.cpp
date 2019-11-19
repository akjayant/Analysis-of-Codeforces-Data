#include<bits/stdc++.h>
using namespace std;
const long long p = 1e9 + 7;
long long dp[100005][2];
int main(){
    ios::sync_with_stdio(false);
    int n, m;
    memset(dp, 0, sizeof(dp));
    cin>>n>>m;
    dp[1][1] = 2;
    for(int i = 2; i <= n; i++){
        dp[i][0] = dp[i - 1][1] % p;
        dp[i][1] = (dp[i - 1][1] + dp[i - 1][0]) % p;
    }
    long long ans = (dp[n][0] + dp[n][1] - 2) % p;
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 2;
    for(int i = 2; i <= m; i++){
        dp[i][0] = dp[i - 1][1] % p;
        dp[i][1] = (dp[i - 1][1] + dp[i - 1][0]) % p;
    }
    ans = (ans + (dp[m][0] + dp[m][1])) % p;
    cout<<ans<<endl;
}
