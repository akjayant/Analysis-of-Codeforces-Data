#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int mo=1e9+7;

LL qpow(LL a,LL b)
{
	LL ans=1;
	a%=mo;
	while(b)
	{
		if(b&1)
			ans=ans*a%mo;
		b>>=1;
		a=a*a%mo;
	}
	return ans;
}


const int maxn=2005;

struct node
{
	int x,y;
}a[maxn];

int fa[maxn];

struct edge
{
	int idx,idy;
	LL w;
	bool operator<(const edge&_)const
	{
		return w<_.w;
	}
}p[maxn*maxn+maxn];

int find_father(int x)
{
	if(x== fa[x])
		return x;
	return fa[x]=find_father(fa[x]);
}

int c[maxn];
int k[maxn];

vector<int>pid;
vector<node>pedge;

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<=n;i++)
		fa[i]=i;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for(i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&k[i]);
	int j;
	int cnt=0;
	for(i=1;i<=n;i++)
	{
		p[cnt++]={0,i,c[i]};
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		{
			p[cnt++]={i,j,(LL)(k[i]+k[j])*(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y))};
		}
	sort(p,p+cnt);
	int num=0;
	int x,y;
	LL ans=0;
	for(i=0;i<cnt;i++)
	{
		x=find_father(p[i].idx);
		y=find_father(p[i].idy);
		if(x==y)	
			continue;
		if(x<y)
		{
			fa[y]=x;
			ans+=p[i].w;
			if(p[i].idx==0)
			{
				pid.push_back(p[i].idy);
			}
			else
			{
				pedge.push_back({p[i].idx,p[i].idy});
			}
		}
		else
		{
			fa[x]=y;
			ans+=p[i].w;
			if(p[i].idy==0)
			{
				pid.push_back(p[i].idx);
			}
			else
			{
				pedge.push_back({p[i].idx,p[i].idy});
			}
		}
		num++;
		if(num>n)
			break;
	}
	printf("%lld\n",ans);
	printf("%d\n",(int)pid.size());
	for(i=0;i<pid.size();i++)
	{
		if(i +1 == pid.size())
		{
			printf("%d\n",pid[i]);
		}
		else
			printf("%d ",pid[i]);
	}
	printf("%d\n",(int)pedge.size());
	for(i=0;i<pedge.size();i++)
	{

			printf("%d %d\n",pedge[i].x,pedge[i].y);

	}
	
	return 0;
}