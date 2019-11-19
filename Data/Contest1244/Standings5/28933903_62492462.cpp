//by Judge
#include<bits/stdc++.h>
#define Rg register
#define fp(i,a,b) for(Rg int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(Rg int i=(a),I=(b)-1;i>I;--i)
#define go(u) for(Rg int i=head[u],v=e[i].to;i;v=e[i=e[i].nxt].to)
#define ll long long
using namespace std;
const int M=2e5+3;
typedef int arr[M];
#ifndef Judge
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
char buf[1<<21],*p1=buf,*p2=buf;
inline int read(){ int x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0'; return x*f;
} char sr[1<<21],z[20];int CCF=-1,Z;
inline void Ot(){fwrite(sr,1,CCF+1,stdout),CCF=-1;}
inline void print(ll x,char chr='\n'){
	if(CCF>1<<20)Ot();if(x<0)sr[++CCF]=45,x=-x;
	while(z[++Z]=x%10+48,x/=10);
	while(sr[++CCF]=z[Z],--Z);sr[++CCF]=chr;
} int n,root,p[4],ans[4]; arr du,pp,a[4];
ll tmp,val=1e18,cnt;
int pat,head[M];
struct Edge{ int to,nxt; }e[M<<1];
inline void add(int u,int v){
	e[++pat]={v,head[u]},head[u]=pat,++du[v];
	e[++pat]={u,head[v]},head[v]=pat,++du[u];
}
void dfs(int u,int fa){
	tmp+=a[p[(cnt-1)%3+1]][u],++cnt;
	go(u) if(v^fa) dfs(v,u);
}
void calc(int u,int fa){
	pp[u]=ans[p[(cnt-1)%3+1]],++cnt;
	go(u) if(v^fa) calc(v,u);
}
int main(){ n=read();
	fp(j,1,3) fp(i,1,n) a[j][i]=read();
	fp(i,2,n){ Rg int x=read(),y=read();
		add(x,y); if(du[x]>2) return !printf("-1\n");
		if(du[y]>2) return !printf("-1\n");
	}
	fp(i,1,n) if(du[i]==1){
		root=i; break;
	}
	fp(i,1,3) p[i]=i;
	do{
		tmp=0,cnt=1,dfs(root,0);
		if(tmp<val){ val=tmp;
			fp(i,1,3) ans[i]=p[i];
		}
	}while(next_permutation(p+1,p+4));
	print(val),cnt=1,calc(root,0);
	fp(i,1,n) print(pp[i],' '); return Ot(),0;
}