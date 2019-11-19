#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn=1e5+10;
ll dp[maxn][2][2];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	dp[0][0][1]=dp[0][1][0]=1;
	for(int i=1;i<max(n,m);i++)
	{
		dp[i][0][0]=dp[i-1][0][1];
		dp[i][0][1]=(dp[i-1][1][0]+dp[i-1][1][1])%MOD;
		dp[i][1][1]=dp[i-1][1][0];
		dp[i][1][0]=(dp[i-1][0][0]+dp[i-1][0][1])%MOD;
	}
	ll ans=0;
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)
	{
		ans=(ans+dp[n-1][i][j])%MOD;
		ans=(ans+dp[m-1][i][j])%MOD;
	}
	ans=ans+MOD-2;
	ans=ans%MOD;
	printf("%I64d\n",ans);
	return 0;
}