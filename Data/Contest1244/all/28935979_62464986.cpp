#include<bits/stdc++.h>
using namespace std;
typedef long long giant;
template<typename T> inline T& Min(T &x,const T &y) {return y<x?(x=y):x;}
template<typename T> inline T& Max(T &x,const T &y) {return x<y?(x=y):x;}
inline int read() {
	int x=0,f=1;
	char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
void work() {
	int a=read(),b=read(),c=read(),d=read(),k=read();
	int x=(a+c-1)/c,y=(b+d-1)/d;
	if (x+y>k) {
		puts("-1");
		return;
	}
	printf("%d %d\n",x,y);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif
	for (int T=read();T--;) work();
	return 0;
}
