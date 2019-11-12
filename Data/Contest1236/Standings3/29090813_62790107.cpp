#include <bits/stdc++.h>

#define enter putchar('\n')
#define space putchar(' ')
#define int long long

using namespace std;

const int mod=1000000007;

int n,m;

inline int Pow(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return ans;
}

inline int read(){
	int x=0;char c=getchar();bool y=1;
	for(;c<'0' || c>'9';c=getchar()) if(c=='-') y=0;
	for(;c>='0' && c<='9';c=getchar()) x=(x<<1)+(x<<3)+c-48;
	if(y) return x;
	return -x;
}

inline void solve(){
	printf("%I64d\n",Pow(Pow(2,m)-1,n));
}

inline void Input(){
	n=read(),m=read();
}

signed main(){
	Input();
	solve();
	return 0;
}