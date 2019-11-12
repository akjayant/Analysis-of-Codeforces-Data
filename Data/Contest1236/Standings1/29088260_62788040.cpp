#include<cstdio>
typedef long long Int;
const Int mod=1000000007;
inline Int pow(Int a,int p)
{
	Int s=1;
	while(p)
	{
		if(p&1)
			s=s*a%mod;
		a=a*a%mod,p>>=1;
	}
	return s;
}
int main()
{
	Int n,m;
	scanf("%I64d%I64d",&n,&m);
	printf("%I64d\n",pow(pow(2,m)-1,n));
	return 0;
}