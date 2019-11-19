#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const long long maxn=10000+50;

struct edge
{
	long long from,to,w;
} 	g[2010*2010];

long long ans,gn,n;
long long father[maxn];

long long Abs(long long x)
{
	if(x<=0) return -x;
	return x;
}

struct city
{
	long long x,y,c,k;
}	ct[maxn];

void add(long long a,long long b,long long c)
{
	gn++;g[gn].to=b;g[gn].from=a;g[gn].w=c;
	gn++;g[gn].to=a,g[gn].from=b;g[gn].w=c;
}

bool cmp(edge a,edge b)
{
	return a.w<b.w;
}

long long getfather(long long x)
{
	if(father[x]==x)
		return x;
	else
 		return father[x]=getfather(father[x]);
}
int main()
{
	long long n;
	cin>>n;

	for(long long i=1;i<=n;i++) cin>>ct[i].x>>ct[i].y;
	for(long long i=1;i<=n;i++) cin>>ct[i].c;
	for(long long i=1;i<=n;i++) cin>>ct[i].k;
	
	for(long long i=1;i<=n;i++)
	{
		add(i,n+1,ct[i].c);
		for(long long j=i+1;j<=n;j++) 
			add(i,j, (ct[i].k+ct[j].k)*  ( Abs(ct[i].x-ct[j].x) + Abs(ct[i].y-ct[j].y) ));
	}
	n++;
	sort(g+1,g+gn+1,cmp);
	for(long long i=1;i<=n;i++)
		father[i]=i;
	
	int ee[maxn]={0},cnt=0;
	
	for(long long i=1;i<=n*n;i++)
		{
			long long p=g[i].from;long long v=g[i].to;
				if(getfather(p)!=getfather(v))
					{
						ans+=g[i].w;
						ee[++cnt] = i;
						father[getfather(p)]=getfather(v);
					}
		}
		
	cout<<ans<<endl;
	int e1[maxn]={0},cnt1=0;
	int e2[maxn]={0},cnt2=0;
	for(int i=1;i<=cnt;i++)
	{
		int p =g[ee[i]].from,v=g[ee[i]].to;
		if(p==n || v==n) ee[i]=0;
		if(p==n ) e1[++cnt1]=v;
		else if(v==n) e1[++cnt1]=p;
	}
	
	cout<<cnt1<<endl;
	for(int i=1;i<=cnt1;i++) cout<<e1[i]<<' ';cout<<endl;
	cout<<cnt-cnt1<<endl;
	for(int i=1;i<=cnt;i++)
	{
		int p =g[ee[i]].from,v=g[ee[i]].to;
		if(ee[i]!=0) cout<<p<<' '<<v<<endl;
	}
	
	return 0;
}