/* ashwani_er */

#include <bits/stdc++.h>

using namespace std;

#define int long long

int mod=1e9 +7;

signed main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin>>n>>m;
	
	int dp[max(n,m)+10];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=max(n,m);i++){
		dp[i]=(dp[i-1]+dp[i-2])%mod;
	}
	cout<<((dp[n]+dp[m]-1)*2)%mod<<endl;
}
