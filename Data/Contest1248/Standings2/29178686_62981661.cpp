#include<bits/stdc++.h>
typedef long long LL;
const LL maxn=1e6+9;
inline LL Read(){
	LL x(0),f(1); char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1; c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<3)+(x<<1)+c-'0'; c=getchar();
	}return x*f;
}
LL n,ans1,ans2;
LL a[maxn];
int main(){
	n=Read();
	for(LL i=1;i<=n;++i) a[i]=Read();
	std::sort(a+1,a+1+n);
	LL N1=n/2,N2=n-N1;
	for(LL i=1;i<=N1;++i) ans1+=a[i];
	for(LL i=N1+1;i<=n;++i) ans2+=a[i];
	printf("%lld\n",ans1*ans1+ans2*ans2);
	return 0;
}