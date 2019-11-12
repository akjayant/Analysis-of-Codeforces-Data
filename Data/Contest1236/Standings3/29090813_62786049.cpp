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

int T,a,b,k;

inline void solve(){
	while(T--){
		a=read(),b=read(),k=read();
		int ans=0,x=min(b,k/2);
		ans+=x*3;
		
		k-=x*2,b-=x;
		ans+=min(a,b/2)*3;
		printf("%d\n",ans);
	}
}

inline void Input(){
	T=read();
}

int main(){
	Input();
	solve();
	return 0;
}