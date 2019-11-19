#include <bits/stdc++.h>
#define ll long long;
const long long maxn=100005;
const long long mod=1e9+7;
using namespace std;
long long n,m;
long long dp[2][2][maxn];
int main() {
    scanf("%lld %lld",&n,&m);
    if(n>=2&&m>=2)
    {
        dp[0][0][1]=1;
        dp[0][1][1]=1;
        dp[1][0][1]=1;
        dp[1][1][1]=1;
        for(int i=2;i<maxn;i++)
        {
            dp[0][0][i]=dp[1][0][i-1]%mod;
            dp[0][1][i]=(dp[0][0][i-1]+dp[1][0][i-1])%mod;
            dp[1][0][i]=(dp[1][1][i-1]+dp[0][1][i-1])%mod;
            dp[1][1][i]=dp[0][1][i-1]%mod;
        }
        printf("%lld\n",(dp[0][0][m-1]+dp[0][1][m-1]+dp[1][0][m-1]+dp[1][1][m-1]+dp[0][0][n-1]+dp[0][1][n-1]+dp[1][0][n-1]+dp[1][1][n-1]-2)%mod);
        return 0;
    }
    if(n==1&&m==1)
    {
        printf("2\n");
        return 0;
    }
    if(n==1)
    {
        dp[0][0][1]=1;
        dp[0][1][1]=1;
        dp[1][0][1]=1;
        dp[1][1][1]=1;
        for(int i=2;i<maxn;i++)
        {
            dp[0][0][i]=dp[1][0][i-1]%mod;
            dp[0][1][i]=(dp[0][0][i-1]+dp[1][0][i-1])%mod;
            dp[1][0][i]=(dp[1][1][i-1]+dp[0][1][i-1])%mod;
            dp[1][1][i]=dp[0][1][i-1]%mod;
        }
        printf("%lld\n",(dp[0][0][m-1]+dp[0][1][m-1]+dp[1][0][m-1]+dp[1][1][m-1])%mod);
        return 0;
    }
    if(m==1)
    {
        dp[0][0][1]=1;
        dp[0][1][1]=1;
        dp[1][0][1]=1;
        dp[1][1][1]=1;
        for(int i=2;i<maxn;i++)
        {
            dp[0][0][i]=dp[1][0][i-1]%mod;
            dp[0][1][i]=(dp[0][0][i-1]+dp[1][0][i-1])%mod;
            dp[1][0][i]=(dp[1][1][i-1]+dp[0][1][i-1])%mod;
            dp[1][1][i]=dp[0][1][i-1]%mod;
        }
        printf("%lld\n",(dp[0][0][n-1]+dp[0][1][n-1]+dp[1][0][n-1]+dp[1][1][n-1])%mod);
        return 0;
    }
    return 0;
}