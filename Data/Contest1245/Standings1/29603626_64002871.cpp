#include <bits/stdc++.h>
using namespace std;
const int N=2005;
#define ll long long
ll e[N][N],cost[N];
int last[N];
int x[N],y[N],c[N],k[N];
bool vis[N];
int dist(int i,int j){
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
vector <pair<int,int>> edge;
int main (){
	int n;scanf ("%d",&n);
	for (int i=1;i<=n;i++) scanf ("%d%d",&x[i],&y[i]);
	for (int i=1;i<=n;i++) scanf ("%d",&c[i]);
	for (int i=1;i<=n;i++) scanf ("%d",&k[i]);
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++)
			e[i][j]=1ll<<50ll;
	for (int i=0;i<=n;i++) cost[i]=1ll<<50ll;
	for (int i=1;i<=n;i++) e[0][i]=e[i][0]=c[i];
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			e[i][j]=e[j][i]=1ll*dist(i,j)*(k[i]+k[j]);
	vis[1]=true;
	cost[0]=0;
	for (int i=1;i<=n;i++) cost[i]=e[0][i];
	ll ans=0;
	for (int i=0;i<n;i++){
		int to,l;ll mn=1ll<<50ll;
		for (int j=0;j<=n;j++)
			if (cost[j]&&cost[j]<mn)
				mn=cost[j],to=j,l=last[j];
		cost[to]=0,ans+=mn;
		if (l!=0) edge.push_back(make_pair(to,l));
		for (int j=1;j<=n;j++)
			if (cost[j]>e[to][j]) cost[j]=e[to][j],last[j]=to;
	}
	printf ("%I64d\n",ans);int t=0;
	for (int i=1;i<=n;i++) t+=(last[i]==0);
	printf ("%d\n",t);
	for (int i=1;i<=n;i++) if (!last[i]) printf ("%d ",i);puts("");
	printf ("%d\n",n-t);
	for (int i=0;i<edge.size();i++) printf ("%d %d\n",edge[i].first,edge[i].second);
	return 0;
}