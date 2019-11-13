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
LL head[maxn];
void Add(LL u,LL v){
	dis[++num]=(node){v,head[u]}; head[u]=num;
}
char s[maxn],t[maxn];
int main(){
	T=Read();
	while(T--){
		n=Read();
		scanf(" %s %s",s+1,t+1);
		LL cnt(0),f1(1),pre(0);
		for(LL i=1;i<=n;++i){
			if(s[i]!=t[i]){
				if(cnt==2){
					f1=0;
				}
				if(cnt){
//					printf("(%c,%d)(%c,%c)\n",s[pre],t[i],t[pre],s[i]);
					if(s[pre]!=s[i] || t[pre]!=t[i]) f1=0;
				}
				pre=i;
				++cnt;
			}
//			printf("%d ",f1);
		}
		if(cnt==1 || cnt>2) f1=0;
		if(f1) puts("Yes");
		else puts("No");
	}
	return 0;
}