#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<vector>
#include<utility>
#include<cmath>
using namespace std;

typedef long long LL;
int p[5];
int c1[100005];
int c2[100005];
int c3[100005];
LL ans[5][5];
int a[600005],tl[600005],nx[600005],ln;
int q[100005],tail;
int cnt[100005];
int c[100005];
int used[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&c1[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c2[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c3[i]);
	for(int i=1;i<=n;i++) tl[i]=++ln;
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		cnt[x]++,cnt[y]++;
		a[tl[x]=nx[tl[x]]=++ln]=y;
		a[tl[y]=nx[tl[y]]=++ln]=x;
	}
	int st=0;
	for(int i=1;i<=n;i++) 
	{
		if(cnt[i]>2) return !printf("-1");
		if(cnt[i]==1) st=i;
	}
	int now=st,lnow=0;
	q[++tail]=st;
	used[st]=true;
	while(now)
	{
		lnow=0;
		for(int i=nx[now];i;i=nx[i])
		{
			if(used[a[i]]) continue;
			used[a[i]]=true;
			q[++tail]=a[i];
			lnow=now=a[i];
		}
		now=lnow;
	}
	long long Ans=0xfffffffffffffff;
	for(int i=1;i<=n;i+=3) ans[1][1]+=c1[q[i]];
	for(int i=1;i<=n;i+=3) ans[1][2]+=c2[q[i]];
	for(int i=1;i<=n;i+=3) ans[1][3]+=c3[q[i]];
	for(int i=2;i<=n;i+=3) ans[2][1]+=c1[q[i]];
	for(int i=2;i<=n;i+=3) ans[2][2]+=c2[q[i]];
	for(int i=2;i<=n;i+=3) ans[2][3]+=c3[q[i]];
	for(int i=3;i<=n;i+=3) ans[3][1]+=c1[q[i]];
	for(int i=3;i<=n;i+=3) ans[3][2]+=c2[q[i]];
	for(int i=3;i<=n;i+=3) ans[3][3]+=c3[q[i]];
	Ans=min(Ans,ans[1][1]+ans[2][2]+ans[3][3]);
	Ans=min(Ans,ans[1][1]+ans[2][3]+ans[3][2]);
	Ans=min(Ans,ans[1][2]+ans[2][1]+ans[3][3]);
	Ans=min(Ans,ans[1][2]+ans[2][3]+ans[3][1]);
	Ans=min(Ans,ans[1][3]+ans[2][1]+ans[3][2]);
	Ans=min(Ans,ans[1][3]+ans[2][2]+ans[3][1]);
	printf("%lld\n",Ans);
	if(Ans==ans[1][1]+ans[2][2]+ans[3][3])
	{
		p[1]=1,p[2]=2,p[3]=3;
		for(int i=1;i<=n;i++) c[q[i]]=p[(i-1)%3+1];
	}
	if(Ans==ans[1][1]+ans[2][3]+ans[3][2])
	{
		p[1]=1,p[2]=3,p[3]=2;
		for(int i=1;i<=n;i++) c[q[i]]=p[(i-1)%3+1];
	}
	if(Ans==ans[1][2]+ans[2][1]+ans[3][3])
	{
		p[1]=2,p[2]=1,p[3]=3;
		for(int i=1;i<=n;i++) c[q[i]]=p[(i-1)%3+1];
	}
	if(Ans==ans[1][2]+ans[2][3]+ans[3][1])
	{
		p[1]=2,p[2]=3,p[3]=1;
		for(int i=1;i<=n;i++) c[q[i]]=p[(i-1)%3+1];
	}
	if(Ans==ans[1][3]+ans[2][1]+ans[3][2])
	{
		p[1]=3,p[2]=1,p[3]=2;
		for(int i=1;i<=n;i++) c[q[i]]=p[(i-1)%3+1];
	}
	if(Ans==ans[1][3]+ans[2][2]+ans[3][1])
	{
		p[1]=3,p[2]=2,p[3]=1;
		for(int i=1;i<=n;i++) c[q[i]]=p[(i-1)%3+1];
	}
	for(int i=1;i<=n;i++) printf("%d ",c[i]);
	return 0;
} 
