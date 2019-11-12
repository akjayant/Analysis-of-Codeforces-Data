#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define mod 1000000007
LL n,m;
inline LL Pow(LL a,LL b)
{
	LL ret=1;
	while(b)
	{
		if(b&1)
			ret=a*ret%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	LL ans=(Pow(2,m)-1+mod)%mod;
	printf("%lld",Pow(ans,n));
}

