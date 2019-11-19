#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#define int long long
using namespace std;
const int maxn = 1e5+10;
const int inf = 1e15;

int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	return x*f;
}

int to[maxn<<1],net[maxn<<1],h[maxn],e=1;
inline void add(int x,int y){
	to[++e]=y;net[e]=h[x];h[x]=e;
}

int k,m,n;
int cost[4][maxn],deg[maxn],v[maxn],anss[maxn],ans=inf,summ,x1,x2;
void dfs(int x,int c1,int c2,int sum){
	int flag=1;
	for(register int i=h[x];i;i=net[i]){
		int y=to[i];
		if(v[y])continue;
		v[y]=1;
		for(register int c=1;c<=3;c++){
			if(c==c1 || c==c2)continue;
			dfs(y,c,c1,sum+cost[c][y]);
		}
		flag=0;
	}	
	if(flag==1)summ=sum;
	return ;
}

void dfs2(int x,int c1,int c2){
	anss[x]=c1;
	for(register int i=h[x];i;i=net[i]){
		int y=to[i];
		if(v[y])continue;
		v[y]=1;
		for(register int c=1;c<=3;c++){
			if(c==c1 || c==c2)continue;
			dfs2(y,c,c1);
		}
	}
	return;
}

signed main(){
	n=read();
	for(register int i=1;i<=3;i++)
		for(register int j=1;j<=n;j++)
			cost[i][j]=read();
	for(register int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y);add(y,x);
		deg[x]++;deg[y]++;
	}
	for(register int i=1;i<=n;i++){
		if(deg[i]>2){puts("-1");return 0;}
	}
	for(register int i=1;i<=n;i++){
		if(deg[i]==1){
			for(register int u=h[i];u;u=net[u]){
				int y=to[u];
				for(register int c=1;c<=3;c++){
					for(register int c2=1;c2<=3;c2++){
						if(c==c2)continue;
						memset(v,0,sizeof(v));
						v[i]=v[y]=1;
						dfs(y,c2,c,cost[c][i]+cost[c2][y]);
						if(ans>summ){
							ans=summ;
							x1=c;x2=c2;
						}
					}
				}
				printf("%lld\n",ans);
				memset(v,0,sizeof(v));
				v[i]=v[y]=1;
				anss[i]=x1;anss[y]=x2;
				dfs2(y,x2,x1);
				for(register int now=1;now<=n;now++)printf("%lld ",anss[now]);
				return 0;
			}
		}
	}
	return 0;
}