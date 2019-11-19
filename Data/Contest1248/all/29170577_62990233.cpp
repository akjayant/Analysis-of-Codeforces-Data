#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
const int mod=1e9+7;
int _dp[maxn][2];
int dp[maxn][2];
int main() {
    int n,m;
    cin>>n>>m;
    dp[1][1]=2;
    for(int i=2;i<=max(n,m);i++) {
        dp[i][0]=dp[i-1][1];
        dp[i][1]=(dp[i-1][1]+dp[i-1][0])%mod;
    }
    cout<<((((dp[n][0]+dp[n][1])%mod+dp[m][1])%mod+dp[m][0])%mod+mod-2)%mod<<endl;
    return 0;
}
