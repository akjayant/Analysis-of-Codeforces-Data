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

int n,T;

inline void solve(){
	for(int i=1;i<=n;i++)
	{
		T=i;
		for(int j=1;j<=n;j++)
		{
			printf("%d ",(j-1)*n+T);
			T=n-T+1;
		}
		enter;
	}
	return;
}

inline void Input(){
	n=read();
}

int main(){
	Input();
	solve();
	return 0;
}