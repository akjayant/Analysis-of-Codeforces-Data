#include<bits/stdc++.h>
#define maxl 2010

using namespace std;

int n,m,cnt,tot,cnt1,cnt2;
int k[maxl],c[maxl],f[maxl],ans1[maxl];
long long ans;
long long dis[maxl][maxl];
struct node
{
	int x,y;
}a[maxl],ans2[maxl*maxl];
char s[maxl];
struct ed
{
	int u,v;
	long long w;
}e[maxl*maxl];


inline void prework()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&k[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			dis[i][j]=abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
			e[++cnt]=ed{i,j,dis[i][j]*(k[i]+k[j])};	
		}
}

inline int find(int x)
{
	if(f[x]!=x)
		f[x]=find(f[x]);
	return f[x];
}

inline bool cmp(const ed &a,const ed &b)
{
	return a.w<b.w;
}

inline void mainwork()
{
	for(int i=1;i<=n;i++)	
		f[i]=i;	
	sort(e+1,e+1+cnt,cmp);
	int x,y;
	long long tmp=0;
	for(int i=1;i<=n;i++)
		tmp+=c[i];
	ans=tmp;
	for(int i=1;i<=cnt;i++)
	{
		x=find(e[i].u);y=find(e[i].v);
		if(x==y)
			continue;
		if(max(c[x],c[y])>e[i].w)
		{
			tmp=tmp-max(c[x],c[y])+e[i].w;
			ans2[++cnt2]=node{e[i].u,e[i].v};
			if(c[x]<c[y])
				f[y]=x;
			else
				f[x]=y;
		}
		ans=min(tmp,ans);
	}
}

inline void print()
{
	for(int i=1;i<=n;i++)
	if(find(i)==i)
		ans1[++cnt1]=i;
	printf("%lld\n",ans);
	printf("%d\n",cnt1);
	for(int i=1;i<=cnt1;i++)
		printf("%d%c",ans1[i],(i==cnt1)?'\n':' ');
	printf("%d\n",cnt2);
	for(int i=1;i<=cnt2;i++)
		printf("%d %d\n",ans2[i].x,ans2[i].y);
}

int main()
{
	int t=1;
	//scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{ 
		prework();
		mainwork();
		print();
	}
	return 0;
}
