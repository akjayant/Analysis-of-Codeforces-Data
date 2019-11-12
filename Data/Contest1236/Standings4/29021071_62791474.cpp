#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7;

long long n,m;

long long qpow(long long x,long long y)
{
	long long ans=1;
	for(;y;y=y>>1)
	{
		if(y&1) ans=ans*x%mo;
		x=x*x%mo;
	}
	return ans%mo;
}

int main()
{
	scanf("%lld%lld",&n,&m);
	printf("%lld",qpow((qpow(2,m)-1+mo)%mo,n));
	return 0;
}
