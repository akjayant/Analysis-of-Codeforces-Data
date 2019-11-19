#include<bits/stdc++.h>
using namespace std;
typedef long long giant;
template<typename T> inline T& Min(T &x,const T &y) {return y<x?(x=y):x;}
template<typename T> inline T& Max(T &x,const T &y) {return x<y?(x=y):x;}
inline giant read() {
	giant x=0,f=1;
	char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const int maxn=1e5+10;
int n,cnt[maxn],c;
giant k,a[maxn],w[maxn];
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif
	n=read(),k=read();
	for (int i=1;i<=n;++i) w[i]=a[i]=read();
	sort(w+1,w+n+1),c=unique(w+1,w+n+1)-w-1;
	for (int i=1;i<=n;++i) ++cnt[lower_bound(w+1,w+c+1,a[i])-w];
	int L=1,R=c;
	while (L<R) {
		giant mi=min(cnt[L],cnt[R]);
		if (mi>k) break;
		giant s=k/mi; // able
		if (mi==cnt[L]) {
			giant dif=w[L+1]-w[L];
			giant tr=min(dif,s);
			k-=tr*mi;
			if (dif<=s) cnt[++L]+=mi; else w[L]+=s;
		} else if (mi==cnt[R]) {
			giant dif=w[R]-w[R-1];
			giant tr=min(dif,s);
			k-=tr*mi;
			if (dif<=s) cnt[--R]+=mi; else w[R]-=s;
		}
	}
	printf("%lld\n",w[R]-w[L]);
	return 0;
}
