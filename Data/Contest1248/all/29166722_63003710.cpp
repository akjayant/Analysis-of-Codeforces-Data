#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main()
{
    long long n,m,x=1;
    cin>>n>>m;
    long long dp[m+1],dp1[n+1],dp2[n+1],dp4[n+1];
    dp1[1]=2;
    dp1[2]=4;
    dp2[1]=4;
    dp2[2]=6;
    for(int i=3;i<=n;i++)
    {
        dp1[i]=dp1[i-1]+dp1[i-2];
        dp1[i]%=mod;
    }
    for(int i=3;i<=n;i++)
    {
        dp2[i]=dp2[i-1]+dp2[i-2]-2;
        dp2[i]%=mod;
    }
    dp[1]=dp1[n];
    dp[2]=dp2[n];
    dp4[1]=0;
    dp4[2]=2;
   for(int i=3;i<=n;i++)
   {
       dp4[i]=dp4[i-1]+dp4[i-2]+2;
       dp4[i]%=mod;
   }
   x=dp4[n];
    for(int i=3;i<=m;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]-x;
        dp[i]%=mod;
    }
    dp[m]+=mod;
    dp[m]%=mod;
    cout<<dp[m];
}