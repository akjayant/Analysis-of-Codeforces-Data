#include<bits/stdc++.h>
#define M 100005
#define LL long long
using namespace std;
int n;
int C[4][M];
struct edge{
	int to,fr;
}E[M<<1];
int lst[M],tote,deg[M];
void addedge(int a,int b){
	E[++tote]=(edge){b,lst[a]};
	lst[a]=tote;
	deg[b]++;
}
LL mn=2e18;
int ans[M];
LL val;
int clo[M];
void dfs(int v,int f,int c1,int c2){
	for(int i=lst[v];i;i=E[i].fr){
		int u=E[i].to;
		if(u==f)continue;
		for(int q=0;q<3;q++)
			if(q!=c1&&q!=c2){
				clo[u]=q;
				val+=C[q][u];
				dfs(u,v,c2,q);
				break;	
			}
	}
}
int main(){
	scanf("%d",&n);
	for(int q=0;q<3;q++)for(int i=1;i<=n;i++)scanf("%d",&C[q][i]);
	int s,t;
	for(int i=1,a,b;i<n;i++){
		scanf("%d%d",&a,&b);
		addedge(a,b);
		addedge(b,a);
	}
	if(n==1){
		for(int i=0;i<3;i++)mn=min(mn,1LL*C[i][1]);
		printf("%lld\n",mn);
		return 0;
	}
	for(int i=1;i<=n;i++)if(deg[i]>=3){
		puts("-1");return 0;
	}else if(deg[i]==1)s=i;
	t=E[lst[s]].to;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(i!=j){
				clo[s]=i,clo[t]=j;
				val=C[i][s]+C[j][t];
				dfs(t,s,i,j);
				if(val<mn){
					memcpy(ans,clo,sizeof(int)*(n+1));
					mn=val;
				}
			}
	cout<<mn<<endl;
	for(int i=1;i<=n;i++)printf("%d ",ans[i]+1);puts("");
	return 0;
}