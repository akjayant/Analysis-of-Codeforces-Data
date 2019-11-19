#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
LL read(){
	LL f=0,x=0;char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=1;c=getchar();}
	while('0'<=c&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?-x:x;
}
#define MAXN 100000
#define INF 0x3f3f3f3f
LL Exgcd(LL a,LL b,LL &x,LL &y){
	if(!b){x=1,y=0;return a;}
	LL g=Exgcd(b,a%b,y,x);
	y-=a/b*x;
	return g;
}
int main(){
	LL n=read(),p=read(),w=read(),d=read(),x,y,g=Exgcd(w,d,x,y);
	if(p%g!=0){
		puts("-1");
		return 0;
	}
	LL tmp=(p/g)%(w/g);
	y%=(w/g);
	y=(y*tmp%(w/g)+w/g)%(w/g);
	x=(p-y*d)/w;
	if(y>n||x>n||x+y>n||x<0){
		puts("-1");
		return 0;
	}
	printf("%lld %lld %lld\n",x,y,n-x-y);
	return 0;
}
