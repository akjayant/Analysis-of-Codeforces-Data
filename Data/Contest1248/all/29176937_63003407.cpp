#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int  mod  =1e9+7;
const int  maxn =1e5+7;
int n,m;
ll dp[2][maxn]={1};
int main(){

    scanf("%d%d",&n,&m);
    int maxx = max(n,m);
    for(int i=1;i<maxx;i++)
    {
        //he 1
        dp[1][i] = dp[0][i-1];

        dp[0][i] = (dp[1][i-1]+dp[0][i-1])%mod;
        //printf("%lld %lld\n",dp[1][i],dp[0][i]);
    }
    ll ans =((dp[1][n-1]+dp[0][n-1]+dp[1][m-1]+dp[0][m-1]-1)%mod*2)%mod;
    printf("%lld",ans);
    return 0 ;
}
