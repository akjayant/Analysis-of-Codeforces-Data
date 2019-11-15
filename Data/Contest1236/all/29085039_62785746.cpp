#include <cstdio>
#include <algorithm>
using namespace std;
#define mod 1000000007
long long qpow(long long x,long long y)
{
	long long tmp=1;
	while(y)
	{
		if(y&1) (tmp*=x)%=mod;
		(x*=x)%=mod,y>>=1;
	} return tmp;
}
int main()
{
	int n,m; scanf("%d%d",&n,&m);
	long long ans=(qpow(2,m)-1+mod)%mod;
	printf("%lld\n",qpow(ans,n));
}