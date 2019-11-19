#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 1000005
#define INF 0x3f3f3f3f
int a[N],mx1[N],mx2[N];
bool f[N];
char s[N];
int n,m;
inline int X()
{
	for(int i=0;i<=n+1;i++)
		mx1[i]=mx2[i]=INF;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==')')
			a[i]=a[i-1]-1;
		else
			a[i]=a[i-1]+1;
		mx1[i]=min(mx1[i-1],a[i]);
	}
	for(int i=n;i>=1;i--)
		mx2[i]=min(mx2[i+1],a[i]);
	int ret=0;
	if(mx1[n]>=0&&a[n]==0)
		ret++;
	for(int i=1;i<n;i++)
		if(mx2[i+1]-a[i]>=0&&mx1[i]+a[n]-a[i]>=0&&a[n]==0)
			ret++;
	return ret;
}
int main()
{
	int T=1;
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		int x1=1,y1=1;
		int ans=X();
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(s[i]!=s[j])
				{
					swap(s[i],s[j]);
					int ml=X();
					if(ml>ans)
						ans=ml,x1=i,y1=j;
					swap(s[i],s[j]);
				}
		printf("%d\n%d %d\n",ans,x1,y1);
	}
}
