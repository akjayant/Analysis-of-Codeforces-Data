#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define reg register
#define clr(a,b) memset(a,b,sizeof a)
#define Mod(x) (x>=mod)&&(x-=mod)
#define abs(a) ((a)<0?-(a):(a))
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define debug2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define debug3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define rep(a,b,c) for(reg int a=(b),a##_end_=(c); a<=a##_end_; ++a)
#define ret(a,b,c) for(reg int a=(b),a##_end_=(c); a<a##_end_; ++a)
#define drep(a,b,c) for(reg int a=(b),a##_end_=(c); a>=a##_end_; --a)
#define erep(i,G,x) for(int i=(G).Head[x]; i; i=(G).Nxt[i])
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(3,"Ofast","inline")

inline int Read(void) {
	int res = 0, f = 1;
	char c;
	while (c = getchar(), c < 48 || c > 57)if (c == '-')f = 0;
	do res = (res << 3) + (res << 1) + (c ^ 48);
	while (c = getchar(), c >= 48 && c <= 57);
	return f ? res : -res;
}

template<class T>inline bool Min(T &a, T const&b) {
	return a > b ? a = b, 1 : 0;
}
template<class T>inline bool Max(T &a, T const&b) {
	return a < b ? a = b, 1 : 0;
}

const int N=3e2+5,M=1e4+5,K=10,mod=1e9+7,INF=2e9;

bool MOP1;

bool MOP2;

void _main(void) {
//	cerr<<"M="<<(&MOP2-&MOP1)/1024.0/1024.0<<endl;
	int T=Read();
	while(T--) {
		int a=Read(),b=Read(),c=Read(),d=Read(),k=Read();
		int x=(a+c-1)/c,y=(b+d-1)/d;
		if(x+y>k)puts("-1");
		else printf("%d %d\n",x,y);
	}
}

signed main() {
//	freopen("1.in", "r", stdin);
//    freopen(".out", "w", stdout);
	_main();
	return 0;
}