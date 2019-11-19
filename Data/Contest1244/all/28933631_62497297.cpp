#include<bits/stdc++.h>
#define int long long
using namespace std;
int cost[4][300007];
int color[300007];
vector<int>e[300007];
int d[300007];
int n,cnt;
int x[300007];
int ans[300007];
int vis[300007];
int fa[300007];
void dfs(int father,int now)
{
	x[++cnt]=now;
	for(int i=0;i<e[now].size();i++)
	{
		int nxt=e[now][i];
		if(nxt!=father)  dfs(now,nxt);
	}
}
long long get_ans(int a,int b)
{
	color[1]=a,color[2]=b;
	for(int i=3;i<=n;i++)
		color[i]=6-color[i-1]-color[i-2];
	long long now=0;
	for(int i=1;i<=n;i++) now+=cost[color[i]][x[i]];
	return now;
}
signed main()
{
	ios::sync_with_stdio(false); 
	memset(color,0,sizeof color);
	memset(vis,0,sizeof vis);
	cin>>n;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=n;j++) cin>>cost[i][j];
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		d[x]++,d[y]++;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(d[i]>=3) return cout<<-1<<endl,0;
	cnt=0;
	for(int i=1;i<=n;i++)
		if(d[i]==1) {dfs(-1,i);break;}
	long long Ans=LLONG_MAX;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			int f=i,s=j;
			if(f!=s)
			{
				long long now_ans=get_ans(f,s);
				if(now_ans<Ans)
				{
					Ans=now_ans;
					for(int i=1;i<=n;i++) ans[x[i]]=color[i];
				}
			}
		}
	}
	cout<<Ans<<endl;
	for(int i=1;i<=n;i++) cout<<ans[i]<<(i!=n?" ":"\n");
}

