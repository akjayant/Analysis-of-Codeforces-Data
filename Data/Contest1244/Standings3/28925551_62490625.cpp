#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int N=100005;
int n,c[5][N],d[N],L[N],ans[N],b[N];
long long ans_t,b_t;
vector<int> g[N];
void dfs(int x,int fa,int p){
	L[p]=x;
	for(int i=0;i<g[x].size();++i){
		int y=g[x][i];
		if(y==fa)continue;
		dfs(y,x,p+1);
	}
}
void put_(){
	ans_t=b_t;
	for(int i=1;i<=n;++i)ans[i]=b[i];
}
void redfs(int x){
	if(x>n){
		if(b_t<ans_t)put_();
		return;
	}
	if(x==1){
		int u=L[1],v=L[2],w=L[3];
		b[u]=1;b[v]=2;b[w]=3;
		b_t=0ll+c[1][u]+c[2][v]+c[3][w];
		redfs(x+3);
		b[u]=1;b[v]=3;b[w]=2;
		b_t=0ll+c[1][u]+c[3][v]+c[2][w];
		redfs(x+3);
		b[u]=2;b[v]=1;b[w]=3;
		b_t=0ll+c[2][u]+c[1][v]+c[3][w];
		redfs(x+3);
		b[u]=2;b[v]=3;b[w]=1;
		b_t=0ll+c[2][u]+c[3][v]+c[1][w];
		redfs(x+3);
		b[u]=3;b[v]=1;b[w]=2;
		b_t=0ll+c[3][u]+c[1][v]+c[2][w];
		redfs(x+3);
		b[u]=3;b[v]=2;b[w]=1;
		b_t=0ll+c[3][u]+c[2][v]+c[1][w];
		redfs(x+3);
		return;
	}
	int u=L[x],v=L[x-3];
	b[u]=b[v];
	b_t+=c[b[u]][u];
	redfs(x+1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=3;++i)for(int j=1;j<=n;++j)scanf("%d",&c[i][j]);
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		++d[u];++d[v];
		if(d[u]>2 || d[v]>2){puts("-1");return 0;}
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int x;for(x=1;d[x]>1;++x);
	dfs(x,0,1);
	ans_t=1e15;redfs(1);
	cout<<ans_t<<endl;
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}
