#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N=2086;
int flag[N*N];
int fa[N];
struct node
{
	int u,v;
	long long len;
	node(int uu,int vv,long long ww)
	{
		u=uu;
		v=vv;
		len=ww;
	}
	node()
	{
		
	}
	bool operator < (const node & rhs)const
	{
		return len<rhs.len;
	}
};
node ed[N*N];
long long sum;
int n,m;
int cnt;
int tot;
int zx[N];
int zy[N];
int fe[N];
int co[N];
int bu[N];
vector <int> zo;
int find(int x)
{
	if(x==fa[x])
		return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&zx[i],&zy[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&fe[i]);
		ed[++tot]=node(0,i,1ll*fe[i]);
		zo.push_back(tot);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&co[i]);
		fa[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ed[++tot]=node(i,j,1ll*(co[i]+co[j])*(abs(zx[i]-zx[j])+abs(zy[i]-zy[j])));
		}
	}
	sort(ed+1,ed+tot+1);
	int cs=0;
	for(int i=1;i<=tot;i++)
	{
		int x=find(ed[i].u);
		int y=find(ed[i].v);
		if(x!=y)
		{
			fa[x]=y;
			cnt++;
			sum+=ed[i].len;
			flag[i]=1;
			if(ed[i].u==0)
			{
				cs++;
				bu[ed[i].v]=1;
			}
		}
		if(cnt>=n)
			break;
	}
	printf("%lld\n",sum);
	printf("%d\n",cs);
	int first=1;
	for(int i=0;i<n;i++)
	{
		if(bu[i+1])
		{
			if(first)
			{
				first=0;
			}
			else
				printf(" ");
			printf("%d",i+1);
		}
	}
	printf("\n%d\n",n-cs);
	for(int i=1;i<=tot;i++)
	{
		if(flag[i]&&ed[i].u!=0)
		{
			printf("%d %d\n",ed[i].u,ed[i].v);
		}
	}
	return 0;
}
