#include<bits/stdc++.h>
typedef int LL;
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
LL n,m,ans,L,R;
LL sum[maxn];
char s[maxn],t[maxn];
inline void Check(LL l,LL r){
	LL ret(0);
	for(LL i=1;i<=n;++i){
		sum[i]=sum[i-1];
		if(s[i]=='(') sum[i]+=1;
		else sum[i]+=-1;
		ret=std::min(ret,sum[i]);
	}
	if(sum[n]!=0) return;
	LL x(1),nw(0);
//	if(l==10 && r==10) printf("%lld ",ret);
	if(ret<0)
	    for(LL i=n;i>=1;--i){
	    	nw+=(s[i]=='('?1:-1);
		    if(nw==-ret){
		    	x=i; ret=0; break;
			}
	    }
//	if(l==10 && r==10)printf("%lld ",x);
	if(ret) return;
//	if(x){
LL tot(0);
	for(LL i=x;i<=n;++i) t[++tot]=s[i];
	for(LL i=1;i<x;++i) t[++tot]=s[i];
	LL tmp(0);
	for(LL i=1;i<=n;++i){
		sum[i]=sum[i-1];
		if(t[i]=='(') sum[i]+=1;
		else sum[i]+=-1;
//		ret=std::min(ret,sum[i]);
		if(sum[i]==0) ++tmp;
		if(sum[i]<0) return;
	}
	if(tmp>=ans){
		ans=tmp; L=l; R=r;
	}
//	}
}
int main(){
	n=Read();
	scanf(" %s",s+1);
	for(LL i=1;i<=n;++i){
		for(LL j=i;j<=n;++j){
			std::swap(s[i],s[j]);
			Check(i,j);
			std::swap(s[i],s[j]);
		}
	}
	if(!ans) printf("0\n1 1");
	else printf("%d\n%d %d",ans,L,R);
	return 0;
}