#include<bits/stdc++.h>
using namespace std;
long long n,p,w,d,x,y;
long long exgcd(long long a,long long b,long long &x,long long &y){
	if(!b){x=1,y=0;return a;}
	long long d=exgcd(b,a%b,y,x);
	y-=a/b*x;return d;
}
int main(){
	scanf("%lld%lld%lld%lld",&n,&p,&w,&d);
	long long gcd=exgcd(w,d,x,y);
	if(p%gcd){puts("-1");return 0;}
	y%=w/gcd;
	y=((p/gcd%(w/gcd)*y)%(w/gcd)+(w/gcd))%(w/gcd);
	x=(p-y*d)/w;
	if(x>=0&&y>=0&&x+y<=n)printf("%lld %lld %lld\n",x,y,n-x-y);
	else puts("-1");
	return 0;
}