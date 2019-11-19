#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;

#define LL long long
#define debug(x) cerr<<#x<<": "<<x<<endl;
#define fgx cerr<<"--------------"<<endl;
#define dgx cerr<<"=============="<<endl;

inline LL read(){
	LL x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const LL INF = 2147483600;
const LL MAXN = 100010;

LL N,P,W,D;
inline LL exgcd(LL a,LL b,LL &x,LL &y){
	if(!b) { x=1; y=0;  return a; }
	LL d=exgcd(b,a%b,y,x); y-=(a/b)*x; return d;
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read(),P=read(),W=read(),D=read();
	swap(W,D); LL X,Y;
	LL d=exgcd(W,D,X,Y);
	if(P%d) { puts("-1"); return 0; }
	LL T=D/d,G=(P/d)%T; X=X*G%T; 
	X=(X%T+T)%T; Y=(P-X*W)/D;
	if(X+Y>N||X<0||Y<0){ puts("-1"); return 0; }
	swap(X,Y);
	cout<<X<<" "<<Y<<" "<<N-X-Y<<endl;
	return 0;
}
