#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <cstdlib>
#define inf 0x3f3f3f3f
#define LL long long 
#define inf64 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
const int mod=1e9+7;
ll dp[maxn][2];
ll num[maxn][2];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	dp[1][0]=dp[1][1]=1;
	dp[2][0]=2,dp[2][1]=2;
	for(int i=3;i<=m;i++){
		dp[i][0]=(dp[i-1][1]+dp[i-2][1])%mod;
		dp[i][1]=(dp[i-1][0]+dp[i-2][0])%mod;
	}
	num[1][1]=1,num[2][1]=2;
	num[1][0]=1,num[2][0]=2;
	for(int i=3;i<=n;i++){
		num[i][0]=(num[i-1][1]+num[i-2][1])%mod;
		num[i][1]=(num[i-1][0]+num[i-2][0])%mod;
	}
	// printf("%lld\n",dp[m][0]+dp[m][1]);
	// printf("%lld\n",num[n][0]+num[n][1]);
	ll ans=((dp[m][0]+dp[m][1])%mod+(num[n][0]+num[n][1])%mod-2+mod)%mod;
	printf("%lld\n",ans);
	return 0;
}

