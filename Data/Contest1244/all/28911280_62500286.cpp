#include <bits/stdc++.h>
#define N 1000005
#define int long long
using namespace std;
int x,y,n,b,c,d;
int exgcd(int a,int b,int &x,int &y) {
	if(b==0){
		y=0,x=1;
		return a;
	}
	int t=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return t;
}
signed main() {
	scanf("%lld%lld%lld%lld",&n,&b,&c,&d);
	int t=exgcd(c,d,x,y);
	if(b%t){
		puts("-1");
		return 0;
	}
	b/=t,c/=t,d/=t,y=(y%c+c)%c*(b%c)%c,x=(b-y*d)/c;
	if(x<0||x+y>n) {
		puts("-1");
		return 0;
	}
	printf("%lld %lld %lld\n",x,y,n-x-y);
	return 0;
}