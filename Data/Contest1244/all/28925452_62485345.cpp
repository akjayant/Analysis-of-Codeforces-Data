#include<bits/stdc++.h>
#define M 100005
using namespace std;
int stk[M],top;
int c[3][M],head[M],nxt[2*M],to[2*M],deg[M],n,mark[M],f[M],col[M],ANS[M];
long long ans,mn;
int cnt;
void Add(int a,int b) {
	to[++cnt]=b;
	nxt[cnt]=head[a];
	head[a]=cnt;
}
void dfs(int u,long long sum,int dep) {
	mark[u]=1;
	int lef=1;
	for(int k=0; k<3; k++) {
		if(k!=col[f[u]]&&k!=col[f[f[u]]]) {
			col[u]=k;
			stk[dep]=u;
			for(int i=head[u]; ~i; i=nxt[i]) {
				int v=to[i];
				if(f[u]==v)continue;
				lef=0;
				f[v]=u;
				dfs(v,sum+c[k][u],dep+1);
			}
		}
	}
	if(lef) {
		for(int k=0; k<3; k++) {
			if(k!=col[f[u]]&&k!=col[f[f[u]]]) {
				col[u]=k;
				stk[dep]=u;
				if(mn>sum+c[k][u]) {
					for(int i=1; i<=dep; i++)ANS[stk[i]]=col[stk[i]];
					mn=sum+c[k][u];
				}
			}
		}
	}
}
int main() {
	memset(head,-1,sizeof(head));
	memset(col,-1,sizeof(col));
	scanf("%d",&n);
	for(int i=0; i<3; i++)
		for(int j=1; j<=n; j++)scanf("%d",&c[i][j]);
	for(int i=1; i<n; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		Add(a,b);
		Add(b,a);
		deg[a]++;
		deg[b]++;
	}
	for(int i=1; i<=n; i++) {
		if(deg[i]==1&&!mark[i])mn=1e18,dfs(i,0,1),ans+=mn;
		else if(deg[i]>2) {
			puts("-1");
			return 0;
		}
	}
	printf("%lld\n",ans);
	for(int i=1; i<=n; i++)printf("%d ",ANS[i]+1);
	puts("");
	return 0;
}
