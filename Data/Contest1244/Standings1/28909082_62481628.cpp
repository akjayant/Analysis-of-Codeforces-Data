#include<bits/stdc++.h>
#define gc getchar
#define re register
#define rep(i,s,t) for(re int i=s;i<=t;++i)
#define reb(i,s,t) for(re int i=s;i>=t;--i)

template<class T>inline void Readin(T &X){
	X=0;
	register bool F=false;
	register char C=gc();
	while(C<'0' or C>'9'){if(C=='-')F=true;C=gc();}
	while(C<='9' and C>='0')X=(X<<1)+(X<<3)+(C&15),C=gc();
	if(F)X=-X;
}
template<class T>inline void Prt(T X){
	if(X<0)putchar('-'),X=-X;
	if(X>9)Prt(X/10);
	putchar(X%10+'0');
}

using namespace std;
typedef long long ll;

const int N=1e5+5;
int n,c[4][N],cnt_edge,head[N],deg[N],rk[N],ac[4],col[N];
ll Ans;
struct Edge{
	int nxt,to;
}e[N<<1];

inline void add_edge(int u,int v){e[++cnt_edge].to=v,e[cnt_edge].nxt=head[u],head[u]=cnt_edge;}
inline void dfs(int cur,int fa){
	re int dest;
	rk[++rk[0]]=cur;
	for(re int i=head[cur];i;i=e[i].nxt){
		dest=e[i].to;
		if(dest==fa)continue;
		dfs(dest,cur);
	}
}
int main(){
	Readin(n);
	rep(k,1,3)rep(i,1,n)Readin(c[k][i]);
	re int u,v;
	rep(i,2,n){
		Readin(u),Readin(v);
		++deg[u],++deg[v];
		if(deg[u]>2||deg[v]>2)return not printf("-1");
		add_edge(u,v),add_edge(v,u);
	}
	rep(i,1,n)if(deg[i]==1){dfs(i,0);break;}
	Ans=1e18;
	int a[4];
	bool vis[4];
	ll Cur;
	rep(k1,1,3)rep(k2,1,3){
		if(k1==k2)continue;
		a[1]=k1,a[2]=k2;
		Cur=0;
		memset(vis,0,sizeof vis);
		vis[k1]=vis[k2]=1;
		rep(i,1,3)if(!vis[i]){a[3]=i;break;}
		for(re int i=1,j=1;i<=n;++i,++j){
			if(j>3)j=1;
			Cur+=c[a[j]][rk[i]];
		}
		if(Ans>Cur){
			ac[1]=a[1];
			ac[2]=a[2];
			ac[3]=a[3];
			Ans=Cur;
		}
	}
	printf("%I64d\n",Ans);
	for(re int i=1,j=1;i<=n;++i,++j){
		if(j>3)j=1;
		col[rk[i]]=ac[j];
	}
	rep(i,1,n)printf("%d ",col[i]);
	return 0;
}
