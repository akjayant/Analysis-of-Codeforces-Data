#include<bits/stdc++.h>
//#include <numeric>
using namespace std;
#define int long long int
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int dp[100001][2][2];
    dp[1][0][0]=1;
    dp[1][1][0]=1;
    dp[1][0][1]=0;
    dp[1][1][1]=0;
    int x=1e9 +7;
    for(int i=2;i<=(long long)1e5;i++)
    {
        dp[i][0][0]=(dp[i-1][1][0]+dp[i-1][1][1])%x;
        dp[i][0][1]=dp[i-1][0][0];
        dp[i][1][0]=(dp[i-1][0][0]+dp[i-1][0][1])%x;
        dp[i][1][1]=dp[i-1][1][0];
    }
    int n,m;
    cin>>n>>m;
    int ma=max(n,m);
    int mi=min(n,m);
    int ans=(dp[ma][0][0]+dp[ma][0][1]+dp[ma][1][1]+dp[ma][1][0]-2+dp[mi][0][0]+dp[mi][0][1]+dp[mi][1][1]+dp[mi][1][0]+x)%x;
    cout<<ans;
}