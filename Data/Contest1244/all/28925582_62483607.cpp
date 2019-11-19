#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x,y;
ll gcd(ll a,ll b){
	if(b==0){
		x=1,y=0;
		return a;
	}ll w=gcd(b,a%b),t=x;
	x=y,y=t-a/b*y;
	return w;
}
int main(){
	ll n,p,w,d,ans1=0,ans2=0,ans3=0;
	scanf("%lld%lld%lld%lld",&n,&p,&w,&d);
	ll mx=w*d/gcd(w,d);ans1=p/mx*(mx/w);p%=mx;
	ll t=gcd(d,w),tp=w/t;
	if(p%t){
		puts("-1");
		return 0;
	}
	x=(x%tp)*((p/t)%tp);x=(x%tp+tp)%tp;y=(p-x*d)/w;
	ans1+=y;ans2=x;ans3=n-ans1-ans2;
	if(ans1<0||ans2<0||ans3<0)puts("-1");
	else printf("%lld %lld %lld",ans1,ans2,ans3);
}