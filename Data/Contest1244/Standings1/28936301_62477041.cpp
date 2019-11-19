#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,p,d,w;
bool b[200000];
ll gcd(ll x,ll y){
	ll z=x%y;
	while (z){
	x=y;y=z;z=x%y;
	}
	return y;
}
int main(){
	scanf("%lld%lld%lld%lld",&n,&p,&w,&d);
	if (p%gcd(w,d)!=0) {
		puts("-1"); return 0;
	}
	ll x1=p/w;
	while ((p-x1*w)%d!=0&&x1>0&&!b[(p-x1*w)%d]) {
		b[(p-x1*w)%d]=1;
		x1--;
	}
	if (b[(p-x1*w)%d]) puts("-1");
	else
	if (((p-x1*w)%d==0)&&((n-x1-(p-x1*w)/d)>=0)) printf("%lld %lld %lld",x1,(p-x1*w)/d,n-x1-(p-x1*w)/d);
	else puts("-1");
}