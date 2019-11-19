#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+100;
const ll INF=1e15;
struct edge{
	int s,e,net;
}ed[N<<1];
int n,tot,start,num,anss;
ll sum,minn=INF;
int head[N],val[10][N],in[N],a[N],color[N];
int ans[10][10];
bool mark[10];
inline void dfs_color(int x,int fa,int y,int dep)
{
	color[x]=ans[y][dep%3];
	for (int i=head[x];i;i=ed[i].net)
	if (ed[i].e!=fa) dfs_color(ed[i].e,x,y,dep+1);
	return ;
}
inline void dfs(int x,int fa,int y,int dep)
{
	sum=sum+val[ans[y][dep%3]][x];
	for (int i=head[x];i;i=ed[i].net)
	if (ed[i].e!=fa) dfs(ed[i].e,x,y,dep+1);
	return ;
}
inline void dfs_ans(int x)
{
	if (x==4)
	{
		++num;
		for (int i=1;i<=3;i++)
		ans[num][i-1]=a[i];
		return ;
	}
	for (int i=1;i<=3;i++)
	if (!mark[i])
	{
		a[x]=i;
		mark[i]=1;
		dfs_ans(x+1);
		mark[i]=0;
	}
	return ;
}
inline void add(int s,int e)
{
	ed[++tot]=(edge){s,e,head[s]};
	in[s]++;
	head[s]=tot;
	return ;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=3;i++)
	for (int j=1;j<=n;j++)
	scanf("%d",&val[i][j]);
	for (int i=1;i<=n-1;i++)
	{
		int s,e;
		scanf("%d%d",&s,&e);
		add(s,e);add(e,s);
	}
	for (int i=1;i<=n;i++)
	if (in[i]>2)
	{
		printf("-1\n");
		return 0;
	}
	else if (in[i]==1) start=i;
	dfs_ans(1);
	for (int i=1;i<=6;i++)
	{
		sum=0;
		dfs(start,0,i,0);
		if (sum<minn)
		{
			minn=sum;
			anss=i;
		}
	}
	printf("%lld\n",minn);
	dfs_color(start,0,anss,0);
	for (int i=1;i<=n;i++)
	printf("%d ",color[i]);
	return 0;
}
