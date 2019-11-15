#include<bits/stdc++.h>
typedef int LL;
const LL maxn=1e6+9;
LL Read(){
	LL x(0),f(1); char c=getchar();
	while(c<'0' || c>'9'){ if(c=='-') f=-1; c=getchar(); }
	while(c>='0' && c<='9'){ x=(x<<3)+(x<<1)+c-'0'; c=getchar(); } return x*f;
}
LL T,n,m;
struct node{
	LL to,nxt;
}dis[maxn];
LL num;
LL head[maxn],a[maxn];
void Add(LL u,LL v){
	dis[++num]=(node){v,head[u]}; head[u]=num;
}
int main(){
	T=Read();
	while(T--){
		n=Read(); for(LL i=1;i<=n;++i) a[i]=Read();
		std::sort(a+1,a+1+n);
		LL ans(0);
		for(LL i=1;i<=n;++i){
//			if(n-i+1>=a[i]) 
			ans=std::max(ans,std::min(a[i],n-i+1));
		}
		printf("%d\n",ans);
	}
	return 0;
}