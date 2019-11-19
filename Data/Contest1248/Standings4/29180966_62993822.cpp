#include <bits/stdc++.h>
#define ll long long
#define mid 1000000007
using namespace std;
ll n,m,dp1[100005][5][5],dp[100005][5][5];
int main() 
{
    cin>>n>>m;
        dp1[0][0][1]=1;
        dp1[0][1][1]=1;
        for (int i=1; i<n; i++)
        {
            dp1[i][0][1]=(dp1[i-1][1][1]+dp1[i-1][1][2])%mid;
            dp1[i][0][2]=dp1[i-1][0][1];
            dp1[i][1][1]=(dp1[i-1][0][1]+dp1[i-1][0][2])%mid;
            dp1[i][1][2]=dp1[i-1][1][1];
        }
        dp[0][0][1]=1;
        dp[0][1][1]=1;
        for (int i=1; i<m; i++)
        {
            dp[i][0][1]=(dp[i-1][1][1]+dp[i-1][1][2])%mid;
            dp[i][0][2]=dp[i-1][0][1];
            dp[i][1][1]=(dp[i-1][0][1]+dp[i-1][0][2])%mid;
            dp[i][1][2]=dp[i-1][1][1];
        }
    cout<<(dp1[n-1][0][1]+dp1[n-1][0][2]+dp1[n-1][1][1]
    +dp1[n-1][1][2]+dp[m-1][0][1]+dp[m-1][0][2]+
    dp[m-1][1][1]+dp[m-1][1][2]-2)%mid<<endl;
    return 0;
}