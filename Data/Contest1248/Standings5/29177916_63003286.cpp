#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline ll read()
{
    ll ret=0,flag=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')flag=-1;c=getchar();}
    while(c>='0'&&c<='9')ret=ret*10+(c^'0'),c=getchar();
    return flag*ret;
}

const ll N=1e5+5,mod=1e9+7;
ll dp[N][5];

ll calc(ll n)
{
    dp[0][1]=dp[0][2]=dp[0][3]=dp[0][4]=1;
    dp[1][1]=dp[1][2]=0,dp[1][3]=dp[1][4]=1;
    dp[2][1]=dp[2][2]=1,dp[2][3]=dp[2][4]=1;
    for(ll i=3;i<=n;i++)
    {
        dp[i][1]=(dp[i-2][4]+dp[i-2][2])%mod;
        dp[i][2]=(dp[i-2][3]+dp[i-2][1])%mod;
        dp[i][3]=(dp[i-1][2]+dp[i-1][4])%mod;
        dp[i][4]=(dp[i-1][1]+dp[i-1][3])%mod;
    }
    return (dp[n][1]+dp[n][2]+dp[n][3]+dp[n][4])%mod;
}

int main()
{
    ll n=read(),m=read();
    ll ans=0;
    ans=(ans+calc(n))%mod;
    ans=(ans+calc(m))%mod;
    printf("%lld",(ans-2+mod)%mod);
    return 0;
}
