#include <bits/stdc++.h>

#define enter putchar('\n')
#define space putchar(' ')

using namespace std;

inline int read(){
	int x=0;char c=getchar();bool y=1;
	for(;c<'0' || c>'9';c=getchar()) if(c=='-') y=0;
	for(;c>='0' && c<='9';c=getchar()) x=(x<<1)+(x<<3)+c-48;
	if(y) return x;
	return -x;
}

inline int fread(){
	char c=getchar();
	for(;c<'0' || c>'9';c=getchar());
	return (c^48);
}

int T;

int x1,n;

inline void solve(){
	T=read();
	while(T--){
		n=read();
		int ans=n;
		for(int i=1;i<=n;i++){
			x1=fread();
			if(x1==1) ans=max(ans,max(2*i,2*(n-i+1)));
		}
		printf("%d\n",ans);
	}
	return;
}

int main(){
	solve();
	return 0;
}