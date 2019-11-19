#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

struct edge
{
	long long x,y,z;
};

long long n,i,j,S,tot,ans,x,y;
long long a[10005][2],c[10005],k[10005];
edge list[10000005];
long long fa[100050];
long long cho[100005];
long long ans1[100005],ans2[100005][2],SS;

long long getfather(long long x)
{
	if (fa[x]==x) return x;
	return fa[x]=getfather(fa[x]);
}

long long dis(long long x,long long y)
{
	return abs(a[x][0]-a[y][0])+abs(a[x][1]-a[y][1]);
}

void insert(long long x,long long y,long long z)
{
	tot++;
	list[tot].x=x;list[tot].y=y;list[tot].z=z;
}

int comp(edge a,edge b)
{
	return a.z<b.z;
}

int main()
{
	//freopen("read.in","r",stdin);
	scanf("%lld",&n);
	S=n+1;
	for (i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i][0],&a[i][1]);
		fa[i]=i;
	}
	fa[S]=S;
	for (i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	for (i=1;i<=n;i++)
		scanf("%lld",&k[i]);
	for (i=1;i<=n;i++)
	{
		insert(S,i,c[i]);
		for (j=i+1;j<=n;j++)
		{
			insert(i,j,(k[i]+k[j])*dis(i,j));
		}
	}
	sort(list+1,list+1+tot,comp);
	for (i=1;i<=tot;i++)
	{
		x=list[i].x;
		y=list[i].y;
		if (getfather(x)!=getfather(y))
		{
			cho[++cho[0]]=i;
			fa[getfather(x)]=getfather(y);
		}
	}
	for (i=1;i<=cho[0];i++)
	{
		if (list[cho[i]].x==S)
		{
			ans1[++ans1[0]]=list[cho[i]].y;
			ans+=list[cho[i]].z;
		}
		else
		{
			SS++;
			ans2[SS][0]=list[cho[i]].x;
			ans2[SS][1]=list[cho[i]].y;
			ans+=list[cho[i]].z;
		}
	}
	printf("%lld\n",ans);
	printf("%lld\n",ans1[0]);
	for (i=1;i<=ans1[0];i++)
	{
		printf("%lld ",ans1[i]);
	}
	printf("\n");
	printf("%lld\n",SS);
	for (i=1;i<=SS;i++)
	{
		printf("%lld %lld\n",ans2[i][0],ans2[i][1]);
	}
}