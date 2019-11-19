#include<bits/stdc++.h>
#define ll long long
#define inf 0x7f7f7f7f
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0') {x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n;
int c[1000005][5];
vector<int> g[1000005];
ll dp[1000005][5][4];
int chos[1000005];
int v[1000005];
int lev[1000005];
int f[1000005];
int las,beg;
int an[1000005];
int ta[5];
void dfs(int x,int fa)
{
	f[x]=fa;
	for(int i=1;i<=3;i++)
	    for(int j=0;j<=3;j++)
	    {
	    	if(i!=j) dp[x][i][j]=c[x][i];
		}	
	if(g[x].size()==1&&fa!=0) 	
	{ lev[x]=1; return ; }
	for(int i=0;i<g[x].size();i++)
	{
		if(g[x][i]==fa) continue;
		else 
		{
			int to=g[x][i];
			dfs(to,x);
			if(lev[to]==1)
			{
				for(int j=1;j<=3;j++)
					for(int k=1;k<=3;k++)
						if(j!=k) dp[x][j][k]+=dp[to][k][0];
			}
			else
			{
				dp[x][1][2]+=dp[to][2][3];
				dp[x][1][3]+=dp[to][3][2];
				dp[x][2][1]+=dp[to][1][3];
				dp[x][2][3]+=dp[to][3][1];
				dp[x][3][1]+=dp[to][1][2];
				dp[x][3][2]+=dp[to][2][1];
			}
		}
	}
}
void dfs_ans(int x)
{
	if(f[x]==beg) an[x]=las;
	else if(x!=beg)
	{
		for(int i=1;i<=3;i++) ta[i]=0;
		ta[an[f[x]]]=1; ta[an[f[f[x]]]]=1;
		for(int i=1;i<=3;i++) if(ta[i]==0) an[x]=i;
	}
	for(int i=0;i<g[x].size();i++)
	{
			if(g[x][i]==f[x]) continue;
			else dfs_ans(g[x][i]);
	}
}
int main()
{
	n=read();
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=n;j++)
		c[j][i]=read();
	}
	for(int i=1;i<n;i++)
	{
		int l=read(),r=read();
		g[l].push_back(r);
		g[r].push_back(l);
		v[l]++; v[r]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]>=3) { printf("-1");return 0; }
		if(v[i]==1) beg=i;
	}
	dfs(beg,0);
	ll ans=inf; ans*=ans;
	for(int i=1;i<=3;i++) for(int j=1;j<=3;j++)
	if(i!=j) if(dp[beg][i][j]<ans) 
	{ an[beg]=i; las=j; ans=dp[beg][i][j]; }
	cout<<ans<<endl;
	dfs_ans(beg);
	for(int i=1;i<=n;i++)
	    printf("%d ",an[i]);
	return 0;
}
