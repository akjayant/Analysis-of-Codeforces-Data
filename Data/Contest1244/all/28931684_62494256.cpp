#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int n,x,y,flg,pos,ti;
ll a[3][maxn],tmp[6];
ll ans=0x3f3f3f3f3f3f3f3f;
int degree[maxn];
int b[6][maxn],p[6][3]={0,1,2,0,2,1,1,0,2,1,2,0,2,0,1,2,1,0};
bool vis[maxn];
vector<int>G[maxn];
void dfs(int now,int num){
	vis[now]=1;
	for(int i=0;i<6;i++){
		tmp[i]+=a[p[i][num]][now];
		b[i][now]=p[i][num]+1;
	}
	for(int i=0;i<G[now].size();i++){
		if(!vis[G[now][i]]){	
			dfs(G[now][i],(num+1)%3);
		}
	}
}
int main(){
	//ios::sync_with_stdio(false);
	scanf("%d",&n);
	for(int i=0;i<3;i++)
		for(int j=1;j<=n;j++)
			scanf("%I64d",&a[i][j]);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
		degree[x]++;
		degree[y]++;
		if(degree[x]>2||degree[y]>2)
			flg=1;
	}
	if(flg)
		printf("-1");
	else{
		for(int i=1;i<=n;i++){
			if(degree[i]==1){
				pos=i;
				break;
			}
		}
		dfs(pos,0);
		for(int i=0;i<6;i++){
			if(tmp[i]<ans){
				ans=tmp[i];
				ti=i;
			}
		}
		printf("%I64d\n%",ans);
		for(int i=1;i<=n;i++)
			printf("%d ",b[ti][i]);
	}
	return 0;
}
