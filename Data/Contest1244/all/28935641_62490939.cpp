#include <bits/stdc++.h>
using namespace std;
long long ans=1e18;
int c[100010][5],n,p,col[100010],Ans[100010];
vector<int> e[100010];
void dfsi(int u,int fa){
	if(e[u].size()>2){puts("-1");exit(0);}
	if(e[u].size()==1) p=u;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v==fa) continue;
		dfsi(v,u);
	}
}
void dfs(int u,int fa,int cf,int cff){
	for(int i=1;i<=3;i++) if(i!=cf&&i!=cff) col[u]=i;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v==fa) continue;
		dfs(v,u,col[u],cf);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&c[i][1]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i][2]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i][3]);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfsi(1,0);
	for(int c1=1;c1<=3;c1++)
		for(int c2=1;c2<=3;c2++){
			if(c1==c2) continue;
			dfs(p,0,c1,c2);
			long long tmp=0;
			for(int i=1;i<=n;i++)
				tmp+=c[i][col[i]];
			if(ans>tmp){
				ans=tmp;
				for(int i=1;i<=n;i++)
					Ans[i]=col[i];
			}
		}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++) printf("%d ",Ans[i]);
}