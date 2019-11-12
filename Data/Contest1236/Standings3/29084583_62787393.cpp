#include <cstdio>
const int mod=1000000007;
int n,m;
int ksm(int a,int x)
{
	int s=1;
	while (x)
	{
		if (x&1) s=1ll*s*a%mod;
		a=1ll*a*a%mod;
		x>>=1;
	}
	return s;
}
int main()
{
	scanf("%d%d",&n,&m);
	printf("%d\n",ksm((ksm(2,m)+mod-1)%mod,n));
	return 0;
}