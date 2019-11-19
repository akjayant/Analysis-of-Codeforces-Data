#include<bits/stdc++.h>
#define N 100005
#define int long long
using namespace std;
int n,m,cost[N][3],fa[N];
vector<int>a[N];
bool bo=1;
void dfs(int x,int f){
	fa[x]=f;
	if(!bo)return;
	if(a[x].size()>=3){bo=0;return;}
	for(int i=0;i<(int)a[x].size();i++){
		int y=a[x][i];
		if(y==f)continue;
		dfs(y,x);
	}
}
int col[N],res,ans=1e18;
void dfs1(int x){
	int f1=fa[x],f2=fa[fa[x]];
	col[x]=3-col[f1]-col[f2];
	res+=cost[x][col[x]];
	for(int i=0;i<(int)a[x].size();i++){
		int y=a[x][i];
		if(y==fa[x])continue;
		dfs1(y);
	}
}
int col1[N];
void Copy(){
	for(int i=1;i<=n;i++)col1[i]=col[i]+1;
}
void solve1(){
	int x=a[1][0];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		if(i!=j){
			res=cost[1][i]+cost[x][j];
			col[1]=i,col[x]=j;
			for(int k=0;k<(int)a[x].size();k++){
				int y=a[x][k];
				if(y==1)continue;
				dfs1(y);
			}
			if(res<ans){
				ans=res;
				Copy();
			}
		}
	printf("%lld\n",ans);
	for(int i=1;i<n;i++)printf("%lld ",col1[i]);printf("%lld\n",col1[n]);
}
void solve2(){
	int x1=0,x2=0;
	for(int i=0;i<(int)a[1].size();i++){
		int x=a[1][i];
		if(x1==0)x1=x;
		else if(x2==0)x2=x;
	}
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)if(i!=j)
			for(int k=0;k<3;k++)if(i!=k&&j!=k){
				res=cost[1][i]+cost[x1][j]+cost[x2][k];
				col[1]=i,col[x1]=j,col[x2]=k;
				for(int l=0;l<(int)a[x1].size();l++){
					int y=a[x1][l];
					if(y==1)continue;
					dfs1(y);
				}
				for(int l=0;l<(int)a[x2].size();l++){
					int y=a[x2][l];
					if(y==1)continue;
					dfs1(y);
				}
				if(res<ans){
					ans=res;
					Copy();
				}
			}
	printf("%lld\n",ans);
	for(int i=1;i<n;i++)printf("%lld ",col1[i]);printf("%lld\n",col1[n]);
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&cost[i][0]);
	for(int i=1;i<=n;i++)scanf("%lld",&cost[i][1]);
	for(int i=1;i<=n;i++)scanf("%lld",&cost[i][2]);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1,0);
	if(!bo){puts("-1");return 0;}
	if(a[1].size()==1)solve1();
	else solve2();
	return 0;
}