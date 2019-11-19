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
const int maxn=1005;
int n,a[maxn];
char s[maxn];
int work() {
	n=read();
	scanf("%s",s+1);
	for (int i=1;i<=n;++i) a[i]=s[i]-'0';
	int ans=n;
	for (int i=1;i<=n;++i) if (a[i]) {
		Max(ans,max(2*i,2*(n-i+1)));
	}
	return ans;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif
	for (int T=read();T--;) printf("%d\n",work());
	return 0;
}
