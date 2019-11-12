#include<cstdio>

typedef long long LL;
LL mo=1000000007;
LL qpow(LL a,LL b,LL mo)
{
	LL res=1,Pow=a;
	while(b)
	{
		if(b&1) res=res*Pow%mo;
		Pow=Pow*Pow%mo;
		b>>=1;
	}
	return res;
}
int main()
{
	LL n,m;
	scanf("%lld%lld",&n,&m);
	LL ans=qpow((qpow(2,m,mo)-1+mo)%mo,n,mo);
	printf("%lld\n",ans);
}
