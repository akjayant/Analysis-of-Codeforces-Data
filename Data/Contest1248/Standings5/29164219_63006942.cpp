#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[100005][2][3];
ll dp1[100005][2][3];
ll mod=1e9+7;
ll solve1(ll a, ll b, ll c)
{
	if (dp[a][b][c]!=-1)
	{
		return dp[a][b][c]%mod;
	}
	if (c==1)
	{	
		dp[a][b][c]=(solve1(a+1, b, 2)%mod+solve1(a+1, 1-b,1)%mod)%mod;		
	}
	else
	{
		dp[a][b][c]=(solve1(a+1, 1-b, 1))%mod;
	}
	return dp[a][b][c]%mod;
}
ll solve2(ll a, ll b, ll c)
{
	if (dp1[a][b][c]!=-1)
	{
		return dp1[a][b][c]%mod;
	}
	if (c==1)
	{	
		dp1[a][b][c]=(solve2(a+1, b, 2)%mod+solve2(a+1, 1-b,1)%mod)%mod;		
	}
	else
	{
		dp1[a][b][c]=solve2(a+1, 1-b, 1)%mod;
	}
	return dp1[a][b][c]%mod;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >>n >> m;
    // cout << m;
    for (int i = 0; i <= n; ++i)
    {
    	dp[i][0][2]=-1;
    	dp[i][1][2]=-1;
    	dp[i][0][1]=-1;
    	dp[i][1][1]=-1;
    }
    for (int i = 0; i <= m; ++i)
    {
    	dp1[i][0][2]=-1;
    	dp1[i][1][2]=-1;
    	dp1[i][0][1]=-1;
    	dp1[i][1][1]=-1;
    	
    }
   		dp[n][0][2]=1;
    	dp[n][1][2]=1;
    	dp[n][0][1]=1;
    	dp[n][1][1]=1;
    	dp1[m][0][2]=1;
    	dp1[m][1][2]=1;
    	dp1[m][0][1]=1;
    	dp1[m][1][1]=1;
    cout <<((solve1(1, 0, 1)%mod+solve1(1, 1, 1 )%mod+ solve2(1, 0, 1)%mod+solve2(1, 1, 1)%mod)%mod-2+mod)%mod;
    return 0;
}