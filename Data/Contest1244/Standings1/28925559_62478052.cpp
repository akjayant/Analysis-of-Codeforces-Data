#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,g,base;
long long e,x,y,o,tmp,fo;
long long cnt;
long long gcd(long long a,long long b) {
	return b?gcd(b,a%b):a;
}
void Ex_gcd(long long a,long long b,long long& x,long long& y) {
	if(!b) {
		x=1,y=0;
		return ;
	}
	Ex_gcd(b,a%b,y,x);
	y-=a/b*x;
}
int main() {
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	g=gcd(d,c);
	if(b%g)return puts("-1"),0;
	b/=g,c/=g,d/=g;
	if(d!=1) {
		e=b/(c*d);
		b-=e*c*d,base=e*d;
		Ex_gcd(c,d,x,y);
		x=(x%d+d)%d;//c*x%d==1
		o=x*c/d;
		tmp=b/d;
		fo=(b%d)*x+base;
		tmp-=(b%d)*o;
	} else {
		fo=b/c;
		tmp=b%c;
	}
//	printf("ka_Bar %lld %lld %lld %lld",x,o,fo,tmp);
	if(tmp<0) {
		cnt=(-tmp)/c;
		tmp+=(cnt+1)*c;
		fo-=(cnt+1)*d;
	}
	cnt=tmp/c;
	tmp-=cnt*c;
	fo+=cnt*d;
	if(fo<0||fo+tmp>a) puts("-1");
	else printf("%lld %lld %lld\n",fo,tmp,a-fo-tmp);
	return 0;
}
