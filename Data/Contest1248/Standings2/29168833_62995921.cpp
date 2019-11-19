#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long lint;
const int N=100069;
const lint mo=1000000007;
int n,m;
lint dp[N][2];
int main()
{
	scanf("%d%d",&n,&m);
	if(n<m) swap(n,m);
	dp[0][0]=2;
	for(int i=0;i<n;i++)
	{
		(dp[i+2][1]+=(dp[i][0]+dp[i][1])%mo)%=mo;
		(dp[i+1][0]+=(dp[i][0]+dp[i][1])%mo)%=mo;
	}
	lint ans=(dp[n][1]+dp[n][0]+dp[m][0]+dp[m][1]-2+mo)%mo;
	printf("%I64d\n",ans);
	return 0;
}