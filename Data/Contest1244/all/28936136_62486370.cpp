#include <bits/stdc++.h>
using namespace std;
const int N=100008;
const long long MAX=1e9+7;
struct Edge
{
	int nxt,to;
}edge[200008];
int a[N][3],ecnt,num[N],n,c[N],r[N],cnt,head[N],col[N];
long long ans,tmp;
bool flag=false;
void add(int x,int y)
{
	edge[++ecnt]=(Edge){head[x],y};
	head[x]=ecnt;
	r[x]++;
	if(r[x]>2)flag=true;
}
void dfs(int x,int fa)
{
	num[++cnt]=x;
	for(int p=head[x];p;p=edge[p].nxt)
	{
		int u=edge[p].to;
		if(u!=fa)dfs(u,x);
	}
}
void check()
{
	for(int i=3;i<=n;i++)
		for(int j=0;j<3;j++)
			if((c[num[i-1]]!=j)&&(c[num[i-2]]!=j))
				c[num[i]]=j,tmp+=a[num[i]][j];
	if(tmp<ans)
	{
		ans=tmp;
		for(int i=1;i<=n;i++)
			col[i]=c[i];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i][0]);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i][1]);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i][2]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	if(flag)return puts("-1"),0;
	for(int i=1;i<=n;i++)
		if(r[i]==1){dfs(i,0);break;}
	if(n==1)printf("%lld\n",min(a[1][0],min(a[1][1],a[1][2])));
	else
	{
		ans=1ll*n*MAX;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
			if(i!=j)
			{
				c[num[1]]=i; c[num[2]]=j;
				tmp=1ll*(a[num[1]][i]+a[num[2]][j]);
				check();
			}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)
			printf("%d ",col[i]+1);
		printf("\n");
	}
	return 0;
}