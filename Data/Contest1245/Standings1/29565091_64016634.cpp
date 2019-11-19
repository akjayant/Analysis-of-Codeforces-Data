#include<bits/stdc++.h>
using namespace std;
#define next Next
#define gc getchar
#define int long long
/*char buf[1<<21],*p1=buf,*p2=buf;
inline int gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}*/
inline int read()
{
    int ret=0,f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c)){ret=ret*10+c-48;c=gc();}
    if(f)return -ret;return ret;
}
const int N=2005;
int n,m,gs,ans,fa[N],a[N],x[N],y[N],g[N][N],dis[N];
struct node{
	int x,y,z;
}A[N*N];
vector<int>xu;
vector<node>jia;
bool cmp(node a,node b)
{
	return a.z<b.z;
}
int find(int x)
{
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		x[i]=read();y[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		g[i][n+1]=read();
		g[n+1][i]=g[i][n+1];
	}
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			g[i][j]=(abs(x[i]-x[j])+abs(y[i]-y[j]))*(a[i]+a[j]);
	n++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			A[++gs].x=i;A[gs].y=j;A[gs].z=g[i][j];
		}
	sort(A+1,A+gs+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=gs;i++)
	{
		int x=find(A[i].x),y=find(A[i].y);
		if(x!=y)
		{
			fa[x]=y;
			ans+=A[i].z;
			if(A[i].y==n)xu.push_back(A[i].x);
			else jia.push_back(A[i]);
		}
	}
	cout<<ans<<endl;
	cout<<xu.size()<<endl;
	for(int i=0;i<xu.size();i++)printf("%lld ",xu[i]);
	puts("");
	cout<<jia.size()<<endl;
	for(int i=0;i<jia.size();i++)printf("%lld %lld\n",jia[i].x,jia[i].y);
}