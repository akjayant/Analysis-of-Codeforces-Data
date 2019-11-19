#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=100005;
int n,st;
int c[N][3],col[N];
LL tot[5][5];
vector<int>G[N];
void Dfs(int u,int fa,int dep) {
	col[u]=dep%3;
	for(int k=0;k<3;k++)
		tot[dep%3][k]+=c[u][k];
	for(int i=0;i<(int)G[u].size();i++) {
		int v=G[u][i];
		if(v==fa) continue;
		Dfs(v,u,dep+1);
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&c[i][0]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i][1]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i][2]);
	for(int i=1,u,v;i<n;i++) {
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		if(G[i].size()>2) {
			printf("-1\n");
			return 0;
		}
		else if(G[i].size()==1)
			st=i;
	Dfs(st,st,0);
	int ti=-1,tj=-1,tk=-1;
	LL ans=1e16+233;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++) {
			if(i==j) continue;
			for(int k=0;k<3;k++) {
				if(i==k||j==k) continue;
				if(tot[0][i]+tot[1][j]+tot[2][k]<ans) {
					ans=tot[0][i]+tot[1][j]+tot[2][k];
					ti=i; tj=j; tk=k;
				}
			}
		}
	printf("%lld\n",ans);
	for(int i=1;i<n;i++) {
		if(col[i]==0) printf("%d ",ti+1);
		else if(col[i]==1) printf("%d ",tj+1);
		else if(col[i]==2) printf("%d ",tk+1);
	}
	if(col[n]==0) printf("%d\n",ti+1);
	else if(col[n]==1) printf("%d\n",tj+1);
	else if(col[n]==2) printf("%d\n",tk+1);
	return 0;
}