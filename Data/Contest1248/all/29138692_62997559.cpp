#include <bits/stdc++.h>

using namespace std;
int n,m;
long long dp[6][100005],mod=1e9+7;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;
	dp[0][2]=1;
	dp[1][2]=1;
	dp[2][2]=1;
	dp[3][2]=1;
	for(int i=3;i<=max(n,m);i++){
		dp[0][i]=dp[3][i-1]%mod;;
		dp[1][i]=(dp[0][i-1]+dp[3][i-1])%mod;
		dp[2][i]=dp[1][i-1]%mod;
		dp[3][i]=(dp[1][i-1]+dp[2][i-1])%mod;
	}
	if(n==1 && m==1){
		cout<<2<<endl;;
		return 0;
	}
	if(n==1){
		cout<<(dp[0][m]+dp[1][m]+dp[2][m]+dp[3][m])%mod<<endl;
		return 0;
	}
	if(m==1){
		cout<<(dp[0][n]+dp[1][n]+dp[2][n]+dp[3][n])%mod<<endl;
		return 0;
	}
	cout<<(dp[0][n]+dp[1][n]+dp[2][n]+dp[3][n]+dp[0][m]+dp[1][m]+dp[2][m]+dp[3][m]-2)%mod<<endl;
}


