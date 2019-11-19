#include<bits/stdc++.h>
typedef long long LL;
const LL maxn=1e6+9;
LL Read(){
	LL x(0),f(1); char c=getchar();
	while(c<'0' || c>'9'){ if(c=='-') f=-1; c=getchar(); }
	while(c>='0' && c<='9'){ x=(x<<3ll)+(x<<1ll)+c-'0'; c=getchar(); } return x*f;
}
LL T,n,m;
struct node{
	LL to,nxt;
}dis[maxn];
LL num;
LL head[maxn];
void Add(LL u,LL v){
	dis[++num]=(node){v,head[u]}; head[u]=num;
}
int main(){
	n=Read();
	LL ans(0);
	for(LL i=2;i*i<=n;++i){
		if(n%i==0){
			if(i!=n) ans=std::__gcd(ans,i);
			if(n/i!=n) ans=std::__gcd(ans,n/i);
		}
	}
	if(!ans) printf("%lld\n",n);
	else printf("%lld\n",ans);
	return 0;
}