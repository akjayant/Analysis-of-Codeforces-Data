#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[2001],y[2001],k[2001];
int dis[2001],pre[2001];
bool vis[2001];
inline int calc(int a,int b)
{
	return (k[a]+k[b])*(abs(x[a]-x[b])+abs(y[a]-y[b]));
}
bool fst[2001];
signed main()
{
	int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld %lld",&x[i],&y[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&dis[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&k[i]);
	memset(vis,false,sizeof(vis));
	memset(pre,0,sizeof(pre));
	int ans=0,fstcnt=0;
	for(int i=1;i<=n;i++)
	{
		int p=-1;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&(p==-1||dis[j]<dis[p]))
				p=j;
		vis[p]=true;
		ans+=dis[p];
		if(!pre[p])
			fstcnt++;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&dis[j]>calc(p,j))
			{
				dis[j]=calc(p,j);
				pre[j]=p;
			}
	}
	printf("%lld\n",ans);
	printf("%lld\n",fstcnt);
	for(int i=1;i<=n;i++)
		if(!pre[i])
			printf("%lld ",i);
	printf("\n%lld\n",n-fstcnt);
	for(int i=1;i<=n;i++)
		if(pre[i])
			printf("%lld %lld\n",pre[i],i);
	if(n!=fstcnt)
		putchar('\n');
	return 0;
}