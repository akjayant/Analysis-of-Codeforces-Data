#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
const int N=1e5+5;

int l[N],x[N<<1],e[N<<1];
int c[3][N<<1];
int d[N],cl[N];

void pshe(int t,int u,int v){
	x[t]=l[u];l[u]=t;e[t]=v;
}

i64 dfs(int v,int p,int c1,int c2,int c3){
	int i;
	cl[v]=c1;
	for(i=l[v];i;i=x[i])
		if(e[i]!=p)return c[c1-1][v]+dfs(e[i],v,c2,c3,c1);
	return c[c1-1][v];
}

i64 ans=1e17+7;
int ansc[N],n;

void mini(i64 t){
	if(t<ans){
		ans=t;
		for(int i=1;i<=n;i++)
			ansc[i]=cl[i];
	}
}

int main()
{
	int i,j,u,v;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&c[0][i]);
	for(i=1;i<=n;i++)scanf("%d",&c[1][i]);
	for(i=1;i<=n;i++)scanf("%d",&c[2][i]);
	for(i=1;i<n;i++)scanf("%d%d",&u,&v),pshe(i<<1,u,v),pshe(i<<1|1,v,u),++d[u],++d[v];
	for(i=1;i<=n;i++)if(d[i]>2){printf("-1");return 0;}
	for(i=1;i<=n;i++)if(d[i]==1){
		mini(dfs(i,0,1,2,3)),
		mini(dfs(i,0,1,3,2)),
		mini(dfs(i,0,2,1,3)),
		mini(dfs(i,0,2,3,1)),
		mini(dfs(i,0,3,1,2)),
		mini(dfs(i,0,3,2,1));
		printf("%I64d\n",ans);
		for(j=1;j<=n;j++)printf("%d ",ansc[j]);
		return 0;
	}
	return 0;
}