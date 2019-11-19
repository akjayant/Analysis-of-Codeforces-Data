#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<set>
#include<unordered_map>
#include<vector>
typedef long long ll;
using namespace std;
#define N 100010
int n;
ll f[4][N];
int seq[N],tot;
int col[N];
vector<int>G[N];
void dfs(int p,int f){
	int i;
	seq[++tot]=p;
	for(auto v:G[p]){
		if(v==f)continue;
		dfs(v,p);
	}
}
int res[N],op[N],deg[N];
int main(){
	int i,u,v;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&f[1][i]);
	for(i=1;i<=n;i++)scanf("%d",&f[2][i]);
	for(i=1;i<=n;i++)scanf("%d",&f[3][i]);
	for(i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		deg[u]++;
		deg[v]++;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int root=1;
	for(i=1;i<=n;i++){
		if(deg[i]>2)return printf("-1"),0;
		if(deg[i]==1)root=i;
	}
	ll ret=1e18;
	dfs(root,0);
	for(col[1]=1;col[1]<4;col[1]++){
		for(col[2]=1;col[2]<4;col[2]++){
			if(col[1]==col[2])continue;
			for(col[3]=1;col[3]<4;col[3]++){
				if(col[1]==col[3]||col[2]==col[3])continue;
				ll ans=f[col[1]][seq[1]]+f[col[2]][seq[2]]+f[col[3]][seq[3]];
				for(i=4;i<=n;i++){
					col[i]=6-col[i-1]-col[i-2];
					ans+=f[col[i]][seq[i]];
				}
				if(ans<ret){
					ret=ans;
					memcpy(res,col,sizeof(res));
				}
			}
		}
	}
	printf("%lld\n",ret);
	for(i=1;i<=n;i++)op[seq[i]]=res[i];
	for(i=1;i<=n;i++)printf("%d ",op[i]);
	return 0;
}