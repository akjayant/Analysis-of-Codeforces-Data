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

int T,a,b,c,d,k;

inline void solve(){
	T=read();
	while(T--){
		a=read(),b=read(),c=read(),d=read(),k=read();
		bool flag=0;
		for(int i=0;i<=k;i++){
			if(c*i>=a && d*(k-i)>=b)
			{printf("%d %d\n",i,k-i);flag=1;break;}
		}
		if(!flag)
		puts("-1");
	}
	return;
}

int main(){
	solve();
	return 0;
}