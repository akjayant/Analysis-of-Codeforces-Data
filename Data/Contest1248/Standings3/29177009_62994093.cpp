#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

long long dp[100010];

int main()
{
    int n,m;
    cin>>n>>m;
    if(n<m) swap(n,m);
    if(m == 1){
        if( n== 1) cout<<2<<endl;
        else{
            memset(dp,0,sizeof(dp));
            dp[2] = 1;
            for(int i = 2;i<=n;i++){
                dp[i+2] += dp[i];
                dp[i+1] += dp[i];
                if(dp[i+2] >= mod) dp[i+2] -= mod;
                if(dp[i+1] >= mod) dp[i+1] -= mod;
            }
            long long res = dp[n+2] + dp[n+1];
            cout<<2*res%mod<<endl;
            return 0;
        }
        return 0;
    }
    memset(dp,0,sizeof(dp));
    dp[2] = 1;
    for(int i = 2;i<=n;i++){
                dp[i+2] += dp[i];
                dp[i+1] += dp[i];
                if(dp[i+2] >= mod) dp[i+2] -= mod;
                if(dp[i+1] >= mod) dp[i+1] -= mod;
            }
            long long res = dp[n+2] + dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[2] = 1;
    for(int i = 2;i<=m;i++){
                dp[i+2] += dp[i];
                dp[i+1] += dp[i];
                if(dp[i+2] >= mod) dp[i+2] -= mod;
                if(dp[i+1] >= mod) dp[i+1] -= mod;
            }
    res += dp[m+2] + dp[m+1];
    cout<<(2*res-2)%mod<<endl;
    return 0;
}
