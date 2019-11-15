//ѹ�пδ�
#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,m,mod=1e9+7;
int read(){int sss=0,fff=1;char ccc;ccc=getchar();while(ccc<'0'||ccc>'9'){if(ccc=='-')fff=-1;ccc=getchar();}while(ccc>='0'&&ccc<='9')sss=(sss<<1)+(sss<<3)+(ccc^'0'),ccc=getchar();return sss*fff;}
int R(){char ccc=getchar();while(ccc<'0'||ccc>'9') ccc=getchar();return ccc-'0';}
LL ksm(LL base,LL k)
{
	LL sum=1;
	while(k)
	{
		if(k&1) sum=sum*base%mod;
		base=base*base%mod;
		k>>=1;
	}
	return (sum%mod+mod)%mod;
}
int main()
{
//	freopen("123.in","r",stdin);
//	freopen("123.out","w",stdout);
	n=read();m=read();
	LL ans=ksm(ksm(2,m)-1,n);
	printf("%lld\n",ans);
	return 0;
}
