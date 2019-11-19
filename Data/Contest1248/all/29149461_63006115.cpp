#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define MAXN 100005
using namespace std;
ll f[MAXN],sum[MAXN];
int main()
{
	f[1] = 2,f[2] = 4,sum[0] = 0,sum[1] = 2,sum[2] = 4;
	for(int i = 3;i <= MAXN-5;++i)
	{
		f[i] = (f[i-2]+f[i-1])%MOD;
		sum[i] = (sum[i-1]+f[i-1])%MOD;
	}
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		printf("%lld\n",(f[n]+sum[m-1])%MOD);
	}
	return 0;
}
