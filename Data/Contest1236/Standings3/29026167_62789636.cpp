#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long A(long long x,long long y)
{
	long long z=1;
	while(y)
	{
		if(y&1)
		z=z*x%mod;
		x=x*x%mod;
		y=y>>1;
	}
	return z;
}
int main()
{
	long long x,y;
	scanf("%lld%lld",&x,&y);
	printf("%lld",A(A(2,y)-1,x));
	return 0;
}