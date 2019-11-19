#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+7;
ll mod=1e9+7;
int n,m;
ll dp[maxn][4];
int main()
{
    scanf("%d %d",&n,&m);
    if(n<m)
        swap(n,m);
    dp[1][2]=1;
    dp[1][3]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=dp[i-1][3];
        dp[i][1]=dp[i-1][2];
        dp[i][2]=(dp[i-1][0]+dp[i-1][3])%mod;
        dp[i][3]=(dp[i-1][1]+dp[i-1][2])%mod;
    }
    ll ans=0;
    for(int i=0;i<4;i++)
        ans=(ans+dp[n][i]+dp[m][i])%mod;
    ans=(ans-2+mod)%mod;
    printf("%lld\n",ans);
}

