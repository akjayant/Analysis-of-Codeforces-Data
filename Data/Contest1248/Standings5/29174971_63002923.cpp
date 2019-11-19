#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[100005][5];
const ll mod=1000000007;
int main()
{
    ll n,m;
    scanf("%lld%lld",&n,&m);
    ll ans=0;
    dp[1][0]=0;
    dp[1][1]=1;
    dp[1][2]=1;
    dp[1][3]=0;
    for(ll i=2;i<=max(n,m);i++)
    {
        dp[i][0]=dp[i-1][1]%mod;
        dp[i][1]=(dp[i-1][2]+dp[i-1][3])%mod;
        dp[i][2]=(dp[i-1][0]+dp[i-1][1])%mod;
        dp[i][3]=dp[i-1][2]%mod;
       // printf("%lld %lld %lld %lld %lld\n",i,dp[i][0],dp[i][1],dp[i][2],dp[i][3]);
    }
ll su=(dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3]-2)%mod;
     ll su2=(dp[m][0]+dp[m][1]+dp[m][2]+dp[m][3]-2)%mod;
    printf("%lld\n",(su+su2+2)%mod);
}
