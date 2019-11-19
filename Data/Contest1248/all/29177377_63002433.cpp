#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const int maxn = 200005;
ll dp[maxn][2][2][2];
ll sum(int k){
	return (dp[k][0][0][1]+dp[k][1][0][1]+dp[k][0][1][1]+dp[k][1][0][0]+dp[k][1][1][0]+dp[k][0][1][0])%mod;
}
int main()
{
	int n,m;
	cin>>n>>m;
	dp[1][0][0][1]=2;
	dp[2][0][0][1]=4;
	dp[3][0][0][1]=dp[3][1][0][1]=dp[3][0][1][1]=dp[3][1][0][0]=dp[3][1][1][0]=dp[3][0][1][0]=1;
	for(int i=4;i<=max(n,m);i++){
		dp[i][0][0][1]=(dp[i-1][0][1][0]+dp[i-1][0][1][1])%mod;
		dp[i][1][0][1]=(dp[i-1][1][0][0]+dp[i-1][1][0][1])%mod;
		dp[i][0][1][1]=(dp[i-1][1][1][0])%mod;
		dp[i][1][0][0]=(dp[i-1][0][0][1])%mod;
		dp[i][1][1][0]=(dp[i-1][1][0][0]+dp[i-1][1][0][1])%mod;
		dp[i][0][1][0]=(dp[i-1][1][0][0]+dp[i-1][1][0][1])%mod;
	}
	cout<<(sum(n)+sum(m)-2)%mod<<endl;
	return 0;
}