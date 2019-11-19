#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int head[4000005],nex[4000005],vet[4000005],tim,edgenum,n,m;
int dfn[4000005],low[4000005],st[4000005],top,numid,id[4000005];
bool vis[4000005];
int len1,len2,k1[4000005],k2[4000005],du[4000005];
void addedge(int x,int y)
{
	edgenum++,vet[edgenum]=y,nex[edgenum]=head[x],head[x]=edgenum;
}
void tarjan(int u)
{
	dfn[u]=low[u]=++tim,vis[u]=true,st[++top]=u;
	for (int e=head[u];e!=0;e=nex[e])
	{
		int v=vet[e];
		if (!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if (vis[v])low[u]=min(low[u],dfn[v]);
	}
	if (low[u]==dfn[u])
	{
		numid++;
		while (1)
		{
			vis[st[top]]=false,id[st[top]]=numid;
			if (st[top--]==u) break;
		}
	}
}

void print(int x)
{
	if (numid==1) {printf("No\n");return;}
	len1=len2=0;
	for (int i=1;i<=n;i++)
		if (id[i]!=x) k1[++len1]=i;
		else k2[++len2]=i;
	printf("Yes\n");
	printf("%d %d\n",len1,len2);
	for (int i=1;i<=len1;i++) printf("%d ",k1[i]);
	printf("\n");
	for (int i=1;i<=len2;i++) printf("%d ",k2[i]);
	printf("\n");
}
void solve()
{
	numid=top=edgenum=tim=0;
	for (int i=0;i<=n+n;i++)
		dfn[i]=low[i]=head[i]=st[i]=id[i]=du[i]=vis[i]=0;
	scanf("%d%d",&n,&m);
	for (int i=1,x,y;i<=m;i++)
		scanf("%d%d",&x,&y),addedge(x,y);
	for (int i=1;i<=n;i++)
		if (!dfn[i]) tarjan(i);
	for (int i=1;i<=n;i++)
		for (int j=head[i];j!=0;j=nex[j])
			if (id[vet[j]]!=id[i]) du[id[vet[j]]]++;
	for (int i=1;i<=numid;i++)
		if (du[i]==0) {print(i);break;}
}
int main()
{
	int cas;scanf("%d",&cas);
	while (cas--) solve();
	return 0;
}