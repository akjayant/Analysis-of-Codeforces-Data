#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge
{
	int u,v,w,ans;
}e[5000001];
bool cmp(edge a,edge b){return a.w<b.w;}
int edge_cnt;
int fa[1000001];
int find(int x){return (fa[x]==x)?fa[x]:fa[x]=find(fa[x]);}
int kruskal()
{
	int ans=0;
	for(int i=1;i<=edge_cnt;i++)
	{
		int u=e[i].u,v=e[i].v;
		if(find(u)!=find(v))
		{
			fa[find(u)]=find(v);
			e[i].ans=1;
			ans+=e[i].w;
		}
	}
	return ans;
}
void add(int u,int v,int w)
{
	e[++edge_cnt].u=u;
	e[edge_cnt].v=v;
	e[edge_cnt].w=w;
}
int x[1000001],y[1000001],k[1000001];
int dis(int a,int b){return abs(x[a]-x[b])+abs(y[a]-y[b]);}
signed main() 
{
	int n;
	scanf("%I64d",&n);
	for(int i=0;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
		scanf("%I64d%I64d",&x[i],&y[i]);
	for(int i=1;i<=n;i++)
	{
		int c;
		scanf("%I64d",&c);
		add(i,0,c);
	}
	for(int i=1;i<=n;i++)
		scanf("%I64d",&k[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			add(i,j,dis(i,j)*(k[i]+k[j]));
	sort(e+1,e+edge_cnt+1,cmp);
	printf("%I64d\n",kruskal());
	int tot=0,sum=0;
	for(int i=1;i<=edge_cnt;i++)
		if(e[i].v==0&&e[i].ans==1)
			sum++;
	printf("%I64d\n",sum);
	for(int i=1;i<=edge_cnt;i++)
		if(e[i].v==0&&e[i].ans==1)
		{
			printf("%I64d ",e[i].u);
		}
		else if(e[i].ans==1)
			tot++;
	printf("\n");
	printf("%I64d\n",tot);
	for(int i=1;i<=edge_cnt;i++)
		if(e[i].ans==1&&e[i].v!=0)
			printf("%I64d %I64d\n",e[i].u,e[i].v);
	return 0;
}
