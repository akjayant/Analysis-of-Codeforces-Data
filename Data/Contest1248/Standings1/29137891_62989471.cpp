#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1000000007;
char s[100001];
int a[100001];
int f[100001];
signed main()
{
	int n,m;
	scanf("%I64d%I64d",&n,&m);

/*	dp[1][0]=1;
	dp[2][0]=dp[2][1]=1;
	for(int i=3;i<=max(n,m);i++)
	{
		dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
		dp[i][1]=dp[i-2][0];
	}
	printf("%I64d",((dp[n][0]+dp[n][1]+dp[m][0]+dp[m][1])*2%mod-2+mod)%mod);
*/
	f[0]=f[1]=2;
	for(int i=2;i<=max(m,n);i++)
		f[i]=(f[i-1]+f[i-2])%mod;
	printf("%I64d",(f[n]+f[m]-2+mod)%mod);
	return 0;
}