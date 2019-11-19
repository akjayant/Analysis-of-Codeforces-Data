#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define M 100005
int A[M][3];
template<class T>bool tomin(T &x,T y){
	if(x>y)return x=y,1;
	return 0;
}
int n;
vector<int>edge[M];
LL dp[M][3][1<<3];
const LL inf=1e17;
struct Node{
	int a,b,c;	
}nxt[M][3][1<<3];
void dfs(int F,int now){
	for(int i=0;i<edge[now].size();i++){
		int to=edge[now][i];
		if(to==F)continue;
		dfs(now,to);	
	}
	for(int i=0;i<3;i++)
		dp[now][i][1<<i]=A[now][i];
	vector<int>Son;
	static LL tmp[3][1<<3];
	static Node Tmp[3][1<<3];
	for(int f=0;f<edge[now].size();f++){
		int to=edge[now][f];
		if(to==F)continue;
		for(int i=0;i<3;i++)
			for(int j=0;j<1<<3;j++)tmp[i][j]=inf;
		for(int i=0;i<3;i++)
			for(int k=0;k<8;k++)if(dp[now][i][k]!=inf)
				for(int j=0;j<3;j++)
					for(int r=0;r<8;r++)if(dp[to][j][r]!=inf){
						if(r&(1<<i))continue;
						if((1<<j)&k)continue;
						if(tomin(tmp[i][k|(1<<j)],dp[now][i][k]+dp[to][j][r]))
							Tmp[i][k|(1<<j)]=(Node){to,j,r};
					}
		for(int i=0;i<3;i++)
			for(int j=0;j<8;j++){
				dp[now][i][j]=tmp[i][j];
				if(tmp[i][j]!=inf)nxt[now][i][j]=Tmp[i][j];
			}
	}
}
int Col[M];
void DFS(int now,int a,int b){
	if((1<<a)==b){
		Col[now]=a+1;
		return;
	}else{
		Node tmp=nxt[now][a][b];
		DFS(tmp.a,tmp.b,tmp.c);
		DFS(now,a,b^(1<<tmp.b));
	}
}
int main(){
	cin>>n;
	for(int i=0;i<3;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&A[j][i]);
	for(int a,b,i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<8;k++)dp[i][j][k]=inf;
	dfs(0,1);
	Node f;
	LL ans=inf;
	for(int i=0;i<3;i++)
		for(int j=0;j<8;j++)if(tomin(ans,dp[1][i][j]))f=(Node){1,i,j};
	if(ans==inf)return puts("-1"),0;
	cout<<ans<<endl;
	DFS(f.a,f.b,f.c);
	for(int i=1;i<=n;i++)printf("%d ",Col[i]);
	return 0;
}