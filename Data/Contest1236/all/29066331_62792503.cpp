#include<cstdio>
using namespace std;
const long long mod=1e9+7;
long long Qpow(long long x,long long y)
{
	long long ans=1;
	x%=mod;
	while(y)
	{
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
long long n,m;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	long long k=Qpow(2,m);
	k-=1;
	printf("%I64d",Qpow(k,n));
}