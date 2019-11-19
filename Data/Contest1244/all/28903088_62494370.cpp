#include<bits/stdc++.h>
#define M 100006
using namespace std;
int A[3][M],deg[M],Ans[M],S[M],son[M][3];
long long dp[4][4][M];
void dfs(int x,int fa) {
	if(fa&&deg[x]==1) {
		dp[0][3][x]=A[0][x];
		dp[1][3][x]=A[1][x];
		dp[2][3][x]=A[2][x];
		return;
	}
	int y;
	for(int i=1; i<=son[x][0]; i++) {
		y=son[x][i];
		if(y==fa)continue;
		dfs(y,x);
		break;
	}
	S[x]=y;
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(i==j)continue;
			for(int u=0; u<4; u++) {
				if(i==u||j==u)continue;
				dp[i][j][x]=min(dp[i][j][x],dp[j][u][y]+A[i][x]);
			}
		}
	}
}
void Ranse(int x,int fa,int col,int lacol,long long now) {
	Ans[x]=col;
	for(int j=0; j<4; j++) {
		if(j==lacol)continue;
		if(dp[col][j][x]==now) {
			Ranse(S[x],x,j,col,now-A[col][x]);
			return;
		}
	}
}
int main() {
	memset(dp,32,sizeof(dp));
	int n,u,v;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d",&A[0][i]);
	for(int i=1; i<=n; i++)scanf("%d",&A[1][i]);
	for(int i=1; i<=n; i++)scanf("%d",&A[2][i]);
	for(int i=1; i<n; i++) {
		scanf("%d%d",&u,&v);
		deg[u]++,deg[v]++;
		if(deg[u]>2||deg[v]>2) {
			puts("-1");
			return 0;
		}
		son[u][++son[u][0]]=v;
		son[v][++son[v][0]]=u;
	}
	int st=0;
	for(int i=1; i<=n; i++)if(deg[i]==1) {
			st=i;
			break;
		}
	dfs(st,0);
	long long ans=1e18;
	int col=0;
	for(int i=0; i<4; i++)for(int j=0; j<4; j++)
		if(dp[i][j][st]<ans)ans=dp[i][j][st],col=i;
	printf("%lld\n",ans);
	Ranse(st,0,col,3,ans);
	for(int i=1; i<=n; i++)printf("%d ",Ans[i]+1);
	return 0;
}