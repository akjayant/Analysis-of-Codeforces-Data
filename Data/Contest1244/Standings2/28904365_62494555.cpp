#include<bits/stdc++.h>
using namespace std;
#define llong long long
int n;
int c[100100][3];
struct data{
	int to,nxt;
}mp[200200];
int head[100100],cnt;
void link(int x,int y)
{
	mp[++cnt].to=y;
	mp[cnt].nxt=head[x];
	head[x]=cnt;
}
int d[100100];

int id[100100],clk;
void dfs(int x,int fa)
{
	id[++clk]=x;
	for(int i=head[x];i;i=mp[i].nxt)
		if(mp[i].to!=fa)
			dfs(mp[i].to,x);
}
llong dp[100100][3][3];
int al[6];
int an[100100];
int main()
{
	scanf("%d",&n);
	for(int cc=0;cc<3;++cc)
		for(int i=1;i<=n;++i)
			scanf("%d",&c[i][cc]);
	int xx,yy;
	for(int i=1;i<n;++i)
	{
		scanf("%d%d",&xx,&yy);
		link(xx,yy);link(yy,xx);
		d[xx]++;d[yy]++;
		if(d[xx]>2||d[yy]>2)
		{
			puts("-1");
			return 0;
		}
	}
	for(int i=1;i<=n;++i)
		if(d[i]==1)
		{
			dfs(i,0);
			break;
		}
	llong ans=0x7fffffffffffffff;
	int ac1,ac2;
	llong ta;
	for(int c1=0;c1<3;++c1)
		for(int c2=0;c2<3;++c2)
		{
			if(c1==c2)continue;
			al[1]=c1;al[2]=c2;al[0]=3-c1-c2;
			ta=0;
			for(int i=1;i<=n;++i) 
				ta+=c[id[i]][al[i%3]];
			if(ta<ans)
			{
				ans=ta;
				ac1=c1,ac2=c2;
			}
		}
	cout<<ans<<endl;
	al[1]=ac1;al[2]=ac2;al[0]=3-ac1-ac2;
	for(int i=1;i<=n;++i)
		an[id[i]]=al[i%3]+1;
	for(int i=1;i<=n;++i)printf("%d ",an[i]);
	puts("");
	return 0;
}
