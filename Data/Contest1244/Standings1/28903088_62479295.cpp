#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
void exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
int main(){
	ll n,p,w,d;//x*w+y*d=p     x+y+z=n
	int fl=0;
	scanf("%lld%lld%lld%lld",&n,&p,&w,&d);
	if(w>d)swap(w,d),fl=1;
	ll u=(p%d+d)%d;
	ll G=gcd(w,d),c=u/G,x,y,k=d/G;
	if(u%G){
		puts("-1");
		return 0;
	}
	exgcd(w,d,x,y);
	x=(x%d+d)%d;
	x=x*c%k;
	y=(x*w/d);
	ll now=(p-x*w-y*d);
	if(now<0)puts("-1");
	else {
		y+=now/d;
		if(fl)swap(x,y);
		if(x+y>n)puts("-1");
		else printf("%lld %lld %lld\n",x,y,n-x-y);
	}
	return 0;
}