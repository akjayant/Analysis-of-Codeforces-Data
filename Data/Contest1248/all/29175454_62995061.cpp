#include <bits/stdc++.h>
 
using namespace std;
#define fr(i,x,y) for(int i=x;i<y;i++)
#define rfr(i,x,y) for(int i=x;i>=y;i--)
#define int long long
const int N=1000000,M=6,INF=1e9,MOD=1e9+7,L=10;
int dp[N][2];
int dp2[N][2];
main()
{
	int n,m;
	cin>>n>>m;
	dp[0][0]=1;
	dp[0][1]=1;
	dp[1][0]=2;
	dp[1][1]=2;
	fr(i,2,max(n,m))
	{
		dp[i][0]=dp[i-1][1]+dp[i-2][1];
		dp[i][0]%=MOD;
		dp[i][1]=dp[i-1][0]+dp[i-2][0];
		dp[i][1]%=MOD;
	}
	cout<<((dp[n-1][0]+dp[n-1][1])%MOD+((dp[m-1][0]+dp[m-1][1])-2)%MOD)%MOD;
}