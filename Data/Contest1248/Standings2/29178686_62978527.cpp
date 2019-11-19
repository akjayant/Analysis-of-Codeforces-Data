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
LL T;
LL cnt1[2],cnt2[2];
int main(){
	T=Read();
	while(T--){
		LL n(Read()),m;
		cnt1[0]=cnt1[1]=cnt2[0]=cnt2[1]=0;
		for(LL i=1;i<=n;++i){
			LL x(Read()%2); cnt1[x]++;
		}
		m=Read();
		for(LL i=1;i<=m;++i){
			LL x(Read()%2); cnt2[x]++;
		}
		printf("%lld\n",cnt1[0]*cnt2[0]+cnt1[1]*cnt2[1]);
	}
	return 0;
}