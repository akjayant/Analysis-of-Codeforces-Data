#include<iostream>
#include<algorithm>
#include<memory.h>
#include<unordered_map>
#include<queue>
#include<ctime>
#define iris 1000000007
#define int long long
using namespace std;

int dp[100010][2];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,i,m;
	cin>>n>>m;
	dp[1][0]=0;
	dp[1][1]=2;
	for(i=2;i<=max(n,m);i++)
	{
		dp[i][0]=dp[i-1][1];
		dp[i][1]=(dp[i-1][0]+dp[i-1][1])%iris;
//		cout<<dp[i][0]<<' '<<dp[i][1]<<'\n';
	}
	
//	dp[1][1]=(dp[n][0]+dp[n][1])%iris;
//	dp[1][0]=0;
//	cout<<dp[1][1]<<'\n';
//	int ouo=dp[1][1]-2;
/*	for(i=2;i<=m;i++)
	{
		dp[i][0]=dp[i-1][1];
		dp[i][1]=(dp[i-1][0]+dp[i-1][1])%iris;
//		cout<<dp[i][0]<<' '<<dp[i][1]<<'\n';
	}*/
	
	int qwq=(dp[m][0]+dp[m][1])%iris;
	int ouo=(dp[n][0]+dp[n][1]-2+iris)%iris;
//	cout<<ouo*2<<'\n';
	cout<<(qwq+ouo)%iris<<'\n';
	
	return 0;
}
