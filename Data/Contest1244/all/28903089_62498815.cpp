#include <bits/stdc++.h>

using namespace std;

#define int long long
#define reg register
#define clr(a,b) memset(a,b,sizeof a)
#define Mod(x) (x>=mod)&&(x-=mod)
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define abs(a) ((a)<0?-(a):(a))
#define debug2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define debug3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define rep(a,b,c) for(reg int a=(b),a##_end_=(c); a<=a##_end_; ++a)
#define ret(a,b,c) for(reg int a=(b),a##_end_=(c); a<a##_end_; ++a)
#define drep(a,b,c) for(reg int a=(b),a##_end_=(c); a>=a##_end_; --a)
#define erep(i,G,x) for(int i=(G).Head[x]; i; i=(G).Nxt[i])
#pragma GCC optimize(2)

inline int Read(void) {
	int res=0,f=1;
	char c;
	while(c=getchar(),c<48||c>57)if(c=='-')f=0;
	do res=(res<<3)+(res<<1)+(c^48);
	while(c=getchar(),c>=48&&c<=57);
	return f?res:-res;
}

template<class T>inline bool Min(T &a, T const&b) {
	return a>b?a=b,1:0;
}
template<class T>inline bool Max(T &a, T const&b) {
	return a<b?a=b,1:0;
}
const int N=1e5+5,M=1e5+5,mod=2147483648;

bool MOP1;

int a,b,c;

int exgcd(int a,int b,int &x,int &y) {
	if(!b) {
		y=0,x=1;
		return a;
	}
	int Now=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return Now;
}

bool MOP2;
/*
4 13 16 3
*/
inline void _main() {
	//  cerr<<"M="<<(&MOP2-&MOP1)/1024.0/1024.0<<endl;
	int x,y,v,a=Read(),b=Read(),c=Read(),d=Read();
	int t=exgcd(c,d,x,y);
	if(b%t) {
		puts("-1");
		return;
	}
	b/=t,c/=t,d/=t,y=(y%c+c)%c*(b%c)%c,x=(b-y*d)/c;
	if(x<0||x+y>a) {
		puts("-1");
		return;
	}
	cout<<x<<" "<<y<<" "<<a-x-y;
}

signed main() {
	//  freopen("star.in", "r", stdin);
	//  freopen("star.out", "w", stdout);
	_main();
	//  fclose(stdin),fclose(stdout);
	return 0;
}