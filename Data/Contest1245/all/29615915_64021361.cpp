#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <utility>
#define MAXN 2005
#define MAXM 5000005
using namespace std;
typedef long long ll;
ll g[MAXN][MAXN];
int x[MAXN],y[MAXN],c[MAXN],k[MAXN];
inline int abso(const int& x){return x<0? -x:x;}
typedef pair<ll,int> pi;
pi dis[MAXN];
bool vis[MAXN];
int main()
{
	memset(g,0x3f,sizeof(g));
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1;i<=n;i++) scanf("%d",&k[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			g[i][j]=g[j][i]=(ll)(k[i]+k[j])*(abso(x[i]-x[j])+abso(y[i]-y[j]));
	for (int i=1;i<=n;i++) g[i][n+1]=g[n+1][i]=c[i];
	memset(dis,0x3f,sizeof(dis));
	dis[n+1]=make_pair(0,0);
	int cnt=0;
	ll sum=0;
	while (cnt<n+1)
	{
		int now=0;
		for (int i=1;i<=n+1;i++)
			if (!vis[i]&&dis[i]<dis[now])
				now=i;
		sum+=dis[now].first;
		vis[now]=true;++cnt;
		for (int i=1;i<=n+1;i++)
			if (!vis[i])
				dis[i]=min(dis[i],make_pair(g[now][i],now));
	}
	cout<<sum<<'\n';
	cnt=0;
	for (int i=1;i<=n;i++) cnt+=(dis[i].second==n+1);
	printf("%d\n",cnt);
	for (int i=1;i<=n;i++) if (dis[i].second==n+1) printf("%d ",i);
	puts("");
	cnt=0;
	for (int i=1;i<=n;i++) cnt+=(dis[i].second<n+1);
	printf("%d\n",cnt);
	for (int i=1;i<=n;i++)
		if (dis[i].second<n+1)
			printf("%d %d\n",i,dis[i].second);
	return 0;
}
