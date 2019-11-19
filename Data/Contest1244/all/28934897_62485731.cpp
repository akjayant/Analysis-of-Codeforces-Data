//ѹ�пδ�
#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
LL n,p,w,d;
LL read(){LL sss=0,fff=1;char ccc;ccc=getchar();while(ccc<'0'||ccc>'9'){if(ccc=='-')fff=-1;ccc=getchar();}while(ccc>='0'&&ccc<='9')sss=(sss<<1)+(sss<<3)+(ccc^'0'),ccc=getchar();return sss*fff;}
template<typename T> inline void write(T x){if(!x) return;write(x/10);putchar((x%10)+'0');}
template<typename T> inline void wri(T x){write(x);puts("");}
//LL exgcd(LL x,LL y,LL &P,LL &Q)
//{
//	if(y==0){P=1;Q=0;return x;}
//	LL r=exgcd(y,x%y,Q,P);
//	Q-=x/y*P;
//	return r;
//}
void solve()
{
	for(LL i=0;i<=w;i++)
		if((p-i*d)%w==0)
		{
			LL x=(p-i*d)/w,y=i;
			if(x<0) break;
			if(x+y<=n)
			{
				printf("%lld %lld %lld\n",x,y,n-x-y);
				return;
			}
		}
	printf("-1\n");
}
int main()
{
//	freopen("123.in","r",stdin);
//	freopen("123.out","w",stdout);
	n=read();p=read();w=read();d=read();
	solve();
	
	/*LL P,Q,r=exgcd(w,d,P,Q);
	if(p%r!=0)
	{
		printf("-1\n");
		return 0;
	}
	LL kd=p/r,cg=w*d/__gcd(w,d);
	P*=kd;Q*=kd;
	if(P>=0&&Q>=0&&P+Q<=n)
	{
		printf("%lld %lld %lld\n",P,Q,n-P-Q);
		return 0;
	}
	LL derta=(cg/d)-(cg/w),KKD;
//	printf("%lld %lld\n",P,Q);
//	printf("%lld %lld\n",(cg/d),(cg/w));
	KKD=((P+Q-n)/derta);
//	printf("%lld %lld\n",derta,KKD);
	P=P+KKD*(cg/w);Q=Q-KKD*(cg/d);
	if(P<0)
	{
		LL PDP=(-P)/(cg/w);
		P=P+PDP*(cg/w);Q=Q-PDP*(cg/d);
		if(P<0) P=P+(cg/w),Q=Q-(cg/d);
	}
	if(Q<0)
	{
		LL QDQ=(-Q)/(cg/d);
		P=P-QDQ*(cg/w);Q=Q+QDQ*(cg/d);
		if(Q<0) P=P-(cg/w),Q=Q+(cg/d);
	}
//	printf("%lld %lld\n",P,Q);
	if(P>=0&&Q>=0&&P+Q<=n)
	{
		printf("%lld %lld %lld\n",P,Q,n-P-Q);
		return 0;
	}
	P=P+(cg/w);Q=Q-(cg/d);
	if(P>=0&&Q>=0&&P+Q<=n)
	{
		printf("%lld %lld %lld\n",P,Q,n-P-Q);
		return 0;
	}
	P=P+(cg/w);Q=Q-(cg/d);
	if(P>=0&&Q>=0&&P+Q<=n)
	{
		printf("%lld %lld %lld\n",P,Q,n-P-Q);
		return 0;
	}
	P=P-2*(cg/w);Q=Q+2*(cg/d);
	
	P=P-(cg/w);Q=Q+(cg/d);
	if(P>=0&&Q>=0&&P+Q<=n)
	{
		printf("%lld %lld %lld\n",P,Q,n-P-Q);
		return 0;
	}
	P=P-(cg/w);Q=Q+(cg/d);
	if(P>=0&&Q>=0&&P+Q<=n)
	{
		printf("%lld %lld %lld\n",P,Q,n-P-Q);
		return 0;
	}
	printf("-1\n");*/
	return 0;
}
